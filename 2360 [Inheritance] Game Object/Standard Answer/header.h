#ifndef HEADER_H
#define HEADER_H
#include<iostream>
using namespace std;
class gameobject {
    protected:
        double x, y;
        double dx, dy;
        int hp;
    public:
        gameobject(double x = 0, double y = 0, double dx = 0, double dy = 0)
        : x(x), y(y), dx(dx), dy(dy), hp(10) {}
        virtual void select() = 0;
        virtual void move() = 0;
        void under_attack(int x) {
            hp -= x;
        }
        void get_repaired() {
            hp = 10;
        }
        int get_hp() {
            return hp;
        }
};
class worker : public gameobject {
    public:
        worker(double x = 0, double y = 0) : gameobject(x, y, 1, 1) {}
        virtual void select() {
            cout << "Scv good to go, sir!\n";
        }
        virtual void move() {
            x += dx;
            y += dy;
            cout << "Worker moves to (" << x << ", "<< y << ")\n";
        }
        void repair(gameobject* g) {
            g->get_repaired();
        }
        void build(int x) {
            for (int i = 1; i <= x; i++) {
                for (int j = 1; j <= x-i; j++) cout << " ";
                for (int j = 1; j <= 2*i-1; j++) cout << "*";
                cout << endl;
            }
        }
};
class zealot : public gameobject {
    private:
        int _attack;
    public:
        zealot(double x = 0, double y = 0)
        : gameobject(x, y, 2, 2), _attack(1) {}
        virtual void select() {
            cout << "My life for Aiur!\n";
        }
        virtual void move() {
            x += dx;
            y += dy;
            cout << "Zealot moves to (" << x << ", "<< y << ")\n";
        }
        void attack(gameobject* g) {
            g->under_attack(_attack);
        }
};
class tower : public gameobject {
    private:
        int _attack;
    public:
        tower(double x = 0, double y = 0)
        : gameobject(x, y, 0, 0), _attack(1) {}
        virtual void select() {
            cout << "~\n";
        }
        virtual void move() {
            cout << "Tower cannot move.\n";
        }
        void attack(gameobject* g) {
            g->under_attack(_attack);
        }
};
#endif
