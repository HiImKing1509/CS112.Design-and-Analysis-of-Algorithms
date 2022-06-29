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
    string str1, str2;
    cin >> str1 >> str2;
    ll n = str1.length();
    ll m = str2.length();

    vector<vector<ll>>a(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            if (i == 0) a[i][j] = j;
            if (j == 0) a[i][j] = i;
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                a[i][j] = a[i - 1][j - 1];
            else
                a[i][j] = 1 + min(a[i][j - 1], min(a[i - 1][j - 1], a[i - 1][j]));
        }
    }
    cout << a[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //_TestCases_
        SolveProblem();

    return 0;
}
