#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define MAX 100005

/*
We have to find two things:
    1. vertices which are exactly l dist apart from soruce vertex s.
    2. all points on edges which are l dist apart from source verext s.

First thing we can easily do using SSSP bu assuming source vertex as s.
For second thing we use the dist calculated by SSSP func.

now here we work for each which we are given. Now what we have to do is to count the total 
points on each edge that are exactly l dist apart from source s.

Point to be observed:
    1. at each edge there must be atmost 2 points that can be exactly l dist away.
    2. if any vertex of the edge(not both) are already included in the ans  (means theri vertex are already l dist away),
       then it is not necessary that they dont have any point of edge that are l dist away.
    
Now how we cal the no of point on edge.

If given edge is shorted path edge and min(dist[u],dist[v])<l and max(dist[u],dist[v])>l then there must be at most one single point.

Now when max(dist[u], dist[v]<l), then we have two cases,
    1. extra_dist_req_to_min = l-min(dist[u], dist[v])
       extra_dist_req_to_max = l-max(dist[u], dist[v]) 

       if(sum of these two == weight of edge) then it's sure that they both have a point on same point (means they point to same point)
       so add 1 into ans.

       WHy this?. Beacuse the extra dist req to both so that their dist will be exactly equal to l dist away from source, are same
       means they point same jagah, isliye 1 add kiya

    2. if (sum of these two < weight[edge]) then we can have two points that can we exaclty l dist away,
       Understand why. Now if these two point sum is <= weight, means they are not meet at same point and we
       already know are some postive val, so we will have two points.

       extra_dist_req_to_min = l-min(dist[u], dist[v])
       extra_dist_req_to_max = l-max(dist[u], dist[v]) 
       Remember these max and min dist can not be acheive by the same vertex. 


       so if we have 1 and 3 and weight as 5.
       1 from one vertex and 3 from other vertex. so we have point on at 1 and other at 3.so total point will be 2.

Now third case is when a single vertex dist is less than l and other vertex dist if greater then l, then also we have 
a single point from less than vertex.
*/
vector<pair<ll, ll> >adj[MAX];
vector<vector<ll> >edges;
vector<ll>dist(MAX, INT_MAX);
ll n,m,s,l;

ll ans=0;

void BFS(){
    set<pair<ll, ll> >q;
    q.insert({0, s});
    dist[s]=0;

    while(!q.empty()){
        pair<ll, ll>front = *q.begin();
        q.erase(q.begin());

        ll node = front.second;
        ll parent_dist = front.first;

        for(pair<ll, ll> child: adj[node]){
            if(dist[child.first]>parent_dist+child.second){
                set<pair<ll, ll> >::iterator f = q.find({dist[child.first], child.first});
                if(f != q.end()){
                    q.erase(f);
                }
                dist[child.first] = parent_dist + child.second;
                q.insert({dist[child.first], child.first});
            }
        }
    }

    for(ll i=1; i<=n; i++){
        ans += (dist[i]==l);
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m>>s;

    for(ll i=0; i<m; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        adj[u].push_back({v, w});
        adj[v].push_back({u,w});
    }
    
    cin>>l;

    BFS();

    // for(int i=1; i<=n; i++){
    //     cout<<dist[i]<<" ";
    // }
    // cout<<endl;

    // debug(ans);

    for(ll i=0; i<m; i++){
        ll u=edges[i][0];
        ll v=edges[i][1];
        ll w=edges[i][2];

        ll min_dist = min(dist[u], dist[v]);
        ll max_dist = max(dist[u], dist[v]);     

        if(max_dist - min_dist == w){// if this is the shortest path edge
            if(max_dist >l and min_dist<l) ans++;
        }
        else{
            if(max_dist < l){
                ll extra_dist_req_to_min = l-min_dist;
                ll extra_dist_req_to_max = l-max_dist;

                if(extra_dist_req_to_max+extra_dist_req_to_min == w){//means dono ek hi point par point kar rahe hai 
                    ans++;
                }
                if(extra_dist_req_to_min+extra_dist_req_to_max < w){
                    ans += 2;
                }
            }
            else if(min_dist<l && max_dist >= l) ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}