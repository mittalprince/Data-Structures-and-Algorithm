// https://codingblocks.com/resources/read-the-minimum-pages/
#include<iostream>
#include<vector>
#include<algorithm>
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

/*
Logic: Binary Search

Task: we have to minimize the max no of pages allocated to a students, means the max pages allocated to single student
must be minnimum as much as we can.

For this we use BS we find mid(means if we give atmost mid pages to a single student then using this mid, can we achieve our configuration)

We check can we give atmost mid pages to a sinlge student and using this can we read all books with given total students or not
if yes means we can also get ans for large value of mid so we dec our range and move left to get minimum of ans.
*/

bool isPossible(ll books[], ll total_books, ll total_students, ll max_pages){
    int students=1;
    ll curr_pages=0;
    for(int i=0; i<total_books; i++){
        if(curr_pages + books[i] > max_pages){
            students++; // need one more student as total_page assigned to a student > max_pages
            curr_pages = books[i]; // now this student curr_page will be books[i]
            if(students>total_students)return false; // if students>total_student this max_pages not possible, so we incre range (move right)
        }
        else{
            curr_pages += books[i];
        }
    }
    return true;
}

void solve(){
    ll no_of_books, no_of_students;
    cin>>no_of_books>>no_of_students;

    ll total_pages=0;
    ll s=0;

    ll books[no_of_books];
    for(int i=0; i<no_of_books; i++){
        cin>>books[i];
        s = max(s, books[i]);
        total_pages += books[i];
    }

    ll e=total_pages; // initially the max pages read by a single student will be total pages avaible
    ll ans = 0;

    while(s<=e){
        ll mid = s+(e-s)/2;
        if(isPossible(books, no_of_books, no_of_students, mid)){
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    cout<<ans<<endl;
    
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}