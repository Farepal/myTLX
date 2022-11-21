#include <bits/stdc++.h>
using namespace std;

int main(){
	string x;
	cin >> x;
	int n;
	cin >> n;
	
	string prex = "";
	string postx = "";
	int aster = x.find('*');
	for (int i = 0; i < aster; i++){
		prex += x[i];
	}
	for (int i = aster+1; i < x.length(); i++){
		postx += x[i];
	}
	
	int prel = prex.length();
	int postl = postx.length();
	
	while (n--){
		string s;
		cin >> s;
		int sl = s.length();
		if (sl < prel+postl) continue;
		
		bool flag = true;
		
		for (int i = 0; i < prel; i++){
			if (s[i] != prex[i]){
				flag = false;
				break;
			}
		}
		
		for (int i = postl-1, p = sl-1; i >= 0; i--, p--){
			if (s[p] != postx[i]){
				flag = false;
			}
		}
		if (flag){
			cout << s << endl;
		}
	}
	
	return 0;
}