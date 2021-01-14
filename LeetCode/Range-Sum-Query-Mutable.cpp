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

// Using Segment Tree
class NumArray
{
    class SegmentTreeNode
    {
    public:
        int start, end, sum;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int a, int b) : start(a), end(b), sum(0), left(NULL), right(NULL) {}
    };

    SegmentTreeNode *root;

public:
    NumArray(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        root = buildTree(nums, 0, n - 1);
    }

    void update(int i, int val)
    {
        modifyTree(i, val, root);
    }

    int sumRange(int i, int j)
    {
        return queryTree(i, j, root);
    }
    SegmentTreeNode *buildTree(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return nullptr;
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        if (start == end)
        {
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = buildTree(nums, start, mid);
        root->right = buildTree(nums, mid + 1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    int modifyTree(int i, int val, SegmentTreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int diff;
        if (root->start == i && root->end == i)
        {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start + root->end) / 2;
        if (i > mid)
        {
            diff = modifyTree(i, val, root->right);
        }
        else
        {
            diff = modifyTree(i, val, root->left);
        }
        root->sum = root->sum + diff;
        return diff;
    }
    int queryTree(int i, int j, SegmentTreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->start == i && root->end == j)
            return root->sum;
        int mid = (root->start + root->end) / 2;
        if (i > mid)
            return queryTree(i, j, root->right);
        if (j <= mid)
            return queryTree(i, j, root->left);
        return queryTree(i, mid, root->left) + queryTree(mid + 1, j, root->right);
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