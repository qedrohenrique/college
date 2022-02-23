#include <stdio.h>
 
int main() {
 
    int cod, num, cod2, num2;
    double val, val2;
    double total = 0;
    double total2 = 0;
    
    scanf("%d %d %lf\n", &cod, &num, &val);
    total = total + (num*val);
    
    scanf("%d %d %lf\n", &cod2, &num2, &val2);
    total2 = total2 + (num2*val2);
    
    printf("VALOR A PAGAR: R$ %.2lf\n", total+total2);
    
    return 0;
}