#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    map<int, vector<int> >reservedSeats_track;

    for(int i=0; i<reservedSeats.size(); i++){
        reservedSeats_track[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
    }

    int ans=0;
    int row=0;

    for(auto it: reservedSeats_track){
        row++;
        vector<int>vec = it.second;
        sort(vec.begin(), vec.end());

        for(int i=2; i<=6;){
            auto lb = lower_bound(vec.begin(), vec.end(), i);
            if(lb == vec.end() || *lb-i >= 4){
                ans++;
                i += 4;
            }
            else i+= 2;
        }
    }
    ans += (n-row)*2;
    return ans;
}

// optmized Approach using Bit mask
int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, int>m;
    for(auto &seat : reservedSeats){
        m[seat[0]] += (1<<seat[1]);
    }

    int ans=0, rows=0;
    for(auto it: m){
        rows++;
        int reserved_mask = it.second;
        int ct=0;
        if((reserved_mask & 60) == 0) ct++;
        if((reserved_mask & 960) == 0) ct++;
        if((reserved_mask & 240) == 0 && ct == 0) ct++;
        ans += ct;
    }

    ans += (n-rows)*2;
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}