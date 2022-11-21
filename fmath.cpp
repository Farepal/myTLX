#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

bool prime (int n);
int lcm (int a, int b);
void batasprima(int x);
void banyaknyabilanganprima(int x);
void faktorisasiprima (int n);
int phi (int n);
void faktorbilangan (int n);

signed main(){
	cout << "=============" << endl;
	cout << "  F M A T H  " << endl;
	cout << "=============" << endl << endl;
	cout << " PILIH NOMOR " << endl;
	cout << "1.  Mengecek Bilangan Prima " << endl;
	cout << "2.  Great Common Divisor atau Faktor Persekutuan Terbesar " << endl;
	cout << "3.  Least Common Multiple atau Kelipatan Persekutuan Terkecil" << endl;
	cout << "4.  Bilangan Prima dengan batasnya " << endl;
	cout << "5.  Bilangan Prima dengan banyaknya " << endl;
	cout << "6.  Faktorisasi Prima " << endl;
	cout << "7.  Fungsi Phi " << endl;
	cout << "8.  Operasi Modulo dua bilangan " << endl;
	cout << "9.  Penjumlahan Bilangan " << endl;
	cout << "10. Pengurangan Bilangan " << endl;
	cout << "11. Perkalian Bilangan " << endl;
	cout << "12. Faktor Bilangan " << endl;
	cout << "13. Perpangkatan Bilangan " << endl;
	int xx;
	cout << "MASUKKAN NOMOR : ";
	cin >> xx;
	cout << endl;
	if (xx == 1){
		int n;
		cout << "1.  Mengecek Bilangan Prima " << endl;
		cout << "MASUKKAN ANGKA POSITIF : ";
		cin >> n;
		cout << endl;
		if (prime (n) == true){
			cout << " INI ADALAH BILANGAN PRIMA ";
		}
		else {
			cout << " INI BUKAN BILANGAN PRIMA ";
		}
	}
	else if (xx == 2){
		int a, b;
		cout << "2.  Great Common Divisor atau Faktor Persekutuan Terbesar " << endl;
		cout << " MASUKKAN 2 ANGKA :";
		cin >> a >> b;
		cout << endl;
		cout << " hasilnya adalah : " << __gcd(a, b);
	}
	else if (xx == 3){
		int a, b;
		cout << "3.  Least Common Multiple atau Kelipatan Persekutuan Terkecil" << endl;
		cout << "MASUKKAN 2 ANGKA : ";
		cin >> a >> b;
		cout << endl;
		cout << " hasilnya adalah : " << lcm(a, b);
	}
	else if (xx == 4){
		int n;
		cout << "4.  Bilangan Prima dengan batasnya " << endl;
		cout << "MASUKKAN ANGKA POSITIF : ";
		cin >> n;
		cout << endl;
		batasprima (n);
	}
	else if (xx == 5){
		cout << "5.  Bilangan Prima dengan banyaknya " << endl;
		int n;
		cout << "MASUKKAN ANGKA POSITIF  : ";
		cin >> n;
		cout << endl;
		banyaknyabilanganprima(n);
	}
	else if (xx == 6){
		cout << "6.  Faktorisasi Prima " << endl;
		int n;
		cout << "MASUKKAN ANGKA POSITIF : ";
		cin >> n;
		cout << endl;
		faktorisasiprima (n);
	}
	else if (xx == 7){
		cout << "7.  Fungsi Phi " << endl;
		int n;
		cout << "MASUKKAN ANGKA POSIIF : ";
		cin >> n;
		cout << endl;
		cout << "hasilnya adalah : " << phi (n);
	}
	else if (xx == 8){
		cout << "8.  Operasi Modulo dua bilangan " << endl;
		int a, b;
		cout << "Masukkan 2 buah angka : ";
		cin >> a >> b;
		cout << endl;
		int output = a > b ? a % b : b % a; //ternary operator
		cout << output;
	}
	else if (xx == 9){
		cout << "9.  Penjumlahan Bilangan " << endl;
		cout << "Masukkan angka berapapun " << endl;
		cout << "Pencel ctrl + z lalu enter untuk berhenti " << endl;
		
		int temp;
		int ans = 0;
		
		while (cin >> temp){
			ans = ans + temp;
		}
		cout << ans;
	}
	else if (xx == 10){
		cout << "10. Pengurangan Bilangan " << endl;
		cout << "Masukkan angka berapapun " << endl;
		cout << "Pencel ctrl + z lalu enter untuk berhenti dan menghasilkan output" << endl;
		
		int temp;
		int ans = 0;
		
		while (cin >> temp){
			ans = ans - temp;
		}
		cout << ans;
	}
	else if (xx == 11){
		cout << "11. Perkalian Bilangan " << endl;
		cout << "Masukkan angka berapapun " << endl;
		cout << "Pencel ctrl + z lalu enter untuk berhenti dan menghasilkan output" << endl;
		
		int temp;
		int ans = 1;
		
		while (cin >> temp){
			ans = ans * temp;
		}
		cout << ans;
	}
	else if (xx == 12){
		cout << "12. Faktor Bilangan " << endl;
		int n;
		cout << "Masukkan Bilangan : ";
		cin >> n;
		cout << endl;
		faktorbilangan (n);
	}
	else if (xx == 13){
		cout << "13. Perpangkatan Bilangan " << endl;
		int a, b;
		cout << "Masukkan bilangan : ";
		cin >> a;
		cout << "Masukkan pangkatnya : ";
		cin >> b; 
		cout << endl;
		cout << "hasilnya adalah : " << pow (a , b);
	}
	
	cout << endl;
	
	return 0;
}


