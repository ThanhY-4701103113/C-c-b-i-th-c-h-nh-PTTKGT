#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void quickSort(int arr[], int n) {
    stack<int> s;
    int low = 0, high = n - 1;

    s.push(low);
    s.push(high);

    while (!s.empty()) {
        high = s.top();
        s.pop();
        low = s.top();
        s.pop();

        int pivotIndex = (low + high) / 2;
        int pivot = arr[pivotIndex];

        int i = low, j = high;
        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }

            while (arr[j] > pivot) {
                j--;
            }

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (low < j) {
            s.push(low);
            s.push(j);
        }

        if (i < high) {
            s.push(i);
            s.push(high);
        }
    }
}

int main() {
    int arr[] = {9, 3, 5, 1, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}