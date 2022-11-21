#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int x[2] = {0,4};
void solve (){
    x[1] = 5;
}


int main(){
    solve ();
    cout << x[1] << endl;
    return 0;
}
