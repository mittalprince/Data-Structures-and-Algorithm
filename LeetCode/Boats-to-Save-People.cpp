//https://leetcode.com/problems/boats-to-save-people/
#include <iostream>
#include <vector>
#include <algorithm>
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

int numRescueBoats(vector<int> &people, int limit)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    sort(people.rbegin(), people.rend());
    for (i = 0, j = people.size() - 1; i <= j; ++i)
        if (people[i] + people[j] <= limit)
            j--;
    return i;
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