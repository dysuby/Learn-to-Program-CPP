#include "Bulider.hpp"
#include <string>
#include <iostream>
using std::cout;
using std::endl;

Bulider* Bulider::_instance = NULL;

Bulider* Bulider::getInstance() {
 if (_instance == NULL)
  _instance = new Bulider();
 return _instance;
}

void Bulider::destroyInstance() {
 if (_instance != NULL) {
  delete _instance;
  _instance = NULL;
 }
}

void Bulider::handleOneToken(Token token) {
  // if _error, abort further operations
  if (_error) return;
  if (token.type == "DATA") {
    token.depth = _stack.empty() ? 0 : _stack.top().depth + 1;
    _tokens.push_back(token);
  } else if (token.type == "OPEN_TAG") {
    token.depth = _stack.empty() ? 0 : _stack.top().depth + 1;
    _tokens.push_back(token);
    _stack.push(token);
  } else if (token.type == "CLOSE_TAG") {
    if (!_stack.empty() && _stack.top().content == token.content) {
      _stack.pop();
    } else {
      _error = true;
      return;
    }
  }
}

void Bulider::display() {
  if (_error || !_stack.empty()) {
    _error = true;
    cout << "INVALID INPUT" << endl;
    return;
  }
  for (int i = 0; i < _tokens.size(); ++i) {
    Token cur = _tokens[i];
    cout << std::string(cur.depth * 2, ' ')
         << (cur.type == "DATA" ? cur.content : cur.content + ":") << endl;
  }
}
