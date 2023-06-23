#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node *head[20010];
int longest;

int dfs(int now, int parent){
    Node* cur = head[now], *del;
    int max[2]={0};

    while(cur!=NULL){
        if(cur->data!=parent){
            int P = dfs(cur->data,now);

            if(max[0]<P+1){
                max[1]=max[0];
                max[0]=P+1;
            }else if (max[1]<P+1){
                max[1]=P+1;
            }
        }
        del = cur;
        cur = cur->next;

        free(del);
    }

    int D = max[0]+max[1];
    longest = (D>longest)?D:longest;

    head[now]=NULL;
    return max[0];
}

int main(){
    int T,N,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        longest = 0;
        Node *now[20010];
        for(int i = 0; i<N-1; i++){
            scanf("%d%d",&a,&b);
            if(head[a]==NULL)head[a]=now[a]=(Node*)malloc(sizeof(Node));
            else now[a]=now[a]->next=(Node*)malloc(sizeof(Node));
            if(head[b]==NULL)head[b]=now[b]=(Node*)malloc(sizeof(Node));
            else now[b]=now[b]->next=(Node*)malloc(sizeof(Node));

            now[a]->next = NULL;
            now[b]->next = NULL;
            now[a]->data = b;
            now[b]->data = a;
        }
        dfs(1,0);
        printf("%d\n",longest);
    }
}
