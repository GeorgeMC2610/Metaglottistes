#include <stdio.h>

int main(int argc, char const *argv[]) {
  char c1;
  char c2;
  printf("The grammar is :\n", );
  printf("<E> --> (<Y>)\n");
  printf("<Y> --> <A><B>\n");
  printf("<A> --> v|<E> \n", );
  printf("<B> --> -<Y>|+<Y>|ε\n", );
  printf("\n");
  printf("\n");
  printf("So we begin with the E \n", );
  printf("<E> --> (<Y>)\n");
  printf("<Y> --> <A><B>\n");
  printf("Choose for A : you can chose : ν| <Ε>\n");
  c1 = getchar();
  printf("You chose : \n");
  putchar (c1);
  printf("\n");
  return 0;

}
