#include <future>
#include <iostream>
#include <thread>
int findAnser() { return 20; };

int main() {
  std::future<int> answer = std::async(findAnser);
  bool validate1 = answer.valid();
  std::cout << validate1 << std::endl;
  int res1 = answer.get();
  bool validate2 = answer.valid();
  std::cout << validate2 << std::endl;
  // int res2 = answer.get();
  // int res3 = answer.get();
  // std::cout << res1 << " " << res2 << " " << res3 << std::endl;
  return 0;
}