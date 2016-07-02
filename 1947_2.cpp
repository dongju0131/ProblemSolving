#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i;
    long long int data[1000005];
    data[1] = 0;
    data[2] = 1;
    for(i = 3;i <= n;i++){
        data[i] = (i - 1) * (data[i-1] + data[i-2]) % 1000000000;
        // data[i] %= 1000000000;
    }
    printf("%lld",data[n] % 1000000000);
    return 0;
}