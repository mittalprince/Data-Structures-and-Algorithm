#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int c,n;
    while(1){
        cin>>c>>n;
        if(c==0){
            break;
        }
        ll arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(i>0) arr[i] = arr[i]+arr[i-1];
            arr[i] %= c;
        }

        int visited[c];
        for(int i=0; i<c; i++){
            visited[i] = -1;
        }
        visited[0] = 0;

        for(int i=0; i<n; i++){
            if(visited[arr[i]] != -1){
                int val=visited[arr[i]];
                if(arr[i]) val++;
                for(int k=val; k<=i; k++){
                    cout<<k+1<<" ";
                }
                break;
            }
            else{
                visited[arr[i]] = i;
            }
        }
        cout<<endl;
    }
    return 0;
}