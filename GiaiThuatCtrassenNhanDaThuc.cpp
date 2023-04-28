#include <iostream>
#include <vector>

using namespace std;

vector<int> addPoly(vector<int> A, vector<int> B) {
    vector<int> C;
    int n = A.size(), m = B.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] > B[j]) {
            C.push_back(A[i]);
            i++;
        } else if (A[i] < B[j]) {
            C.push_back(B[j]);
            j++;
        } else {
            C.push_back(A[i]);
            i++;
            j++;
        }
    }
    while (i < n) {
        C.push_back(A[i]);
        i++;
    }
    while (j < m) {
        C.push_back(B[j]);
        j++;
    }
    return C;
}

vector<int> subPoly(vector<int> A, vector<int> B) {
    vector<int> C;
    int n = A.size(), m = B.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] > B[j]) {
            C.push_back(A[i]);
            i++;
        } else if (A[i] < B[j]) {
            C.push_back(-B[j]);
            j++;
        } else {
            i++;
            j++;
        }
    }
    while (i < n) {
        C.push_back(A[i]);
        i++;
    }
    while (j < m) {
        C.push_back(-B[j]);
        j++;
    }
    return C;
}

vector<int> multiplyPoly(vector<int> A, vector<int> B) {
    int n = A.size(), m = B.size();
    vector<int> C(n + m - 1, 0);
    if (n <= 4 || m <= 4) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                C[i+j] += A[i] * B[j];
            }
        }
        return C;
    }
    int k = (n + 1) / 2;
    vector<int> A1(A.begin(), A.begin() + k);
    vector<int> A2(A.begin() + k, A.end());
    vector<int> B1(B.begin(), B.begin() + k);
    vector<int> B2(B.begin() + k, B.end());
    vector<int> C1 = multiplyPoly(A1, B1);
    vector<int> C2 = multiplyPoly(A2, B2);
    for (int i = 0; i < k; i++) {
        A1[i] += A2[i];
        B1[i] += B2[i];
    }
    vector<int> C3 = multiplyPoly(A1, B1);
    vector<int> C4 = subPoly(C3, addPoly(C1, C2));
    for (int i = 0; i < C1.size(); i++) {
        C[i] += C1[i];
    }
    for (int i = 0; i < C2.size(); i++) {
        C[n - k + i] += C2[i];
    }
    for (int i = 0; i < C4.size(); i++) {
        C[k
