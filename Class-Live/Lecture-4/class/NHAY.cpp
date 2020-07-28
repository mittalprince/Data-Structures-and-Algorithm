// KMP Algo -> Pattern Matching
// In naive when we find a mismatch in pattern in string we set j (pattern iterator to start)
// and text itertator to i+1, hence total complexigty will be o(M*N)

// In KMP we use logic of longest prefix which is also suffic
// when pattern[j] != text[i] we dont set i iterator to starting pos,
// while we reset to j 
// In Kmp we build resetTvale which tell where the prefix repetiton occur
// i.e where the prefx become suffix
// so when we find mismatch we dont reset j=0 but, we set j to pos of table[j-1]
// which tell where this pattern occur previously

// resetTable ith index tell where this ith patten occure before 
/*  
    0 1 2 3 4 5 6 7 8 
    A B C D A B C D X

    so let us assume we find first mismatch in pattern and text at pos 8 (X), so
    inspite of reseting j to 0 we set j to pos where just prev of x (D) occur before 
    so it will move to pos 4, iska matalb yeh hai ki D(7) ka pattern A(4) pos tak ke pattern
    se match karta hai 

    now why we not reset j to 0
    qki aise ho sakta hai, jaise D tak sab cheez match hui but x nahi, so hum dekhenhe ki abb
    D tak ka koi pattern prev occur hua ki nahi agr ha toh i ko abb pattern[table[j-1]] se match karna start karenge

*/
//We use the LPS table to decide how many characters are to be skipped for comparison when a mismatch has occurred.
// isme jha pattern mismatch ata hai toh mein check karta hoo ki aise suffix kahi prefix tha agr ha
// toh j ko vha reset kar deta hoo
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 10000000
ll table[MAX];

void buildResetTable(string pattern){
    ll i=1, j=0;
    ll len = pattern.length();
    while(i<len){
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
void solve(string pattern, string text){
    ll lp = pattern.length();
    ll lt = text.length();
    bool flag = (lp>lt), check=false;
    if(!flag){
        buildResetTable(pattern);
        ll i=0, j=0;

        while(i<lt){
            while(j>0 && pattern[j] != text[i]){
                j = table[j-1];
            }
            if(pattern[j] == text[i]){
                i++;
                j++;
            }
            else i++;
            if(j==lp){
                cout<<i-lp<<endl;
                j = table[j-1];
                check=true;
            }
        }
    }
    if(!check) cout<<endl;
}
int main(){
    int n;
    while(cin>>n){
        string pattern, text;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, pattern);
        getline(cin, text);
        solve(pattern, text);
    }
    return 0;
}