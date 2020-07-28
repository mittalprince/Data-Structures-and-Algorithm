#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int fact(int val){
    int s=1;
    if(val==1 || val==0)
        return 1;
    else{
        while(val>0){
            s=(s% 1000003)*(val% 1000003);
            val--;
        }
    }
    return s;
}
int findRank(string A) {
    long long int sum=0;
    for(int i=0;i<A.length();i++){
        long long int cnt=0;
        for(int j=i+1;j<A.length();j++){
            if(A[j]<A[i]){
                // cout<<A[i]<<" "<<A[j-1]<<endl;
                cnt++;
            }
        }
        sum=sum+(fact(A.length()-i-1)*cnt)% 1000003;
    }
    return (sum+1)% 1000003;
}

int FindRank(string A){
    int ans = 0;
    int n = A.size();
    int m = n;
    int Mod = 1e6 + 3;
    for (int i = 0; i < A.size(); i++)
    {
        int count = 0;
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[i] > A[j])
                count++;
        }
        ans = ((ans * 1ll * m) % Mod + count) % Mod;
        m--;
    }
    ans++;
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}