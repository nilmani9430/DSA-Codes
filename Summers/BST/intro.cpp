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

Node *insertintobst(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertintobst(root->right, d);
    }
    else
    {
        root->left = insertintobst(root->left, d);
    }
    return root;
}
void takeinput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertintobst(root, data);
        cin >> data;
    }
}

void levelordertraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

bool searchinBST(Node* root,int x) //this is recursive takes O(n) in case of sckewed binary tree
{
    if(root==NULL) return false;
    if(root->data==x) return true;
    if(root->data<x) return searchinBST(root->right,x);
    if(root->data>x) return searchinBST(root->left,x);
}

bool searchbstiterative(Node* root,int x){
    if(root==NULL) return false;

    Node* temp=root;
    bool ans=false;
    while (temp!=NULL)
    {
        if(temp->data==x) 
        {
            break;
            ans=true;
        }
        if(temp->data>x) temp=temp->left; 
        else if(temp->data<x) temp=temp->right; 
    }
    return ans; 
}

Node* minvalue(Node* root)
{
    Node* temp=root;
    while (temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

Node* maxvalue(Node* root)
{
    Node* temp=root;
    while (temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
}

Node* deletion(Node* root,int x)
{
    if(root==NULL) return root;
    if(root->data==x)
    {
        // 0 child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        //1 child 
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minvalue(root->right)->data;
            root->data=mini;
            root->right=deletion(root->right,mini);
            return root;
        }
    }
    else if(root->data>x)
    {
        root->left=deletion(root->left,x);
        return root;
    }
    else{
        root->right=deletion(root->right,x);
        return root;
    }
}

bool isBST(Node* root,int min,int max){
    if(root==NULL) return true;
    if(root->data>=min && root->data<=max){
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left && right;
    }
    return false;
}
bool validateBST(Node* root)
{
    return isBST(root,INT_MIN,INT_MAX);
}

int solve(Node* root,int &i,int k){
    if(root==NULL) return -1;
    int left=solve(root->left,i,k);
    //L
    if(left!=-1) return left;
    //N
    i++;
    if(i==k) return root->data; // place n-k+1 in place of k for finding kth largest element 
    //R
    return solve(root->right,i,k);
}
int kthsmallest(Node* root,int k){
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}

pair<int,int> predecessor_and_successor(Node* root,int key){
    //find key
    int predecessor=-1;
    int successor=-1;
    Node* temp=root;
    while (temp->data!=key)
    {
        if(temp->data>key) 
        {
            successor=temp->data;
            temp=temp->left;
        }
        else{
            predecessor=temp->data;
            temp=temp->right;
        }
    }
    
    //pred
    Node* lefttree=temp->left;
    while (lefttree!=NULL)
    {
        predecessor=lefttree->data;
        lefttree=lefttree->right;
    }

    //succ
    Node* righttree=temp->right;
    while (righttree!=NULL)
    {
        successor=righttree->data;
        righttree=righttree->left;
    }
    pair<int,int> ans={predecessor,successor};
    return ans; 
}

Node* LCAinbst(Node* root,Node* p,Node* q)
{
    if(root==NULL) return NULL;

    if(root->data<p->data && root->data<q->data) return LCAinbst(root->right,p,q);
    if(root->data>p->data && root->data>q->data) return LCAinbst(root->left,p,q);
    else return root;
}
Node* LCAinbstiterative(Node* root,Node* p,Node* q)
{
    while(root!=NULL){
        if(root->data<p->data && root->data<q->data) root=root->right;
        if(root->data>p->data && root->data>q->data) root=root->left;
        else return root;
    }
}


int main()
{
    Node* root = NULL;
    cout << "Enter data to create BST "<<endl;
    takeinput(root);
    // cout<<"Printing the BST"<<endl;
    // levelordertraversal(root);
    // cout<<"Min value is "<<minvalue(root)->data<<endl;
    // cout<<"Max value is "<<maxvalue(root)->data<<endl;
    // root=deletion(root,30); // 0 child
    // root=deletion(root,90); // 1 child
    // root=deletion(root,50); // 2 child
    // cout<<"Printing the BST after deletion"<<endl;
    // levelordertraversal(root);
    /*pair<int,int> ps= predecessor_and_successor(root,30);
    cout<<"The predecessor is "<<ps.first<<endl;
    cout<<"The successor is "<<ps.second<<endl;*/

    /*Node* p=root->left->left;
    Node* q=root->right->right;
    cout<<"LCA is "<<LCAinbst(root,p,q)->data<<endl;*/


}