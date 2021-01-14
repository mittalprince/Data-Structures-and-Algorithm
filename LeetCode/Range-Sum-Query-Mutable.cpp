//https://leetcode.com/problems/range-sum-query-mutable/
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define ip(arr, n)              \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define ip1(arr, n)              \
    for (int i = 1; i <= n; i++) \
        cin >> arr[i];
#define op(arr, n)              \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";
#define fstIO                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define debug(x) cout << x << "\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

class NumArray
{
    vector<int> BIT;
    vector<int> numbers;
    int n;

public:
    NumArray(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        n = nums.size();
        numbers = nums;
        BIT = vector<int>(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            init(i, nums[i]);
        }
    }

    void init(int i, int val)
    {
        int index = i + 1;
        while (index <= n)
        {
            BIT[index] += val;
            index += index & (-index);
        }
    }

    void update(int i, int val)
    {
        init(i, val - numbers[i]);
        numbers[i] = val;
    }

    int getSum(int i)
    {
        int sum = 0;
        int index = i + 1;
        while (index > 0)
        {
            sum += BIT[index];
            index -= index & (-index);
        }
        return sum;
    }

    int sumRange(int left, int right)
    {
        return getSum(right) - getSum(left - 1);
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);

    return 0;
}