// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
#include<iostream>
#include<vector>
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

class node{
    public:
    int val;
    node *left, *right;

    node():val(0),left(NULL),right(NULL){}
};

class trie{
    node *root;

    public:
    trie(){
        root = new node();
    }

    int insert(int val){
        node *temp = root;
        node *temp_xor = root;
        int curr = 0;

        for(int i=31; i>=0; i--){
            int v = ((val>>i)&1);
            if(!v){
                if(!temp->left){
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else{
                if(!temp->right){
                    temp->right = new node();
                }
                temp = temp->right;
            }

            if(v){
                if(temp_xor->left){
                    curr += (1<<i);
                    temp_xor = temp_xor->left;
                }
                else{
                    temp_xor = temp_xor->right;
                }
            }
            else{
                if(temp_xor->right){
                    curr += (1<<i);
                    temp_xor = temp_xor->right;
                }
                else{
                    temp_xor = temp_xor->left;
                }
            }
        }
        temp->val = val;
        return curr;
    }  
};

int findMaximumXOR(vector<int>& nums) {
    trie root;
    int ans=0;
    for(int i: nums){
        ans = max(ans, root.insert(i));
    }

    return ans;
}

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