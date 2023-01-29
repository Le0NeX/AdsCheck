#include "Source.h"


KufoCheck::KufoCheck() {
	URL_ONE = L"https://www.kufar.by/l/r~mogilev/kompyuternye-uslugi";
	URL_TWO = L"https://www.kufar.by/l/r~mogilev/remont-tehniki-elektroniki?srel=10";
	FILE = L"downloadedPage.txt";
	urlDownResult = NULL;
	adsFound = 0;
	adsClassSearch = "XS_QS\">";
	adsClassEnd = '<';
	adsTitle = L"Компьютерный мастер, компьютерные услуги с выездом";
	titleCheck = L"";
	stream = ' ';
	symbolFound = 0;
	classSearchResult = false;
	titleCopyResult = false;
	positionSearchResult = false;
	titlePrintResult = false;
}

const HRESULT KufoCheck::urlDownFile(const wchar_t* URL_ONE, const wchar_t* FILE) {

	HRESULT urlDownResult = URLDownloadToFile(NULL, URL_ONE, FILE, 0, NULL);

	if (urlDownResult == S_OK) {
		messagePrint("The download started syccessfuly.");

		return S_OK;

	} else if (urlDownResult == INET_E_DOWNLOAD_FAILURE) {
		messagePrint("The specified resource or callback interface was invalid.");

		return INET_E_DOWNLOAD_FAILURE;

	} else if (urlDownResult == E_OUTOFMEMORY) {
		messagePrint("The buffer length is invalid, or there is insufficient memory to complete the operation.");

		return E_OUTOFMEMORY;
	}
	return urlDownResult;
}

void KufoCheck::streamValue(const wchar_t* FILE) {
	std::wifstream inFile(FILE, std::ios::in);
	inFile.imbue(std::locale("ru_RU.UTF-8"));

	if (inFile.is_open()) {

		while (!inFile.eof() && !getPositionSearchResult()) {
			setStream(inFile.get());
			setClassSearchResult(classSearch(getClassSearchResult(), getSymbolFound(), getAdsClassSearch(), getStream()));
			setTitleCopyResult(createTitleCopy(getClassSearchResult(), getStream(), getAdsClassEnd()));
			setAdsPositionSearch(adsPositionSearch(getTitleCopyResult(), getAdsTitle(), getAdsTitleCheck()));
		}
		inFile.close();
	}
	else { messagePrint("File not opened. ", inFile.exceptions()); }
}

const bool KufoCheck::classSearch(const bool& classSearchResult, const int& symbolFound, const std::string& adsClassSearch, const wchar_t& stream)
{
	if (!classSearchResult)
	{
		for (; symbolFound < adsClassSearch.length();) {
			if (stream == adsClassSearch[symbolFound]) {

				setSymbolFound(+1);
				return false;
			}
			else {
				setSymbolFound();//Variable symbolCount equals 0.
				return false;
			}
		}
		setAdsFound(+1);
	}
	setSymbolFound();//Variable symbolCount equals 0.

	return true;
}

const bool KufoCheck::createTitleCopy(const bool& classSearchResult, const wchar_t& stream, const char& adsClassEnd)
{
	if (classSearchResult)
	{
		if (stream != adsClassEnd)
		{
			setTitleCheck(stream);
		}
		else
		{
			setClassSearchResult(false);
			return true;
		}
	}
	return false;
}

const bool KufoCheck::adsPositionSearch(const bool& titleCopyResult, const std::wstring& adsTitle, const std::wstring& adsTitleCheck)
{
	if (titleCopyResult)
	{
		if (adsTitle == adsTitleCheck)
		{
			messagePrint("Your ads on the: ", getAdsFound(), " spot.");
			return true;
		}
		else
		{
			setTitleCheck();//""
			setTitleCopyResult(false);
		}
	}
	//PlaySound(TEXT("adsKomputerHelpNotFound.wav"), NULL, SND_FILENAME);
	return false;
}