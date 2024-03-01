#include <iostream>

using namespace std;

int n;
int chess[n][n] = {0};
bool found = false;

bool issafe(int r, int c) {
    for (int j = c; j >= 0; j--) {
        if (chess[r][j] == 1) {
            return false;
        }
    }
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (chess[i][j] == 1) {
            return false;
        }
    }
    for (int i = r, j = c; i <= n && j >= 0; i++, j--) {
        if (chess[i][j] == 1) {
            return false;
        }
    }
    return true;
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chess[i][j] == 1) {
                cout << "Q ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
}

void solve(int c) {
    if (c == n) {
        found = true;
        print();
        return;
    } else {
        for (int i = 0; i < n; i++) {
            if (issafe(i, c)) {
                chess[i][c] = 1;
                solve(c + 1);
                if (found) { // If a solution is found, stop searching
                    return;
                }
                chess[i][c] = 0;
            }
        }
    }
}

int main() {
    // Get input for n
    cout << "Enter the size of the chessboard (n): ";
    cin >> n;

    // Validate input (optional)
    if (n <= 0) {
        cout << "Invalid input: n must be a positive integer." << endl;
        return 1;
    }

    solve(0);
    return 0;
}