//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/move-minimization-8a9d3991/description/?layout=old
#include<iostream>
#include<vector>
#include<climits>
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

int merge(int arr[], int temp[], int left, int mid, int right){ 
    int i, j, k; 
    int inv_count = 0; 
  
    i = left;
    j = mid;
    k = left; 

    while((i<=mid-1) && (j<=right)){ 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else{ 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
        } 
    } 

    while(i<=mid-1) temp[k++] = arr[i++]; 
  
    while(j<=right) temp[k++] = arr[j++]; 
  
    for(i=left; i<=right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 

int _mergeSort(int arr[], int temp[], int left, int right) { 
    int mid, inv_count = 0; 
    if (right>left) { 
        mid = (right+left) / 2; 
        inv_count += _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
  
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
}

int mergeSort(int arr[],int l, int array_size) { 
    int temp[array_size]; 
    return _mergeSort(arr, temp, l, array_size - 1); 
} 
 
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	int a[n];

	for(int i=0;i<n;i++){
		cin>>a[i];
        a[i]--;
	}

	int ans=INT_MAX,m1=-1,m2=1,l=-1,r=-1;
    for(int i=0;i<n;i++){
        int d=a[i]-i;
        if(d>m1){
            m1=d,l=i;
        }
    }
    for(int i=0;i<n;i++){
        int d=a[i]-i;
        if(d<m2){
            m2=d,r=i;
        }
    }
    swap(a[l],a[r]);
    ans = min(ans,mergeSort(a,0,n));
    cout<<ans<<endl;
	return 0;
}