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
#define max_size 1e6

struct building {
    ll left;
    ll right;
    ll height;
};

void SolveProblem()
{
    ll n; cin >> n;
    vector<building>a(n);
    for (auto& i : a)
        cin >> i.left >> i.right >> i.height;

    vector<ll>b(max_size);

    for (auto building_ : a)
        for (ll j = building_.left; j <= building_.right; j++)
            b[j] = max(b[j], building_.height);

    if (b[0]) cout << 0 << " " << b[0] << "\n";

    for (ll i = 1; i < max_size; i++)
    {
        if (b[i] > b[i - 1])
            cout << i << " " << b[i] << "\n";
        if (b[i] < b[i - 1])
            cout << i - 1 << " " << b[i] << "\n";
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
