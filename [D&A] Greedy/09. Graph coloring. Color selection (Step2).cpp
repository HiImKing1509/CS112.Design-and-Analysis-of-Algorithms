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

void SolveProblem()
{
        ll v, e, n; cin >> v >> e >> n;

        map<string, ll>vertices;
        for (ll i = 0; i < v; i++)
        {
                string vertice; cin >> vertice;
                vertices[vertice] = i;
        }

        vector<vector<bool>>graph(v, vector<bool>(v, false));
        for (ll i = 0; i < e; i++)
        {
                string vertice1, vertice2; cin >> vertice1 >> vertice2;

                graph[vertices[vertice1]][vertices[vertice2]] = true;
                graph[vertices[vertice2]][vertices[vertice1]] = true;
        }

        vector<ll>color(v);
        set<ll>selectedColor;
        for (ll i = 0; i < v; i++)
        {
                cin >> color[i];
                if (color[i] != -1) selectedColor.insert(color[i]);
        }


        for (ll i = 0; i < n; i++)
        {
                set<ll>checkColor;
                bool flag = true;

                string selectedVertice; cin >> selectedVertice;

                for (ll j = 0; j < v; j++)
                        if (graph[vertices[selectedVertice]][j])
                                checkColor.insert(color[j]);

                if (!(color[vertices[selectedVertice]] + 1)) flag = false;
                else
                {
                        for (auto it = checkColor.begin(); it != checkColor.end(); it++)
                                if (*(it) == color[vertices[selectedVertice]])
                                        flag = false;
                }

                if (flag) cout << "TRUE\n";
                else
                {
                        bool continueFlag1 = true;
                        bool continueFlag2 = true;
                        for (auto a = selectedColor.begin(); a != selectedColor.end() && continueFlag1; a++)
                        {
                                bool checkFlag = true;

                                for (auto b = checkColor.begin(); b != checkColor.end(); b++)
                                        if (!(*(a)-*(b)))
                                                checkFlag = false;

                                if (checkFlag)
                                {
                                        cout << *(a) << "\n";
                                        continueFlag1 = false;
                                }
                        }

                        for (ll numColor = 0; numColor < 16777215 && continueFlag1 && continueFlag2; numColor++)
                        {
                                bool checkFlag = true;

                                for (auto it = selectedColor.begin(); it != selectedColor.end(); it++)
                                        if (!(numColor - *(it)))
                                                checkFlag = false;

                                if (checkFlag)
                                {
                                        cout << numColor << "\n";
                                        continueFlag2 = false;
                                }
                        }
                }
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
