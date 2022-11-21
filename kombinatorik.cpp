#include <iostream>
//kombinasi dari N baris dengan baris sebanyak B

using namespace std;
//index dimulai dari 1
int count = 0;
void kombinasi (int baris[], int b, int n, int ind){
	if (ind > b){
		count++;
		for (int i = 1; i <= b; i++){
			cout << baris[i];
		}
		if (count % 7 == 0) cout << endl;
		else cout << "\t";
	}
	else {
		for (baris[ind] = baris[ind-1]+1; baris[ind] <= n; baris[ind]++){
			kombinasi (baris, b, n, ind+1);
		}
	}
}

int main(){
	int n, b;
	cin >> n >> b;
	int baris[b+1];
	
	baris[0] = 0;
	
	kombinasi (baris, b, n, 1);
	cout << endl;
	cout << "BANYAKNYA KOMBINATORIK : " << count << endl;
	
	return 0;
}