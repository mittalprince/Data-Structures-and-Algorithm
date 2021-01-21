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
#define MOD 1000003

vector<ll> BIT;
vector<ll> arr;
ll n;

void init(ll i, ll val)
{
	ll index = i + 1;
	while (index <= n)
	{
		BIT[index] = (BIT[index] + val) % MOD;
		index += index & (-index);
	}
}

void update(ll i, ll val)
{
	init(i, val - arr[i]);
	arr[i] = val;
}

ll getSum(ll i)
{
	ll sum = 0;
	ll index = i + 1;
	while (index > 0)
	{
		sum = (sum + BIT[index]) % MOD;
		index -= index & (-index);
	}
	return sum % MOD;
}

ll sumRange(ll left, ll right)
{
	return (getSum(right) - getSum(left - 1) + MOD) % MOD;
}

int main()
{
	cin >> n;
	arr.resize(n);
	ip(arr, n);

	BIT = vector<ll>(n + 1, 0);
	for (ll i = 0; i < n; i++)
	{
		ll t = 0;
		if (arr[i] % 4 == 0)
			t = arr[i];
		else if (arr[i] % 4 == 1)
			t = 1;
		else if (arr[i] % 4 == 2)
			t = arr[i] + 1;
		arr[i] = t;
	}

	for (ll i = 0; i < n; i++)
	{
		init(i, arr[i]);
		op(BIT, n);
		cout << endl;
	}

	ll q;
	cin >> q;
	while (q--)
	{
		ll type, l, r;
		cin >> type >> l >> r;
		if (type == 1)
		{
			ll t = 0;
			if (r % 4 == 0)
				t = r;
			else if (r % 4 == 1)
				t = 1;
			else if (r % 4 == 2)
				t = r + 1;
			update(l, t);
			cout << "-1 ";
		}
		else
		{
			cout << sumRange(l, r) << " ";
		}
	}
	cout << endl;
	return 0;
}