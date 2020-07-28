#include<iostream>
#include<vector>
using namespace std;

vector<int> transformArray(vector<int>&arr){
    int n=arr.size();
    vector<int> prev(arr.begin(), arr.end());
    bool flag=false;
    do{
        flag=false;
        for(int i=1; i<n-1; i++){
            if(prev[i] > prev[i-1] && prev[i] > prev[i+1]){
                arr[i]--;
                flag=true;
            }
            else if (prev[i] < prev[i - 1] && prev[i] < prev[i + 1])
            {
                arr[i]++;
                flag=true;
            }
        }
        prev = arr;
    }while(flag);

    return prev;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    arr = transformArray(arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}