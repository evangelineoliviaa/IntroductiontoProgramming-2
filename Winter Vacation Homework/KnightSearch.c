#include <stdio.h>

char r[110][110];
char as[13] = "ICPCASIASG";    
int n, flag;                   

void rec(int now, int prog){   

    if(prog == 10){
        flag = 1;
        return;
    }
    for(int i=-2; i<=2 && !flag; i++)  
    for(int j=-2; j<=2 && !flag; j++){     
        if( j*j + i*i != 5 || now/n + i < 0 || now/n + i >= n || now%n + j < 0 || now%n + j >= n ){
            continue;
        }
        if( r[now/n+i][now%n+j] == as[prog] ) {
        rec( now + i*n + j, prog+1 );
        }
    }
    return;
}

int main(){
    scanf("%d\n", &n);
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        scanf("%c", &r[i][j]);

    flag=0;
    int cnt=-1;
    while(cnt < n*n && !flag){
        cnt++;
        if(r[cnt/n][cnt%n] == as[0]){
        rec(cnt, 1);
        }
    }
    printf("%s\n", (flag?"YES":"NO") );
    return 0;
}
