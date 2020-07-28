#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<list>
using namespace std;
typedef unsigned long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

template <typename T>
class graph{
private:
    map<T, list<T>> adj;
    ll n;

public:
    void addEdge(T u, T v, bool bidir = true){
        adj[u].push_back(v);
        if (bidir){
            adj[v].push_back(u);
        }
    }

    int sssp(T src, T des){
        map<T, int> dist;
        map<T, T> parent;

        for (auto it : adj)
        {
            dist[it.first] = INT_MAX;
        }

        queue<T> q;
        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while (!q.empty())
        {
            T front = q.front();
            q.pop();

            for (auto node : adj[front])
            {
                if (dist[node] > dist[front] + 1)
                {
                    dist[node] = dist[front] + 1;
                    parent[node] = front;
                    q.push(node);
                }
            }
        }

        for (auto node : dist)
        {
            cout << "Distance of " << node.first << " from " << src << " is " << node.second << endl;
        }
        T temp = des;

        while (temp != src)
        {
            cout << temp << " <-- ";
            temp = parent[temp];
        }

        return dist[des];
    }
};


int main(){
    fstIO;
    int t;
    cin>>t;
    while(t--){
        
    }
    return 0;
}