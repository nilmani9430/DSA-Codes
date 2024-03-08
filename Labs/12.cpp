#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans1 = 0, ans2 = 0, ans3 = 0;
    cout << "Enter a String or Enter '$' to exit \n";
    while (true)
    {
        string str;
        getline(cin, str);
        if (str == "$")
            break;
        ans2++;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
                ans1++;
        }
    }
    cout << "No. of Lines: " << ans2 << "\n";
    cout << "No. of Blank Spaces: " << ans1 << "\n";
    return 0;
}