#include "Source.h"


KufoCheck::KufoCheck() {
  URL_ONE = L"https://www.kufar.by/l/r~mogilev/kompyuternye-uslugi";
  URL_TWO = L"https://www.kufar.by/l/r~mogilev/remont-tehniki-elektroniki?srel=10";
  FILE = L"downloadedPage.txt";
  section_name = "";
  url_down_result = NULL;
  ads_found = 0;
  ads_class_search = "XS_QS\">";
  ads_class_end = '<';
  ads_title = L"Компьютерный мастер, компьютерные услуги с выездом";
  title_check = L"";
  stream = ' ';
  symbol_found = 0;
  class_search_result = false;
  title_copy_result = false;
  position_search_result = false;
  title_print_result = false;
  sounds_names = {L"sorry_lord.wav",
                  L"ads_in_section.wav",
                  L"computer_help.wav",
                  L"repair_computers.wav",
                  L"needs_updating.wav",
                  L"current_position.wav",
                  L"one.wav",
                  L"two.wav",
                  L"three.wav",
                  L"four.wav",
                  L"five.wav",
                  L"six.wav",
                  L"seven.wav",
                  L"eight.wav",
                  L"nine.wav",
                  L"ten_or_more.wav"
  };
}

KufoCheck::~KufoCheck() {}

HRESULT KufoCheck::UrlDownFile(const wchar_t* url_one, const wchar_t* file) {

  HRESULT url_down_result = URLDownloadToFile(NULL, url_one, file, 0, NULL);
    if (url_down_result == S_OK) {
	//MessagePrint("The download started syccessfuly.\n");
	return S_OK;

  } else if (url_down_result == INET_E_DOWNLOAD_FAILURE) {
	MessagePrint("The specified resource or callback interface was invalid.");
	return INET_E_DOWNLOAD_FAILURE;

  } else if (url_down_result == E_OUTOFMEMORY) {
	MessagePrint("The buffer length is invalid, or there is insufficient memory to complete the operation.");
	return E_OUTOFMEMORY;
  }
  return url_down_result;
}

void KufoCheck::StreamValue(const wchar_t* file) {
  std::wifstream in_file(file, std::ios::in);
  in_file.imbue(std::locale("ru_RU.UTF-8"));

  if (in_file.is_open()) {
    while (!in_file.eof() && !GetPositionSearchResult()) {
      SetStream(in_file.get());
	    SetClassSearchResult(ClassSearch(GetAdsClassSearch(), GetStream()));
	    SetTitleCopyResult(CreateTitleCopy(GetStream(), GetAdsClassEnd()));
	    SetAdsPositionSearch(AdsPositionSearch(GetAdsTitle(), GetAdsTitleCheck()));
      SayPosition(GetAdsFound(), GetSectionName());
	  }
    in_file.close();
  } else {
    MessagePrint("File not opened. ", in_file.exceptions());
  }
}

bool KufoCheck::ClassSearch(const std::string& ads_class_search, const wchar_t stream) {
  if (!GetClassSearchResult()) {
	for (; GetSymbolFound() < ads_class_search.length();) {
      if (stream == ads_class_search[GetSymbolFound()]) {
		SetSymbolFound(+1);
		return false;
	  } else {
		SetSymbolFound();//Variable symbolCount equals 0.
		return false;
	  }
	}
	SetAdsFound(+1);
  }
  SetSymbolFound();//Variable symbolCount equals 0.
  return true;
}

bool KufoCheck::CreateTitleCopy(const wchar_t stream, const char ads_class_end) {
  if (GetClassSearchResult()) {
    if (stream != ads_class_end) {
	  SetTitleCheck(stream);
	} else {
	  SetClassSearchResult(false);
	  return true;
	}
  }
  return false;
}

bool KufoCheck::AdsPositionSearch(const std::wstring& ads_title, const std::wstring& ads_title_check) {
  if (GetTitleCopyResult()) {
	  if (ads_title == ads_title_check) {
      MessagePrint("Your ads in section: ");
      MessagePrint(GetSectionName());
      MessagePrint(" to be on the: ");
      MessagePrint(GetAdsFound());
      MessagePrint(" position.\n");
      SayPosition(GetAdsFound(), GetSectionName());
	    return true;
	  } else {
	    SetTitleCheck();//""
	    SetTitleCopyResult(false);
	  }
  }
  return false;
}

void KufoCheck::SayPosition(const int value, const char* section) {
  if (GetPositionSearchResult()) {
    if (value > 4) {
      PlaySound(GetSoundsNames().at(0), NULL, SND_FILENAME);
      PlaySound(GetSoundsNames().at(1), NULL, SND_FILENAME);
      
      if (section == "Services the computers") { PlaySound(GetSoundsNames().at(2), NULL, SND_FILENAME);
      } else if (section == "Computers repair") { PlaySound(GetSoundsNames().at(3), NULL, SND_FILENAME);
      }
      PlaySound(GetSoundsNames().at(4), NULL, SND_FILENAME);
      PlaySound(GetSoundsNames().at(5), NULL, SND_FILENAME);

      switch (value) {
        case 5: PlaySound(GetSoundsNames().at(10), NULL, SND_FILENAME);
          break;
        case 6: PlaySound(GetSoundsNames().at(11), NULL, SND_FILENAME);
          break;
        case 7: PlaySound(GetSoundsNames().at(12), NULL, SND_FILENAME);
          break;
        case 8: PlaySound(GetSoundsNames().at(13), NULL, SND_FILENAME);
          break;
        case 9: PlaySound(GetSoundsNames().at(14), NULL, SND_FILENAME);
          break;
        case 10: PlaySound(GetSoundsNames().at(15), NULL, SND_FILENAME);
          break;
      }
    } else if(value == 0) {

    }
  }
}