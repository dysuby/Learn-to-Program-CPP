#ifndef _CYCLE_LIST_
#define _CYCLE_LIST_

#include <iostream>
#include <vector>
using std::string;
using std::ostream;
using std::vector;
class CycleList {
    private:
        struct node {
            string food;
            node *next, *front;
            node(string fo, node* n = 0, node* f = 0):food(fo), next(n), front(f){}
        };
        node* head;
        int _size;
    public:
        CycleList(const vector<string> &);
        void Eat();  // remove head, head->front,head->next
        void Eat(int pos); // remove pos, pos->next,pos->front
        int size() const;
        void clear();
        ~CycleList();
        friend ostream& operator<<(ostream &, const CycleList &);
        /*
            ouput format：
            foodname+" "
        */
};

#endif