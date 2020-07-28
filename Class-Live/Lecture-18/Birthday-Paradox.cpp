// Birthday Paradox
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

/*
No of people req inside room to have prob of having 2 people bithday on same day is less than 50%
*/

// return min no of people req 
ll solve(double p){
    if(p==1){
        return 366; // 366 people needed for having birthday on same day
        // in 365 days in year, as it sure sure that now out of 366 people 2 people have birthday on same day
    }

    ll people=0;
    double num = 365; // Total days in year
    double deno = 365;

    double ans=1.0; // people logo ka bday same day nahi ata uski prob ans store kar rha hai 
    // now p is ki do logo ka bday same din ata hoo, so 1-p is ki do logo ka bday same din n ata hoo
    // as p is 0.5 so 1-p is 0.5 so we will ans untill ans>= 1-p

    // as ans and 1-p point to same prob but we want people until ans>= 1-p, means we want ans ki val atleat 1-p toh hoo
    while(ans >= 1-p){
        ans *= num/deno;
        num--;
        people++;

        cout<<"Number of people "<<people<<" are required for probability "<<ans<<endl;
    }
    return people;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cout<<solve(0.5)<<endl;
    return 0;
}
