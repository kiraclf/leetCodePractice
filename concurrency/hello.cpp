#include <iostream>
#include <thread>
#include <vector>

void hello() { std::cout << "Hello" << std::endl; }

int main() {
  std::vector<std::thread> threads;
  for (int i = 0; i < 20; i++) {
    // 此处调用 copy 函数时,会进行 move 的操作,因此无所谓
    threads.push_back(std::thread(hello));
  }
  std::for_each(threads.begin(), threads.end(),
                std::mem_fn(&std::thread::join));
  return 0;
}