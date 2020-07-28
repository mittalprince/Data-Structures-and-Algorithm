#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n;
    cin>>n;
    int arr[n];
    ll sum=0; // store the sum of whole array
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    if(sum&1){
        // if sum is odd, we can't divide into two equal parts
        // so ans is no
        cout<<"NO\n";
        return 0;
    }
    // now we divide the sum by 2
    // as we can't del array element and juist move them, so the whole arr sum divide into two parts
    // so sum/2 (both parts must have these sum)
    sum = sum/2;
    map<ll, bool>m;
    ll left_sum=0;

    for(int i=0; i<n; i++){
        // now we take one by one element from starting and find their sum
        // and check if left_sum - sum
        // now sum ke andar voh val hai jo left and right arr (after division, their elemt sum) ke baad honi chahiye
        // agr abb koi bhi aise condition milti hai ki (left_sum-sum) ki val left arr mein hai
        // (if diff is pos) iska matlab hai ki left_arr ka sum that is left_sum, sum se greater ho chuka hai
        // toh jitne amt se bda hai and voh amt ka element present hai, toh hum usse right arr mein shift kar sakta hai
        // so sol exist
        // (if diff -ne) same concept
        left_sum += arr[i];
        m[arr[i]]=true;
        if(m[left_sum-sum]){
            cout<<"YES\n";
            return 0;
        }
    }
    m.clear();
    ll right_sum=0;
    for(int i=n-1; i>=0; i--){
        right_sum += arr[i];
        m[arr[i]]=true;
        if(m[right_sum-sum]){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}