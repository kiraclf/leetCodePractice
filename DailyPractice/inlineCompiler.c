int double_num(int num) {
  __asm__ __volatile__(
      "lsl x0, x0, 1\n"
      "str x0, [sp, #12]\n");
  return num;
}

int main() {
  int res = double_num(2);
  return 0;
}