#include <iostream>
using namespace std;

// Hàm đổi tiền
void doiTien(int tien)
{
    int to500k, to200k, to100k, to50k, to20k, to10k, to5k, to2k, to1k;
    to500k = tien / 500000;
    tien %= 500000;
    to200k = tien / 200000;
    tien %= 200000;
    to100k = tien / 100000;
    tien %= 100000;
    to50k = tien / 50000;
    tien %= 50000;
    to20k = tien / 20000;
    tien %= 20000;
    to10k = tien / 10000;
    tien %= 10000;
    to5k = tien / 5000;
    tien %= 5000;
    to2k = tien / 2000;
    tien %= 2000;
    to1k = tien / 1000;

    cout << "So to tien 500k: " << to50k << endl;
    cout << "So to tien 200k: " << to20k << endl;
    cout << "So to tien 100k: " << to10k << endl;
    cout << "So to tien 50k: " << to50k << endl;
    cout << "So to tien 20k: " << to20k << endl;
    cout << "So to tien 10k: " << to10k << endl;
    cout << "So to tien 5k: " << to5k << endl;
    cout << "So to tien 2k: " << to2k << endl;
    cout << "So to tien 1k: " << to1k << endl;
}

int main()
{
    int tien;

    cout << "Nhap so tien can doi: ";
    cin >> tien;

    doiTien(tien);

    return 0;
}
