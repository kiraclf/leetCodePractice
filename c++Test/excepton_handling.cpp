#include <stdio.h>
using namespace std;
class Error {};

void f() {
  throw Error();
};

int main() {
  try {
    f();
  } catch (const Error&) {
    printf("catch error");
  }
  printf("continue");
  return 0;
}