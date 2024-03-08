#include<bits/stdc++.h>
using namespace std;
int solverec(int n,int x,int y,int z){
    if(n==0) return 0;
    if(n<x && n<y && n<z) return INT_MIN; // if(n<0) return INT_MIN; bith can be written
    int a=1+solverec(n-x,x,y,z);
    int b=1+solverec(n-y,x,y,z);
    int c=1+solverec(n-z,x,y,z);

    int ans=max(a,max(b,c));
    return ans;

}

int solvemem(int n,int x,int y,int z,vector<int> &dp){
    if(n==0) return 0;
    if(n<x && n<y && n<z) return INT_MIN; // if(n<0) return INT_MIN; bith can be written
    
    if(dp[n]!=-1) return dp[n];

    int a=1+solvemem(n-x,x,y,z,dp);
    int b=1+solvemem(n-y,x,y,z,dp);
    int c=1+solvemem(n-z,x,y,z,dp);

    dp[n]=max(a,max(b,c));
    return dp[n];
}

int solvetab(int n,int x,int y,int z){
    vector<int> dp(n+1,INT_MIN);
    dp[0]=0;

    for (int i = 0; i <=n; i++)
    {
        if(i-x>=0)
        dp[i]=max(dp[i],dp[i-x]+1);

        if(i-y>=0)
        dp[i]=max(dp[i],dp[i-y]+1);

        if(i-z>=0)
        dp[i]=max(dp[i],dp[i-z]+1);
    }

    if(dp[n]<0) return 0;
    else return dp[n];
}
int cutsegment(int n,int x,int y,int z){
    /*int ans=solverec(n,x,y,z);
    if(ans<0) return 0;
    else return ans;*/

    /*vector<int> dp(n+1,-1);
    int ans=solvemem(n,x,y,z);
    if(ans<0) return 0;
    else return ans;*/

    return solvetab(n,x,y,z);


}
int main(){
    cout<<cutsegment(8,3,3,3);

}