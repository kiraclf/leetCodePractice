#include <iostream>
void func(int& a) {
  std::cout << "func:" << a << std::endl;
  a = 100;
}

int main() {
  const int d = 30;
  int c = 20;
  func(const_cast<int&>(d));
  func(c);
  std::cout << "first:" << d << std::endl;
  std::cout << "second:" << c << std::endl;
  return 0;
}