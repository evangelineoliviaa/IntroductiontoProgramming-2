#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct _node
{
    int val;
    struct _node *next;
} node;

node* revertList(node* head){
    node *prev = NULL;
    while(head){
        node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
bool is_palindrome(node *head){
    if (!head || !head->next)
        return true;

    node* p1 = head, *p2 = head, *prev = NULL;
    while (p2 && p2->next) {
        prev = p1;
        p1 = p1->next;
        p2 = p2->next->next;
    }

    prev->next = NULL;
    p1 = revertList(p1);
    while (p1 && head) {
        if (head->val != p1->val)
            return false;
        
        p1 = p1->next;
        head = head->next;
    }
    return true;
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        node *head = malloc(sizeof(node)), *cur = head;
        while (n--)
        {
            scanf("%d", &(cur->val));
            if (n)
                cur = cur->next = malloc(sizeof(node));
            else
                cur->next = NULL;
        }
        putchar(is_palindrome(head) ? 'T' : 'F');
        while (head)
        {
            node *tmp = head;
            head = head->next;
            free(tmp);
        }
    }
    putchar('\n');
    return 0;
}
