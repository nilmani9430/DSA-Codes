#include<bits/stdc++.h>
using namespace std;
void test(int &b)
{
    b++;
    cout<<"inside test "<<b<<endl;
}
int main()
{
    int a=5;
    test(a);
    cout<<"inside main "<<a<<endl;
}