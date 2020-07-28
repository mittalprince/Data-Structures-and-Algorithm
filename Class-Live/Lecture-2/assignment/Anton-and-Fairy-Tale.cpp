#include<iostream>
using namespace std;
typedef long long ll;
#define MAX 2e9

int main(){
    ll n,m;
    cin>>n>>m;
    if(n<=m){
        //as every day bird eat grain, amd m make barns full
        // but on nth day, n birds eat all grain and at night barn is empty
        cout<<n<<endl;
    }
    else{
        ll s=0, e=MAX;
        n = n-m;
        ll ans=0;
        while(s<=e){
            ll mid = (s+e)/2;
            ll val = (mid*(mid+1))/2;
            if(val >= n){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        cout<<(m+ans)<<endl;
    }
}
/*
At first, let's make the following assumption: 
if a sparrow cannot eat a grain because the barn is empty, the number of grains in the barn becomes negative. 
It's easy to see that the answer doesn't change because of this.

Now, let's observe the number of grains before sparrows come. 
At first, the barn remains full for m + 1 days (because sparrows eat less grains than it's added to the barn). 
Then the number of grains is decreased by one, by two and so on. 
So, on the m + 1 + i-th day there are  n-i(i+1)/2 grains in the barn before sparrows come (remember that for any positive integer x the equality  is always true).

How can we determine if the barn is empty? 
It's reasonable that if there are q grains on the k-th day after grain is brought, then at the end of the k - 1-th day 
there are q - m grains in the barn. So, if on the k - 1-th day the barn becomes empty (q - m ≤ 0), 
then there must be q ≤ m grains on the k-th day after grain is brought.

So, we must find such minimal day m + 1 + k, in which there are m or less grains after grain is brought. 
That is, using the formula above, we must find such minimal k that
n-k(k+1)/2 <= m or n-m <= k(k+1)/2

It can be easily done using binary search. It's not hard to observe that the answer in this case is m + k (if in the m + 1 + k-th day before sparrows come there are less or equal than m grains, 
then in the m + 1 + k - 1 = m + k-th day the barn is empty).
The corner case in this problem is m ≥ n. In this case the barn becomes full every day and it becomes empty only in the n-th day when sparrows eat all the grain.
Also notice that k can be found using a formula, but such solutions could fail by accuracy, because the formula is using the square root function.

Time complexity is nlongn.
*/
