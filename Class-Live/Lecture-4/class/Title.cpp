#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// we must have exactly k first letter in ouput
void solve(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    int i=0, j=s.length()-1;
    bool map[30]={0};
    while(i<j){
        if(s[i] == '?' && s[j]=='?'){
            i++;
            j--;
        }
        else if (s[i] != '?' && s[j] == '?'){
            s[j]=s[i];
            map[s[i]-'a'+1]=true;
            i++;
            j--;
        }
        else if (s[i] == '?' && s[j] != '?'){
            s[i]=s[j];
            map[s[i]-'a'+1]=true;
            i++;
            j--;
        }
        else if(s[i] == s[j]){
            map[s[i]-'a'+1]=true;
            i++;
            j--;
        }
        else{
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }

    if(i==j && s[i] != '?'){
        map[s[i]-'a'+1] = true;
    }

    // now we have string in which we have only ? at (i, len-i) pos
    // as in upper loop we already handlw when we have one "?" conditon

    // now we move outward and place the kth letter at ? and decremnt k so that in final we have lexographical smallest
    // one point if we have already first k letter in s, then we normaly assign a for ?
    while(i>=0){
        // decr k until we find first less than equal to  k char, that is not present in string
        // why first less than equal to  k -> as we can have exactly gitst k letters
        while(k>1 && map[k]) k--;
        
        // now assign 'a'+k-1 to ? and make this pos true in map
        if(s[i]==s[j] && s[i] == '?'){
            s[i]=s[j] = 'a'+k-1;
            map[k] = true;
        }
        i--;
        j++;
    }
    // check whether we have exactly k first letter or not
    if(k==1 && map[k]){
        cout<<s<<endl;
    }
    else cout<<"IMPOSSIBLE\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}