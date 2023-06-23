#include <iostream>
#include <string>

struct Node{
    Node *prev;
    Node *next;
    int val;
    int tag;
};

class KuoYangPresent {
public:
	KuoYangPresent(int k);
	void Push(int x);
	void Pop();
	void ProgrammingTanoshi();
	void KuoYangTeTe();
	void PrintList(); 
	
private:
	Node *head, *mid, *tail;
	int sz, k;
};

using namespace std;
Node* curTag;

KuoYangPresent::KuoYangPresent(int K){
    head = NULL;
    mid = NULL;
    tail = NULL;
    sz = 0;
    k = K;
}

void KuoYangPresent :: Push(int x){
    Node *temp = new Node;
    //Node *temp(new Node);
    temp->val = x;
    temp->tag = 0;
    temp->next = NULL;
    temp->prev = NULL;

   if(head == NULL){
       head = temp;
       curTag = mid = tail = head;
       sz += 1;
   }
   else{
       tail->next = temp;
       tail->next->prev = tail;
       tail = tail->next;
       sz += 1;
   }

   if(sz % 2 == 1 && sz != 1){
       mid = mid->next;
   }
   
}

void KuoYangPresent::Pop(){
    Node* toPop = mid;
    Node* next = mid->next;
    Node* prev = mid->prev;
    next->prev = prev;
    prev->next = next;
    if(sz % 2 == 1){//odd middle = middle->prev
        if(mid->prev == curTag)curTag = curTag->prev;
        mid = mid->prev;
        sz--;
        delete toPop;
    }
    else if(sz %2 ==0){
        if(mid->next == curTag)curTag = curTag->prev;
        mid = mid->next;
        sz--;
        delete toPop;
    }
}

void KuoYangPresent::ProgrammingTanoshi(){
    Node* node = curTag;
    while(node != NULL){
        if(node->tag == 0) node->tag = 1;
        curTag = node;
        //cout<<"curTag: "<<curTag->val<<endl; // move the currentTag, anggep last time u do tanosh
        node = node->next;
    }
}

void KuoYangPresent::KuoYangTeTe(){
    Node* node = head;
    while(node!= NULL){
        if(node->tag){
            //cout<<']'<<node->val;
            node->val %= k;
        }
        node = node->next;
    }
}

void KuoYangPresent::PrintList(){
    Node* node = head;
    while(node != NULL){
        cout<<node->val<<" ";
        node = node->next;
    }
    cout<< endl;
}

using namespace std;
int n, k, q;

int main() {
	cin >> n >> k >> q;
	KuoYangPresent present = KuoYangPresent(k);
	for (int i = 1; i <= n; ++ i) {
		int x;
		cin >> x;
		present.Push(x);
	}
	while (q--) {
		string op;
		cin >> op;
		if (op == "push") {
			int x;
			cin >> x;
			present.Push(x);
            present.PrintList();
		}
		else if (op == "pop") {
			present.Pop();
            present.PrintList();
		}
		else {
			cin >> op;
			present.ProgrammingTanoshi();
            present.PrintList();
		}
	}
	present.KuoYangTeTe();
	present.PrintList();
}
