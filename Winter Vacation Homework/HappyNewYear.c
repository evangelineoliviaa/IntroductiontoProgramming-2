#include<stdio.h>
#define inf 2100000000;

int main(){
    int n , x;
    int mx = -1, mn = inf;

    scanf("%d",&n);
    for(int i = 0; i< n+1; i++){
        scanf("%d",&x);
        if(x>mx){
            mx = x;
        }
        if(x<mn){
            mn = x;
        }
    }
    printf("%d\n",2 * (mx-mn));
}