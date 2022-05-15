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

#define _TestCases_ ll tcs; cin >> tcs; while (tcs--)
#define db double
#define ld long double
#define ll long long
#define i64 __int64 // == ll
#define ull unsigned long long
#define ui64 unsigned __int64 // == unsigned ll
#define pq priority_queue
#define sortU(v) sort(v.begin(), v.end())
#define sortD(v) sort(v.rbegin(), v.rend())
#define pll pair<ll, ll>

string eraseDemo(string str, ll index)
{
    // Deletes character at position index
    str.erase(str.begin() + index);
    return str;
}
void SolveProblem()
{
    string str; cin >> str;
    ll n; cin >> n;
    bool flag = false;

    if (n > str.size()) cout << "error";
    else if (n == str.size()) cout << 0;
    else
    {
        for (ll i = 0; i < n; i++)
        {
            flag = false;
            for (ll j = 0; j < str.size() - 1; j++)
            {
                if (str[j] > str[j + 1])
                {
                    flag = true;
                    str = eraseDemo(str, j);
                    break;
                }
            }
            if (!flag) str = eraseDemo(str, str.size() - 1);
        }
        cout << stoi(str);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    SolveProblem();

    return 0;
}

// Shortcut key for comment in Visual Studio 2019: Ctrl + K + C
// Shortcut key for uncomment in Visual Studio 2019: Ctrl + K + U
