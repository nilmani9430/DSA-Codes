#include<bits/stdc++.h>
using namespace std;
#define ll long long
int bs(vector<int>& v,int target){
    int low=0;
    int high =v.size()-1;
    while (low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]==target)return mid;

        if(target>v[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    return -1; 
}

int BSrecursive(vector<int>& v,int low,int high,int target){
    if(low>high) return -1;

    ll mid = (low+high)/2;

    if(v[mid]==target) return mid;

    if(target>v[mid]) return BSrecursive(v,mid+1,high,target);
    else return BSrecursive(v,low,mid-1,target);
}

int main(){
    vector<int> v={2,45,70,75};
    cout<<BSrecursive(v,0,4,80);
}