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
#define psl pair<string, ll>
#define MOD 1e9 + 7

void SolveProblem()
{
        ll n; cin >> n;
        vector<vector<char>>a(n + 1, vector<char>(n + 1, '*'));

        for (ll i = 1; i <= n; i++)
                for (ll j = 1; j <= n; j++)
                        cin >> a[i][j];

        vector<vector<ll>>dp(n + 1, vector<ll>(n + 1));
        if (a[1][1] == '*')
                cout << 0;
        else 
        {
                dp[1][1] = 1;
                for (ll i = 0; i <= n; i++)
                {
                        for (ll j = 0; j <= n; j++)
                        {
                                if (i == 1 && j == 1)
                                        continue;
                                else if (a[i][j] == '*' || i == 0 || j == 0)
                                        dp[i][j] = 0;
                                else
                                        (dp[i][j] += (dp[i - 1][j] + dp[i][j - 1])) %= (ll)MOD;
                        }
                }
                cout << dp[n][n];
        }
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        //_TestCases_
                SolveProblem();
        return 0;
}

// Shortcut key for comment in Visual Studio 2019: Ctrl + K + C
// Shortcut key for uncomment in Visual Studio 2019: Ctrl + K + U
