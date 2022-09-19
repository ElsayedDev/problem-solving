#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> solve(int N, vector<vector<string>> A, string D, string V)
{
    vector<vector<string>> sol;

    map<string, int> data = {
        {"bank_account_number", 0},
        {"account_holder_first_name", 1},
        {"account_holder_last_name", 2},
        {"registered_mobile_number", 3},
        {"branch_code", 4},
    };

    for (int i = 0; i < N; i++)
    {
        if (A[i][data[D]] == V)
        {
            sol.push_back(A[i]);
        }
    }

    sort(sol.begin(), sol.end());


    return sol;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<vector<string>> A(N, vector<string>(5));
    for (int i_A = 0; i_A < N; i_A++)
    {
        for (int j_A = 0; j_A < 5; j_A++)
        {
            cin >> A[i_A][j_A];
        }
    }
    string D;
    cin >> D;
    string V;
    cin >> V;

    vector<vector<string>> out_;
    out_ = solve(N, A, D, V);
    for (int i_out_ = 0; i_out_ < out_.size(); i_out_++)
    {
        cout << out_[i_out_][0];
        for (int j_out_ = 1; j_out_ < out_[i_out_].size(); j_out_++)
        {
            cout << " " << out_[i_out_][j_out_];
        }
        cout << "\n";
    }
}
