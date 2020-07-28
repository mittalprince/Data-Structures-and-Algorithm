#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MAX 100005
bool comp(int a, int b){
    return a>b;
}

int main(){
    int n;
    cin>>n;
    int arr[MAX]={0},brr[MAX]={0};
    for(int i=0; i<n; i++){
        cin>>arr[i];
    } 
    for(int i=0; i<n; i++){
        cin>>brr[i];
    }
    sort(arr, arr+n, comp);
    sort(brr, brr+n, comp);

    int i=0, j=0;
    bool flag=true;
    ll sum1=0, sum2=0;
    ll ct=0;
    while(ct<(2*n)){
        if(flag){
            if(arr[i]>=brr[j]){
                sum1+=arr[i];
                i++;
            }
            else j++;
        }
        else{
            if(brr[j]>=arr[i]){
                sum2+=brr[j];
                j++;
            }
            else i++;
        }
        ct++;
        flag = !flag;
    }
    cout<<sum1-sum2<<endl;
}