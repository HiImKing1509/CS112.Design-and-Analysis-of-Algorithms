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

vector<string>res;
vector<string>resCheck;
ll countLoop = 0;

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

void minimumWeightHamiltonianCycle(vector<vector<pair<pair<string, string>, ll>>>& graph, ll s, string firstStr)
{
        vector<ll> vertex;
        for (ll i = 0; i < graph.size(); i++)
                if (i != s)
                        vertex.push_back(i);

        ll min_path = LLONG_MAX;
        do {
                ll current_pathweight = 0;

                ll k = s;
                for (ll i = 0; i < vertex.size(); i++)
                {
                        if (graph[k][vertex[i]].second != 0)
                        {
                                current_pathweight += graph[k][vertex[i]].second;
                                resCheck.push_back(graph[k][vertex[i]].first.second);
                                k = vertex[i];
                        }
                }
                if (graph[k][s].second != 0)
                {
                        current_pathweight += graph[k][s].second;
                        resCheck.push_back(graph[k][s].first.second);
                }

                if (current_pathweight < min_path && resCheck.size() - graph.size() == 1)
                {
                        min_path = current_pathweight;
                        res = resCheck;
                }
                resCheck.clear();
                resCheck.push_back(firstStr);
                countLoop++;

        } while (next_permutation(vertex.begin(), vertex.end()) && countLoop <= 1000000);
}

void SolveProblem()
{
        ll n, mapStartPoint; cin >> n;
        string startPoint; cin >> startPoint;
        vector<pair<pair<string, string>, ll>>a(n);

        set<string>alphaBet;

        for (ll i = 0; i < n; i++)
        {
                cin >> a[i].first.first >> a[i].first.second >> a[i].second;
                alphaBet.insert(a[i].first.first);
                alphaBet.insert(a[i].first.second);
        }

        sortU(a);
        vector<psl>b;
        ll i = 0;
        for (auto it = alphaBet.begin(); it != alphaBet.end(); ++it, i++)
        {
                b.push_back(make_pair(*it, i));
                if ((*it) == startPoint) mapStartPoint = i;
        }

        vector<vector<pair<pair<string, string>, ll>>>graph(b.size(), vector<pair<pair<string, string>, ll>>(b.size()));
        for (ll i = 0; i < graph.size(); i++)
        {
                for (ll j = 0; j < graph[0].size(); j++)
                {
                        ll check = findPairBinarySearch(a, b[i].first, b[j].first);
                        if (check != -1)
                                graph[i][j].second = a[check].second;
                        else
                                graph[i][j].second = 0;
                        graph[i][j].first = make_pair(b[i].first, b[j].first);
                }
        }
        resCheck.push_back(startPoint);
        minimumWeightHamiltonianCycle(graph, mapStartPoint, startPoint);
        for (ll i = 0; i < res.size(); i++)
                cout << res[i] << " ";
        cout << "\n" << countLoop;
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
