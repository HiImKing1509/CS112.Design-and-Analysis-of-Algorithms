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

ll findPairBinarySearch(vector<pair<pair<string, string>, ll>>& arr, string str1, string str2)
{
    ll left = 0;
    ll right = arr.size() - 1;
    while (left <= right)
    {
        ll mid = (left + right) / 2;

        if (arr[mid].first.first == str1)
        {
            if (arr[mid].first.second == str2)
                return mid;
            else if (arr[mid].first.second > str2)
                right = mid - 1;
            else
                left = mid + 1;
        }
        else if (arr[mid].first.first > str1)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

void SolveProblem()
{
    ll e, n; cin >> e >> n;
    vector<pair<pair<string, string>, ll>>a(e);
    for (ll i = 0; i < e; i++)
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;

    sortU(a);

    for (ll k = 0; k < n; k++)
    {
        vector<string>b;
        bool flag = true;
        while (flag)
        {
            string s; cin >> s;
            if (s == ".")  flag = false;
            else b.push_back(s);
        }

        ll sum = 0;
        bool flag_check = true;
        for (ll i = 0; i < b.size() - 1 && flag_check; i++)
        {
            ll res = findPairBinarySearch(a, b[i], b[i + 1]);
            if (res != -1)
                sum += a[res].second;
            else
                flag_check = false;
        }
        if (flag_check) cout << sum << "\n";
        else cout << "FALSE\n";
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
