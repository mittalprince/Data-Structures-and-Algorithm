//https://leetcode.com/problems/find-the-closest-palindrome/description/
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

string nearestPalindromic(string n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(n.length()==1) return to_string(stoi(n)-1); //Special case for single digit numbers

   int digits=n.length();
   vector<long>candidates;
   candidates.push_back(pow(10,digits-1)-1);//Case 1
   candidates.push_back(pow(10,digits)+1);//Case 2

   int mid=(digits+1)/2;
   long prefix=stol(n.substr(0,mid));
   //Case 3
   vector<long>v={prefix,prefix+1,prefix-1};
   for(long i:v)
   {
       string postfix=to_string(i);
       if(digits%2!=0) postfix.pop_back();//// If the total length is odd number, pop the middle number in postfix
       reverse(postfix.begin(),postfix.end());
       string c=to_string(i)+postfix;
       candidates.push_back(stol(c));
   }
   long mindiff=LONG_MAX;long result;long num=stol(n);
   for(int i=0;i<5;i++)
   {
       if(candidates[i]!=num&&abs(candidates[i]-num)<mindiff)//Candidate must not be the same number and abs diff is minm
       {
           mindiff=abs(candidates[i]-num);
           result=candidates[i];
       }
       else if(abs(candidates[i]-num)==mindiff) result=min(result,candidates[i]);
   }
    return to_string(result);
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