#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template<typename T>
class Stack {  
    public:  
        Stack(): top_node(NULL), node_num(0) {}

        Stack(const Stack &stack): top_node(NULL) {
          node_num = stack.node_num;
          if (node_num == 0)
            return;
          Node *oth = stack.top_node -> next;
          top_node = new Node(stack.top_node -> element);
          Node *temp = top_node;
          while (oth) {
            temp -> next = new Node(oth -> element);
            oth = oth -> next;
            temp = temp -> next;
          }
        }

        ~Stack() {
          clear();
        }

        bool empty() {
          return !node_num;
        }

        size_t size() const {
          return node_num;
        }

        T top() const {
          if (node_num)
            return top_node -> element;
          T res;
          return res;
        }

        void push(T element) {
          Node *temp = new Node(element, top_node);
          top_node = temp;
          ++node_num;
        }

        void pop() {
          if (node_num == 0) 
            return;
          Node *temp = top_node -> next;
          delete top_node;
          top_node = temp;
          --node_num;
        }

        void swap(Stack& stack) {
          Node* temp = top_node;
          top_node = stack.top_node;
          stack.top_node = temp;
          size_t i = node_num;
          node_num = stack.node_num;
          stack.node_num = i;
        }

        void reverse() {
          if (node_num == 0)
            return;
          Node *temp = top_node;
          Node *res = new Node(temp -> element);
          temp = temp -> next;
          int size = node_num;
          while (temp) {
            res = new Node(temp -> element, res);
            temp = temp -> next;
          }
          clear();
          node_num = size;
          top_node = res;
        } /*reverse the elements' order in the stack*/

        void clear() {
          Node* temp = top_node;
          while (top_node) {
            temp = top_node -> next;
            delete top_node;
            top_node = temp;
          }
          top_node = NULL;
          node_num = 0;
        }

    private:  
        struct Node {  
            T element;  
            Node* next;  
            Node(T ele, Node *n = NULL) {  
                element = ele;  
                next = n;  
            }  
        };  
        Node *top_node;  
        size_t node_num;  
};
#endif