#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

#define fi first
#define sc second

int n, r, y, j;
vector<pair<int, char>> gerakan;
vector<int> skor;
int juri[2000];
bool pernah[20] = {false};
bool yakin = false;

void kontes(int index, int nilai, char gerak)
{
    if (index == 0)
    {
        for (int i = 0; i < n; i++)
        {
            pernah[i] = true;
            nilai += gerakan[i].fi;
            if (gerakan[i].sc == 'Y')
                yakin = true;
            kontes(1, nilai, gerakan[i].sc);
            if (gerakan[i].sc == 'Y')
                yakin = false;
            nilai -= gerakan[i].fi;
            pernah[i] = false;
        }
    }
    else if (index == r)
    {
        skor.push_back(nilai);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int temp = nilai;
            if (pernah[i])
                continue;
            if (gerak == 'Y' || gerak == 'B')
            {
                pernah[i] = true;
                temp += gerakan[i].fi;
                if (gerakan[i].sc == 'Y')
                    yakin = true;
                else if (yakin)
                    temp += y;
                kontes(index + 1, temp, gerakan[i].sc);
                if (gerakan[i].sc == 'Y')
                    yakin = false;
                pernah[i] = false;
            }
            else if (gerak == 'P')
            {
                pernah[i] = true;
                temp += (gerakan[i].fi * 2);
                if (gerakan[i].sc == 'Y')
                    yakin = true;
                else if (yakin)
                    temp += y;
                kontes(index + 1, temp, gerakan[i].sc);
                if (gerakan[i].sc == 'Y')
                    yakin = false;
                pernah[i] = false;
            }
            else if (gerak == 'L')
            {
                pernah[i] = true;
                temp += (gerakan[i].fi / 2);
                if (gerakan[i].sc == 'Y')
                    yakin = true;
                else if (yakin)
                    temp += y;
                kontes(index + 1, temp, gerakan[i].sc);
                if (gerakan[i].sc == 'Y')
                    yakin = false;
                pernah[i] = false;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    string x;
    getline(cin, x);
    cin >> n >> r >> y >> j;

    for (int i = 0; i < n; i++)
    {
        int iii;
        char ccc;
        cin >> iii >> ccc;
        gerakan.push_back(make_pair(iii, ccc));
    }

    for (int i = 0; i < j; i++)
    {
        int iii;
        cin >> juri[i];
    }

    kontes(0, 0, '*');

    sort(skor.begin(), skor.end());

    long long sz = skor.size();

    for (int i = 0; i < j; i++)
    {
        long long tt = upper_bound(skor.begin(), skor.end(), juri[i]) - skor.begin();
        cout << sz - tt << '\n';
    }

    return 0;
}