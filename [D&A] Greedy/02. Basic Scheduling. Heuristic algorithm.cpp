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
    vector<pll>a(n);
    vector<pll>machine(m);
    pq<pll, vector<pll>, greater<pll>>autoSort;

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    for (ll i = 0; i < m; i++)
    {
        machine[i] = make_pair(0, i);
        autoSort.push(machine[i]);
    }

    sortD(a);
    vector<ll>res(n);
    ll j = -1;
    for (ll i = 0; i < n; i++)
    {
        machine[autoSort.top().second].first += a[i].first;
        j = autoSort.top().second;
        res[a[i].second] = machine[autoSort.top().second].second;
        autoSort.pop();
        autoSort.push(machine[j]);
    }

    for (ll i = 0; i < n; i++)
        cout << res[i] << " ";

    /*for (ll i = autoSort.size(); i > 0; i--)
    {
        cout << autoSort.top().first << " " << autoSort.top().second << "\n";
        autoSort.pop();
    }*/
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
