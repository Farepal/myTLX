#include <bits/stdc++.h>
using namespace std; 
 
int mt2gcd (vector <int> d, int s){
	if (s == 0){
		return d[0];
	}
	else {
		return __gcd(d[s], mt2gcd(d, s-1));
	}
}

int main()
{
	int n;
	cin >> n;
	
	vector <int> d;
	for (int i = 0; i < n; i++){
		int pol;
		cin >> pol;
		d.push_back(pol);
	}
	
	sort (d.begin(), d.end());
	
	int ans = d[0];
	for (int i = 1; i < n; i++){
		ans = (d[i]*ans) / __gcd(d[i], ans);
	}//contoh //2 3 4 5 // 6 4 5// 12 5
	// ini itu sama aja kayak kpk dari semua bilangan di array
	
	cout << ans << endl;
	
	return 0;
}