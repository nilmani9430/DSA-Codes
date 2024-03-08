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

void intraverse(Node *root, vector<int> &inval)
{
    if (root == NULL)
        return;
    intraverse(root->left, inval);
    inval.push_back(root->data);
    intraverse(root->right, inval);
}
bool twosuminBST(Node *root, int target,pair<int,int> &pairsum)
{
    vector<int> inval;
    intraverse(root,inval);
    int i = 0, j = inval.size()-1;
    while (i < j)
    {
        int sum = inval[i] + inval[j];
        if (sum == target)
        {
            pairsum.first=inval[i];
            pairsum.second=inval[j];
            return true;
        }
        else if (sum > target)
            j--;
        else
            i++;
    }
    return false;
}

Node* flattenbsttosortedLL(Node*root){
    vector<int> inval;
    intraverse(root,inval);
    Node* newroot=new Node(inval[0]);
    Node* curr=newroot;
    for (int i = 1; i <inval.size(); i++)
    {
        Node* temp=new Node(inval[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=curr->right; 
    }
    curr->left=NULL;
    curr->right=NULL;
    return newroot;
}
void prinrLL(Node* root){ //function for  testing
    while (root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->right;
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
Node* convertedintobalancedbst(Node* root){ //inorder will be same for both balanced and non balanced
    vector<int> inval;
    int t=inval.size()-1;
    intraverse(root,inval);
    return inOrdertoBST(0,t,inval);
}

Node* solveforPREtoBST(vector<int> &preval,int mini,int maxi,int &i){
    if(i >= preval.size()) return NULL;
    if((preval[i] < mini) || (preval[i] > maxi)) return NULL;

    Node* root=new Node(preval[i++]);
    root->left=solveforPREtoBST(preval,mini,root->data,i);
    root->right=solveforPREtoBST(preval,root->data,maxi,i);
    return root;
}
Node* preordertoBST(vector<int> &preval){
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=0;
    solveforPREtoBST(preval,mini,maxi,i);
}


int main()
{
    Node* root = NULL;
    cout << "Enter data to create BST "<<endl;
    takeinput(root);

    /*pair<int,int> pairsum;
    cout<<twosuminBST(root,50,pairsum)<<endl;
    cout<<"The pair are "<<pairsum.first<<" "<<pairsum.second<<endl;*/

    /*Node* newroot=flattenbsttosortedLL(root);
    prinrLL(newroot);*/



}