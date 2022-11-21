// NGE HACK SUDOKU ANJING
#include <iostream>
#include <vector>//dynamic array

using namespace std;
int cnt = 0;
vector <vector <vector <int>>> kotak;
bool udah[9][9] = {false};

void inputer ();
int finder (int i, int j, int sizer, int penanda);
vector <int> eraser (int i, int j, int sizer, int IndexTerhapus);
void EliminasiSebaris (int i, int j, int penanda);
void PartisiEliminasiKotak (int i, int j, int penanda);
void EliminasiKotakKecil(int iBegin, int iEnd, int jBegin, int jEnd, int penanda);
void showHasil ();

int main(){
    inputer();
    for (int i = 0; cnt < 81; i++){
        for (int j = 0; j < 9 && cnt < 81; j++){
            if (kotak[i][j].size() == 1 && !udah[i][j]){
                EliminasiSebaris (i, j, kotak[i][j][0]);
                PartisiEliminasiKotak (i, j, kotak[i][j][0]);
                udah[i][j] = true;
            }
        }
        if (i == 8)
            i = 0;
    }
    cout << endl << "=====JAWABAN======"  << endl << endl;
    showHasil();
    
    return 0;
}

void inputer (){
    vector <int> pbb {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++){
        vector <vector <int>> gg;
        for (int j = 0; j < 9; j++){
            char testerr;
            cin >> testerr;
            if (testerr == '.' || testerr == '0')
                gg.push_back(pbb);
            else {
                gg.push_back(vector <int> (1, (int)(testerr - '0')));
                cnt++;
            }
        }
        kotak.push_back(gg);
    }
}

int finder (int i, int j, int sizer, int penanda){
    for (int awal = 0; awal < sizer; awal++){
        if (kotak[i][j][awal] == penanda)
            return awal;
    }
    return sizer;
}

vector <int> eraser (int i, int j, int sizer, int IndexTerhapus){
    vector <int> temp;
    for (int nob = 0; nob < sizer; nob++){
        if (nob == IndexTerhapus)
            continue; 
        temp.push_back(kotak[i][j][nob]);
    }
    return temp;
}

void EliminasiSebaris (int i, int j, int penanda){
    for (int ind = 0; ind < 9; ind++){
        //Ke Samping
        if (kotak[i][ind].size() != 1){
            int sz = kotak[i][ind].size();
            int dumb = finder (i, ind, sz, penanda);
            if (dumb != sz)
                kotak[i][ind] = eraser (i, ind, sz, dumb);
            if (kotak[i][ind].size() == 1)
                cnt++;
        }
        //Ke Bawah
        if (kotak[ind][j].size() != 1){
            int sz = kotak[ind][j].size();
            int dumb = finder (ind, j, sz, penanda);
            if (dumb != sz)
                kotak[ind][j] = eraser (ind, j, sz, dumb);
            if (kotak[ind][j].size() == 1)
                cnt++;
        }
    }
}

void EliminasiKotakKecil(int iBegin, int iEnd, int jBegin, int jEnd, int penanda){
    for (int i = iBegin; i <= iEnd; i++){
        for (int j = jBegin; j <= jEnd; j++){
            if (kotak[i][j].size() != 1){
                int sz = kotak[i][j].size();
                int dumb = finder (i, j, sz, penanda);
                if (dumb != sz)
                    kotak[i][j] = eraser (i, j, sz, dumb);
                if (kotak[i][j].size() == 1)
                    cnt++;
            }
        }
    }
}

//ADA 9 KOTAK DENGAN BATAS YANG BERBEDA BEDA
void PartisiEliminasiKotak (int i, int j, int penanda){
    //Kotak Kecil 1
    if (i >= 0 && i <= 2 && j >= 0 && j <= 2){
        EliminasiKotakKecil (0, 2, 0, 2, penanda);
    }
    //2
    else if (i >= 0 && i <= 2 && j >= 3 && j <= 5){
        EliminasiKotakKecil (0, 2, 3, 5, penanda);
    }
    //3
    else if (i >= 0 && i <= 2 && j >= 6 && j <= 8){
        EliminasiKotakKecil (0, 2, 6, 8, penanda);
    }
    //4
    else if (i >= 3 && i <= 5 && j >= 0 && j <= 2){
        EliminasiKotakKecil (3, 5, 0, 2, penanda);
    }
    //5
    else if (i >= 3 && i <= 5 & j >= 3 && j <= 5){
        EliminasiKotakKecil (3, 5, 3, 5, penanda);
    }
    //6
    else if (i >= 3 && i <= 5 && j >= 6 && j <= 8){
        EliminasiKotakKecil (3, 5, 6, 8, penanda);
    }
    //7
    else if (i >= 6 && i <= 8 && j >= 0 && j <= 2){
        EliminasiKotakKecil (6, 8, 0, 2, penanda);
    }
    //8
    else if (i >= 6 && i <= 8 && j >= 3 && j <= 5){
        EliminasiKotakKecil (6, 8, 3, 5, penanda);
    }
    //9
    else if (i >= 6 && i <= 8 && j >= 6 && j <= 8){
        EliminasiKotakKecil (6, 8, 6, 8, penanda);
    }
}

void showHasil (){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            for (int k = 0; k < kotak[i][j].size(); k++){
                cout << kotak[i][j][k];
            }
            cout << ' ';
            if (j == 2 || j == 5)
                cout << ' ';
        }
        cout << endl;
        if (i == 2 || i == 5)
            cout << endl;
    }
}