//http://prochal.com/2019/06/the-jungle-book/
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

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int ints[] = {-1, 8, 6, 0, 7, 3, 8, 9, -1, 6, 1};
    int ans = 1;
    int arrLen = 11; //ints.length();
    for (int i = 0; i < arrLen; i++)
    {
        int a = i;
        int counter = 1;
        while (ints[a] > -1 && ints[a] < arrLen && counter < arrLen)
        {
            a = ints[a];
            counter++;
        }

        if (counter > ans)
            ans = counter;
    }
    cout << ans << endl;

    return 0;
}