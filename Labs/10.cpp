#include <bits/stdc++.h>
using namespace std;
int main()
{
    // S->aS
    // S->Sb
    // S->ab
    string str;
    cout<<"Enter any string"<<endl;
    cin >> str;
    int fl = 0;
    int cnt1 = 0, cnt2 = 0;
    for (auto it : str)
    {
        if (it == 'a')
        {
            if (cnt2 != 0)
            {
                fl = 1;
                break;
            }
            cnt1++;
        }
        else if (it == 'b')
        {
            if (cnt1 == 0)
            {
                fl = 1;
                break;
            }
            cnt2++;
        }
        else
        {
            fl = 1;
            break;
        }
    }
    if (fl)
    {
        cout << "Given string doesn't satisfy the grammer\n";
    }
    else
    {
        cout << "Given string satisfies the grammer\n";
    }
    return 0;
}
