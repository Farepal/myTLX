#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector <int> val (1, 1);
	int temp;
	int carry = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < val.size(); j++){
			val[j] = val[j] * i + carry;
			carry = val[j] / 10;
			val[j] %= 10;
		}
		while (carry){
			temp = carry % 10;
			val.emplace_back(temp);
			carry /= 10;
		}
	}
	
	for (auto i = val.rbegin(); i != val.rend(); i++){
		cout << *i;
	}
	cout << '\n';
	
	return 0;
}