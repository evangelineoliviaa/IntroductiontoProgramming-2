#include <stdio.h>
#define maxn 200005
char s[maxn];
int idx[30];
char map[30];

void swap_int(int* a, int* b);
void swap_char(char* a, char* b);

int main(){
    int n, m;
    char c1, c2;
    
    for(int i=0; i<26; i++){
        idx[i] = i;
        map[i] = (char)('a'+i);
    }

    scanf("%d %d", &n, &m);  
    scanf("%s", s);
    for(int i=0; i<m; ++i){
        scanf(" %c %c", &c1, &c2);
        swap_char(&map[idx[c1-'a']], &map[idx[c2-'a']]);
        swap_int(&idx[c1-'a'], &idx[c2-'a']);       
    }

    for(int i=0; i<n; i++){
        printf("%c", map[s[i]-'a']);
    }
    printf("\n");

    return 0;
}

void swap_int(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void swap_char(char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}