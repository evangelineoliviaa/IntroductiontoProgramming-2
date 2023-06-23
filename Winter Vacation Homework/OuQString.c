#include <stdio.h>

int k;
long long l, r, tmp, len[53];

void rec(int k){
    if( tmp+len[k] <= l ){  
        tmp+=len[k];
        return ;
    }
    else if(tmp <= r){   
        if(tmp >= l && tmp <= r) printf("O"); 
        tmp++;
        if(k!=1 && tmp <= r) rec(k-1);
        if(tmp >= l && tmp <= r) printf("u"); 
        tmp++;
        if(k!=1 && tmp <= r) rec(k-1);
        if(tmp >= l && tmp <= r) printf("Q"); 
        tmp++;
    }
    else return ;
}

long long lenk(int k){    
    if(len[k]) return len[k];
    if(k==1) return len[1] = 3;
    return len[k] = 3 + 2*lenk(k-1);
}

int main(){
    lenk(50);
    while( scanf("%d %lld %lld", &k, &l, &r)!=EOF ){
        tmp = 0;
        rec(k);
        printf("\n");
    }
    return 0;
}