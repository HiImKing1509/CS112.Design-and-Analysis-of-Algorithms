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

void SolveProblem()
{
    ll n, m; cin >> n >> m;
    vector<vector<ll>>a(m, vector<ll>(n));
    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<ll>res(n);
    vector<ll>sum(m, 0);
    for (ll i = 0; i < n; i++)
    {
        ll min = LLONG_MAX;
        ll index = -1;
        for (ll j = 0; j < m; j++)
        {
            if (a[j][i] == -1) continue;
            else if (sum[j] + a[j][i] < min)
            {
                min = sum[j] + a[j][i];
                index = j;
            }
        }
        sum[index] += a[index][i];
        res[i] = index;
    }
    for (ll i = 0; i < n; i++) cout << res[i] << " ";
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
