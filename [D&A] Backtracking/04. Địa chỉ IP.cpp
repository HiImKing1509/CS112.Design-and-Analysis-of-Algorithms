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

void backtrack_4(string ans, string str, ll num, ll part, vector<string>& res)
{
    if (part > 3)
    {
        if (num >= str.length())
        {
            ans.pop_back();
            res.push_back(ans);
        }
        return;
    }

    string ip;

    // Backtracking
    for (ll i = num; i < str.length(); i++)
    {
        if (ip == "0") return;
        ip += str[i];
        if (stoi(ip) >= 0 && stoi(ip) <= 255)
        {
            string temp = ans;
            ans += (ip + ".");
            backtrack_4(ans, str, i + 1, part + 1, res);
            ans = temp;
        }
        else return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s, ans; cin >> s;
    vector<string>res;
    backtrack_4(ans, s, 0, 0, res);
    for (ll i = 0; i < res.size(); i++)
        cout << res[i] << "\n";
    return 0;
}
