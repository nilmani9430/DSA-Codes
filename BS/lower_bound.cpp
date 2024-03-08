#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int>& v,int target){
    int low=0;
    int high=v.size()-1;
    int ans=v.size();

    while (low<=high)
    {
        long long mid=(low+high)/2;
        /*if(low>high) return ans;
        if(target>v[mid]){
            low=mid+1;
        }
        else{
            ans=mid;
            high=mid-1;
        }*/

        //More optimised code

        if(v[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }

    return ans;
}

int upper_bound(vector<int>& v,int target){
    int low=0;
    int high=v.size()-1;
    int ans=v.size();

    while (low<=high)
    {
        long long mid=(low+high)/2;

        if(v[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }

    return ans;
}

int main(){
    vector<int> v={6,6 ,7, 12, 16, 18, 19, 22, 23, 30};
    cout<<v[lower_bound(v,14)]<<endl;
    cout<<v[upper_bound(v,14)]<<endl;
}