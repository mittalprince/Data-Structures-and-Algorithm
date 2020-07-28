#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define DONE (1<<n)-1

int ans=0;
bitset<30> col, rd, ld;

// using Bitset (N^2)
void nQueen(int i, int n){
    if(i==n){
        ans++;
        return;
    }
    for(int j=0; j<n; j++){
        if(!col[j] && !rd[i+j] && !ld[j-i+(n-1)]){
            col[j] = rd[i+j] = ld[j-i+(n-1)] = 1;
            nQueen(i+1, n);
            col[j] = rd[i+j] = ld[j-i+(n-1)] = 1; 
            // backtracking, if I find a sol for this config might be possible 
            // we also have other possible sol wihout this
        }
    }
}

// using bitmasking (N)
void NQueen(int col, int ld, int rd, int n){
    if(col==DONE){
        ans++;
        return;
    }
    // DONE ek bit mak jo batata hai kha kha par queen place kar sakra hai
    // DONE mein jha jha one hai uss col mein queen place ki ja sakti hai

    int remCols = DONE&(~(col|ld|rd)); // bta dega kha kha 1 hai i.e kha kha queen place ho sakti hai
    
    while(remCols){ // yeh loop basically yahi hai ki ek row mein kitni available pos hai jha jha place kar sakta hoo
         int pos = remCols & (-remCols); // gives pos where we find first 1, now we place queen at this pos
         remCols -= pos;// so remove this pos now from remCOl as we have placed queen

        NQueen(col|pos,(ld|pos)<<1, (rd|pos)>>1, n);
    }
}

int main(){
    int n;
    cin>>n;
    NQueen(0, 0, 0, n);
    cout<<ans<<endl;
    return 0;
}