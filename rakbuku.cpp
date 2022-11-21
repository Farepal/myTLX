#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, r;
    cin >> n >> r;
    vector <long long> tg;
    for (int i = 0; i < n; i++){
        long long x; 
        cin >> x; 
        tg.push_back(x);
        int temp = i;
        //insertion sort
        while (temp > 0 && tg[temp] > tg[temp - 1]){
            swap (tg[temp], tg[temp - 1]);
            temp--;
        }
    }
    unsigned long long jum = 0;
    int i;
    for (i = 0; jum < r; i++){
        jum += tg[i];
    }
    cout << i << endl;

    return 0;
}