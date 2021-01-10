//https://leetcode.com/problems/create-sorted-array-through-instructions/
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

int arr[100005];
const int mod = 1000000007;

void update(int x)
{
    while (x < 100005)
    {
        arr[x]++;
        x += x & (-x);
    }
}

int get(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += arr[x];
        x -= x & (-x);
    }
    return ans;
}

int createSortedArray(vector<int> &instructions)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    int n = instructions.size();
    for (int i = 0; i < n; i++)
    {
        ans = (ans + min(get(instructions[i] - 1), i - get(instructions[i]))) % mod;
        update(instructions[i]);
    }
    return ans;
}
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