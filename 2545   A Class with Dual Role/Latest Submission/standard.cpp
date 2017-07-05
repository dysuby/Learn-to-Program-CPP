 #include "standard.hpp"

D::D(int a, int b, int c, int d, int e): 
        B(a, b), member(c, d), k(e) {}

void D::print(void) const {
  cout << "Printing from Base:\n";
  B::print();
  cout << "Printing from member:\n";
  member.print();
  cout << "Printing from D field:\n" << k;
}