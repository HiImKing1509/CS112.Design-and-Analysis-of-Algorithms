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

ll numColor = 16777215;

bool sortBySecond(const pll & a, const pll & b)
{
        return (a.second > b.second);
}

void SolveProblem()
{
        ll v, e; cin >> v >> e;

        map<string, ll>vertices;

        vector<pll>valencyVertice;

        for (ll i = 0; i < v; i++)
        {
                string vertice; cin >> vertice;
                vertices[vertice] = i;

                valencyVertice.push_back(make_pair(i, 0));
        }

        vector<vector<bool>>graph(v, vector<bool>(v, false));
        for (ll i = 0; i < e; i++)
        {
                string vertice1, vertice2; cin >> vertice1 >> vertice2;

                graph[vertices[vertice1]][vertices[vertice2]] = true;
                graph[vertices[vertice2]][vertices[vertice1]] = true;
                
                valencyVertice[vertices[vertice1]].second++;
                valencyVertice[vertices[vertice2]].second++;
        }
        
        sort(valencyVertice.begin(), valencyVertice.end(), sortBySecond);

        vector<ll>checkSelectedColor(v, -1);

        vector<ll>selectedColor = checkSelectedColor;

        for (ll k = 0; k < v; k++)
        {
                checkSelectedColor[valencyVertice.front().first] = k;

                for (ll i = 1; i < v; i++)
                {
                        ll minValencyVertice = valencyVertice[i].first;

                        set<ll>checkColor;

                        for (ll j = 0; j < v; j++)
                                if (graph[minValencyVertice][j] && checkSelectedColor[j] != -1)
                                        checkColor.insert(checkSelectedColor[j]);

                        bool flag = true;
                        for (ll j = 0; j < v && flag; j++)
                        {
                                if (checkColor.find(j) == checkColor.end())
                                {
                                        checkSelectedColor[minValencyVertice] = j;
                                        flag = false;
                                }
                        }
                }

                ll maxColor = LLONG_MIN;
                for (ll i = 0; i < checkSelectedColor.size(); i++)
                        if (checkSelectedColor[i] > maxColor)
                                maxColor = checkSelectedColor[i];

                if (maxColor < numColor)
                {
                        numColor = maxColor;
                        selectedColor = checkSelectedColor;
                }
                checkSelectedColor.resize(v, -1);
        }
        for (ll i = 0; i < selectedColor.size(); i++)
                cout << selectedColor[i] << " ";
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
