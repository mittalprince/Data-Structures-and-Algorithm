#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void towerOfHanoi(int n, string src, string dest, string aux){
    if(n==1){
        cout<<"Move 1th disc from "<<src<<" to "<<dest<<endl;
        return;
    }
    towerOfHanoi(n-1, src, aux, dest);
    cout<<"Move "<<n<<"th disc from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1, aux, dest, src);
}

void printString(string src, string dest, int disk){
    cout<<"Move "<<disk<<"th "<<"disk from "<<src<<" to "<<dest<<endl;
}

void moveDisk(stack<int>&src, stack<int>&dest, string s, string d){

    if(src.empty()){
        src.push(dest.top());
        dest.pop();
        printString(d, s, src.top());
    }
    else if(dest.empty()){
        dest.push(src.top());
        src.pop();
        printString(s, d, dest.top());
    }
    else if(src.top() > dest.top()){
        src.push(dest.top());
        dest.pop();
        printString(d, s, src.top());
    }
    else{
        dest.push(src.top());
        src.pop();
        printString(s, d, dest.top());
    }
}

void tohIterative(int n){
    stack<int> src, dest, aux;
    int total_moves = (1<<n)-1;
    string s="T1", d="T2", a="T3";

    if(n%2==0){
        swap(d, a);
    }
    for(int i=n; i>=1; i--){
        src.push(i);
    }

    for(int i=1; i<=total_moves; i++){
        if(i%3 == 1){ // legal movement bt src & dest
            moveDisk(src, dest, s, d);
        }
        else if(i%3 == 2){ // legal movement bt src & aux
            moveDisk(src, aux, s, a);
        }
        else{ // legal movement bt aux & dest
            moveDisk(aux, dest, a, d);
        }
    }

    cout<<total_moves<<endl;
}

void hepler(){
    int n;
    cin>>n;
    tohIterative(n);
}

int main(){
    // int n;
    // cin>>n;
    // towerOfHanoi(n, "T1", "T2", "T3");
    // cout<<((1<<n)-1)<<endl;
    hepler();
    return 0;
}