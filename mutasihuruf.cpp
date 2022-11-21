#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int len;
string x;
size_t angka[2000];
bool udah[2000];
int c = 0;

void mutasi (int a){
	if (a == len){
		c++;
		for (int i = 0; i < len; i++){
			cout << x[angka[i]];
		}
		if (c % 7 == 0) cout << '\n';
		else cout << '\t';
	}
	else {
		for (int i = 0; i < len; i++){
			if (!udah[i]){
				udah[i] = true;
				angka[a] = i;
				mutasi(a + 1);
				udah[i] = false;
			}
		}
	}
}

int main(){
	cin >> x;
	memset (udah, false, sizeof udah);
	len = x.length();
	
	mutasi (0);
	
	return 0;
}