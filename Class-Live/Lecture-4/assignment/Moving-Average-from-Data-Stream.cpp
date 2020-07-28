#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class MovingAverage{
    queue<int> q;
    int n,sum;

    public:
    MovingAverage(int size){
        n=size;
        sum=0;
    }

    double next(int x){
        q.push(x);
        sum += x;
        double ans=0;
        if(q.size()<n){
            return (double)(sum/q.size);
        }
        else{
            sum -= q.front();
            q.pop();
            return (double)(sum/n);
        }
    }
};

int main(){
    int n;
    cin>>n;
    return 0;
}