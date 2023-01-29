#pragma once
#pragma comment (lib, "urlmon.lib")
#pragma comment (lib, "winmm.lib")

#include <urlmon.h>
#include <string>
#include <fstream>
#include <iostream>
#include <mmsystem.h>

class KufoCheck {
public:
	KufoCheck();

	const wchar_t* getURL_ONE() { return this->URL_ONE; }
	const wchar_t* getURL_TWO() { return this->URL_TWO; }
	const wchar_t* getFile() { return this->FILE; }
	const int getSymbolFound() { return this->symbolFound; }
	const wchar_t& getStream() { return this->stream; }
	const std::wstring& getAdsTitle() { return this->adsTitle; }
	const std::wstring& getAdsTitleCheck() { return this->titleCheck; }
	const std::string& getAdsClassSearch() { return this->adsClassSearch; }
	const bool& getClassSearchResult() { return this->classSearchResult; }
	const bool& getTitleCopyResult() { return this->titleCopyResult; }
	const char& getAdsClassEnd() { return this->adsClassEnd; }
	const int& getAdsFound() { return this->adsFound; }
	const bool& getPositionSearchResult() { return this->positionSearchResult; }

	void setUrlDownFile(const HRESULT& urlDownResult) { this->urlDownResult = urlDownResult; }
	void setAdsFound(const int& value) { this->adsFound += value; }
	void setStream(const wchar_t& stream) { this->stream = stream; }
	void setSymbolFound(const int& symbolFound) { this->symbolFound += symbolFound; }
	void setClassSearchResult(const bool& classSearchResult) { this->classSearchResult = classSearchResult; }
	void setTitleCopyResult(const bool& titleCopyResult) { this->titleCopyResult = titleCopyResult; }
	void setAdsPositionSearch(const bool& positionSearchResult) { this->positionSearchResult = positionSearchResult; }
	void setTitlePrintResult(const bool& titlePrintResult) { this->titlePrintResult = titlePrintResult; }
	void setTitleCheck(const wchar_t& symbol) { this->titleCheck += symbol; }
	
	void setSymbolFound() { this->symbolFound = 0; }
	void setTitleCheck() { this->titleCheck = L""; }

	const HRESULT urlDownFile(const wchar_t* URL_ONE, const wchar_t* FILE);
	void streamValue(const wchar_t* FILE);
	const bool classSearch(const bool& classSearchResult, const int& symbolFound, const std::string& adsClassSearch, const wchar_t& stream);
	const bool createTitleCopy(const bool& classSearchResult, const wchar_t& stream, const char& adsClassEnd);
	void messagePrint(const std::string& message) { std::cout << message << std::endl; }
	void messagePrint(const std::string& message, const int& value) { std::cout << message << value << std::endl; }
	void messagePrint(const std::string& messageOne, const int& value, const std::string& messageTwo) { std::cout << messageOne << value << messageTwo << std::endl; }
	void messagePrint(const wchar_t& symbol) { std::wcout << symbol; }
	const bool adsPositionSearch(const bool& titleCopyResult, const std::wstring& adsTitle, const std::wstring& adsTitleCheck);

private:
	const wchar_t* URL_ONE;
	const wchar_t* URL_TWO;
	const wchar_t* FILE;
	HRESULT urlDownResult;
	int adsFound;
	std::string adsClassSearch;
	char adsClassEnd;
	std::wstring adsTitle;
	std::wstring titleCheck;
	wchar_t stream;
	int symbolFound;
	bool classSearchResult;
	bool titleCopyResult;
	bool positionSearchResult;
	bool titlePrintResult;
};