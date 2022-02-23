#include <stdio.h>
 
int min(int a, int b){
    return a < b ? a : b;
}
 
int main(){
 
    int num, power = 1;
 
    scanf("%d",&num);
 
    int dp[num + 1];
    for(int i = 0; i <= num; i++){
        if(i == power){
            dp[i] = 1;
            power *= 2;
            continue;
        }
        dp[i] = min(dp[i - power / 2], dp[power - i]) + 1;
    }
 
    printf("%d",dp[num]);
 
    return 0;
}