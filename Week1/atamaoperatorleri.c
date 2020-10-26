#include <stdio.h>

int main(){
  int sayi_1 = 10;
  int sayi_2 = 10;
  int sayi_3 = 10;
  int sayi_4 = 10;
  int sayi_5 = 10;
  sayi_1 += 3;
  printf("%d\n",sayi_1);
  sayi_2 -= 3;
  printf("%d\n",sayi_2);
  sayi_3 /= 3; // DIKKAT Integer Division
  printf("%d\n",sayi_3);
  sayi_4 *= 3;
  printf("%d\n",sayi_4);
  sayi_5 %= 3;
  printf("%d\n",sayi_5);
  return 0;
}
