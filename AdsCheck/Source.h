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
 ~KufoCheck();

 //This is getters.
  const wchar_t* GetUrlOne() {
	return this->URL_ONE;
  }
  const wchar_t* GetUrlTwo() {
	return this->URL_TWO;
  }
  const wchar_t* GetFile() {
	return this->FILE;
  }
  const int GetSymbolFound() {
	return this->symbol_found;
  }
  const wchar_t GetStream() {
	return this->stream;
  }
  const std::wstring& GetAdsTitle() {
	return this->ads_title;
  }
  const std::wstring& GetAdsTitleCheck() {
	return this->title_check;
  }
  const std::string& GetAdsClassSearch() {
	return this->ads_class_search;
  }
  const bool GetClassSearchResult() {
	return this->class_search_result;
  }
  const bool GetTitleCopyResult() {
	return this->title_copy_result;
  }
  const char GetAdsClassEnd() {
	return this->ads_class_end;
  }
  const int GetAdsFound() {
	return this->ads_found;
  }
  const bool GetPositionSearchResult() {
	return this->position_search_result;
  }

  //Thiss is setters.
  void SetUrlDownFile(const HRESULT& url_down_result) {
	this->url_down_result = url_down_result; }
  void SetAdsFound(const int value) {
	this->ads_found += value;
  }
  void SetStream(const wchar_t stream) {
	this->stream = stream;
  }
  void SetSymbolFound(const int symbol_found) {
	this->symbol_found += symbol_found;
  }
  void SetClassSearchResult(const bool class_search_result) {
	this->class_search_result = class_search_result;
  }
  void SetTitleCopyResult(const bool title_copy_result) {
	this->title_copy_result = title_copy_result;
  }
  void SetAdsPositionSearch(const bool position_search_result) {
	this->position_search_result = position_search_result;
  }
  void SetTitlePrintResult(const bool title_print_result) {
	this->title_print_result = title_print_result;
  }
  void SetTitleCheck(const wchar_t symbol) {
	this->title_check += symbol;
  }
  void SetSymbolFound() {
	this->symbol_found = 0;
  }
  void SetTitleCheck() {
	this->title_check = L"";
  }

  HRESULT UrlDownFile(const wchar_t* url_one, const wchar_t* file);
  void StreamValue(const wchar_t* file);
  bool ClassSearch(const std::string& ads_class_search, const wchar_t stream);
  bool CreateTitleCopy(const wchar_t stream, const char ads_class_end);
  bool AdsPositionSearch(const std::wstring& ads_title, const std::wstring& ads_title_check);
  void MessagePrint(const std::string& message) {
	std::cout << message << '\n';
  }
  void MessagePrint(const std::string& message, const int value) {
	std::cout << message << value << '\n';
  }
  void MessagePrint(const std::string& message_one, const int value, const std::string& message_two) {
	std::cout << message_one << value << message_two << '\n';
  }
  void MessagePrint(const wchar_t symbol) {
	std::wcout << symbol;
  }

private:
  const wchar_t* URL_ONE;
  const wchar_t* URL_TWO;
  const wchar_t* FILE;
  HRESULT url_down_result;
  int ads_found;
  std::string ads_class_search;
  char ads_class_end;
  std::wstring ads_title;
  std::wstring title_check;
  wchar_t stream;
  int symbol_found;
  bool class_search_result;
  bool title_copy_result;
  bool position_search_result;
  bool title_print_result;
};