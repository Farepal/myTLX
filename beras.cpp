#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <iomanip>

using namespace std;

bool urut (pair<int, int> a, pair <int, int> b){
	double x = (double)a.second / a.first;
	double y = (double)b.second / b.first;
	
	return (x > y);
}

int main(){
	int n, x;
	cin >> n >> x;
	
	vector <pair<int,int>> beras (n);
	
	int jumlahB = 0;
	for (int i = 0; i < n; i++){
		cin >> beras[i].first;
		jumlahB += beras[i].first;
	}
	
	cout << setprecision(5) << fixed;
	
	double jumlahH = 0;
	for (int i = 0; i < n; i++){
		cin >> beras[i].second;
		jumlahH += beras[i].second;
	}
	
	if (x >= jumlahB){
		cout << jumlahH << endl;
	}
	else {
		sort (beras.begin(), beras.end(), urut);
		jumlahH = 0;
		for (int i = 0; x > 0; i++){
			double perkilo = (double) beras[i].second / beras[i].first;
			int temp = beras[i].first;
			while (temp > 0 && x > 0){
				jumlahH += perkilo;
				temp--;
				x--;
			}
		}
		cout << jumlahH << endl;
	}
	
	return 0;
}