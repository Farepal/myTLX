#include <stdio.h>

int main(){
    int n;
    scanf ("%d",&n);
    if (n & 1){
        printf ("0\n");
    }
    else {
        long long k[n+1];
        k[0] = 1, k[2] = 1;
        for (int i = 4; i <= n; i+=2){
            k[i] = 0;
            for (int j = 0; j < i; j+=2)
                k[i] += k[j] * k[i-2-j];
        }
        printf ("%lli\n", k[n]);
    }
    return 0;
}