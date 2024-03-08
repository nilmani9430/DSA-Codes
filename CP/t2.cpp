#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> v;
        for()
        int i=0;
        for(int j=0;j<v.size();j++)
        {
            if(v[j]<0)
            {
                swap(v[i],v[j]);
                i++;
            }
        }
        for(auto it:v)
        {
            cout<<it<<" ";
        }       
    }
}