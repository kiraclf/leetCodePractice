#include <iostream>
#include <string>
using namespace std;
int globalVal = 20;

int& foo() {
  int a = 20;
  return a;
}

string printName() { return "hello"; }

/// 允许任意的 lValue 或者 rVlaue 传入
void printReference(const string& str) { cout << str; }

/// 只允许 rValue 传入
void printReference(string&& str) { cout << str; }

int main() {
  // 调用第一个方法
  printReference("hello");
  // 调用第二个方法
  printReference(printName());
  return 0;
}

class ArrayWrapper {
 public:
  // common constructor
  ArrayWrapper(int n) : _p_values(new int[n]), _size(n) {}
  // common copy constructor
  ArrayWrapper(const ArrayWrapper& other)
      : _p_values(new int[other._size]), _size(other._size) {
    for (int i = 0; i < _size; i++) {
      _p_values[i] = other._p_values[i];
    }
  }
  // move constructor
  ArrayWrapper(ArrayWrapper&& other)
      : _p_values(other._p_values), _size(other._size) {
    // 此处需要设空的原因在于一旦 other 的生命周期到后,也会自动调用 ~
    // 方法,如果不将其对应的指针设置为 null,
    // 那么就会自动清除我们保存的指针的内容
    other._p_values = nullptr;
    other._size = 0;
  }
  ~ArrayWrapper() { delete[] _p_values; }

 private:
  int* _p_values;
  int _size;
};