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

bool findPairBinarySearch(vector<pair<string, string>>& arr, string str1, string str2)
{
    ll left = 0;
    ll right = arr.size() - 1;
    while (left <= right)
    {
        ll mid = (left + right) / 2;

        if (arr[mid].first == str1)
        {
            if (arr[mid].second == str2)
                return true;
            else if (arr[mid].second > str2)
                right = mid - 1;
            else
                left = mid + 1;
        }
        else if (arr[mid].first > str1)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

void SolveProblem()
{
    ll n; cin >> n;
    vector<pair<string, string>>a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sortU(a);
    //for (ll i = 0; i < n; i++) cout << a[i].first << " " << a[i].second << "\n";
    bool flag = true;
    for (ll i = 0; i < n; i++)
        if (!findPairBinarySearch(a, a[i].second, a[i].first))
            flag = false;
    if (flag) cout << "TRUE";
    else cout << "FALSE";
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
