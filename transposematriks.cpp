#include <iostream>

using namespace std;

int main(){
	int n, m;
	cout << "baris : ";
	cin >> n;
	cout << "kolom : ";
	cin >> m;
	
	int mat1[n][m];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat1[i][j];	
		}
	}
	
	int mat2[m][n];
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat2[i][j] = mat1[j][i];
			if (j == n-1)
			{
				cout << mat2[i][j] << endl;
			}
			else
			{
				cout << mat2[i][j] << " ";
			}
		}
	}
	return 0;
}