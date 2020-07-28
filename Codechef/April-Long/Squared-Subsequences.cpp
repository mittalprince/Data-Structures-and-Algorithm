// #include<iostream>
// #include<cmath>
// #include<vector>
// using namespace std;
// typedef long long ll;
// #define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
// #define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
// #define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// ll findInvalidComb(ll arr[], ll n){
//     ll invalid_combination = 0;
//     ll start=0, end=0;

//     while((start<n) && (arr[start]%4 != 0) && (arr[start]%4 != 2)) start++;
//     if(start == n) return invalid_combination;

//     if (!(arr[start]%4)){
//         while((start<n) && (arr[start]%4 == 0)) start++;
//         if (start == n) return invalid_combination;
//     }
//     else start=0;

//     for(ll i=start; i<n;){

//         while((i<n) && (arr[i]%4 != 2)){ 
//             i++;
//         }
//         if(i==n){
//             return invalid_combination;
//         }
//         end = i+1;
//         while((end<n) && (arr[end]%4 != 2) && (arr[end]%4 != 0)) end++;

//         end--;
//         // cout<<(i-start+1)*(end-i+1)<<" "<<start<<" "<<end<<" "<<i<<endl;
//         invalid_combination = invalid_combination + ((i - start + 1)*(end - i + 1));
//         end++;
//         if((end<n) && (arr[end]%4 == 0)){
//             ll temp = end;
//             while((temp<n) && (arr[temp]%4 ==0)) temp++;
//             start = temp;
//             end=temp;
//         }
//         else{
//             start = i+1;
//         }
//         i=end;
//     }
//     return invalid_combination;
// }

// int main(){
//     fstIO;
//     int t;
//     cin>>t;
//     while(t--){
//         ll n;
//         cin >> n;
//         ll arr[n];
//         for (ll i = 0; i < n; i++)
//         {   
//             cin >> arr[i];
//             arr[i] = abs(arr[i]);
//             // arr[i] %= 4;
//             // if(!arr[i])arr[i]=4;
//         }
//         ll total_combination = (n * (n + 1)) / 2;    
//         ll invalid_combination = findInvalidComb(arr, n);
//         // cout<<invalid_combination<<endl;
//         cout<<(total_combination - invalid_combination)<<endl;
//     }
//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){

    ll n, temp, ct_two = 0;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {   
        // while taking i/p we store val that indicate whether its divisble by 2, 4 or not
        // divisible by 4 -> 0
        // divisible by 2 -> 2;
        // else 1
        // we also maintain a var that store how many elemt divisble by 2
        cin >> arr[i];
        arr[i] = abs(arr[i]);
        if (arr[i] % 4 == 0)
        {
            arr[i] = 0;
            ct_two++;
        }
        else if (arr[i] % 2 == 0)
        {
            arr[i] = 2;
            ct_two++;
        }
        else
            arr[i] = 1;
    }

    // then we store all pos that is divisible by 2
    vector<ll> pos;
    for (ll i = 0; i < n; i++)
        if (arr[i] % 2 == 0)
            pos.push_back(i);

    // for(int i=0; i<pos.size(); i++) cout<<pos[i]<<" ";
    // cout<<endl;

    ll invalid_ct = 0, j, start, end;
    //run loop for total elemnts divisble by 2
    for (ll i = 0; i < ct_two; i++)
    {   
        // we compute invalid sub arry in this loop
        // so we check only pos that contain 2
        if (arr[pos[i]] == 2) // check whther elemt at this pos divivble by 2 or 4, if contain 2 by 2, 0 -> 4
        {
            j = pos[i]; // store its pos, compute all subarr that contain this subarry (i+1)*(n-i) logib
            if (i - 1 < 0) // if this first element then start will be -1
                start = -1;
            else
                start = pos[i - 1]; // else prev pos where 0/2 occur
            if (i + 1 >= ct_two) // if its last then end will be n
                end = n;
            else
                end = pos[i + 1]; // else next pos where 0/2 occur

            invalid_ct += ((j - start) * (end - j)); // compute all invalid subarr
        }
    }
    ll total_ct = (n * (n + 1)) / 2;
    total_ct -= invalid_ct;
    cout << total_ct << endl;
}

int main(){
    fstIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}