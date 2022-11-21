#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//gabungkan kedua vector
vector <int> arr;
//misal 4 5 6 6
//a4 = 2, a5 = 91, a6 = 72
void Merge (int aKiri, int aKanan, int bKiri, int bKanan){
    int size = bKanan - aKiri + 1;
    vector <int> temp (size);
    int tIndex = 0;
    int aIndex = aKiri;
    int bIndex = bKiri;
    //Selama Kedua subArray masih ada isinya, ambil yang terkecil dan isi ke temp
    while ((aIndex <= aKanan) && (bIndex <= bKanan)){
        if (arr[aIndex] <= arr[bIndex]){
            temp[tIndex] = arr[aIndex];
            aIndex++;
        }
        else {
            temp[tIndex] = arr[bIndex];
            bIndex++;
        }
        tIndex++;
    }
    //Masukkan subarray yang masih bersisa ke temp
    //Hanya salah satu dari kedua while ini yang akan dieksekusi
    while (aIndex <= aKanan){
        temp[tIndex] = arr[aIndex];
        aIndex++;
        tIndex++;
    }
    while (bIndex <= bKanan){
        temp[tIndex] = arr[bIndex];
        bIndex++;
        tIndex++;
    }
    //salin ini array temp ke array asli
    for (int i = 0; i < size; i++){
        arr[aKiri + i] = temp[i];
    }
}

void MergeSort (int kiri, int kanan){
    if (kiri != kanan){
        int mid = (kiri + kanan) / 2;
        MergeSort(kiri, mid);//kiri
        MergeSort(mid+1, kanan);//kanan
        cout << kiri << " " << mid  << " " << mid + 1 << " " << kanan << endl;
        Merge (kiri, mid, mid + 1, kanan);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int t;
    for (int i = 0; i < n; i++){
        cin >> t;
        arr.push_back(t);
    }
    MergeSort(0, n-1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}