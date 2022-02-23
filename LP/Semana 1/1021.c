#include <stdio.h>
int main(){

double N;
int r100, r50, r20, r10, r5, r2, r1, c50, c25, c10, c5,c1;
int reais,centavos;

scanf("%lf",&N);
reais = (N); // Tirando os centavos de N
centavos = ((N - reais) * 100); //Transformando centavos em inteiro

r100 = reais / 100;
reais = reais%100;
r50 = reais / 50;
reais = reais%50;
r20 = reais / 20;
reais = reais%20;
r10 = reais / 10;
reais = reais%10;
r5 = reais / 5;
reais = reais%5;
r2 = reais / 2;
reais = reais%2;
r1 = reais / 1;

c50 = centavos / 50;
centavos = centavos%50;
c25 = centavos / 25;
centavos = centavos%25;
c10 = centavos / 10;
centavos = centavos%10;
c5 = centavos / 5;
centavos = centavos%5;
c1 = centavos / 1;

printf("NOTAS:\n");
printf("%d nota(s) de R$ 100.00\n",r100);
printf("%d nota(s) de R$ 50.00\n",r50);
printf("%d nota(s) de R$ 20.00\n",r20);
printf("%d nota(s) de R$ 10.00\n",r10);
printf("%d nota(s) de R$ 5.00\n",r5);
printf("%d nota(s) de R$ 2.00\n",r2);
printf("MOEDAS:\n");
printf("%d moeda(s) de R$ 1.00\n",r1);
printf("%d moeda(s) de R$ 0.50\n",c50);
printf("%d moeda(s) de R$ 0.25\n",c25);
printf("%d moeda(s) de R$ 0.10\n",c10);
printf("%d moeda(s) de R$ 0.05\n",c5);
printf("%d moeda(s) de R$ 0.01\n",c1);
return 0;
}