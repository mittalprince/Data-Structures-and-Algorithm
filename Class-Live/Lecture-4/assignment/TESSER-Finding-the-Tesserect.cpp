#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 1000005
int table[MAX]={0};

void buildResetTable(string pattern){
    int lp = pattern.length();
    int i=1,j=0;
    while(i<lp){
        while(j>0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = j+1;
            i++;
            j++;
        }
        else{ 
            if(j==0){
                table[i]=0;
                i++;
            }
        }
    }
}

void solve(){
    int n, prev,curr;
    cin>>n;
    string text;
    for(int i=0; i<n; i++){
        cin>>curr;
        if(i>0){
            if(prev == curr){
                text.push_back('E');
            }
            else if(prev<curr){
                text.push_back('G');
            }
            else text.push_back('L');
        }
        prev = curr;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string pattern;
    cin >> pattern;
    // cout<<text<<" "<<pattern<<" "<<text.length()<<" "<<pattern.length()<<endl;
    buildResetTable(pattern);
    int lp = pattern.length();
    int lt = text.length();

    int i=0, j=0;
    bool flag=false;
    while(i<lt){
        while(j>0 && pattern[j] != text[i]){
            j = table[j-1];
        }
        if(pattern[j] == text[i]){
            i++;
            j++;
        }
        else i++;

        if(j == lp){
            flag=true;
            break;
        }
    }
    if(flag){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}