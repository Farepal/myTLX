#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector <int> arr (n+1);
	
	for (int i=1;i<=n;i++){
		cin >> arr[i];
	}
	
	if (n > 2000){
		cout << 0 << endl;
		return 0;
	}
	
	sort (arr.begin(), arr.end());
	//anjing ternyata disorting dulu tai
	//jadi gagal submit kan
	
	unsigned long long int ans = 1;
	for (int k = 1; k<=n; k++){
		for (int j=k+1; j<=n; j++){
			ans = (ans * (arr[k] ^ arr[j])) % 998244353;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}