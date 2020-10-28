#include <stdio.h>

int main(){
  //degiskenler ilk tanimlandiklarinda bir degere esitlenmek zorunda degildirler
  int girdi_tam_sayi;
  float girdi_ondalikli;
  double girdi_uzun_ondalikli;
  char girdi_harf;
  printf("Harf giriniz: ");
  scanf(" %c",&girdi_harf);
  printf("Tam sayi giriniz: ");
  scanf("%d",&girdi_tam_sayi);
  printf("Ondalikli sayi giriniz: ");
  scanf("%f",&girdi_ondalikli);
  printf("Uzun ondalikli sayi giriniz: ");
  scanf("%lf",&girdi_uzun_ondalikli);
  printf("-------------------------------------------\n");

  printf("Girdirler\n");
  printf("Harf: %c\n",girdi_harf);
  printf("Tam sayi: %d",girdi_tam_sayi);
  //Bir printf icinde birden fazla degisken basilabilir
  printf("Ondalikli sayi: %f\nUzun ondalikli sayi: %lf\n",girdi_ondalikli,girdi_uzun_ondalikli);
  //Bu tip printlemelerde siralama cok onemlidir
  //en soldaki formata virgulden sonra en soldaki degisken basilir
  return 0;
}
