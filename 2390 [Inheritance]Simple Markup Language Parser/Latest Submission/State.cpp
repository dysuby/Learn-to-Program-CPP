 #include "State.hpp"
#include "Parser.hpp"
State* DataState::_instance = NULL;
State* TagNameState::_instance = NULL;

State* DataState::getInstance() {
  if (_instance)
    return _instance;
  return (_instance = new DataState);
}

void DataState::destroyInstance() {
  delete _instance;
  _instance = NULL;
}

void DataState::handleOneChar(Parser* parser, char ch) {
  if (!_cache.size() && ch == ' ')
    return;
  if (ch == '\0' && _cache.size()) {
    for (auto i = _cache.end() - 1; *i == ' '; --i)
      _cache.erase(i);
  }
  if (ch == '\0')
    emit(parser -> getBulider());
  _cache += ch;
}

void DataState::emit(Bulider* dest) {
  if (_cache.size()) {  
    Token token;
    token.type = "DATA";
    token.content = _cache;
    token.depth = 0;
    dest -> handleOneToken(token);
  }
}

State* TagNameState::getInstance() {
  if (_instance)
    return _instance;
  return (_instance = new TagNameState);
}

void TagNameState::destroyInstance() {
  delete _instance;
  _instance = NULL;
}

void TagNameState::handleOneChar(Parser* parser, char ch) {
  if (ch == '\0')
    emit(parser -> getBulider());
  _cache += ch;
}

void TagNameState::emit(Bulider*dest) {
  if (_cache.size() && _cache != string("/")) {  
    Token token;
    token.type = (_cache[0] == '/') ? "CLOSE_TAG" : "OPEN_TAG";
    token.content = _cache;
    token.depth = 0;
    dest -> handleOneToken(token);
  }
}