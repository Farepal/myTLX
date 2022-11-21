#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

char arr[129][129];
int sz = 1;

void reverseQuadtree (vector <string> sol){
	int lenV = sol.size();
	
	for (int i=0 ; i<lenV; i++){
		string s = sol.at(i);
		
		int len = s.length();
		
		int a = 1, b = 1, c = sz, d = sz;
		
		for (int i=1; i < len; i++){
			//untuk perubahan c dan d tidak membutuhkan + 1
			//untuk perubahan a dan b membutuhkan + 1
			if (s[i] == '0'){
				//kiri atas
				c = (a+c)/2;
				d = (b+d)/2;
			}
			else if (s[i] == '1'){
				//kanan atas
				b = (b+d)/2 + 1;
				c = (a+c)/2;
			}
			else if (s[i] == '2'){
			//kiri bawah
				a = (a+c)/2 + 1;
				d = (b+d)/2;
			}
			else if (s[i] == '3'){
			//kanan bawah
				a = (a+c)/2 + 1;
				b = (b+d)/2 + 1;
			}
		}
		
		for (int i = a; i <= c; i++){
			for (int j = b; j <= d; j++){
				arr[i][j] = '1';
			}
		}
		
	}
}
	

int main(){
	memset (arr, '0', sizeof arr);

	int snowman;
	cin >> snowman;
	
	vector <string> sol;
	
	for (int i=0; i<snowman; i++){
		string s;
		cin >> s;
		sol.push_back (s);
	}
	
	int r, c;
	cin >> r >> c;
	
	int max = r > c ? r : c;
	
	while (sz < max){
		sz *= 2;
	}
	
	reverseQuadtree (sol);
	
	for (int i = 1; i <= r; i++){
		for (int j = 1; j <= c; j++){
			if (j == c) cout << arr[i][j] << endl;
			else cout << arr[i][j] << " ";
		}
	}
	
	return 0;
}