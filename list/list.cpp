#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node(int v): val(v), next(NULL) {}
};

Node* build(int n)
{
    Node* head = new Node(0);
    Node* tail = head;
    //Node* m;
    for(int i=1;i<n;i++)
    {
        Node* l = new Node(i);
        tail->next=l;
        tail=l;
        if(i==4) m =l;
    }
    //tail->next = m;
    return head;
}


void vprint(Node *head)
{
    if(head==NULL)
        return;
    vprint(head->next);
    cout<<head->val<<endl;
}


Node* reverse1(Node* head)
{

}


bool checkCycle(Node *head)
{
    int cnt = 0;
    Node *fast, *slow;
    fast = slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        cnt++;
        if(fast == slow){
            cout<<cnt<<endl;
            return true;
        }
    }
    return false;
}


int main()
{
    Node *l = build(9);
    //vprint(l);
    cout<<checkCycle(l)<<endl;
    //Node* l = reverse1(head);
    //while(l){
     //   cout<<l->val<<endl;
     //   l = l->next;
    //}
    return 0;
}

























/*





Node* build(int n)
{
    Node *head = new Node(0);
    Node *t = head;
    for(int i=1; i<n; i++){
        Node *node = new Node(i);
        t->next = node;
        t = node;
    }
    return head;
}


void vprint(Node *head)
{
    if(!head)
        return;
    vprint(head->next);
    cout<<head->val<<endl;
}


Node* reverse1(Node* head)
{
    if(!head) return head;
    Node *p, *q, *t;
    q = head->next;
    head->next = NULL;
    p = head;
    while(q){
        t = q->next;
        q->next = p;
        p = q;
        q = t;
    }
    return p;
}

bool checkCycle(Node* head)
{
    Node *p, *q;
    p = head->next;
    q = head->next->next;
    while(p != q){
        p = p->next;
        if(q&&q->next)
            q = q->next->next;
        else return false;
    }
    return true;
}


*/

















