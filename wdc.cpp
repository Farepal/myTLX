#include <bits/stdc++.h>
using namespace std;

int main(){
	string x;
	cin >> x;
	int n;
	cin >> n;
	
	int xl = x.length();
	int indexAsterik;
	for (int i = 0; i < xl; i++){
		if (x[i] == '*'){
			indexAsterik = i;
			break;
		}
	}
	
	vector <string> list;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		list.push_back(s);
	}
	
	vector <string> hasil;
	if (xl == 1 && indexAsterik == 0){
		for (int i = 0; i < n; i++){
			hasil.push_back(list[i]);
		}
	}
	else if (indexAsterik == xl-1){
		string xtemp = x.erase(xl-1, 1);
		for (int i = 0; i < n; i++){
			if (list[i].find(xtemp) == 0){
				hasil.push_back(list[i]);
			}
		}
	}
	else if (indexAsterik == 0){
		string xtemp = x.erase (0, 1);
		int xtl = xtemp.length();
		for (int i = 0; i < n; i++){
			string ss;
			ss.clear();
			for (int j = list[i].length()-xtl; j < list[i].length(); j++){
				ss = ss + list[i][j];
			}
			if (ss == xtemp){
				hasil.push_back(list[i]);
			}
		}
	}
	//x itu string contoh ma* //pengingat doang ea
	else {
		string xkiri, xkanan;
		for (int i = 0; i < indexAsterik; i++){
			xkiri += x[i];
		}
		for (int i = indexAsterik+1; i < x.length(); i++){
			xkanan += x[i];
		}
		for (int i = 0; i < list.size(); i++){
			bool flag = true;
			for (int j = 0; j < xkiri.length(); j++){
				if (list[i][j] != xkiri[j]){
					flag  = false;
					break;
				}
			}
			int s = list[i].length()-1;
			for (int j = xkanan.length()-1; j >= 0 ; j--){
				if (list[i][s] != xkanan[j]){
					flag  = false;
					break;
				}
				s--;
			}
			if (flag){
				hasil.push_back(list[i]);
			}
		}
	}
	
	//OUTPUT
	for (int i = 0; i < hasil.size(); i++){
		cout << hasil[i] << endl;
	}
	
	return 0;
}