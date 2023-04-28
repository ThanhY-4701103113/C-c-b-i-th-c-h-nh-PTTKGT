#include <iostream>
#include <cstring>
using namespace std;

// Hàm tìm chuỗi chung dài nhất
string LCS(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();
    int L[m + 1][n + 1];

    // Tính ma trận LCS
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    // Tìm chuỗi chung dài nhất
    int len = L[m][n];
    char lcs[len + 1];
    lcs[len] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[len - 1] = str1[i - 1];
            i--;
            j--;
            len--;
        }
        else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return string(lcs);
}

int main()
{
    string str1, str2;

    cout << "Nhap chuoi 1: ";
    getline(cin, str1);

    cout << "Nhap chuoi 2: ";
    getline(cin, str2);

    cout << "Chuoi chung dai nhat: " << LCS(str1, str2) << endl;

    return 0;
}