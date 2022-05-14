/*------------------------------------------------------------------------*
|    User: Huynh Viet Tuan Kiet                                           |
|    Degree: Student - Formal University                                  |
|    Study Computer Science at the University of Information Technology   |
|    Country: Viet Nam                                                    |
|    City: Ho Chi Minh                                                    |
|    Organization: VNUHCM - UIT - University of Information Technology    |
*-------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool palindrome(string s, ll left, ll right)
{
    while (left < right)
        if (s[left++] != s[right--])
            return false;
    return true;
}

void backtrack_3(string str, ll numStr, vector<vector<string>>&res, vector<string>& part)
{
    if (numStr >= str.size())
    {
        res.push_back(part);
        return;
    }
    for (ll i = numStr; i < str.size(); i++)
    {
        if (palindrome(str, numStr, i))
        {
            string subRes = "";
            for (ll start = numStr; start <= i; start++)
                subRes += str[start];
            part.push_back(subRes);

            backtrack_3(str, i + 1, res, part);

            part.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    vector<vector<string>>res;
    vector<string>part;

    backtrack_3(s, 0, res, part);

    for (ll i = 0; i < res.size(); i++)
    {
        for (ll j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
