#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Write a function to generate the generalized abbreviations of a word.

Example: Given word = "word", return the following list (order does not matter):

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2",
"1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/

// using bitamsking
vector<string> generateAbbreviations(string s){
    vector<string>ans;
    int n=s.length();

    for(int i=0; i<(1<<n); i++){
        string t="";
        int ct=0;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                ct++;
            }
            else{
                if(ct){
                    t += to_string(ct);
                    ct=0;
                }
                t += s[j];
            }
        }

        if(ct){
            t += to_string(ct);
        }
        ans.push_back(t);
    }

    return ans;
}

void solve(string s, int i, int ct, string t, vector<string>&ans){
    if(i == s.length()){
        if(ct>0) t += to_string(ct);
        ans.push_back(t);
        return;
    }

    solve(s, i+1, 0, t+((ct>0)?to_string(ct):"")+s[i], ans);
    solve(s, i+1, ct+1, t, ans);
}

// using recursion
vector<string> generateAbbreviations(string s){
    vector<string>ans;
    solve(s, 0, 0, "", ans);
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<string>ans = generateAbbreviations(s);
    for(string i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}