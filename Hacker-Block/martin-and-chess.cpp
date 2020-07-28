#include <iostream>
#include <map>
using namespace std;
#define MAX 10
map<pair<int, int>, int> m;

int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int cal(int i, int j, int k)
{
    if (k == 0 && m[make_pair(i, j)] == 0)
    {
        m[make_pair(i, j)] = 1;
        return 1;
    }
    int ans = 0;
    if (k > 0)
    {
        for (int l = 0; l < 8; l++)
        {
            if ((dx[l] + i) >= 0 && (dx[l] + i) <= MAX - 1 && (dy[l] + j) >= 0 && (dy[l] + j) <= MAX - 1)
            {
                ans += cal(dx[l] + i, dy[l] + j, k - 1);
            }
        }
    }
    return ans;
}

int main()
{
    int i, j, k;
    cin >> i >> j >> k;
    cout << cal(i, j, k) << endl;
}