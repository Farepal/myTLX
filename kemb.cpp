#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, kem;
    cin >> n;
    vector <int> koin (n);
    for (int i = 0; i < n; i++)
        cin >> koin[i];
    cin >> kem;
    vector <int> ooo (kem + 1, 5000000);
    ooo[0] = 0;
    for (int i = 1; i <= kem; i++){
        for (int j = 0; j < n; j++){
            if (i >= koin[j])
                ooo[i] = min (ooo[i], ooo[i - koin[j]] + 1);
        }
    }
    cout << ((ooo[kem] == 5000000) ? -1 : ooo[kem]) << endl;
    return 0;
}