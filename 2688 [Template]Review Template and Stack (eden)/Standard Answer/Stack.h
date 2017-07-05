#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class Stack {
    public:
        Stack();
        void push(const T& data);
        T pop();
        T top();
        int size() const;
        bool empty();

    private:
        queue<T> q1;
        queue<T> q2;
        int count;
};

template<typename T>
Stack<T>::Stack() {
    count = 0;
}

template<typename T>
int Stack<T>::size() const {
    return count;
}

template<typename T>
bool Stack<T>::empty() {
    return count == 0;
}

template<typename T>
void Stack<T>::push(const T& data) {
    if (q1.empty() && q2.empty()) {
        q1.push(data);
    } else {
        if (!q1.empty()) q1.push(data);
        else q2.push(data);
    }
    count++;
}

template<typename T>
T Stack<T>::top() {
    if (!q1.empty()) return q1.back();
    return q2.back();
}

template<typename T>
T Stack<T>::pop() {
    T value;
    if (!empty()) {
        if (q1.empty()) {
            while (q2.size() >= 2) {
                q1.push(q2.front());
                q2.pop();
            }
            value = q2.front();
            q2.pop();
        } else {
            while (q1.size() >= 2) {
                q2.push(q1.front());
                q1.pop();
            }
            value = q1.front();
            q1.pop();
        }
        count--;
    }
    return value;
}

template<typename T>
void print(Stack<T> stack) {
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}



