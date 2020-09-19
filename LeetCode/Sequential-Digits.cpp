// https://leetcode.com/problems/sequential-digits/
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

class Solution {
public:
vector<int> sequentialDigits(int low, int high) {
	auto [d, nb_digits] = first_digit_order(low);

	if(not valid_digit_order(d, nb_digits))
		next_seq_digit_order(d, nb_digits);

	if(seq_number(d, nb_digits) < low)
		next_seq_digit_order(d, nb_digits);

	vector<int> result;
	while(true){
		int n = seq_number(d, nb_digits);
		if(n>high)
			break;
		result.push_back(n);
		next_seq_digit_order(d, nb_digits);
	}
	return result;
}

inline bool valid_digit_order(int digit, int nb_digits) {return (10 - digit) >= nb_digits;}

void next_seq_digit_order(int &digit, int& nb_digits){
	++digit;
	if(not valid_digit_order(digit, nb_digits)){
		++nb_digits;
		digit = 1;
	}
}

pair<int, int> first_digit_order(int n){
	int nb_digits = 0, d = 0;
	while(n > 0){
		d = n%10; 
		n = n/10; 
		++nb_digits;
	}
	return {d, nb_digits};
}

int seq_number(int d, int nb_digits){
	int n = 0;
	for(int i = 0; i != nb_digits; ++i)
		n = n * 10 + d++;
	return n;
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