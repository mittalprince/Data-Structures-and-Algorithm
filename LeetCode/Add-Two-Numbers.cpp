//https://leetcode.com/problems/add-two-numbers/
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (l1 == NULL || l2 == NULL)
    {
        return (l1 == NULL) ? l1 : l2;
    }
    int carry = 0, val = 0;
    ListNode *prev = NULL, *temp1 = l1, *temp2 = l2;

    while (temp1 && temp2)
    {
        val = temp1->val + temp2->val + carry;
        temp1->val = val % 10;
        temp2->val = val % 10;
        carry = val / 10;
        prev = temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (carry && (!temp2 && !temp1))
    {
        prev->next = new ListNode(carry);
        return l1;
    }

    if (temp1)
    {
        while (temp1)
        {
            val = temp1->val + carry;
            temp1->val = val % 10;
            carry = val / 10;
            prev = temp1;
            temp1 = temp1->next;
        }
        if (carry)
        {
            prev->next = new ListNode(carry);
        }
        return l1;
    }
    else
    {
        while (temp2)
        {
            val = temp2->val + carry;
            temp2->val = val % 10;
            carry = val / 10;
            prev = temp2;
            temp2 = temp2->next;
        }
        if (carry)
        {
            prev->next = new ListNode(carry);
        }
        return l2;
    }
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