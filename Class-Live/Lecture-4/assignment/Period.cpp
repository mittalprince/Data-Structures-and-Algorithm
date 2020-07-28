// longest prefix which can also be sufix for each i (if)
/* 
reference 
Let's assume that prefix function for a prefix with length i is p[i].
If i mod (i - p[i]) == 0 then K = i / (i - p[i]) else K = 1(the idea of the proof is that any period is a multiply of the smallest period and the smallest period is exactly i - p[i]).
So you can use KMP algorithm to compute prefix function for all prefixes of the string and then use the formula above.
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define endl "\n"
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// find the length of longest suffix which is also prefix of the string.
// for period, period is a multiply of the smallest period and the smallest period is exactly i - p[i]

void solve(int t){
    printf("Test case #%d\n", t);
    int n;
    scanf("%d", &n);
    string pattern;
    cin>>pattern;
    vector<int> table(n, 0);
    int j=0;
    for(int i=1;i<n;i++){
        while(j>0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i]=j+1;
            j++;
        }
        else{
            if(j==0) table[i]=0;
        }
		if(!table[i]) continue;
		int len = i + 1 - table[i];
		if((i + 1) % len != 0) continue;
		printf("%d %d\n", i + 1, (i + 1) / len);
    }
    printf("\n");
}

int main(){
    // fstIO;
    int t, tc_n=1;
    scanf("%d", &t);
    while(t--){
        solve(tc_n);
        tc_n++;
    }
    return 0;
}