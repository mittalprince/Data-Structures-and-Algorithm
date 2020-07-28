#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class workers{
    public:
    int quality, wage;
    double ratio;

    workers(){}
    workers(int q, int w){
        quality = q;
        wage = w;
        ratio = (double)wage/quality;
    }
};

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n=quality.size();
    workers arr[n];

    for(int i=0; i<n; i++){
        arr[i] = workers(quality[i], wage[i]);
    }

    sort(arr, arr+n, [=](workers a, workers b){
        return a.ratio<b.ratio;
    });

    priority_queue<int>pq;
    int sum=0;
    double ans = 10000000001;

    for(int i=0; i<n; i++){
        sum += arr[i].quality;
        pq.push(arr[i].quality);

        if(pq.size() > k){
            sum -= pq.top();
            pq.pop();
            ans = min(ans, sum*arr[i].ratio);
        }
        else if(pq.size() == k){
            ans = min(ans, sum * arr[i].ratio);
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}