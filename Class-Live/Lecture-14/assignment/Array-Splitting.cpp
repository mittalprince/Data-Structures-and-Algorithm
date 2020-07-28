#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Editorial
arr = [1, -2, -3, 4, -5, 6, -7]
suf = [-6, -7,-5, -2, -6, -1, -7]

1. add suffix[0] into cost.
   * Qki mujhe sare elemnt lena hai and 1 subarr arr[0] se start hogi.
   * Why suffix[0] not arr[0] -> as every elemnt will add into cost at least once( voh baat alg hai
     ki usse f(i) se bhi multiply karna hai, but qki f(i) ki min val 1 hogi toh isse yeh pta chalta hai 
     ki har element ek baar toh cost mein add hoga hi hoga), so add all elemnt sum into cost
   * isse humne yeh mann liya ki hum ek sub arr bna chuka hai 1 to n tak ki and total cost will be
     sum of all elements.

2. * Now we add all suffix[i] into pq except suffix[0] as we must consider it and we have already included
     into cost(matlab hum 0 se ek subarr bna chuka hai)
   * Abb humme (k-1) subarr chahiye.
   * so we will pick subarr whose suffix sum is max
   * now consider -1 pick kiya, abb qki yeh 2 subarr hai toh isse f(i) = 2 se multiply hona chahiye tha
     but agr hum dekhe toh yeh (-1) cost mein 2 bari include ho chuka hai, ek bari suffix[0] se (jab humne
     ek subaar banayi tak and second abb).
   * Now we have build 2 subarr (1 to -5) & (6 to -7).
   * But we need one more, so pick another max from pq
   * -2 pick kiya, qki -2 jo hai voh (4 to -7) tak ke elemnt ka sum hai and (6 to -7) hum consider kar chuka hai
   * So jab hum -2 ko cost mein include karnege toh (4 to -5) ka sum 2 bari cost mein include hoga
     ek bari suffix[0] se and dusari bari abb, But the point to be notrd here is qki humare pass 3 subarr 
     a gayi hai (1 to -3), (4 to -5), (6 to -7) and (6 to -7) ka sum cost mein 3*sum of(6,-7) bari include hona chahiye
     And actually mein yeh 3 ari hi inlude hua hai 
     1. suffix[0]
     2. (4 to -5) ke andar (6 to -7) ka sum include hao
     3. ek bari khud hua (-1 ko jab humne pq se cost mein add kiya tha)
   * so issi tarah se hum jab bhi top of pq ko pick karta hai voh toh uss suffix[i] ke right valio val
     automatically one more time add ho jati hai that is abb voh xth subarr se x+1th subarr ban jati hai.
   * same case for left val of suffix[i]  
*/
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    ip(arr, n);

    ll sufix[n+1];
    sufix[n-1]=arr[n-1];
    priority_queue<ll>pq;
    pq.push(sufix[n-1]);

    for(int i=n-2; i>=0; i--){
        sufix[i] = sufix[i+1]+arr[i];
        if(i>0){
            pq.push(sufix[i]);
        }
    }
    
    ll ans = sufix[0];
    for(int i=0; i<k-1; i++){
        ans += pq.top();
        pq.pop();
    }

    cout<<ans<<endl;
    return 0;
}