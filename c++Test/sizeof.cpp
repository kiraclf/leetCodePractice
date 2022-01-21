#include <iostream>
using namespace std;

class A {};

class B {
 public:
  char c;
  B(char c) : c(c) {}
};

int main() {
  int aSize = sizeof(A);
  int bSize = sizeof(B);
  cout << "A: " << aSize << endl;
  cout << "B: " << bSize << endl;
  return 0;
}