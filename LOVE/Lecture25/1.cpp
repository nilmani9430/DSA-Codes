#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*int num=5;
    cout<<num<<endl;
    cout<<"Address of num is "<<&num<<endl;
    
    int *ptr=&num;
    cout<<"Value is :"<<*ptr<<endl;*/

    // int num=5;
    // int *p=&num;
    // (*p)++;
    // cout<<*p<<endl;

    //Important concept
    int i=3;
    int *t=&i;
    *t=*t+1;
    cout<<*t<<endl;
    cout<<"Before t "<<t<<endl;
    t=t+1;
    cout<<"After t "<<t<<endl;
}
