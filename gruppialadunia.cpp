#include <bits/stdc++.h>

using namespace std; 

bool ada;
//pskor itu permutasi skor
void kemungkinan (int skor[], int pskor[], int indA, int indB, int n){
	if (indA == n){
		bool flag = true;
		for (int i = 0; i < n; i++){
			if (pskor[i] != skor[i]) flag = false;
		}
		if (flag) ada = true;
	}
	else if (indB == n){
		kemungkinan (skor, pskor, indA + 1, indA + 2, n);
	}
	else {
		//menang a
		pskor[indA] += 3;
		kemungkinan (skor, pskor, indA, indB + 1, n);
		pskor[indA] -= 3;//mulai pskor dari 0 lagi ya!!!
		//kalah a
		pskor[indB] += 3;
		kemungkinan (skor, pskor, indA, indB + 1, n);
		pskor[indB] -= 3;
		//seri
		pskor[indA] += 1;
		pskor[indB] += 1;
		kemungkinan (skor, pskor, indA, indB + 1, n);
		pskor[indA] -= 1;
		pskor[indB] -= 1;
	}
}

int main(){
	int t;
	cin >> t;
	
	while (t--){
		int n;
		cin >> n;
		int skor[n];
		for (int i = 0; i < n; i++){
			cin >> skor[i];
		}
		
		ada = false;
		int pskor[n];
		memset (pskor, 0, sizeof pskor);
		
		kemungkinan (skor, pskor, 0, 1, n);
		
		if (ada) {
			cout << "YES" << endl << flush;
		}
		else {
			cout << "NO" << endl << flush;
		}
	}
	
	return 0;
}