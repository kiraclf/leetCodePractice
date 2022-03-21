#include <cmath>
#include <iostream>
using namespace std;

// 友元函数的使用

class Point {
 public:
  Point(int x = 0, int y = 0) : X(x), Y(y) {}
  int GetX() { return X; }
  int GetY() { return Y; }
  // 定义友元函数
  friend float Distance(Point &a, Point &b);

 private:
  int X, Y;  // 私有成员变量
};

// 在友元函数中可以访问其私有属性
float Distance(Point &a, Point &b) {
  double dx = a.X - b.X;
  double dy = a.Y - b.Y;
  return sqrt(dx * dx + dy * dy);
}

// 友元类

class A {
  friend class B;

 public:
  void Display() { cout << x << endl; }

 private:
  int x;
};

class B {
 public:
  void Set(int i);
  void Display();

 private:
  A a;
};

void B::Set(int i) { a.x = i; }

void B::Display() { a.Display(); }