bool prime(int n){
	if (n % 2 == 0 && n != 2 or n == 1 or n % 3 == 0 && n != 3 or n % 5 == 0 && n != 5 or n % 7 == 0 && n != 7){
		return false;
	}
	
	for (int i = 11; i <= floor(sqrt(n)); i += 2){
		while (i % 3 == 0 or i % 5 == 0 or i % 7 == 0){
			i += 2;
		}
		
		if (n % i == 0){
			return false;
		}
	}
	return true;
}

void batasprima(int x){
	if (x == 2){
		cout << 2 << endl;
	}
	
	if (x > 2){
		cout << 2 << " ";
	}
	
	if (x >= 3){
		for (int i = 3; i <= x; i += 2){
			while (prime(i) == false){
				i += 2;
			}
			
			if (i > x){
				break;
			}
			cout << i << " ";
		}
	}	
}

void banyaknyabilanganprima(int x){
	if (x == 1){
		cout << 2;
	}
	
	if (x > 1){
		cout << 2 << " ";
	}
	
	if (x >= 2){
		for (int i = 3; x > 1; i += 2, x--){
			while (prime(i) == false){
				i += 2;
			}//penyeleksian bilangan prima
			cout << i << " ";
		}
	}	
}
	

int phi(int n){
	int temp = n;
	int ans = n;
	//sifat phi (n) itu jika n bilangan prima maka phi(n) = n - 1
	if (prime(n) == true){
		return n-1;
	}
	//p1 itu faktor bilangan n yg bersifat prima yang pertama
	//untuk p2 p3 p4 itu seterusnya
	//misal 1000 faktor prima yang pertama itu 2(p1) terus yg kedua itu 5(p2)
	//rumus Phi (n) = n (1 - 1/p1) (1- 1/p2) (1 - 1/p3) ....
	//(1 - 1/p1) = (p1/p1 - 1/p1) = (p1 - 1)/p1
	//saya menggunakan rumus phiq (n) = n(p1-1)(p2-1)(p3-1)..... / p1 x p2 x p3 x p4...
	for (int i = 2; temp > 1; i++){
		while (prime(i) == false){
			i++;
		}
		
		bool first = true;
		
		while (temp % i == 0){
			
			if (first){
				ans = ans * (i - 1) / i;
				first = false;
			}
			temp = temp / i;
		}
	}
	return ans;
}

int lcm(int a, int b){
	//least common multiple atau kelipatan perkalian terkecil
	//rumus kpk itu kpk (a,b) = (a * b) / fpb(a, b)
	return a * b / __gcd(a, b);
}

void faktorisasiprima(int n){
	bool yangpertama = true;
	int modus;
	for (int i = 2; n > 1; i++){
		while (prime(i) == false){
			i++;
		}
		
		int pangkat = 0;
		
		while (n % i == 0){
		n /= i;
		pangkat++; 
		}
		
		if (pangkat > 0){
			if (yangpertama){
				yangpertama = false;
				if (pangkat > 1){
					cout << i << "^" << pangkat;
				}
				else {
					cout << i;
				}
			}
			else {
				cout << " x ";
				if (pangkat > 1){
					cout << i << "^" << pangkat;
				}
				else {
					cout << i;
				}
			}
		}
	}
}

void faktorbilangan (int n){
	vector <int> listfaktor;
	for (int i = 1; i <= floor(sqrt(n)); i++){
		if (n % i == 0){
			listfaktor.push_back(i);
			if (sqrt(n) != i){
				listfaktor.push_back(n/i);
			}
		}
	}
	
	sort(listfaktor.begin(), listfaktor.end());//pengurutan element array
	
	for (int i = 0; i < listfaktor.size(); i++){
		cout << listfaktor.at(i) << " ";
	}
}