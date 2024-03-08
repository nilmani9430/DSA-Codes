#include <bits/stdc++.h>
using namespace std;
inline void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
bool isLetter(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}
bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int main()
{
    debugMode();
    string str;
    cin >> str;
    stack<string> st1;
    stack<char> st2;
    vector<string> vec;
    int n = str.size();
    int cnt = 1;
    string s;
    vector<string> ans;
    string finalOut;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
            continue;
        if (isLetter(str[i]))
        {
            if (vec.size() == 0)
            {
                string s1;
                s1.push_back(str[i]);
                vec.push_back(s1);
            }
            else if (vec.size() == 2)
            {
                string s1;
                s1.push_back(str[i]);
                vec.push_back(s1);
                string temp;
                string tempVar;
                tempVar.push_back('t');
                string tempVarNum = to_string(cnt);
                cnt++;
                for (auto it : tempVarNum)
                {
                    tempVar.push_back(it);
                }
                finalOut = tempVar;
                for (auto it : tempVar)
                {
                    temp.push_back(it);
                }
                temp.push_back('=');
                for (auto it : vec)
                {
                    for (auto it1 : it)
                        temp.push_back(it1);
                }
                vec.clear();
                ans.push_back(temp);
                vec.push_back(tempVar);
                st1.push(tempVar);
            }
        }
        else if (isOperator(str[i]))
        {
            if (vec.size() == 1)
            {
                string s1;
                s1.push_back(str[i]);
                vec.push_back(s1);
            }
        }
    }
    for (auto it : ans)
    {
        cout << it << "\n";
    }
    cout << "Out = " << finalOut << "\n";
    return 0;
}