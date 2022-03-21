// 常类型的对象必须被初始化,而且初始化后不能更新

int main() {
  int a = 100;
  int* const ptr = &a;
  *ptr = 10;
  return 0;
}