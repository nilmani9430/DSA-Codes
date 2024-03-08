#include <bits/stdc++.h>
using namespace std;

bool is_number(const std::string &s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

vector<string> split(const string &s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size())
    {
        string_size j;
        if (s[i] == '"' || s[i + 1] == '"')
        {
            if (s[i] == '"')
                j = i + 1;
            else if (s[i + 1] == '"')
                j += 2;
            while (j != s.size() && s[j] != '"')
                j++;
            j++;
            if (s[i + 1] == '"')
                i++;
        }
        else
        {
            while (i != s.size() && isspace(s[i]))
                ++i;

            j = i;
            while (j != s.size() && !isspace(s[j]))
                j++;
        }
        if (i != j)
        {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

int main()
{
    set<string> keywords = {"int", "float", "main", "for", "if", "else", "while", "cout", "cin", "return", "void", "bool", "string", "char", "else if"};

    set<string> operators = {"+", "-", "*", "/", "=", "==", "++", "--", "<<", ">>"};

    set<string> punc = {",", ";", "(", ")", "{", "}"};

    string s;
    cout<<"While writing the code insert spaces after every token"<<endl;
    cout << "Enter the code and the end of the code put $ sign : " << endl;
    getline(cin, s, '$');

    vector<string> v = split(s);

    vector<vector<string>> ans(5);

    for (auto it : v)
    {
        if (keywords.find(it) != keywords.end())
        {
            ans[0].push_back(it);
        }
        else if (operators.find(it) != operators.end())
        {
            ans[1].push_back(it);
        }
        else if (punc.find(it) != punc.end())
        {
            ans[2].push_back(it);
        }
        else if (is_number(it) || it[0] == '"')
        {
            ans[3].push_back(it);
        }
        else
        {
            ans[4].push_back(it);
        }
    }
    int counter = 0;
    for (auto i : ans)
    {
        if (counter == 0)
            cout << "Keywords : ";
        else if (counter == 1)
            cout << "Operators : ";
        else if (counter == 2)
            cout << "Punctuations : ";
        else if (counter == 3)
            cout << "Constants : ";
        else if (counter == 4)
            cout << "Identifiers : ";

        counter++;
        for (auto it : i)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << "Total number of tokens : " << ans[0].size() + ans[1].size() + ans[2].size() + ans[3].size() + ans[4].size() << endl;
    return 0;
}