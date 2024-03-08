#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i=5;
    int &j=i;  //j is reference varable of i
    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    j++;
    cout<<i<<endl;
    cout<<j<<endl;
}