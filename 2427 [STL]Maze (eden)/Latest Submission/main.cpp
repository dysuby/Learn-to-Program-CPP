#include <iostream>
#include <queue>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::queue;
using std::string;
using std::vector;

typedef struct point {
  int x, y;
  point(int _x, int _y): x(_x), y(_y){}   
} point;

int compute(string maze[], int sy, int sx) {
  queue<point> choice;
  choice.push(point(sx, sy));
  int times(0);
  while (choice.size()) {
    int size = choice.size();
    vector<point> all;
    for (int i = 0; i < size; ++i) {
      all.push_back(choice.front());
      choice.pop();
    }
    for (auto now: all) {
      if (maze[now.y][now.x] == 'E')
        return times;
      else
        maze[now.y][now.x] = '#';
      if (maze[now.y + 1][now.x] != '#' && maze[now.y + 1][now.x] != '!') {
        choice.push(point(now.x, now.y + 1));
      }
      if (maze[now.y][now.x + 1] != '#' && maze[now.y][now.x + 1] != '!') {
        choice.push(point(now.x + 1, now.y));
      }
      if (maze[now.y - 1][now.x] != '#' && maze[now.y - 1][now.x] != '!') {
        choice.push(point(now.x, now.y - 1));
      }
      if (maze[now.y][now.x - 1] != '#' && maze[now.y][now.x - 1] != '!') {
        choice.push(point(now.x - 1, now.y));
      }
    }
    ++times;     
  }
  return -1;
}

int main() {
  int wid(0), hei(0);
  cin >> hei >> wid;
  string maze[21];
  for (int i = 0; i < hei; ++i) 
    cin >> maze[i];
  int sy(0), sx(0);
  bool flag(true);
  for ( ; flag && sy < hei; ++sy) {
    sx = 0;
    for ( ; flag && sx < wid; ++sx) {
      if (maze[sy][sx] == 'S')
        flag = false;
    }
  }
  --sy;
  --sx;
  cout << compute(maze, sy, sx) << endl;
  return 0;
}