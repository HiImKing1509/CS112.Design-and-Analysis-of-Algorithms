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

vector<ll>res;
vector<ll>resCheck;
ll maxJob = LLONG_MAX;

void backtracking(vector<ll>&jobs, vector<ll>&machines, ll job)
{
        for (ll machine = 0; machine < machines.size(); machine++)
        {
                resCheck[job] = machine;

                machines[machine] += jobs[job];

                if (job + 1 < jobs.size()) backtracking(jobs, machines, job + 1);
                else
                {
                        ll maxValue = LLONG_MIN;
                        for (ll i = 0; i < machines.size(); i++)
                                if (machines[i] > maxValue)
                                        maxValue = machines[i];
                        if (maxValue < maxJob)
                        {
                                res = resCheck;
                                maxJob = maxValue;
                        }
                }

                machines[machine] -= jobs[job];
        }
}

void SolveProblem()
{
        ll n, m; cin >> n >> m;
        vector<ll>a(n);
        vector<ll>machine(m);

        for (ll i = 0; i < n; i++) cin >> a[i];

        resCheck.resize(n);

        backtracking(a, machine, 0);

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
