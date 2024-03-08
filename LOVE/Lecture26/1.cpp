#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*int arr[10]={2,3,5,7,8};
    cout<<arr<<endl;
    cout<<"The address of first memory block "<<arr<<endl;
    cout<<"The address of first memory block "<<&arr[0]<<endl;

    cout<<"4th "<<*arr<<endl;
    cout<<"5th "<<*(arr+1)<<endl;

    int i=3;
    cout<<i[arr]<<endl; //NEW THING //POINT TO BE NOTED*/

    /*int temp[10]; 
    cout<<sizeof(temp)<<endl;

    int *ptr=&temp[0];
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(*ptr)<<endl;*/

    /*int a[20]={1,2,3,5};
    cout<<"->"<<&a[0]<<endl;
    // cout<<&a<<endl;
    // cout<<a<<endl;

    int *p=&a[0];
    // cout<<p<<endl;
    // cout<<*p<<endl;
    cout<<"->"<<&p<<endl;*/

    int arr[10]={1,2};
    int *ptr1;
    cout<<sizeof(&ptr1)<<"\n";
    // arr=arr+1 // It will give error as the address of arr cannot be changed 

    int *ptr=&arr[0];
    cout<<ptr<<endl;
    ptr=ptr+1;
    cout<<ptr<<endl;

    

}