#include<iostream>
#include<vector>
#include<cstring>
#include<iomanip>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 305

double dp[MAX][MAX][MAX];
int n,one,two,three;

/*
Logic:
First : what really matters is the number of dishes with 0, 1, 2 and 3 sushis and not the order of the dishes.
So answer for 2,1,0,2,1 is same as answer for 0,1,1,2,2.

Number of dishes with 0 sushis is easily determined by N - one - two - three, where one is the number of dishes with 1 sushi and N is the total number of dishes in the input.

Let F(x, y, z) be the expected moves needed for x dishes with 1 sushi, y with 2 and z with 3.

Now in the next move we can pick a dish with 1 sushi with a probability of x/N or p1. we can pick a dish with 2 sushi with a probability of y/N or p2. we can pick a dish with 3 sushi with a probability of z/N or p3. we can pick a dish with 0 sushi with a probability of (N - (x + y + z))/N or p0.

Now try to understand this :
F(x,y,z) = 1 + p0F(x,y,z) + p1F(x-1,y,z) + p2F(x+1,y-1,z) + p3F(x,y+1,z-1)

Here we add a 1 for the current move that we are making.
(Note : if you pick a dish with 3 sushi z decreases but y increases)

p1 -> one/(one+two+three)
p2 -> two/(one+two+three)
p3 -> three/(one+two+three)

p0 -> n-(one+two+three)/(one+two+three)

as we see all val have denominator (one+two+three), except 1(plus one)

F = ((one+two+three) + (n-(one+two+three)) + one*F + two*F + three*F)/(one+two+three)

F = (n + one*F + two*F + three*F)/(one+two+three)
*/

double solve(int one, int two, int three){
    if(one+two+three == 0 || one<0 || two<0 || three<0) return 0.0;

    if(dp[one][two][three] > -1) return dp[one][two][three];

    ll sum = one+two+three;
    double ans = n + (one*solve(one-1, two, three)) + (two*solve(one+1, two-1, three)) + (three*solve(one, two+1, three-1));

    return dp[one][two][three] = (double)ans/sum;
}

void topDown(){
    memset(dp, -1, sizeof(dp));
    cout<<fixed<<setprecision(14)<<solve(one, two, three)<<endl;
}

// void bottomUp(){
//     memset(dp, 0, sizeof(dp));

//     for(int k=0; k<=n; k++){
//         for(int j=0; j<=n; j++){
//             for(int i=0; i<=n; i++){
//                 int l = i + j + k;
//                 if(l>n) continue;
//                 dp[i][j][k] = (l==0) ? 0 : 1.0 * n / l;
//                 if(i>0) dp[i][j][k] += dp[i-1][j][k] * i / l;
//                 if(j>0) dp[i][j][k] += dp[i+1][j-1][k] * j / l;
//                 if(k>0) dp[i][j][k] += dp[i][j+1][k-1] * k / l;
//                 // cout << i << " " << j << " " << k << " "  << dp[i][j][k] << endl;
//             }
//         }
//     }
//     cout<<fixed<<setprecision(15)<<dp[one][two][three]<<endl;
// }

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x==1)one++;
        else if(x==2)two++;
        else three++;
    }
    topDown();
    return 0;
}