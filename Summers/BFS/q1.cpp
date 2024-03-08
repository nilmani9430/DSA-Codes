#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;
int vis[8][8];
int lev[8][8];
int getx(string s)
{
    return s[0]-'a';
}
int getY(string s)
{
    return s[1]-'1';
}
bool isvalid(int x,int y)
{
    return x>=0 && y>=0 && x<8 && y<8;
}
vector<pair<int,int>> movements = {
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,-1},{2,1},
    {-2,-1},{-2,1},
};
int bfs(string source,string dest)
{
    int sourcex=getx(source);
    int sourcey=getY(source);
    int destx=getx(dest);
    int desty=getY(dest);
    queue<pair<int,int>> q;
    q.push({sourcex,sourcey});
    vis[sourcex][sourcey]=1;
    lev[sourcex][sourcey]=0;
    while (!q.empty())
    {
        pair<int,int> v=q.front();
        int x=v.first,y=v.second;
        q.pop();
        for(auto movement:movements)
        {
            int childx=movement.first+x;
            int childy=movement.second+y;
            if(!isvalid(childx,childy)) continue;
            if(!vis[childx][childy])
            {
                q.push({childx,childy});
                lev[childx][childy]=lev[x][y]+1;
                vis[childx][childy]=1;
            }
        }
        if(lev[destx][desty]!=INF) break;
    }
    return lev[destx][desty];
}
void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8;j++)
        {
            lev[i][j]=INF;
            vis[i][j]=0;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        reset();
        string s1,s2;
        cin>>s1>>s2;
        cout<<bfs(s1,s2)<<endl;
    } 
}