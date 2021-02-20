//https://leetcode.com/problems/roman-to-integer/
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

int romanToInt(string s) {
    int no=0;
    int i=s.length()-1;

    while(i>=0){
        if(s[i] == 'M'){
            if(i-1>=0 && s[i-1] == 'C'){
                no += 900;
                i--;
            }
            else{
                no += 1000;
            }
        }
        else if(s[i] == 'D'){
            if(i-1>=0 && s[i-1] == 'C'){
                no += 400;
                i--;
            }
            else{
                no += 500;
            }
        }
        else if(s[i] == 'C'){
            if(i-1>=0 && s[i-1] == 'X'){
                no += 90;
                i--;
            }
            else{
                no += 100;
            }
        }
        else if(s[i] == 'L'){
            if(i-1>=0 && s[i-1] == 'X'){
                no += 40;
                i--;
            }
            else{
                no += 50;
            }
        }
        else if(s[i] == 'X'){
            if(i-1>=0 && s[i-1] == 'I'){
                no += 9;
                i--;
            }
            else{
                no += 10;
            }
        }
        else if(s[i] == 'V'){
            if(i-1>=0 && s[i-1] == 'I'){
                no += 4;
                i--;
            }
            else{
                no += 5;
            }
        }
        else{
             no += 1;
        }
        i--;
    }

    return no;
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