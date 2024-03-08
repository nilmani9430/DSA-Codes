#include<bits/stdc++.h>
using namespace std;
void update(int **p2)
{
    // p2=p2+1; //kuch change hoga? --No Change

    // *p2=*p2+1; //kuch change hoga??  --YES

    **p2=**p2+1;  //kuch change hoga?   --YES
}
int main()
{
    /*int i=5;
    int *p=&i;
    int **p2=&p;
    // cout<<"Sab sahi chal raha"<<endl;
    // cout<<"Printing P "<<p<<endl;
    // cout<<"Address of p "<<&p<<endl;
 

    // cout<<"printing p2 "<<p2<<endl;
    // cout<<*p2<<endl;

    // cout<<*(*(p2))<<endl;

    cout<<"Before "<< i<<endl;
    cout<<"Before "<< p<<endl;
    cout<<"Before "<< p2<<endl;
    update(p2);
    cout<<"after "<< i<<endl;
    cout<<"after "<< p<<endl;
    cout<<"after "<< p2<<endl;*/ 



    int arr[6]={11,21,31};
    int *p=arr;
    cout<<p[2]; //new idea of adding it is equivalent to *(p+2)




}