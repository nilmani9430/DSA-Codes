#include<bits/stdc++.h>
using namespace std;
    const int N=1e5+10;
    vector<int> g[N];
    bool vis[N];
void dfs(int vertex)
{
    //Take action on vertex after entering the vertex
    vis[vertex]=true;
    for(int child:g[vertex])
    {
        if(vis[child]) continue;
        //take action on child  before entering the child node 
        dfs(child);
        //take action on child after entering the child node 
    }
    //Take action on vertex after exiting the vertex
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < 9; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    
}