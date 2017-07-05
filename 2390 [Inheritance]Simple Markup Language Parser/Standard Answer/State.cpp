#include "State.hpp"
#include "Token.hpp"
#include "Parser.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

string trim(string str);

State* DataState::_instance = NULL;
State* TagNameState::_instance = NULL;

// DataState
State* DataState::getInstance() {
 if (_instance == NULL)
  _instance = new DataState();
 return _instance;
}

void DataState::destroyInstance() {
 if (_instance != NULL) {
  delete _instance;
  _instance = NULL;
 }
}

void DataState::handleOneChar(Parser* parser, char ch) {
 if (ch != '<') {
  _cache.push_back(ch);
 } else {
  this->emit(parser->getBulider());
  parser->setState(TagNameState::getInstance());
 }
}

void DataState::emit(Bulider* dest) {
 string trimmedCache = trim(_cache);
 if (!trimmedCache.size()) {
  _cache.clear();
  return;
 }
 Token token;
 token.type = "DATA";
 token.content = trimmedCache;
 _cache.clear();
 dest->handleOneToken(token);
}

// TagNameState
State* TagNameState::getInstance() {
 if (_instance == NULL)
  _instance = new TagNameState();
 return _instance;
}

void TagNameState::destroyInstance() {
 if (_instance != NULL) {
  delete _instance;
  _instance = NULL;
 }
}

void TagNameState::handleOneChar(Parser* parser, char ch) {
 if (ch != '>') {
  _cache.push_back(ch);
 } else {
  this->emit(parser->getBulider());
  parser->setState(DataState::getInstance());
 }
}

void TagNameState::emit(Bulider* dest) {
 if (_cache == "" || _cache == "/") {
  _cache.clear();
  return;
 }
 Token token;
 if (_cache[0] != '/') {
  token.type = "OPEN_TAG";
  token.content = _cache;
 } else {
  token.type = "CLOSE_TAG";
  token.content = _cache.substr(1);
 }
 _cache.clear();
 dest->handleOneToken(token);
}

// useful function
string trim(string str) {
 size_t lo = str.find_first_not_of(' '),
        hi = str.find_last_not_of(' ');
 if (lo >= hi)
  return string("");
 return str.substr(lo, hi - lo + 1);
}
