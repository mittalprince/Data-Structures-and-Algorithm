// https://leetcode.com/problems/angle-between-hands-of-a-clock/
#include<iostream>
#include<vector>
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

class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

double angleClock(int hour, int minutes) {
    /*
    F min's hand rotates for 360 deg, hr's hand rotates for 30 deg - so for 60 min - hr's hand             rotates for 30 deg. For 1 min it rotates for 0.5 degree
    */

    /*
    For 60min minute hand rotate 360 deg, so for 1 min it rotate 6deg
    */

    /*
    Hour Hand
    The clock is 360deg. Make 4 parts each part is 90deg.
    So every hour our hour hand goes forward 30 deg.
    */

    /*
    We cal the hour angle and minute angle and find abs(diff).
    */
    double hour_angle = (hour%12)*30 + minutes*0.5;
    double minute_angle = minutes*6;

    double ans = min(360-abs(hour_angle-minute_angle), abs(hour_angle-minute_angle));
    return ans;
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