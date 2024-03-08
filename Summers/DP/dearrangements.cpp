#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
long long int solverec(int n){
    if(n==1) return 0;
    if(n==2) return 1;

    int ans= (((n-1)%MOD )*((solverec(n-1)%MOD) + (solverec(n-2)%MOD)))%MOD;
    return ans;
}

long long int solvemem(int n,vector<long long int > &dp){
    if(n==1) return 0;
    if(n==2) return 1;

    if(dp[n]!=-1) return dp[n];
    
    dp[n]= (((n-1)%MOD )*((solvemem(n-1,dp)%MOD) + (solvemem(n-2,dp)%MOD)))%MOD;
    return dp[n];
}

long long int solvetab(int n){
    vector<long long int> dp(n+1,0);
    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++){
        long long int first=dp[i-1]%MOD;
        long long int second=dp[i-2]%MOD;
        long long int sum=(first+second)%MOD;

        long long int ans=((i-1)*sum)%MOD;
        dp[i]=ans;
    }

    return dp[n];

}

long long int spaceoptimsation(int n){
    long long int prev2=0;
    long long int prev1=1;

    long long int ans=0;
    for(int i=3;i<=n;i++){
        long long int first=prev1%MOD;
        long long int second=prev2%MOD;
        long long int sum=(first+second)%MOD;

        ans=((i-1)*sum)%MOD;
        prev2=prev1;
        prev1=ans;
    }
    
    return ans;

}
long long int countdearrangement(int n){
    /*vector<long long int> dp(n+1,-1);
    return solvemem(n,dp);*/

    /*return solvetab(n);*/

    /* return spaceoptimsation(n); */


}
int main(){
    cout<<countdearrangement(7);
}