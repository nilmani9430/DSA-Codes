#include<bits/stdc++.h>
using namespace std;
void print(int *p)
{
    cout<<*p<<endl;
}

void update(int *p)
{
    *p=*p+1;
    // *(&p)=*(&p)+1;  //Both way works 
    // cout<<"inside p "<<p<<endl;
}
int getsum(int arr[],int n)
{
    // cout<<"Size: "<<sizeof(arr)<<endl; //this will give the size of pointer and not the array 
    //above line will give 4 as o/p from this we infer that in this function arr[] is recieved as pointer and not as whole array we can also write getsum(int *arr) it is same thing
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum=sum+arr[i];
    }
    return sum;
    
}
int main()
{
    // int value(5);
    // int *p=&value;
    // // print(p);
    // cout<<"Before "<<*p<<endl; 
    // update(p);
    // cout<<"After "<<*p<<endl;

    int arr[6]={1,2,3,4,5,8};
    cout<<"Sum is "<<getsum(arr+3,3)<<endl;

    return 0;
}