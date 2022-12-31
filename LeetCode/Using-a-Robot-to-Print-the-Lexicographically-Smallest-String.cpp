// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/
#include<iostream>
#include<vector>
#include<stack>
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

bool hasSmaller(vector<int>&freq, char c){
    int idx = c-'a';
    for(int i=0; i<idx; i++){
        if (freq[i])return true;
    }
    return false;
}
string robotWithString(string s) {
    // https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/discuss/2679080/Java-Greedy-O(n)-Solution
    /*
    The first loop is to record the frequence of every character, the array freq, the second loop is to add every character into a stack, when adding the character into the stack, decreate the frequency of the character by one in the array freq, then the array freq is the frequency of every character in the rest of string. When adding one character from the top of the stack to the result, we check if there is one smaller character in the rest of the string, if there is, keep pushing the character of the rest of the string into the stack, if there is not, then add the top character into the result.
    */
    stack<char>st;
    string ans="";
    vector<int>freq(26, 0);
    for(char c: s){
        freq[c-'a']++;
    }

    for(char c: s){
        st.push(c);
        freq[c-'a']--;
        while(!st.empty()){
            char top = st.top();
            if (hasSmaller(freq,top))break;
            ans += top;
            st.pop();
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
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