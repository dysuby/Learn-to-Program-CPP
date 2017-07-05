#include "Parser.hpp"
Parser* Parser::_instance = NULL;

Parser* Parser::getInstance() {
  if (_instance)
    return _instance;
  return (_instance = new Parser);
}

void Parser::destroyInstance() {
  delete _instance;
  _instance = NULL;
}

void Parser::consumeOneChar(char ch) {
  if (ch == '<' || ch == '>') {
    _state -> handleOneChar(_instance, '\0');
    if (ch == '<') {
      DataState::destroyInstance();
      _state = TagNameState::getInstance();
    }
    else {
      TagNameState::destroyInstance();
      _state = DataState::getInstance();
    }
  } else {
    _state -> handleOneChar(_instance, ch);
  }
}