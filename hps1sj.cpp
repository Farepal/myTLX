#include <bits/stdc++.h>

using namespace std;

int main(){
	string x;
	cin >> x;
	
	string s;
	cin >> s;
	
	bool flag = false;
	for (int i = 0; i < x.length(); i++){
		string temp = "";
		for (int j = 0; j < x.length(); j++){
			if (j == i) continue;
			temp += x[j];
		}
		if (temp == s){
			flag = true;
			break;
		}
	}
	
	if (flag) cout << "Tentu saja bisa!" << endl;
	else cout << "Wah, tidak bisa :(" << endl;
	
	return 0;
}