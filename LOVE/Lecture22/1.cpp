#include <bits/stdc++.h>
using namespace std;
#define ll long long

 
bool checkpalindrone(char a[],int n)
{
    int s=0;
    int e=n-1;
    while (s<=e)
    {
        if( tolowercase(a[s]) != tolowercase(a[e]) )
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
    }
    return 1;
    
}

void reverse(char name[],int n)
{
    int s=0;
    int e=n-1;
    while (s<e)
    {
        swap(name[s++],name[e--]);
    }
    
}
int getlength(char name[])
{
    int c=0;
    for(int i=0;name[i]!='\0';i++)
    {
        c++;
    }
    return c;
}
int main()
{
    char name[20];
    cout << "Enter your name" << endl;
    cin >> name;
    int len = getlength(name);
    cout << "Your name is: ";
    cout << name << endl;
    cout<<"Length is "<<len<<endl;
    reverse(name, len);
    cout << "After reversing Your name is: ";
    cout << name << endl;

    cout<<"Palindrone or not: "<<checkpalindrone(name,len)<<endl;

    // cout<<"Check lower case "<<tolowercase('a');

}