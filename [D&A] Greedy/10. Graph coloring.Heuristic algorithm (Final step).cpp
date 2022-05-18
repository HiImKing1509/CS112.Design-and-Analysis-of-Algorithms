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

ll v, e;
vector<vector<ll>> graph;
//vector<bool>visit;
vector<ll>color;

ll findPairBinarySearch(vector<pair<string, ll>>&arr, string str)
{
        ll left = 0;
        ll right = arr.size() - 1;
        while (left <= right)
        {
                ll mid = (left + right) / 2;

                if (arr[mid].first == str)
                        return arr[mid].second;
                else if (arr[mid].first > str)
                        right = mid - 1;
                else
                        left = mid + 1;
        }
        return -1;
}

void greedyColoring()
{
        color[0] = 0;
        vector<bool>check(v, false);

        for (ll i = 1; i < v; i++)
        {
                for (ll j = 0; j < graph[i].size(); j++)
                        if (color[graph[i][j]] != -1)
                                check[color[graph[i][j]]] = true;

                ll cr;
                for (cr = 0; cr < v; cr++)
                        if (!check[cr])
                                break;

                color[i] = cr;
                for (ll j = 0; j < graph[i].size(); j++)
                        if (color[graph[i][j]] != -1)
                                check[color[graph[i][j]]] = false;
        }
}

void SolveProblem()
{
        cin >> v >> e;

        graph.resize(v);
        //visit.resize(v, false);
        color.resize(v, -1);

        vector<pair<string, ll>>vertices(v);

        for (ll i = 0; i < v; i++)
        {
                cin >> vertices[i].first;
                vertices[i].second = i;
        }

        vector<pair<string, ll>>verticesSort = vertices;
        sortU(verticesSort);

        for (ll i = 0; i < e; i++)
        {

                string edge1, edge2;

                cin >> edge1 >> edge2;

                ll pos1 = findPairBinarySearch(verticesSort, edge1);
                ll pos2 = findPairBinarySearch(verticesSort, edge2);

                graph[pos1].push_back(pos2);
                graph[pos2].push_back(pos1);
        }

        greedyColoring();

        for (ll i = 0; i < v; i++) cout << color[i] << " ";
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
