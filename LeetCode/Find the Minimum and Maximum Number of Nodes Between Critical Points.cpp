// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> criticalPoints;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    int position = 0;

    while (curr != nullptr && curr->next != nullptr) {
        if (prev != nullptr && curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {
                criticalPoints.push_back(position);
            }
        }
        prev = curr;
        curr = curr->next;
        position++;
    }

    if (criticalPoints.size() < 2) {
        return {-1, -1};
    }

    int minDistance = INT_MAX;
    int maxDistance = criticalPoints.back() - criticalPoints.front();

    for (int i = 1; i < criticalPoints.size(); i++) {
        minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
    }

    return {minDistance, maxDistance};
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}