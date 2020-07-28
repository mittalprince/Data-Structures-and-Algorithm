// https://leetcode.com/problems/prison-cells-after-n-days/
#include<iostream>
#include<vector>
#include<bitset>
#include<unordered_map>
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

/*
There are 8 prison cells in a row, and each cell is either occupied or vacant.
Each day, whether the cell is occupied or vacant changes according to the following rules:
If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)
We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.
Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]
*/

vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    unordered_map<bitset<8>, int>m;
    vector<bitset<8> >v;
    bitset<8>b;
    
    for(int i=0; i<cells.size(); i++){
        b[i] = cells[i];
    }
    
    int j=0;
    m[b]=j++;
    v.push_back(b);
    
    while(N--){
        bitset<8>b2;
        b = v.back();
        
        for(int i=1; i<cells.size()-1; i++){
            b2[i] = b[i-1] == b[i+1];
        }
        
        if(m.count(b2)){
            int begin = m[b2];
            int len = j-begin;
            v.push_back(v[begin + N%len]);
            break;
        }
        else{
            m[b2]=j++;
            v.push_back(b2);
        }
    }
    
    vector<int>res;
    b = v.back();
    for(int i=0; i<cells.size(); i++){
        res.push_back(b[i]);
    }
    return res;
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