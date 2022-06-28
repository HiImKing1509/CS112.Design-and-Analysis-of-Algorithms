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

ll BinarySearch(vector<ll>& arr, ll xx)
{
    ll left = 0;
    ll right = arr.size() - 1;
    while (left <= right)
    {
        ll mid = (left + right) / 2;

        if (arr[mid] == xx)
            return mid;
        if (arr[mid] > xx)
            right = mid - 1;
        if (arr[mid] < xx)
            left = mid + 1;
    }
    return -1;
}
ll GCD(ll a, ll b)
{
    while (b)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}
ll FirstGreaterElement(vector<ll>& arr, ll xx)
{
    ll len = arr.size() - 1;
    ll st = 0;
    ll ans = -1;
    while (st <= len)
    {
        ll mid = (st + len) / 2;
        if (arr[mid] < xx)
            st = mid + 1;
        else
        {
            ans = mid;
            len = mid - 1;
        }
    }
    return ans;
}
ll LongestCommonSubsequence(vector<vector<ll>>& dp, string s1, string s2)
{
    for (ll i = 0; i <= s2.size(); i++)
    {
        for (ll j = 0; j <= s1.size(); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s2[i - 1] == s1[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[s2.size()][s1.size()];
}

ll fastExp(ll x, ll k)
{
    if (k == 1)
        return x;
    else
    {
        if (!(k % 2))
            return fastExp(x, k / 2) * fastExp(x, k / 2);
        else
            return fastExp(x, k / 2) * fastExp(x, k / 2) * x;
    }
}

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
