#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
vector<int> cols(N); // cols[i] là vị trí của con hậu trong cột i

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cols[j] == i) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isValid(int row, int col) {
    for (int i = 0; i < col; i++) {
        // Kiểm tra các con hậu ở cột i đã được đặt và có ảnh hưởng tới con hậu mới đặt ở hàng row, cột col
        if (cols[i] == row) return false; // Kiểm tra hàng
        if (cols[i] - i == row - col) return false; // Kiểm tra đường chéo phụ
        if (cols[i] + i == row + col) return false; // Kiểm tra đường chéo chính
    }
    return true;
}

void solve(int col) {
    if (col == N) {
        printBoard(); // Tìm được cách đặt con hậu
        return;
    }
    for (int row = 0; row < N; row++) {
        if (isValid(row, col)) {
            cols[col] = row;
            solve(col + 1); // Đệ quy để tìm cách đặt các con hậu tiếp theo
        }
    }
}

int main() {
    solve(0); // Bắt đầu từ cột 0
    return 0;
}