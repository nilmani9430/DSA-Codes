#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int add(int a,int b){
    return ((a%MOD)+(b%MOD))%MOD;
}
int mul(int a,int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}

int solverec(int n,int k){
    if(n==1) return k;
    if(n==2) return add(k,mul(k,k-1));

    int same=mul(solverec(n-2,k),k-1);
    int diff=mul(solverec(n-1,k),k-1);
    int ans=add(same,diff);

    return ans;
}

/*int solverec(int n,int k){
    if(n==1) return k;
    if(n==2) return add(k,mul(k,k-1));

    int same=mul(solverec(n-2,k),k-1);
    int diff=mul(solverec(n-1,k),k-1);
    int ans=add(same,diff);

    return ans;
}*/

int solvemem(int n,int k,vector<int> &dp){
    if(n==1) return k;
    if(n==2) return add(k,mul(k,k-1));

    if(dp[n]!=-1) return dp[n];

    int same=mul(solvemem(n-2,k,dp),k-1);
    int diff=mul(solvemem(n-1,k,dp),k-1);
    dp[n]=add(same,diff);

    return dp[n];
}

int solvetab(int n,int k){
    vector<int> dp(n+1,-1);
    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));

    for(int i=3;i<=n;i++){
        int same=mul(dp[i-2],k-1);
        int diff=mul(dp[i-1],k-1);
        dp[i]=add(same,diff);
    }

    return dp[n];
}

int spaceoptimsation(int n,int k){
    int prev2=k;
    int prev1=add(k,mul(k,k-1));

    for(int i=3;i<=n;i++){
        int same=mul(prev2,k-1);
        int diff=mul(prev1,k-1);
        int ans=add(same,diff);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int numberofways(int n,int k){
    /*return solverec(n,k);*/   

    /*vector<int> dp(n+1,-1);
    return solvemem(n,k,dp);*/

    /*return solvetab(n,k);*/

    // return spaceoptimsation(n,k); 
}
int main(){
    cout<<numberofways(234,532);
}