#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

unordered_map<string, int>m;
int pmask[65];
int dp[100][(1<<16)];
bool choose[100][(1<<16)]={0};
int fmask;

int solve(int i, int cmask, vector<vector<string>>& people){
    if(cmask == fmask) return 0; // no more member req
    if(i == people.size()){
        // when we can't find req skill set and considered all people
        return 5000; // return max val;
    } 

    if(dp[i][cmask] != -1) return dp[i][cmask];

    int person_included = 1+solve(i+1, cmask|pmask[i], people);
    int perosn_not_included = solve(i+1, cmask, people);

    if(person_included < perosn_not_included){
        choose[i][cmask] = true; // chose curr person for curr mask
    }
    else{
        choose[i][cmask]=false;
    }

    return dp[i][cmask] = min(perosn_not_included, person_included);
}

vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {

    for(int i=0; i<req_skills.size(); i++){
        m[req_skills[i]]=i;
    }

    for(int i=0; i<people.size(); i++){
        int mask=0;
        for(int j=0; j<people[i].size(); j++){
            mask |= (1<<m[people[i][j]]);
        }
        pmask[i]=mask;
    }

    fmask = (1<<req_skills.size())-1;
    memset(dp, -1, sizeof(dp));
    solve(0, 0, people);

    int mask=0;
    vector<int>ans;

    for(int i=0; i<people.size(); i++){
        if(choose[i][mask]){
            // if the curr person is  choose for this mask, pb into ans, and  add his mask into curr mask
            mask |= pmask[i];
            ans.push_back(i);
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}