#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	
	int terdekat = INT_MAX;
	int jarakdkt = INT_MAX;
	while (n--){
		int a;
		cin >> a;
		int jarak = abs(x-a);
		if (jarakdkt > jarak){
			terdekat = a;
			jarakdkt = jarak;
		}
		else if (jarak == jarakdkt){
			if (a < terdekat){
				terdekat = a;
			}
		}
	}
	
	cout << terdekat << endl;
	
	return 0;
}