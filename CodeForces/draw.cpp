#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    int ans = 1;
    pair<int, int> prev = {0, 0};
    for (auto i : arr)
    {
        if (max(prev.first, prev.second) <= min(i.first, i.second))
        {
            ans += min(i.first, i.second) - max(prev.first, prev.second);
            if (prev.first != prev.second)
                ans++;
        }
        prev = i;
    }
    cout << ans << endl;
}