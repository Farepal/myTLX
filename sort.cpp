#include <bits/stdc++.h>

using namespace std;

class SORT {
    public :
        int n;
        vector <int> berubah;
        vector <int> tetap;
        int left = 0;
        int right = SORT::n - 1;

        SORT(int s){
            SORT::n = s;
        }

        void Create(){
            for (int i = 0; i < SORT::n; i++){
                int s;
                cin >> s;
                berubah.push_back(s);
                tetap.push_back(s);
            }
        }

        void swap(int& x, int& y){
            int temp = x;
            x = y;
            y = temp;
        }

        void BubbleSort(){
            for (int end = SORT::n - 1; end > 0; end--){
                for (int i = 0; i < end; i++){
                    if (berubah[i] > berubah[i + 1])
                        swap (berubah[i], berubah[i + 1]);
                }
            }
        }

        void SelectionSort(){
            for (int i = 0; i < SORT::n; i++){
                int MinIndex = i;
                for (int j = i + 1; j < SORT::n; j++){
                    if (berubah[j] < berubah[MinIndex])
                        MinIndex = j;
                    //penetapan index di arr dengan nilai terkecil
                }
                swap (berubah[i], berubah[MinIndex]);
            }
        }

        void InsertionSort(){
            int pos;
            for (int i = 0; i < SORT::n; i++){
                pos = i;
                while (pos > 0 && berubah[pos] < berubah[pos - 1]){
                    //kalo index terkecil lebih besar dari index saat ini maka swap
                    swap (berubah[pos], berubah[pos - 1]);
                    pos--;
                }
            }
        }

        void CountingSort(){
            //tidak bisa untuk nilai pecahan
            int nilaiMax = -1e4;
            for (int i = 0; i < SORT::n; i++){
                if (berubah[i] > nilaiMax)
                    nilaiMax = berubah[i];
            }
            int temp[nilaiMax + 1] = {0};
            for (int i = 0; i < SORT::n; i++){
                int x = berubah[i];
                temp[x]++;
            }
            int index = 0;
            for (int i = 0; i <= nilaiMax; i++){
                for (int j = 0; j < temp[i]; j++){
                    berubah[index] = i;
                    index++;
                }
            }
        }

        void Show(){
            for (int i = 0; i < SORT::n; i++)
                cout << berubah[i] << " ";
            cout << endl;
        }

        void Ulang(){
            SORT::berubah = SORT::tetap;
        }
};

int main(){
    int sz;
    cin >> sz;
    SORT arr = SORT (sz);

    arr.Create();

    arr.BubbleSort();
    arr.Show();

    arr.Ulang();

    arr.SelectionSort();
    arr.Show();

    arr.Ulang();

    arr.InsertionSort();
    arr.Show();

    arr.Ulang();

    arr.CountingSort();
    arr.Show();
    
    return 0;
}