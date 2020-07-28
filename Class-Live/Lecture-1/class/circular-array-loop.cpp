#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int next(vector<int> &arr, int x){
    return (x+arr[x]+arr.size())%arr.size();
}

bool circularArrayLoop(vector<int> &arr){
    int n=arr.size();

    for(int i=0; i<n; i++){// check at each point
        int slw=i, fst=i;

        while(arr[i]*arr[next(arr, slw)]>0 &&
            arr[i]*arr[next(arr,fst)]> 0 && 
            arr[i]*arr[next(arr, next(arr, fst))] > 0){
                slw = next(arr, slw);
                fst = next(arr, next(arr, fst));

                if(slw == fst){
                    // to check if cycle exist & its length is 1
                    // so we check slw == next(slw), if yes cycle of len 1
                    if(slw == next(arr, slw)){
                        break;
                    }
                    return true;
                }
            }
        // if for particular i we dont get cycle we simply mark all its path as 0, as using this path we can get a cycle
        slw=i;
        int x = arr[slw];
        while(x*arr[slw]>0){
            int y = next(arr, slw);
            arr[slw]=0;
            slw = y;
        }
    }

    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    (circularArrayLoop(arr))?cout<<"true\n":cout<<"false\n";
    return 0;
}