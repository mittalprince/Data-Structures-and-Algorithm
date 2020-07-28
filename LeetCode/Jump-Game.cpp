#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// logoc here  we use greedy approach
// we assume if we recch at last stairs, 
// so task it to check whther we can reach at this stair form any stairs, if we yes we check the same 
// thi cond and continue until we reach at 0 pos
// if at any point we can't reach at given statir we return false;

bool canJump(vector<int>& nums) {
    int n=nums.size();
    int lastPos = nums[n-1];
    for(int i=n-1; i>=0; i--){
        if(i+nums[i] >= lastPos){// check whether is there any stair from which if we jump we reach at lastPos
            lastPos = i; // if yes we update lastPos to this i and check again for this i
        }
    }
    return lastPos == 0; // if we are at 0 pos we can reach otherwise not
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    if(canJump(arr)) cout<<"true\n";
    else cout<<"false\n";
    return 0;
}