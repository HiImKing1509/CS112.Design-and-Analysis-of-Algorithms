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

bool sortBySecond(const pair<pair<string, ll>, ll> &a, const pair<pair<string, ll>, ll> &b)
{
    return (a.second < b.second);
}

ll stringBinarySearch(vector<pair<pair<string, ll>, ll>>&arr, string s)
{
    ll left = 0;
    ll right = arr.size() - 1;
    while (left <= right)
    {
        ll mid = (left + right) / 2;

        if (arr[mid].first.first == s)
            return mid;
        if (arr[mid].first.first > s)
            right = mid - 1;
        if (arr[mid].first.first < s)
            left = mid + 1;
    }
    return -1;
}

void SolveProblem()
{
    ll v, e; cin >> v >> e;
    vector<pair<pair<string, ll>, ll>>a(v);

    for (ll i = 0; i < v; i++)
    {
        cin >> a[i].first.first;
        a[i].first.second = 0;
        a[i].second = i;
    }

    sortU(a);

    for (ll i = 0; i < e; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        a[stringBinarySearch(a, s1)].first.second++;
        a[stringBinarySearch(a, s2)].first.second++;
    }

    sort(a.begin(), a.end(), sortBySecond);

    for (ll i = 0; i < v; i++)
        cout << a[i].first.second << " ";
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
