// https://leetcode.com/problems/hand-of-straights/
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

bool isNStraightHand(vector<int>& hand, int W) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=hand.size();
    if(n%W)return false;
    if(W==1)return true;

    sort(hand.begin(), hand.end());

    while(!hand.empty()){
        int ct=1;
        int pos = hand.size()-1;
        int target = hand[pos]-1;
        pos--;

        while(ct<W){
            if(pos<0)return false;

            if(target+1 == hand[pos])pos--;
            else if(target == hand[pos]){
                int item = hand[pos];
                for(int i=pos; i<hand.size()-ct-1; i++){
                    hand[i]=hand[i+1];
                }
                hand[hand.size()-ct-1]=item;
                ct++;
                target--;
                pos--;
            }
            else return false;

        }

        for(int i=0; i<W; i++){
            hand.pop_back();
        }
    }
    return true;
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