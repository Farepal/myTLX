#include <iostream>

using namespace std;

int mat[75][75];
int mats[75][75];

bool iden(int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (mat[i][j] != mats[i][j]) return false;
		}
	}
	return true;
}

bool hor(int n){
	for (int i = n-1, is = 0; i >= 0 && is < n; i--, is++){
		for (int j = 0, js = 0; j < n && js < n; j++, js++){
			if (mat[i][j] != mats[is][js]) return false;
		}
	}
	return true;
}

bool ver(int n){
	for (int i = 0, is = 0; i < n && is < n; i++, is++){
		for (int j = n-1 , js = 0; j >= 0 && js < n; j--, js++){
			if (mat[i][j] != mats[is][js]) return false;
		}
	}
	return true;
}

bool dknb(int n){
	for (int i = 0, is = 0; i < n && is < n; i++, is++){
		for (int j = 0, js = 0; j < n && js < n; j++, js++){
			if (mat[j][i] != mats[is][js]) return false;
		}
	}
	return true;
}

bool dkrb (int n){
	for (int i = n-1, is = 0; i >= 0 && is < n; i--, is++){
		for (int j = n-1 , js = 0; j >= 0 && js < n; j--, js++){
			if (mat[j][i] != mats[is][js]) return false;
		}
	}
	return true;
}

int main(){
	int n, ns;
	cin >> n >> ns;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < ns; j++){
			cin >> mat[i][j];
		}
	}
	
	int x, xs;
	cin >> x >> xs;
	
	for (int i = 0; i < x; i++){
		for (int j = 0; j < xs; j++){
			cin >> mats[i][j];
		}
	}
	ote
	if (x != n) cout << "tidak identik" << endl;
	else if (n != ns) cout << "tidak identik" << endl;
	else if (x != xs) cout << "tidak identik" << endl;
	else if (iden(n)) cout << "identik" << endl;
	else if (hor(n)) cout << "horisontal" << endl;
	else if (ver(n)) cout << "vertikal" << endl;
	else if (dknb(n)) cout << "diagonal kanan bawah" << endl;
	else if (dkrb(n)) cout << "diagonal kiri bawah" << endl;
	else cout << "tidak identik" << endl;
	
	return 0;
}