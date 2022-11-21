#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int snowman = 0;
vector <string> sol;
char arr[200][200];

void quadtree(int a, int b, int c, int d, string temp){
	temp[0] = arr[a][b];
	char check = temp[0];
	bool flag = true;
	for (int i=a; i<= c; i++){
		for (int j=b; j<=d; j++){
			if (check != arr[i][j]){
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}
	
	if (!flag){
		//kiri atas // a+c dengan b+d tidak selalu bilangan bulat
		quadtree (a, b, (a+c)/2, (b+d)/2, temp + "0");
		//kanan atas
		quadtree (a, (b+d)/2+1, (a+c)/2, d, temp + "1");
		//kiri bawah
		quadtree ((a+c)/2 + 1, b, c, (b+d)/2, temp + "2");
		//kanan bawah
		quadtree ((a+c)/2+1, (b+d)/2+1, c, d, temp + "3");
	}
	else {
		if (temp[0] == '1'){
			snowman++;
			sol.push_back(temp);
		}
	}
}

int main(){
	int x, y;
	cin >> x >> y;
	
	int z = x > y ? x : y;//ternary operator
	
	int sz = 1;//size
	while (sz < z){
		sz *= 2;//misal z nya 5 maka 2 pangkat berapapun yang terdekat di atas 5
	}
	//mulai array dari 1
	for (int i=1; i<=sz; i++){
		for (int j=1; j<=sz; j++){
			arr[i][j] = '0';
		}
	}
	
	for (int i=1; i<=x; i++){
		for (int j=1; j<=y; j++){
			cin >> arr[i][j];
		}
	}
	
	string num = "0";
	
	quadtree (1, 1, sz, sz, num);

	cout << snowman << endl;
	sort (sol.begin(), sol.end());
	
	for (int i=0; i<sol.size(); i++){
		cout << sol[i] << endl;
	}//tadi pas i<=sol.size() terjadi runtime error
	
	return 0;
}