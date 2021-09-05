#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> adj[1000 + 1];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";

int dfs(int start, vector<bool> &visited, int &salary, int &skill, vector<vector<int>> skill_cost)
{
    visited[start] = true;
    salary += skill_cost[start - 1][1];
    skill += skill_cost[start - 1][0];

    for (auto it : adj[start])
    {
        if (!visited[it])
        {
            dfs(it, visited, salary, skill, skill_cost);
        }
    }
}

bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}

int solve(vector<vector<int>> skill_cost, vector<vector<int>> groupings, int B)
{
    // Write your code here
    int N = skill_cost.size();

    for (int i = 0; i < groupings.size(); i++)
    {
        int u = groupings[i][0];
        int v = groupings[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(N + 1, 0);
    vector<vector<int>> t;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            int salary = 0;
            int skill = 0;
            dfs(i, visited, salary, skill, skill_cost);
            t.push_back({skill, salary});
        }
    }

    sort(t.begin(), t.end(), comp);
    long long ans = 0;
    for (int i = 0; i < t.size(); i++)
    {
        int a = t[i][0];
        int b = t[i][1];
        if (b <= B)
        {
            ans += a;
            B -= b;
        }
    }
    return ans;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int col;
    cin >> col;
    vector<vector<int>> skill_cost(N, vector<int>(col));
    for (int i_skill_cost = 0; i_skill_cost < N; i_skill_cost++)
    {
        for (int j_skill_cost = 0; j_skill_cost < col; j_skill_cost++)
        {
            cin >> skill_cost[i_skill_cost][j_skill_cost];
        }
    }
    int Q;
    cin >> Q;
    int col1;
    cin >> col1;
    vector<vector<int>> groupings(Q, vector<int>(col1));
    for (int i_groupings = 0; i_groupings < Q; i_groupings++)
    {
        for (int j_groupings = 0; j_groupings < col1; j_groupings++)
        {
            cin >> groupings[i_groupings][j_groupings];
        }
    }
    int B;
    cin >> B;

    int out_;
    out_ = solve(skill_cost, groupings, B);
    cout << out_;
}
/*
Input: 
8 2
3 47
6 13
4 47
7 39
8 24
7 23
7 35
4 50
3 2
5 7
6 8
5 6
240

Output: 43

*/