#include <bits/stdc++.h>
using namespace std;

int solve1(vector<int> &cost,int n){ //simlpe recusion will give tle
    if(n<=1) return cost[n];

    int ans=cost[n]+min(solve1(cost,n-1),solve1(cost,n-2));
    return ans;
} 

int solve2(vector<int> &cost, vector<int> &dp, int n) //recursion + memorozation
{
    if (dp[n] != -1)
        return dp[n];

    dp[n] = min(solve2(cost, dp, n - 1), solve2(cost, dp, n - 2)) + cost[n];
    return dp[n];
}

int solve3(vector<int> &cost, int n) //tabulation
{
    vector<int> dp(n + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}

int solve4(vector<int> &cost, int n) //space optimsation
{
    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int i = 2; i < n; i++)
    {
        int curr = min(prev1, prev2) + cost[i];
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n=cost.size();
    int ans=min(solve1(cost,n-1),solve1(cost,n-2));

    /*int n = cost.size();
    vector<int> dp(n + 1, -1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    return min(solve2(cost, dp, n - 1), solve2(cost, dp, n - 2));*/

    /*int n=cost.size();
    return solve3(cost,n);*/

    /*int n = cost.size();
    return solve4(cost, n);*/
}

int main()
{
}