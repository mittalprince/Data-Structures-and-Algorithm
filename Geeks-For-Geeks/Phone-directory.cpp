// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<map>
// #include<iterator>
// using namespace std;
// typedef long long ll;
// #define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
// #define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
// #define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// class node{
//     public:
//     char val;
//     unordered_map<char, node*>m;
//     bool isEnd;

//     node(char val):val(val),isEnd(false){}
// };

// class trie{
//     node *root;

//     public:
//     trie(){
//         root = new node('\0');
//     }

//     void insert(string s){
//         node *temp = root;
//         for(char i: s){
//             if(temp->m.find(i) == temp->m.end()){
//                 temp->m[i] = new node(i);
//             }
//             temp = temp->m[i];
//         }
//         temp->isEnd=true;
//     }

//     bool search(string s){
//         node *temp=root;
//         string res="";
//         for(char i: s){
//             if(temp->m.find(i) == temp->m.end()){
//                 return false;
//             }
//             res += i;
//             printAllComb(temp, res);
//             temp = temp->m[i];
//         }
//         return true;
//     }
//     void printAllComb(node *root, string res){
//         if(root->m.empty()){
//             cout<<res<<" ";
//             return;
//         }
//         if(root->isEnd){
//             cout<<res<<" ";
//         }
//         string s;
//         unordered_map<char, node *>::iterator it;
//         for(it=root->m.begin(); it != root->m.end(); it++){
//             s = res + root->m[it->first]->val;
//             printAllComb(root->m[it->first], s);
//         }
//     }
// };

// void solve(){
//     int n;
//     cin>>n;
//     trie root;
//     for(int i=0; i<n; i++){
//         string s;
//         cin>>s;
//         root.insert(s);
//     }
//     string s, query="";
//     cin>>s;
//     cout<<s<<endl;
//     for(char i: s){
//         query += i;
//         if(!(root.search(query))){
//             cout<<"0";
//         }
//         cout<<endl;
//     }
// }

// int main(){
//     int t;
//     cin>>t;
//      while(t--){
//          solve();
//     }
//     return 0;
// }