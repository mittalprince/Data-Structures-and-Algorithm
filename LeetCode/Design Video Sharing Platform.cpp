// https://leetcode.com/problems/design-video-sharing-platform/
#include<iostream>
#include<vector>
#include<queue>
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

class VideoSharingPlatform {
private:
    priority_queue<int, vector<int>, greater<int>>pq;
    unordered_map<int, string> contents;
    unordered_map<int, int> views, likes, dislikes;
public:
    VideoSharingPlatform() {
        pq.push(0);
    }
    
    int upload(string video) {
        int id = pq.top();
        pq.pop();
        if(pq.empty()){
            pq.push(id+1);
        }
        contents[id] = video;
        views[id]=0;
        likes[id]=0;
        dislikes[id]=0;
        return id;
    }
    
    void remove(int videoId) {
        if(contents.find(videoId) != contents.end()){
            contents.erase(videoId);
            views.erase(videoId);
            likes.erase(videoId);
            dislikes.erase(videoId);
            pq.push(videoId);
        }
    }
    
    string watch(int videoId, int startMinute, int endMinute) {
        if(contents.find(videoId) != contents.end()){
            string content = contents[videoId];
            int len = content.length();
            if (startMinute >= len) return "-1";
            views[videoId]++;
            endMinute = min(endMinute, len-1);
            return content.substr(startMinute, endMinute-startMinute+1);
        }
        return "-1";
    }
    
    void like(int videoId) {
        if(likes.count(videoId)){
            likes[videoId]++;
        }
    }
    
    void dislike(int videoId) {
        if(dislikes.count(videoId))dislikes[videoId]++;
    }
    
    vector<int> getLikesAndDislikes(int videoId) {
        if(likes.count(videoId)){
            return {likes[videoId], dislikes[videoId]};
        }
        return {-1};
    }
    
    int getViews(int videoId) {
        if(views.count(videoId)){
            return views[videoId];
        }
        return -1;
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