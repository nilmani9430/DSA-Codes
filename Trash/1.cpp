#include <bits/stdc++.h>

using namespace std;

int primeFactors(int n) {
    // Vector to store prime factors
    map<int,int> factors;

    // Divide by 2 until n is even
    while (n % 2 == 0) {
        factors[2]++;
        n = n / 2;
    }

    // Divide by odd numbers starting from 3
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            factors[i]++;
            n = n / i;
        }
    }

    // If n becomes a prime number greater than 2
    // if (n > 2) {
    //     factors[n]++;
    // }

    int sum=0;
    for (auto it : factors) {
        cout<<it.first<<" "<<it.second<<endl;
        sum += it.second;
    }
    cout<<endl;
    return sum;
}

int main()
{
    map<char,int> m;
    string s="leetcode";
    for(auto it:s){
        m[it]++;
    }
    for(auto it:m){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
