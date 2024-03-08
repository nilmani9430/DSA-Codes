#include<bits/stdc++.h>
using namespace std;
int stringtoint(string s,int start,int end){
    int a=int(s[start]-'0');
    a=a*10;
    int b=int(s[end]-'0');
    return (a+b);
}
bool ispresent(string s,int start,int end,vector<string> &dict){
    string temp="";
    for(int i=start;i<=end;i++){
        temp+=s[i];
    }
    cout<<temp<<endl;
    auto it =lower_bound(dict.begin(),dict.end(),temp);
    if(it==dict.end())
    { 
        return false;
    }
    else return true;
}
string getstr(string s,int start,int end){
    string temp="";
    for(int i=start;i<=end;i++){
        temp+=s[i];
    }
    return temp;
}
int main()
{
    // string s="123";
    // int a=int(s[0]+s[1]);
    // cout<<a-'0'<<endl;
    // cout<<int(s[0]+s[1])-'0';
    // cout<<s[0]+s[1];
    // cout<<stringtoint(s,1,2)-2;
    vector<string> v={"Nil","Mani","raju"};
    auto it=lower_bound(v.begin(),v.end(),"");
    // cout<<it-v.begin();
    if(it!=v.end()){
        cout<<"is present"<<endl;
    }
    // for(auto it=v.begin();it!=v.begin()+2;it++){
    //     cout<<*it<<endl;
    // }
    // auto it=v.begin()+1;
    // cout<<it-v.begin();

    // string s = "leetcode";
    // vector<string> dict = {"leet","code"};
    // sort(dict.begin(),dict.end());
    // cout<<inpresent(s,0,3,dict);
}