// https://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/
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
    node *left, *right;
    int r,value;

    node(){
        r=-1, value=0;
        left = right = NULL;
    }
};

class trie{
    node *root;

    public:
    trie(){
        root = new node();
    }

    void insert(int val, int r){
        node *temp = root;
        for(int i=31; i>=0; i--){
            int bit = (val>>i)&1;
            if(bit){
                if(temp->right==NULL)temp->right = new node();
                temp = temp->right;
            }
            else{
                if(temp->left==NULL)temp->left = new node();
                temp = temp->left;
            }
        }
        temp->value = val;
        temp->r = r;
    }

    void max_xor_helper(int val, int &max_ans, int &l, int &r, int idx){
        node *temp = root;
        for(int i=31; i>=0; i--){
            int bit = (val>>i)&1;
            if(bit){
                if(temp->left)temp=temp->left;
                else temp=temp->right;
            }
            else{
                if(temp->right)temp=temp->right;
                else temp = temp->left;
            }
        }
        int curr_ans = temp->value^val;
        if(curr_ans>max_ans){
            max_ans = curr_ans;
            l = temp->r+1;
            r=idx;
        }
    }

    void max_xor(vector<int>&arr, int n){
        int max_ans=0, l=0, r=0;
        int val=0;
        insert(0, -1);
        for(int i=0; i<n; i++){
            val ^= arr[i];
            insert(val, i);
            max_xor_helper(val, max_ans, l, r, i);
        }

        cout<<"Max xor subarr will be "<<max_ans<<endl;
        for(int i=l; i<=r; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
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
    ip(arr, n);

    trie t;
    t.max_xor(arr, n);
    return 0;
}