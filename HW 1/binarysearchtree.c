#include<stdio.h>
#include<stdlib.h>
typedef struct _Tree_Node{
    int number;
    struct _Tree_Node* parent;
    struct _Tree_Node* left;
    struct _Tree_Node* right;
}Tree_Node;

Tree_Node* tree_head;

Tree_Node* createTreeNode(int data){
    Tree_Node* node = (Tree_Node*)malloc(sizeof(Tree_Node));
    node->number = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void child(Tree_Node* move, Tree_Node* node){
    if(node->number>move->number){
        if(move->right == NULL){
            move->right = node;
            return;
        }else{
            child(move->right,node);
        }
    }else if(node->number<move->number){
        if(move->left == NULL){
            move->left = node;
            return;
        }else{
            child(move->left,node);
        }
    }
}

void add_node(int n){
    Tree_Node* node = createTreeNode(n);
    Tree_Node* move = tree_head;
    if(tree_head == NULL){
        tree_head = node;
    }
    else{
        child(move,node);
    }
}
void showtree(Tree_Node* treenow){
    if(treenow == NULL)return;
    showtree(treenow->left);
    printf("%d ",treenow->number);
    showtree(treenow->right);
}
int main (){
    int n, a;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);
        add_node(a);
    } 
    showtree(tree_head);
}