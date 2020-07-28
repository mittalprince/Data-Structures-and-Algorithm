#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 100005
#define N 19

int primes[19] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

void tranpose(int mat[][N], int row, int col){
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i!=j){
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
}

void swapRow(int mat[][N], int row1, int row2, int col){
    for(int i=0; i<col; i++){
        swap(mat[row1][i], mat[row2][i]);
    }
}

void swapCol(int mat[][N], int row, int col1, int col2){
    for(int i=0; i<row; i++){
        swap(mat[i][col1], mat[i][col2]);
    }
}

int findRank(int mat[][N], int row, int col){
    if(row>col){
        tranpose(mat, row, col);
        swap(row, col);
    }

    int swapPos=col-1, i, j, k;
    for(i=0; i<row; i++){
        if(mat[i][i]){ // if curr diagonal element is set 
            for(j=0; j<row; j++){ // make entire [row][col] elemnt to 0, run loop over all rows
                if(j!=i){
                    if(mat[j][i]){ // if this elemnt set
                        double multiplier = (double)mat[j][i]/mat[i][i];
                        for(k=0; k<col; k++){ // make the same operation for entire cols
                            mat[j][k] -= multiplier*mat[i][k];
                        }
                    }
                }
            }
        }
        else{
            bool isSwapped=false;
            for(j=i+1; j<row; j++){// check whether this is [j][i] element that is not 0, if yes then swap rows
                if(mat[j][i]){
                    isSwapped=true;
                    swapRow(mat, i, j, col);
                    break;
                }
            }

            if(!isSwapped){
                if(swapPos>i){
                    swapCol(mat, row, swapPos, i);
                    swapPos--;
                }
                else break;
            }
            i--;
        }
    }
    
    int Rank=0;
    for(int i=0; i<row; i++){
        if(mat[i][i]) Rank++;
    }
    return Rank;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int arr[n];
    ip(arr, n);
    
    int dp[n][19];
    memset(dp, 0, sizeof(dp));
    // vector<vector<int> >dp(n, vector<int>(19, 0));
    for(int i=0; i<n; i++){
        int x = arr[i];
        for(int j=0; j<19; j++){
            int ct=0;
            while(x%primes[j] == 0){
                x /= primes[j];
                ct++;
            }
            dp[i][j] = ct%2;
            if(x<=1) break;
        }
    }

    int rank = findRank(dp, n, 19);
    cout<<((1<<(n-rank))-1)%MOD<<endl;
    return 0;
}