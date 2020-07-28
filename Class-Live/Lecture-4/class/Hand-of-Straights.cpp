#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.
bool isNStraightHand(vector<int>& arr, int w){
    int n=arr.size();
    if(n%w) return false;
    if(w==1) return true;

    // sort the given arr
    sort(arr.begin(), arr.end());

    // run till arr become empty
    while(!arr.empty()){
        // now we take a counter and incremt it when we get consecutive elemnt
        // to do this w run a loop till ct<w
        // when ct == w means we got w conscutive elemnt and then we remove w elemet (pop_back())
        int ct=1;
        int pos = arr.size()-1;
        int target = arr[pos]-1;
        pos--;

        // so take last elemnt, set target less than 1 to this val, and dec pos
        while(ct < w){
            // we check this cond to check wether pos not go out of beyond
            // this may be occur when we try to find target we cant, then pos dec
            if(pos<0) return false;
            // if we have same element (== target+1), then we just dec pos to find just target
            if(arr[pos] == target+1) pos--;
            //
            else if(arr[pos] == target){
                int temp = arr[pos];
                // run this loop when we have more than 1 elemt equal to target+1
                // so just move target to just arr.size()-ct-1 this pos
                for(int i=pos; i<arr.size()-ct-1; i++){
                    arr[i] =arr[i+1];
                }
                arr[arr.size()-ct-1] = temp;
                ct++;
                target--;
                pos--;
            }
            // this occur when we neither got taget+1 nor target, so i.e no consuctive so return false
            else return false;
        }

        for(int i=0; i<w; i++){
            arr.pop_back();
        }
    }
    return true;
}

int main(){
    int n, w;
    cin>>n>>w;
    vector<int> arr(n);
    ip(arr, n);
    if(isNStraightHand(arr, w)) cout<<"true\n";
    else cout<<"false\n";
    return 0;
}