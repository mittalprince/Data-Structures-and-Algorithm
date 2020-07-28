#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class Solution {
public:
    /*
    Points:
    dp[i][j] -> whether pattern match with string or not when we have traverse j len pattern and i len string
    1. star can match any thing, that comes after of it, so all string will be matched with pattern before it, then only it can help.
    2. so in pattern when star come, we check whether all string match till this point, then we can match pattern and string (so make entire row of dp true)
    
    3. if a char in string match with pattern, then the dp[i][j] cell will be true only, when string with len-1 and pattern with len-1 match that when dp[i-1][j-1]=true
    4. if * come in pattern there is 2 chance that 
        1. * se phela ka pattern agr (i-1)th tak ki string se match ho rha hai ya nahi 
        2. * se phela tak ka pattern ith index tak ki string se match ho rha hai ki nahi 
        
        then * can match all string with this * to end(fill entire row with 1), so if * then dp[i][j] = dp[i-1][j-1](excluding ith string char)||dp[i-1][j](including ith string char).
        
    5. if ? come in oattern then we check with pat len-1 and string len-1 tal agr string match ho rahi hai toh dp[i][j] wil be true as ? can replac with any char
        and we change it to string[i], so dp[i][j] depend on dp[i-1][j-1] 
    
    */
    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        
        bool dp[2001][2001]={0};
        dp[0][0]=1; // empty string match with empty pattern
        
        for(int i=1; i<=n; i++){
            if(p[i-1] == '*') dp[i][0] = dp[i-1][0]; // so when string is epmpty, but pattern not
            // when there is * in pat then we check whther we can make equal them or not
        }
        
        for(int i=1; i<=n; i++){
            // for ith char in pattern we fill the entire row
            int j=1;
            
            if(p[i-1] == '*'){
                while(j<=m){
                    if(dp[i-1][j-1] || dp[i-1][j]){
                        while(j<=m) dp[i][j++] = 1; 
                        // point 4, when pattern come and string upto (i-1,j-1)|(i-1,j) match them fill entire row with 1, as now * can match everthing
                    }
                    j++;
                }
            }
            else if(p[i-1] == '?'){
                while(j<=m){
                    dp[i][j] = dp[i-1][j-1];
                    j++;
                }
            }
            else{
                while(j<=m){
                    if(p[i-1] == s[j-1]){
                        dp[i][j] = (true&&dp[i-1][j-1]);
                    }
                    j++;
                }
            }
        }
        
        return dp[n][m];
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}