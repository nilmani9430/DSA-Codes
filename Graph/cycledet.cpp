#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
bool vis[N];
int maxi=0;
bool dfs(int vertex,int par,int &a)
{
    vis[vertex]=true;
    bool isloopexist=false;
    for(int child:g[vertex])
    {
        if(vis[child] && child==par) continue;
        a++;
        if(vis[child]) 
        {
            maxi=max(maxi,a);
        }
        isloopexist |=dfs(child,vertex,a);
    }
    return isloopexist;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for (int i = 0; i <e; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool isexistloop=false;
    for (int i = 1; i <=n; i++)
    {
        if(vis[i]) continue;
        int a=1;
        if(dfs(i,0,a))
        {
            isexistloop=true;
        }
    }
    cout<<isexistloop<<endl;
    
}