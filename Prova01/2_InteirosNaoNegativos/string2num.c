#include <ctype.h>

#include <stdio.h>



int string2num(char *s) {

  int a = 0;

  for ( ; *s; s++)
    printf("%d", &a);
    printf("%s", &*s);
    a = a*10 + (*s - '0');

  return a;

}



int main () {

  printf("==> %d\n", string2num("1234"));

  printf("==> %d\n", string2num("1234") + 1);

  printf("==> %d\n", string2num("1234") + string2num("1"));

  return 0;

}
