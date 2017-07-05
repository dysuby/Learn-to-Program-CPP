 #include "DouList.h"
#include <iostream>
#include <sstream>

DouList::DouList(): m_head(NULL), m_tail(NULL) {}
DouList::DouList(const DouList &src): m_head(NULL), m_tail(NULL) {
  DouListNode *temp = src.m_head;
  while (temp) {
    push_back(temp -> elem);
    temp = temp -> next;
  }
}
DouList::~DouList() {
  clear();
}
void DouList::clear() {
  while (m_head) {
    DouListNode *temp = m_head;
    m_head = m_head -> next;
    delete temp;
  }
  m_head = NULL;
  m_tail = NULL;
}
bool DouList::empty() const {
  return !m_head;
}
std::string DouList::to_str() const {
  std::ostringstream res;
  if (!m_head) {
    res << "[]";
  }
  else {
    res << "[" << m_head -> elem;
    DouListNode *temp = m_head -> next;
    while (temp) {
      res << ", " << temp -> elem;
      temp = temp -> next;
    }
    res << "]";
  }
  return res.str();
}
int DouList::front() const {
  if (m_head)
    return m_head -> elem;
  return 0;
}
int DouList::back() const {
  if (m_tail)
    return m_tail -> elem;
  return 0;
}
void DouList::push_front(const int &e) {
  DouListNode *temp = new DouListNode(e, NULL, m_head);
  if (m_head)
    m_head -> prev = temp;
  m_head = temp;
  if (!m_tail)
    m_tail = m_head;
}
void DouList::push_back(const int &e) {
  if (!m_head) {
    m_head = new DouListNode(e, NULL, NULL);
    m_tail = m_head;
    return;
  }
  DouListNode *temp = new DouListNode(e, m_tail, NULL);
  if (m_tail)
    m_tail -> next = temp;
  m_tail = temp;
}
void DouList::pop_front() {
  if (m_head) {
    DouListNode *temp = m_head;
    m_head = m_head -> next;
    m_head -> prev = NULL;
    delete temp;
  }
}
void DouList::pop_back() {
  if (m_tail) {
    DouListNode *temp = m_tail;
    m_tail = m_tail -> prev;
    m_tail -> next = NULL;
    delete temp;
  }
}
DouList& DouList::operator=(const DouList &other) {
  if (m_head == other.m_head)
    return *this;
  clear();
  DouListNode *temp = other.m_head;
  while (temp) {
    push_back(temp -> elem);
    temp = temp -> next;
  }
  return *this;
}
std::ostream& operator<<(std::ostream &out, DouList const &list) {
  out << list.to_str();
  return out;
}