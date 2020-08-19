// https://leetcode.com/problems/design-circular-queue/
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

class MyCircularQueue {
public:
    
    vector<int>arr;
    int front, total_element, size;
    
    MyCircularQueue(int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        arr.resize(k);
        front=0;
        total_element=0;
        size = k;
    }
    
    bool enQueue(int value) {
        if(!isFull()){
            arr[(front+total_element)%size]=value;
            total_element++;
            return true;
        }   
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty()){
            front = (front+1)%size;
            total_element--;
            return true;
        }
        return false;
    }
    
    int Front() {
        return isEmpty()?-1:arr[front%size];
    }
    
    int Rear() {
        return isEmpty()?-1:arr[(front+total_element-1)%size];
    }
    
    bool isEmpty() {
        return (total_element==0);
    }
    
    bool isFull() {
        return (total_element == size);
    }
};

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