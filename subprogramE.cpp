#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, k, x;
	cin >> a >> b >> k >> x;
	
	int ans = x;
	for (int i = 0; i < k; i++){
		ans = abs (a*ans + b);
	}
	
	cout << ans << endl;
	
	return 0;
}