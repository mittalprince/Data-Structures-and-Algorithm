// https://leetcode.com/problems/lru-cache/
#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

class LRUCache {
public:
    class Node{
        public:
            int key,value;
            Node* prev, *next;

            Node(int  key, int val){
                this->key = key;
                this->value = val;
            }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node*>m;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node *node){
        Node *t = head->next;
        node->next = t;
        node->prev = head;

        t->prev = node;
        head->next = node;
    }

    void deleteNode(Node *node){
        Node *p = node->prev;
        Node *n = node->next;

        p->next = n;
        n->prev = p;
    }

    int get(int key) {
        if(m.find(key) != m.end()){
            Node *c = m[key];
            int ans = c->value;
            m.erase(key);
            deleteNode(c);
            addNode(c);
            m[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node *c = m[key];
            deleteNode(c);
            m.erase(key);
        }
        if(m.size() == capacity){
             m.erase(tail->prev->key);
             deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};
class LRUCache {
public:
    map<int, int>m;
    list<int>l;
    int capacity;
    LRUCache(int capacity) {
        m.clear();
        l.clear();
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        auto it = l.find(l.begin(), l.end(), key);
        if(it != l.end()){
            l.erase(it);
        }   
        l.push_front(key);
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            m[key] = value;
            auto it = l.find(l.begin(), l.end(), key);
            l.erase(it);
            l.push_front(key);
            return;
        }
        if(l.size() < capacity){
            m[key]=value;
            l.push_front(key);
        } else {
            map<int, int>::iterator it = m.find(l.back());
            l.pop_back();
            l.push_front(key);
            m.erase(it);
            m[key]=value;
        }
    }
};

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}