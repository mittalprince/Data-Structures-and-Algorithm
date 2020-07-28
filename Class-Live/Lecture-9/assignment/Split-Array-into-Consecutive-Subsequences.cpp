#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
For each num in nums, if there exists any sequence that ends with num-1 (i.e. if backs[num-1] is a non-empty priority queue), 
then find such a sequence with the smallest possible size (get the smallest value from the priority queue at backs[num-1]). 
Now, the sequence will be extended by 1 since we will add num to it. 
So pop the smallest value count from the priority queue at backs[num-1], 
and add a new value count+1 to the priority queue at backs[num].

If no sequence was found that ends in num-1 (i.e. backs[num-1] is empty), 
then create a new sequence. In other words, add 1 to the priority queue at backs[num].
*/
bool isPossible(vector<int>& nums) {
    int n=nums.size();
    if(n<3) return false;

    map<int, priority_queue<int, vector<int>, greater<int>>>m;

    int less_than_3_ct=0;

    for(int i: nums){
        if(!m[i-1].empty()){
            int top = m[i-1].top();
            m[i-1].pop();
            m[i].push(top+1);

            if(top+1 == 3)less_than_3_ct--;
        }
        else{
            m[i].push(1);
            less_than_3_ct++;
        }
    }

    return less_than_3_ct==0;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}