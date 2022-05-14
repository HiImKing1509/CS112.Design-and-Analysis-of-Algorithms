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
#define ll long long

void backtrack_2(vector<pair<char, ll>>& a, ll sum, ll step, vector<char>& ans)
{
    for (ll i = 0; i <= 1; i++)
    {
        ans[step] = a[i].first;
        if (sum + a[i].second < 0 or sum + a[i].second > ans.size() / 2)
            continue;
        if (step < ans.size() - 1)
            backtrack_2(a, sum + a[i].second, step + 1, ans);
        else if (sum + a[i].second == 0)
        {
            for (ll i = 0; i < ans.size(); i++)
                cout << ans[i];
            cout << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // Input
    ll n; cin >> n;
    vector<pair<char, ll>>a;
    a.push_back(make_pair('(', 1));
    a.push_back(make_pair(')', -1));

    // Initialization
    vector<char>ans(2 * n);
    // Solve Problem
    backtrack_2(a, 0, 0, ans);

    return 0;
}
