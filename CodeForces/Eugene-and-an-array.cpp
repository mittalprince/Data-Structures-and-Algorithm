/*
Eugene likes working with arrays. And today he needs your help in solving one challenging task.

An array 𝑐 is a subarray of an array 𝑏 if 𝑐 can be obtained from 𝑏 by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

Let's call a nonempty array good if for every nonempty subarray of this array, sum of the elements of this subarray is nonzero. For example, array [−1,2,−3] is good, as all arrays [−1], [−1,2], [−1,2,−3], [2], [2,−3], [−3] have nonzero sums of elements. However, array [−1,2,−1,−3] isn't good, as his subarray [−1,2,−1] has sum of elements equal to 0.

Help Eugene to calculate the number of nonempty good subarrays of a given array 𝑎.

Input
The first line of the input contains a single integer 𝑛 (1≤𝑛≤2×105)  — the length of array 𝑎.

The second line of the input contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (−109≤𝑎𝑖≤109)  — the elements of 𝑎.

Output
Output a single integer  — the number of good subarrays of 𝑎

3
1 2 -3
5

3
41 -41 41
3
*/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    map<ll, ll> m;
    ll sum = 0, t, start = 0, ans = 0;
    m[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> t;
        sum += t;

        if (m.find(sum) != m.end())
        {
            start = max(start, m[sum] + 1);
        }
        m[sum] = i;
        ans += (i - start);
    }
    cout << ans << endl;
}

// logic is we use prefix sum array, and find the index where the sum becomes equal or zero
// so when sum become 0 or equal we update aur start index of all new sub arry
// here ans += (i-start), in this we add all valid subarray combination as for 
// i=1 it gives 1, for 2 gives 2 and as we sum all these so n*(n+1)/2 

// 1 2 3 4 5  6 7 (indexing)
// 1 1 2 2 1 -3 0
// 1 2 4 6 7 4 4  (prefix sum)
// as in prefix sum 4 appear twice so i.e there are some element present which make sum to 0 after 4
// so we can see 2 1 -3 gives 0, then we update start

//https://codeforces.com/contest/1333/my