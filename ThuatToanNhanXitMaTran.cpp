#include <iostream>
using namespace std;

const int MAX = 100;

// Hàm nhập ma trận
void nhapMaTran(int a[][MAX], int &n, int &m)
{
    cout << "Nhap so hang: ";
    cin >> n;
    cout << "Nhap so cot: ";
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

// Hàm xuất ma trận
void xuatMaTran(int a[][MAX], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// Hàm nhân ma trận
void nhanMaTran(int a[][MAX], int b[][MAX], int c[][MAX], int n, int m, int p)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int n, m, p;

    cout << "Nhap ma tran A: " << endl;
    nhapMaTran(a, n, m);

    cout << "Nhap ma tran B: " << endl;
    nhapMaTran(b, m, p);

    nhanMaTran(a, b, c, n, m, p);

    cout << "Ket qua nhan ma tran A x B: " << endl;
    xuatMaTran(c, n, p);

    return 0;
}
