// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int amountOfTime(TreeNode* root, int start) {
    unordered_map<int, unordered_set<int>> map;
    convert(root, 0, map);
    queue<int> q;
    q.push(start);
    int minute = 0;
    unordered_set<int> visited;
    visited.insert(start);

    while (!q.empty()) {
        int levelSize = q.size();
        while (levelSize > 0) {
            int current = q.front();
            q.pop();

            for (int num : map[current]) {
                if (visited.find(num) == visited.end()) {
                    visited.insert(num);
                    q.push(num);
                }
            }
            levelSize--;
        }
        minute++;
    }
    return minute - 1;
}

void convert(TreeNode* current, int parent, unordered_map<int, unordered_set<int>>& map) {
    if (current == nullptr) {
        return;
    } 
    if (map.find(current->val) == map.end()) {
        map[current->val] = unordered_set<int>();
    }
    unordered_set<int>& adjacentList = map[current->val];
    if (parent != 0) {
        adjacentList.insert(parent);
    } 
    if (current->left != nullptr) {
        adjacentList.insert(current->left->val);
    } 
    if (current->right != nullptr) {
        adjacentList.insert(current->right->val);
    }
    convert(current->left, current->val, map);
    convert(current->right, current->val, map);
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