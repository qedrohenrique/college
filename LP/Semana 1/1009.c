#include <stdio.h>
 
int main() {
 
    int n, hr;
    double sal;
    
    scanf("%d\n%d\n%lf\n", &n, &hr, &sal);
    printf("NUMBER = %d\n", n);
    printf("SALARY = U$ %.2lf\n", hr*sal);
 
    return 0;
}