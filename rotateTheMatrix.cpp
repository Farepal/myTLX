#include <bits/stdc++.h>

using namespace std;

int m, n, r;

int main()
{
    cin >> m >> n >> r;
    int matrix[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int NewMatrix[m][n];
    memset(NewMatrix, 0, sizeof NewMatrix);

    int tempi = 0, tempj = 0; //tempi selalu sama dengan tempj
    int tempm = m - 1, tempn = n - 1;

    int TempeR;
    while (NewMatrix[tempi][tempj] == 0)
    {
        if (tempi == tempm && tempj == tempn)
        {
            NewMatrix[tempi][tempj] = matrix[tempi][tempj];
            break;
        }

        TempeR = r % ((2 * (tempm + 1 - tempi)) + (2 * ((tempn + 1 - tempj) - 2))); //rotasi dimodulo keliling kotak
        int tempr = TempeR;
        int ii = tempi;
        int jj = tempj;

        while (tempr)
        {
            if (ii == tempi)
            {
                while (jj > tempj && tempr > 0)
                {
                    jj--;
                    tempr--;
                }
            }
            if (jj == tempj)
            {
                while (ii < tempm && tempr > 0)
                {
                    ii++;
                    tempr--;
                }
            }
            if (ii == tempm)
            {
                while (jj < tempn && tempr > 0)
                {
                    jj++;
                    tempr--;
                }
            }
            if (jj == tempn)
            {
                while (ii > tempi && tempr > 0)
                {
                    ii--;
                    tempr--;
                }
            }
        }

        NewMatrix[ii][jj] = matrix[tempi][tempj];
        //kotak atas tempi
        for (int j = tempj + 1; j <= tempn; j++)
        {
            if (ii == tempi && jj >= tempj && jj <= tempn - 1) jj++;
            else if (ii >= tempi && ii <= tempm - 1 && jj == tempn) ii++;
            else if (ii == tempm && jj <= tempn && jj >= tempj + 1) jj--;
            else if (jj == tempj && ii <= tempm && ii >= tempi + 1) ii--;
            NewMatrix[ii][jj] = matrix[tempi][j];
        }
        //kotak kanan tempn
        for (int i = tempi + 1; i <= tempm; i++)
        {
            if (ii == tempi && jj >= tempj && jj <= tempn - 1) jj++;
            else if (ii >= tempi && ii <= tempm - 1 && jj == tempn) ii++;
            else if (ii == tempm && jj <= tempn && jj >= tempj + 1) jj--;
            else if (jj == tempj && ii <= tempm && ii >= tempi + 1) ii--;
            NewMatrix[ii][jj] = matrix[i][tempn];
        }
        //kotak bawah tempm
        for (int j = tempn - 1; j >= tempj; j--)
        {
            if (ii == tempi && jj >= tempj && jj <= tempn - 1) jj++;
            else if (ii >= tempi && ii <= tempm - 1 && jj == tempn) ii++;
            else if (ii == tempm && jj <= tempn && jj >= tempj + 1) jj--;
            else if (jj == tempj && ii <= tempm && ii >= tempi + 1) ii--;
            NewMatrix[ii][jj] = matrix[tempm][j];
        }
        //kotak kiri tempj
        for (int i = tempm - 1; i >= tempi + 1; i--)
        {
            if (ii == tempi && jj >= tempj && jj <= tempn - 1) jj++;
            else if (ii >= tempi && ii <= tempm - 1 && jj == tempn) ii++;
            else if (ii == tempm && jj <= tempn && jj >= tempj + 1) jj--;
            else if (jj == tempj && ii <= tempm && ii >= tempi + 1) ii--;
            NewMatrix[ii][jj] = matrix[i][tempj];
        }

        tempi += 1, tempj += 1;
        tempm -= 1, tempn -= 1;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << NewMatrix[i][j];
            if (j < n - 1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}