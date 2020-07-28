// https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1
#include<iostream>
#include<vector>
#include<algorithm>
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

class Node{
public:
    int data;
    Node *left, *right;
    Node():data(0),left(NULL),right(NULL){}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class solver
{
private:
    vector<int>ans;
public:
    
    void kthDistNode(Node *root, int k){
        if(root==NULL)return;
        
        if(k==0){
            ans.push_back(root->data);
            return;
        }
        kthDistNode(root->left, k-1);
        kthDistNode(root->right, k-1);
    }
    
    int helper(Node *root, int target, int k){
        if(root==NULL)return -1;
        
        if(root->data == target){
            kthDistNode(root, k);
            return 1;
        }
        
        int left = helper(root->left, target, k);
        if(left != -1){
            if(left == k){
                ans.push_back(root->data);
            }
            else{
                kthDistNode(root->right, k-left-1);
            }
            return left+1;
        }
        int right = helper(root->right, target, k);
        if(right != -1){
            if(right == k){
                ans.push_back(root->data);
            }
            else{
                kthDistNode(root->left, k-right-1);
            }
            return right+1;
        }
    }
    vector <int> KDistanceNodes(Node* root, int target , int k){
        ans.clear();
        helper(root, target, k);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}