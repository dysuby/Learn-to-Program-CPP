#include "Bulider.hpp"
#include <iostream>
using std::cout;
using std::endl;
Bulider* Bulider::_instance = NULL;

Bulider* Bulider::getInstance() {
  if (_instance)
    return _instance;
  else
    return (_instance = new Bulider);
}

void Bulider::destroyInstance() {
  delete _instance;
  _instance = NULL;
}

void Bulider::handleOneToken(Token token) {
  if (!_stack.size() && token.type == "OPEN_TAG") {
    token.depth = 0;
    _stack.push(token);
    _tokens.push_back(token);
    return;
  } else if (!_stack.size()){
    _error = true;
    return;
  }
  if (token.type == "OPEN_TAG" || token.type == "DATA") {
    Token prev = _stack.top();
    token.depth = prev.depth + 1;
    _tokens.push_back(token);
    if (token.type == "OPEN_TAG")
      _stack.push(token);
  } else if (token.type == "CLOSE_TAG") {
    Token prev = _stack.top();
    if ((string("/") + prev.content) != token.content) 
      _error = true;
    else
      _stack.pop();
  }
}

void Bulider::display() {
  if (_error || _stack.size()) {
    cout << "INVALID INPUT" << endl;
  } else {
    for (Token token: _tokens) {
      for (int i = 0; i < token.depth; ++i)
        cout << "  ";
      cout << token.content;
      cout << (token.type == "OPEN_TAG" ? ":" : "") << endl;
    }
  }
}