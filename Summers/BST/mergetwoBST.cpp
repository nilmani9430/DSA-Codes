#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node *root,vector<int> &inval)
{
    if (root == NULL)
        return;
    inorder(root->left,inval);
    inval.push_back(root->data);
    inorder(root->right,inval);
}
vector<int> mergeArrays(vector<int> &a,vector<int> &b){
    vector<int> ans(a.size()+b.size());
    int i=0,j=0,k=0;
    while (i<a.size() && j<b.size())
    {
        if(a[i]<b[j]){
            ans[k++]=a[i];
            i++;
        }
        else{
            ans[k++]=b[j];
            j++;
        }
    }
    while (i<a.size())
    {
        ans[k++]=a[i];
        i++;
    }
    while (j<b.size())
    {
        ans[k++]=b[j];
        j++;
    }
}
Node* inOrdertoBST(int s,int e,vector<int> &inval){
    if(s>e)return NULL;

    int mid=(s+e)/2;
    Node* root=new Node(inval[mid]);
    root->left=inOrdertoBST(s,mid-1,inval);
    root->right=inOrdertoBST(mid+1,e,inval);
    return root;
}
Node* mergeBST(Node* root1,Node* root2){ //O(m+n) S.C=O(m+n)
    vector<int> bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);

    vector<int> mergedarray=mergeArrays(bst1,bst2);
    int s=0,e=mergedarray.size()-1;
    return inOrdertoBST(s,e,mergedarray);
}

void BSTtosortedDLL(Node* root,Node* &head){
    if(root==NULL) return ;

    BSTtosortedDLL(root->right,head);

    root->right=head;
    if(head!=NULL) head->left=root;
    head=root;
    BSTtosortedDLL(root->left,head);
}
Node* mergeLL(Node* head1,Node* head2){
    Node* head=NULL;
    Node* tail=NULL;
    while (head1!=NULL && head2!=NULL)
    {
        if(head1->data <head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    } 
    while (head1!=NULL)
    {
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    while (head2!=NULL)
    {
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }
    return head;
}
int countnodes(Node* head){
    int cnt=0;
    Node* temp=head;
    while (temp!=NULL)
    {
        cnt++;
        temp=temp->right;
    }
    return cnt;
}
Node* sortedDLLtoBST(Node* &head,int n){
    if(n<=0 || head==NULL) return NULL;
    Node* left=sortedDLLtoBST(head,n/2);
    Node* root=head;
    root->left=left;
    head=head->right;
    root->right=sortedDLLtoBST(head,n-(n/2)-1);
    return root;
}
Node* mergeBSToptimised(Node* root1,Node* root2){ //S.C=O(h1+h2)
    Node* head1=NULL;
    BSTtosortedDLL(root1,head1);
    head1->left=NULL;

    Node* head2=NULL;
    BSTtosortedDLL(root2,head2);
    head2->left=NULL;

    Node* head=mergeLL(head1,head2);

    return sortedDLLtoBST(head,countnodes(head));
}
int main(){

}