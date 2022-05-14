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
#define ld long double

ld currSum = 0;

void backtrack_1(vector<ld>& coeff, vector<ld>& ans, ll step, ld sumScore)
{
    for (ld score = 0.25; score <= 10; score += 0.25)
    {

        ans[step] = score;

        if (currSum + coeff[step] * ans[step] - 0.1 > sumScore)
            break;
        currSum += (coeff[step] * ans[step]);

        if (step < coeff.size() - 1)
            backtrack_1(coeff, ans, step + 1, sumScore);

        else
            if (roundf(currSum * 10) == sumScore * 10)
            {
                for (ll i = 0; i < ans.size(); i++)
                    cout << ans[i] << " ";
                cout << "\n";
            }

        currSum -= (coeff[step] * ans[step]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // Input
    ll n; cin >> n;
    vector<ld>coefficient(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> coefficient[i];
        coefficient[i] /= 100;
    }
    ld sumScore; cin >> sumScore; 

    // Initialization
    vector<ld>ans(n, 0.0);

    // Solve Problem
    backtrack_1(coefficient, ans, 0, sumScore);

    return 0;
}
