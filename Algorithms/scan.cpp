// https://www.geeksforgeeks.org/scan-elevator-disk-scheduling-algorithms/
#include<iostream>
#include<vector>
#include<algorithm>
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

int size = 8;
int disk_size = 200;

void SCAN(int[] arr, int head, string direction){
    int seek_count=0;
    int distance,curr_track;
    vector<int>left, right;
    vector<int>seek_seq;

    if(direction=="left")left.push_back(0);
    if(direction=="right")right.push_back(disk_size-1);

    for(int i=0; i<arr.size(); i++){
        if(arr[i] < head) left.push_back(arr[i]);
        if(arr[i] > head) right.push_back(arr[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int run=2;
    while(run--){
        if(direction=="left"){
            for(int i=left.size()-1; i>=0; i--){
                seek_seq.push_back(left[i]);
                seek_count += abs(head-left[i]);
                head = left[i];
            }
            direction = "right";
        }
        else if(direction=="right"){
            for(in t i=0; i<right.size(); i++){
                seek_seq.push_back(right[i]);
                seek_count += abs(right[i]-head);
                head = right[i];
            }
            direction = "left";
        }
    }
    cout<<"Total seek operation "<<seek_count<<endl;
    cout<<"Seek Seq \n";
    for(int i: seek_seq)cout<<i<<" ";
    cout<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int arr[size] = { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head = 50;
    string direction = "left";

    SCAN(arr, head, direction);

    return 0;
}

bi-weekly =
107815946
111230702
110997146
110997046
bi-weekly-segment = 656694382

48984530
48984530