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
#define pll pair<ll, ll>

bool backtrack_5(vector<string>& crossword, vector<vector<bool>>& check, vector<pll>& nextPos, string word, ll row, ll col, ll index)
{
    if (crossword[row][col] == word[index] && (index + 1) == word.size())
        return true;
    if (crossword[row][col] != word[index])
        return false;
    for (ll i = 0; i < nextPos.size(); i++)
    {
        if (
            row + nextPos[i].first >= 0
            && row + nextPos[i].first < crossword.size()
            && col + nextPos[i].second >= 0
            && col + nextPos[i].second < crossword[0].size()
            && check[row + nextPos[i].first][col + nextPos[i].second]
            )
        {
            check[row][col] = false;
            if (backtrack_5(crossword, check, nextPos, word, row + nextPos[i].first, col + nextPos[i].second, index + 1))
                return true;
            check[row][col] = true;
        }
    }
    return false;
}

bool solveProblem(vector<string>& crossword, vector<vector<bool>>& check, vector<pll>& nextPos, string word)
{
    for (ll i = 0; i < crossword.size(); i++)
        for (ll j = 0; j < crossword[0].size(); j++)
            if (crossword[i][j] == word[0])
                if (backtrack_5(crossword, check, nextPos, word, i, j, 0))
                    return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // Input string
    string word; cin >> word;
    vector<string>crossWord;

    bool flag = true;
    // Input crossword
    while (flag)
    {
        string str; cin >> str;
        if (str == ".") 
            flag = false;
        else 
            crossWord.push_back(str);
    }

    // Initialize the pair containing the next searchable location
    vector<pll>nextPosition;

    for (ll i = -1; i <= 1; i++)
    {
        for (ll j = -1; j <= 1; j++)
        {
            if (i == 0 and j == 0) 
                continue;
            else
                nextPosition.push_back(make_pair(i, j));
        }
    }

    // Initialize the matrix to check whether the locations have been traversed or not
    ll r = crossWord.size();
    ll c = crossWord[0].size();
    vector<vector<bool>>checkPos(r, vector<bool>(c, true));

    // Solve Problem
    bool accept = solveProblem(crossWord, checkPos, nextPosition, word);
    if (accept) cout << "true";
    else cout << "false";
    return 0;
}
