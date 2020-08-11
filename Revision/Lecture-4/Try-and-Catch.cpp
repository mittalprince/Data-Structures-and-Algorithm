// https://codeforces.com/contest/195/problem/C
#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string invalid = "Unhandled Exception";
bool validChar(char e){
    if (('a' <= e) && (e <= 'z'))
        return 1;
    if (('A' <= e) && (e <= 'Z'))
        return 1;
    return 0;
}

string removeSpace(string a){
    int i=0, len = a.length();
    string temp="";

    while(i<len && a[i] == ' ') i++;
    while(i<len){
        temp += a[i];
        i++;
    }
    return temp;
}

bool checkType(string a, string b){
    // string b="try";
    int len_a = a.length(), len_b = b.length();
    if(len_a < len_b) return false;

    int i=0, j=0;
    while(i<len_a && a[i] == ' ') i++;
    while(i<len_a && j<len_b){
        if(tolower(a[i]) != b[j]) return false;
        i++;
        j++;
    }

    // return (i==len_a && j == len_b); 
    return (j == len_b);
}

string getCatchMessage(string a){
    string temp="";
    int i=0, len=a.length();

    while(i<len && a[i] != '"') i++;
    i++;
    while(i<len && a[i] != '"'){
        temp += a[i];
        i++;
    }
    return temp;
}

string getThrowStatement(string a){
    string temp="";
    int i=0, len=a.length();

    while(i<len && a[i] != '(') i++;
    i++;
    // while(i<len && !((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'a' && a[i] <= 'z'))) i++;

    // while (i < len && ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'a' && a[i] <= 'z'))){
    //     temp += a[i];
    //     i++;
    // }

    while(i<len && !validChar(a[i])) i++;
    while(i<len && validChar(a[i])){
        temp += a[i];
        i++;
    }
    return temp;
}

int main(){
    int n;
    cin>>n;
    stack<string> stk;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string s;
    bool throw_occur = false;
    string throw_type="";
    int after_throw_try_catch_no = 0;
    for(int i=0; i<n; i++){
        getline(cin, s);
        s = removeSpace(s);
        // cout<<s<<" "<<stk.size()<<" "<<throw_occur<<endl;
        if(!s.length()) continue;

        if(!throw_occur){
            if(checkType(s, "try")){
                stk.push(s);
            }
            else{
                if(checkType(s, "catch")){
                    if(!stk.empty()) stk.pop();
                }
                else{
                    throw_occur=true;
                    throw_type = getThrowStatement(s);
                }
            }
        }
        else{
            if(checkType(s, "try")) after_throw_try_catch_no++;
            else{
                if(!after_throw_try_catch_no){
                    if(!stk.empty()){
                        string catch_type = getThrowStatement(s);
                        if(catch_type == throw_type){
                            string catch_msg = getCatchMessage(s);
                            cout<<catch_msg<<endl;
                            return 0;
                        }
                        stk.pop();
                    }
                }
                else after_throw_try_catch_no--;
            }
        }
    }
    // cout<<"no match"<<endl;
    cout<<invalid<<endl;
    return 0;
}