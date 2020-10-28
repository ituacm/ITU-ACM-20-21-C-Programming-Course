#include <stdio.h>

int main(){
  int sayi_1 = 10;
  int sayi_2 = 3;
  double toplama_islemi = sayi_1 + sayi_2;
  printf("%lf\n",toplama_islemi);
  double cikarma_islemi = sayi_1 - sayi_2;
  printf("%lf\n",cikarma_islemi);
  double carpma_islemi = sayi_1 * sayi_2;
  printf("%lf\n",carpma_islemi);
  //Alttaki islem sonucunun 3.333 olmasi beklenir
  //fakt sonuc 3.0000 olarak gozukur buna Integer Division denir
  //yani iki sayi birbirine bolundugunde sonuc
  //ondalikli olmasi gerekse bile oyle olmaz
  double tam_sayi_bolme_islemi = sayi_1 / sayi_2; //sonuc 3.0000
  printf("%lf\n",tam_sayi_bolme_islemi);
  //Integer Division'dan kacinmak icin
  //islemdeki sayilardan birinin onune double isareti konulmalidir (oncelik durumuna dikkat edilmelidir)
  double ondalikli_sayi_bolme_islemi = sayi_1 / (double) sayi_2; //sonuc 3.333333
  printf("%lf\n",ondalikli_sayi_bolme_islemi);
  int mod_islemi = sayi_1 % sayi_2;
  printf("%d\n",mod_islemi);
  return 0;
}
