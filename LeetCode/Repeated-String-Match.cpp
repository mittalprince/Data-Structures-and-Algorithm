#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int repeatedStringMatchAdhocApproach(string A, string B){
    int i = 1;
    string s(A);
    while (s.size() < B.size())
    {
        s += A;
        i++;
    }
    if (s.find(B) != string::npos)
        return i;
    if ((s + A).find(B) != string::npos)
        return i + 1;
    return -1;
}

int repeatedStringMatchBruteForce(string A, string B) {
    int maxRepeat = (B.size()+A.size()-1)/A.size()+1;
    string repeat;
    while(maxRepeat)
    {
        repeat += A;
        maxRepeat--;
    }
    
    int ans=0;
    for(int i=0; i<repeat.length(); i++){
        if(repeat.substr(i, B.size()) == B){
            return (i+B.size()+A.size()-1)/A.size();
        }
    }
    return -1;
}


// use KMP logic 
// main point is pattern string is B not A
// we need to find the pattern (B) in text (A), and tell what power of A is req 
int repeatedStringMatch(string A, string B){
    int len_a = A.length(), len_b = B.length();
    vector<int> lps(len_b);

    for(int i=1,j=0; i<len_b;){
        if(B[i] == B[j]){
            lps[i++] = ++j;
        }
        else if(j != 0){
            j = lps[j-1];
        }
        else lps[i] = 0;
    }

    // Search pattern 'B' in string 'A' in a circular fashion
    // variable 'i' represents the starting index of pattern 'B' in string 'A'

    for(int i=0, j=0; i<len_a;){
        if(B[j] == A[(i+j)%len_a]){
            j++;
        }
        if(j==len_b){
            if((i+j)%len_a)
                return (i + j) / len_a + 1; // if (i+j) not completely divide then we return (i+j)/len_a and + 1 as some char left
            else return (i+j)/len_a; // if completely divides then just normnal (i+j)/len_a
        }
        else if(i<len_a and B[j]!=A[(i+j)%len_a]){
            if(j!=0){
                i+=(j-lps[j-1]);//updating 'i' here helps to keep pointed to the same position in 'A'
                j=lps[j-1];
            }
            else
                ++i;//even if no match found for the first letter of the pattern increment 'i'
        } 
    }
    return -1;
}
int main(){
    string a,b;
    cin>>a>>b;
    return 0;
}