#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
int n, m;
class state {
  private:
    int s_x, s_y;
    int e_x, e_y;
    int step;
  public:
    state() {step = 0;}
    state(int a, int b, int c, int d) {
        s_x = a;
        s_y = b;
        e_x = c;
        e_y = d;
        step = 0;
    }
    bool ismeet();
    bool isvaild();
    friend void judge();
};
 bool state::ismeet() {
    if (s_x == e_x && s_y == e_y)
        return true;
    else
        return false;
}
bool state::isvaild() {
    if (s_x > 0 && s_x <= n && s_y > 0 && s_y <= m)
        return true;
    else
        return false;
}
  int s_x, s_y, e_x, e_y;
int mov[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
 char aa[21][21];
bool isvisit[21][21];
void judge();
 int main() {
    cin >> n >> m;
    memset(isvisit, false, sizeof(isvisit));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> aa[i][j];
            if (aa[i][j] == 'S') {
                s_x = i;
                s_y = j;
                aa[i][j] = '.';
            }
            if (aa[i][j] == 'E') {
                e_x = i;
                e_y = j;
                aa[i][j] = '.';
            }
        }
    }
    judge();
    return 0;
}
void judge() {
    queue<state> vv;
    vv.push(state(s_x, s_y, e_x, e_y));
    state temp, hold;
    while (!vv.empty()) {
        temp = vv.front();
        vv.pop();
        for (int i = 0; i < 4; i++) {
            hold.s_x = temp.s_x + mov[i][0];
            hold.s_y = temp.s_y + mov[i][1];
            hold.step = temp.step + 1;
            hold.e_x = temp.e_x;
            hold.e_y = temp.e_y;
            if (hold.isvaild() && aa[hold.s_x][hold.s_y] == '.') {
                if (!isvisit[hold.s_x][hold.s_y]) {
                    isvisit[hold.s_x][hold.s_y] = true;
                    if (hold.ismeet()) {
                        cout << hold.step << endl;
                        return;
                    } else {
                        vv.push(hold);
                    }
                }
            }
        }
    }
    cout <<"-1" <<endl;
}