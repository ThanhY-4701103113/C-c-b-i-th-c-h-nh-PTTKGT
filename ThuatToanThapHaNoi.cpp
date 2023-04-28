//Cài đặt thuật toán tháp Hà Nội

#include <bits/stdc++.h>
using namespace std;

// Hàm đệ quy để di chuyển n đĩa từ cọc A sang cọc C, với cọc trung gian là cọc B
void towerOfHanoi(int n, char A, char C, char B)
{
    if (n == 1) {
        cout << "Di chuyển đĩa 1 từ cọc " << A << " sang cọc " << C << endl;
        return;
    }
    towerOfHanoi(n - 1, A, B, C);
    cout << "Di chuyển đĩa " << n << " từ cọc " << A << " sang cọc " << C << endl;
    towerOfHanoi(n - 1, B, C, A);
}

int main()
{
    int n = 3; // số lượng đĩa ban đầu
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B, C là tên của các cọc
    return 0;
}