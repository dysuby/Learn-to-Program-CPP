#ifndef SOURCE
#define SOURCE
class Exp {
  public:
    Exp() {++count;}
    ~Exp() {--count;}
    static int get_Exp() {
      return count;
    }
  private:
    static int count;
};
int Exp::count = 0;
#endif