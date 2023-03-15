#include<conio.h>
#include<stdio.h>
int main()
{float price,price_vat,discount,total;
 printf("product price : ");
 scanf("%f",&price);
 price_vat=(1.07*price);
 if(price_vat<=10000)discount=price_vat*0.05;
 else discount=price_vat*0.10;
 total=price_vat-discount;
 printf("****************************\n");
 printf("*");
 printf(" price =%11.2f",price);
 printf(" *\n");
 printf("*");
 printf(" price+vat =%11.2f",price_vat);
 printf(" *\n");
 printf("*");
 printf(" discount =%11.2f",discount);
 printf(" *\n");
 printf("*");
 printf(" net pay =%11.2f",total);
 printf(" *\n");
 printf("****************************");
getch();
return 0;
}