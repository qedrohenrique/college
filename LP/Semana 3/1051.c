#include <stdio.h>

int main(){

    double renda;
    double imposto=0;
    scanf("%lf", &renda);

    if(renda>=0&&renda<=2000) imposto=0;
    if(renda>=2000.01&&renda<=3000) imposto=(renda-2000)*0.08;
    if(renda>=3000.01&&renda<=4500) imposto=80+(renda-3000)*0.18;
    if(renda>4500) imposto=80+270+(renda-4500)*0.28;

    if(imposto==0) printf("Isento\n");
    else printf("R$ %.2lf\n", imposto);
    
    return 0;
}