#include<iostream>
#include<vector>
using namespace std;

class MountainArray {
    public:
        int get(int index){
            return 0;
        };
        int length(){
            return 0;
        };
 };

int pivot(MountainArray &a, int n){
    int start=0, end=n-1;

    while(start<end){
        int mid = (start+end)>>1;
        if(a.get(mid) < a.get(mid+1)){
            start=mid+1;
        }
        else{
            end = mid;
        }
    }
    return start;
}

int searchInc(MountainArray &a, int start, int end, int target){
    
    while(start<=end){
        int mid = (start+end)>>1;
        int val = a.get(mid);
        if(val == target){
            return mid;
        }
        else if(val < target) start=mid+1;
        else end = mid-1;
    }
    return -1;
}

int searchDesc(MountainArray &a, int start, int end, int target){
    
    while(start<=end){
        int mid = (start+end)>>1;
        int val = a.get(mid);
        if(val == target){
            return mid;
        }
        else if(val > target) start=mid+1;
        else end = mid-1;
    }
    return -1;
}

int findInMountainArray(int target, MountainArray &mountainArr){
    int n=mountainArr.length();
    int peek = pivot(mountainArr, n-1);
    int idx = searchInc(mountainArr, 0, peek, target);
    if(idx == -1){
        idx = searchDesc(mountainArr, peek, n-1, target);
    }
    return idx;
}


int main(){
   
}