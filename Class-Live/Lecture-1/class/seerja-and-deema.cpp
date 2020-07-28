#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int opt1=0, opt2=0;
    bool flag=true;
    int s=0, e=n-1;
    while(s<=e){
        if(flag){
            if(arr[s]>=arr[e]){
                opt1 += arr[s];
                s++;
            }
            else{
                opt1 += arr[e];
                e--;
            }
            flag = false;
        }
        else{
            if(arr[s]>=arr[e]){
                opt2 += arr[s];
                s++;
            }
            else{
                opt2 += arr[e];
                e--;
            }
            flag = true;
        }
    }
    cout<<opt1<<" "<<opt2<<endl;
    return 0;
}