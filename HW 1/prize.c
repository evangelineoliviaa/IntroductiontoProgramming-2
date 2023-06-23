#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int number;
    struct _Node* next;
    struct _Node* prev;
}Node;

Node* head;

Node* createNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->number = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Node* createList(int n){
    Node* head = NULL;
    Node* first;
    Node* tail;

    for(int i=1; i<=n; i++){
        if(head == NULL){
            first = createNode(i);
            head = createNode(0);
            head->next = first;
            head->prev = first;
            tail = first;
        }
        else{
            tail->next = createNode(i);
            tail->next->prev = tail;
            tail = tail->next;
        }
    }
    first->prev = tail;
    tail->next = first;
    return head;
}

Node* odd_clockwise(Node* head, int idx){
    Node* node = head;
    for(int i=0; i<idx; i++){
        node = node->next;
    }
    return node;
}

Node* even_anticlockwise(Node* head, int idx){
    Node* node = head;
    for(int i=0; i<idx; i++){
        node = node->prev;
    }
    return node;
}

void printDel(Node* node){
    Node* prev = node->prev;
    Node* next = node->next;
    prev->next = next;
    next->prev = prev;
    printf("%d\n", node->number);
    return;
}

void solveJosephus(int n, int k){
    Node* to_del;

    for(int i=0; i<k; i++){
        int idx;
        scanf("%d", &idx);
        //odd
        if(idx%2==1){
            if(idx%n!= 0) idx = idx%n;
            else if(idx%n==0) idx = n;
            to_del = odd_clockwise(head, idx);
        }
        //even
        else if(idx%2==0){
            if(idx%n!=0) idx = idx%n;
            else if(idx%n==0) idx = n;
            to_del = even_anticlockwise(head, idx);
        }
        head = to_del;
        printDel(to_del);
        n--;
    }
}


int main(){

    int n, k;

    while(scanf("%d%d", &n, &k)!=EOF){
        head = createList(n);
        solveJosephus(n, k);
    }

    return 0;
}