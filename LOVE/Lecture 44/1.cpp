#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void insertertathead(node* &head,int n)
{ 
    node *temp=new node(n);
    temp->next=head;
    head=temp;
}

void print(node* &head)
{
    node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}

void insertattail(node* &head,int a)
{
    node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    node *t2=new node(a);
    temp->next=t2;
}
int main()
{
    node* head=new node(10);
    node *temp=new node(4);
    head->next=temp;
    insertertathead(head,8);
    insertattail(head,6);
    print(head);
}