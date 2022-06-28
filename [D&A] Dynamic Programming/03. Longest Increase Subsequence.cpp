/*------------------------------------------------------------------------*
|    User: Huynh Viet Tuan Kiet                                           |
|    Degree: Student - Formal University                                  |
|    Study Computer Science at the University of Information Technology   |
|    Country: Viet Nam                                                    |
|    City: Ho Chi Minh                                                    |
|    Organization: VNUHCM - UIT - University of Information Technology    |
*-------------------------------------------------------------------------*/

#include <bits/stdc++.h>
#include <random>

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
    vector<ll>lis(n);
    for (auto& i : lis) cin >> i;

    set<ll> s;
    for (auto a : lis)
    {
        if (s.find(a) != s.end())
            continue;
        s.insert(a);
        auto it = s.upper_bound(a);
        if (it != s.end())
            s.erase(it);
    }
    cout << s.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //_TestCases_
        SolveProblem();

    return 0;
}
