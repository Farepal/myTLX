#include <iostream>
#include <algorithm>
#include <string>

// #include <bits/stdc++.h>

using namespace std;

bool pengurutan_nama (string a, string b){
	if (a.length() < b.length()) return true;
	else if (a.length() > b.length()) return false;
	else {
		if (a < b) return true;
		else return false;
	}
}

int main(){
	int n;
	cin >> n;
	
	string nama[n];
	for (int i = 0; i < n; i++){
		cin >> nama[i];
	}
	
	sort(nama, nama + n, pengurutan_nama);
	
	for (int i = 0; i < n; ++i){
		cout << nama[i] << endl;
	}
	
	return 0;
}