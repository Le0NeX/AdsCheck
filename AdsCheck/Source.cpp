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
  tmp = L"";
  title_check = L"";
  stream = ' ';
  symbol_found = 0;
  lpcwstr_tmp = nullptr;
  komp_help_not_found = nullptr;
  repair_comp_not_found = nullptr;
  class_search_result = false;
  title_copy_result = false;
  position_search_result = false;
  title_print_result = false;
}

KufoCheck::~KufoCheck() {}

bool KufoCheck::PlaySpeak(const LPCWSTR& sound_name) { 
  PlaySound(sound_name, NULL, SND_FILENAME);
  return true;
}

LPCWSTR KufoCheck::Convert(const std::string& str) {
  SetTmp(std::wstring(str.begin(), str.end()));
  SetLpcwstrTmp(GetTmp().c_str());
  return GetLpcwstrTmp();
}

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
      SetSayPosition(SayPosition(GetAdsFound(), GetSectionName()));
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
	    return true;
	  } else {
	    SetTitleCheck();//""
	    SetTitleCopyResult(false);
	  }
  }
  return false;
}

bool KufoCheck::SayPosition(const int value, const char* str) {
  if (GetPositionSearchResult()) {
          switch (value) {
            case 0:
              PlaySpeak(GetLpcwstrTmp());
              break;
            case 1:
              PlaySpeak(GetLpcwstrTmp());
              break;
            case 2:
              PlaySpeak(GetLpcwstrTmp());
              break;
            case 3:
              PlaySpeak(GetLpcwstrTmp());
              break;
            case 4:
              PlaySpeak(GetLpcwstrTmp());
              break;
            case 5:
              PlaySpeak(GetLpcwstrTmp());
              break;
            case 6:
              PlaySpeak(GetLpcwstrTmp());
              break;
            case 7:
              PlaySpeak(GetLpcwstrTmp());
              break;
            case 8:
              PlaySpeak(GetLpcwstrTmp());
              break;
            case 9:
              PlaySpeak(GetLpcwstrTmp());
              break;
            case 10:
              PlaySpeak(GetLpcwstrTmp());
              break;
          }
  
  }
  return false;
}