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
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};
info solve(Node* root,int &maxsize){
    if(root==NULL) return {INT_MIN,INT_MAX,true,0};
    info left=solve(root->left,maxsize);
    info right=solve(root->right,maxsize);

    info currnode;
    currnode.size=left.size+right.size+1;
    currnode.maxi=max(root->data,right.maxi);
    currnode.mini=max(root->data,right.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currnode.isBST=true;
    }
    else{
        currnode.isBST=false;
    }

    if(currnode.isBST){
        maxsize=max(maxsize,currnode.size);
    }
    return currnode;
}
int largestBST(Node* root){ //T.C=O(n)
    int maxsize=0;
    info temp=solve(root,maxsize);
}
int main(){

}