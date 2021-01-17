#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n)              \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define op(arr, n)              \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";
#define fstIO                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int findLargestArea(vector<int> &arr)
{
    stack<int> s;
    int area = 0, i = 0;
    int n = arr.size();

    for (i = 0; i < n;)
    {
        if (!s.empty() and arr[i] <= arr[s.top()])
        {
            int ht = arr[s.top()];
            s.pop();
            if (s.empty())
            {
                area = max(area, ht * i);
            }
            else
            {
                area = max(area, ht * (i - s.top() - 1));
            }
        }
        else
            s.push(i++);
    }

    while (!s.empty())
    {
        int ht = arr[s.top()];
        s.pop();
        if (s.empty())
        {
            area = max(area, ht * i);
        }
        else
        {
            area = max(area, ht * (i - s.top() - 1));
        }
    }
    return area;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max_area = 0;
    int n = matrix.size();

    int m = n ? matrix[0].size() : 0;

    if (!n or !m)
        return 0;

    int ct = 0;
    vector<int> arr(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                arr[j]++;
            }
            else
                arr[j] = 0;
        }
        max_area = max(max_area, findLargestArea(arr));
    }

    return max_area;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    return 0;
}