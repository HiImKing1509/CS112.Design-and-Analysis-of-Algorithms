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

ll divideAndConquer(vector<ll>& a, ll k, ll l, ll r)
{
        ll pivot = a[r];
        ll res = l;

        for (ll i = l; i < r; i++)
                if (a[i] <= pivot)
                        swap(a[res++], a[i]);

        swap(a[res], a[r]);

        if (res > k)
                return divideAndConquer(a, k, l, res - 1);
        else if (res < k)
                return divideAndConquer(a, k, res + 1, r);
        else
                return a[res];
}

void SolveProblem()
{
        ll n, k; cin >> n >> k;
        vector<ll>a(n);
        for (auto& i : a) cin >> i;

        cout << divideAndConquer(a, n - k, 0, n - 1);
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
