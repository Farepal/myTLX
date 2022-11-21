//ANJING LAH GARA GARA SOAL NYA 
//Ingat bahwa Anda hanya boleh memilih bola ketika rangkaian yang mengandung bola tersebut memiliki lebih dari satu bola.
//jadi ngulang ngulang asw
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
char kotak[50][50];
char kotaktemp[50][50];
vector<long> vskor;
bool udah[50][50];
long skor;

void peruntuhan()
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp = i; //membawa angka 0
            if (kotaktemp[temp][j] == '.')
            {
                while (kotaktemp[temp - 1][j] != '.' && temp != 0)
                {
                    kotaktemp[temp][j] = kotaktemp[temp - 1][j];
                    kotaktemp[temp - 1][j] = '.';
                    temp--;
                }
            }
        }
    }
}

bool bisa(int pa, int pb, int a, int b)
{
    if (pa >= 0 && pb >= 0 && pa < n && pb < m &&
        kotaktemp[pa][pb] == kotaktemp[a][b] && !udah[pa][pb])
        return true;
    else
        return false;
}

void aksi(int a, int b)
{
    skor++;
    udah[a][b] = true;
    if (bisa(a + 1, b, a, b))
    {
        aksi(a + 1, b);
    }
    if (bisa(a - 1, b, a, b))
    {
        aksi(a - 1, b);
    }
    if (bisa(a, b - 1, a, b))
    {
        aksi(a, b - 1);
    }
    if (bisa(a, b + 1, a, b))
    {
        aksi(a, b + 1);
    }
    kotaktemp[a][b] = '.';
}

void aksi1(int a, int b)
{
    skor++;
    udah[a][b] = true;
    if (bisa(a + 1, b, a, b))
    {
        aksi(a + 1, b);
    }
    if (bisa(a - 1, b, a, b))
    {
        aksi(a - 1, b);
    }
    if (bisa(a, b - 1, a, b))
    {
        aksi(a, b - 1);
    }
    if (bisa(a, b + 1, a, b))
    {
        aksi(a, b + 1);
    }
}

bool cek()
{
    int checker = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (kotaktemp[i][j] != '.')
                checker++;
        }
    }
    if (checker <= 1)
    {
        return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    memset(udah, false, sizeof udah);
    memset(kotaktemp, -1, sizeof kotaktemp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> kotak[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (kotak[i][j-1] != kotak[i][j] && kotak [i][j+1] != kotak[i][j] &&
                kotak[i-1][j] != kotak[i][j] && kotak[i+1][j] != kotak[i][j]){
                    continue;
                }
            for (int s = 0; s < n; s++)
            {
                for (int k = 0; k < m; k++)
                {
                    kotaktemp[s][k] = kotak[s][k];
                }
            }
            skor = 0;
            aksi(i, j);
            skor = skor * (skor - 1);
            long xxx = skor;
            memset(udah, false, sizeof udah);
            peruntuhan();
            long terbesar = 0;
            if (cek())
            {
                for (int s = 0; s < n; s++)
                {
                    for (int k = 0; k < m; k++)
                    {
                        if (kotaktemp[s][k] == '.')
                            continue;
                        skor = 0;
                        aksi1(s, k);
                        memset(udah, false, sizeof udah);
                        skor = skor * (skor - 1);
                        if (skor > terbesar)
                            terbesar = skor;
                    }
                }
            }
            vskor.push_back(xxx + terbesar);
        }
    }

    cout << *max_element(vskor.begin(), vskor.end()) << "\n";

    return 0;
}