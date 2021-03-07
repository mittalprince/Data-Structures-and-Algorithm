//https://leetcode.com/problems/design-hashmap/
#include<iostream>
#include<vector>
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

class MyHashMap
{
    vector<list<pair<int, int>>> m_data;
    size_t m_size = 10000;

public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        m_data.resize(m_size);
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        auto &list = m_data[key % m_size];
        for (auto &val : list)
        {
            if (val.first == key)
            {
                val.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        const auto &list = m_data[key % m_size];
        if (list.empty())
        {
            return -1;
        }
        for (const auto &val : list)
        {
            if (val.first == key)
            {
                return val.second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        auto &list = m_data[key % m_size];
        list.remove_if([key](auto n) { return n.first == key; });
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}