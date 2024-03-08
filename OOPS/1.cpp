#include<bits/stdc++.h>
#include<cstring>
using namespace std;
class hero {
    public:
    virtual void show() {
        cout<<"hello 1"<<endl;
    }
    void put()
    {
        cout<<"HEll"<<endl;
    }
};

class hero1 : public hero {
    public:
    void show() {
        cout<<"hello 2"<<endl;
    }
};

int main()
{
    // hero1 obj;
    // hero *ptr;
    // ptr=&obj;
    // ptr->show();

    char arr[4];
    cin>>arr;
    cout<<arr<<"\n";

    char *ptr[4] = {"abcd", "bcda", "cdba", "dbca"};

    if(strcmp(arr, *ptr[0])) cout<<"yes"<<"\n";

    // cout<<*ptr[0]<<"\n";

    // int a= 10;
    // int *ptr;
    // ptr= &a;

    // a = *ptr + a;

    // cout<<a<<"\n";

    return 0;
}