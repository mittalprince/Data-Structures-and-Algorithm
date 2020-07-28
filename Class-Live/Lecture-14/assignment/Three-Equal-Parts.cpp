#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
vector<int> threeEqualParts(vector<int>& A) {
//if there are three equal parts, then the zero/one pattern of the number must be the same for the three number
//first count the total one in the array
//the number of ones for each number is cnt/=3
//to get the exact number, traverse from the rightmost part
//count one to the target number  

    int n=A.size();
    if(n<3) return {-1,-1};

    int one_ct=0;
    for(int i: A){
        if(i==1) one_ct++;
    }
    if(one_ct == 0){
        vector<int>t(2);
        t[0]=0, t[1]=2;
        return t;
    }

    if(one_ct%3 != 0) return {-1, -1};

    int req_one = one_ct/3;
    int r=n-1, pattern_3_one_ct=0;

    // pattern_3
    while(pattern_3_one_ct<req_one){
        if(A[r] == 1){
            pattern_3_one_ct++;
        }
        r--;
    }

    int req_pattern_len =  n-(r+1);
    vector<int>ans(2);

    int l=0;
    while(l<n && A[l] == 0) l++; // remove leading zero

    // pattern_1
    for(int i=0; i<req_pattern_len; i++){
        if(A[l+i] != A[r+1+i]){
            return {-1, -1};
        }
    }

    ans[0] = l+req_pattern_len-1;

    l += req_pattern_len;
    while(l<n && A[l] == 0) l++;

    // pattern_2
    for(int i=0; i<req_pattern_len; i++){
        if(A[l+i] != A[r+1+i]){
            return {-1, -1};
        }
    }

    ans[1] = l+req_pattern_len;
    return ans;
}
*/

vector<int> threeEqualParts(vector<int>& A) {
    int one_ct=0;
    int n=A.size();

    for(int i: A){
        if(i==1) one_ct++;
    }

    if(one_ct == 0){
        return {0,n-1};
    }
    if(one_ct%3 != 0){
        return {-1,-1};
    }

    int req_one = one_ct/3, i, j;

    // remove leading zero
    for(i=0; i<n; i++){
        if(A[i] == 1) break;
    }

    int oneCount=0, start=i; // start-> where the pattern_1 start, after removing leading zero

    for(i=0; i<n; i++){
        if(A[i] == 1) oneCount++;
        // find the req_one+1th 1, as pattern_1 continue untill 1 of pattern_2 occur, which is nothing but req_one+1
        if(oneCount == req_one+1) break;
    }

    int mid=i; // mid-> where the pattern_2 start
    for(j=i+1; j<n; j++){
        if(A[j] == 1) oneCount++;
        // find the 2*req_one+1th 1, as pattern_2 continue untill 1 of pattern_3 occur, which is nothing but 2*req_one+1
        if(oneCount == (2*req_one+1)) break;
    }

    int end=j;

    // here we match the 3 pattern,
    while(end<A.size() && A[start] == A[mid] && A[mid] == A[end]){
        start++;
        mid++;
        end++;
    }

    //If end doesn't reach the end of the array, we find a mismatch and hence, we need to return {-1, -1}
    // why start-1, as we have to give end pos of pattern_1 and start pos of pattern_3
    if(end == n) return {start-1, mid};
    return {-1, -1};
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}