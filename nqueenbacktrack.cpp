#include <iostream>
using namespace std;

bool found = false;

bool issafe(int r, int c,int **chess,int n) {
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
    for (int i = r, j = c; i < n && j >= 0; i++, j--) {
        if (chess[i][j] == 1) {
            return false;
        }
    }
    return true;
}

void print(int n,int **chess) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chess[i][j] == 1) {
                cout << "Q ";
            } else
                cout << "- ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int c,int **chess,int n) {
    if (c == n) {
        found = true;
        print(n,chess);
        return;
    } else {
        for (int i = 0; i < n; i++) {
            if (issafe(i, c,chess,n)) {
                chess[i][c] = 1;
                solve(c + 1,chess,n);
                
                chess[i][c] = 0;
            }
        }
    }
}

int main() {
    cout << "M.Rahul Varma" << endl;
    cout << "22BCI0091" << endl;
    int n;
    cout << "Enter the length of the chess board: ";
    cin >> n;
    int **chess=new int*[n];

    for(int i=0;i<n;i++)
        chess[i]=new int[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            chess[i][j]=0;
        }
    }
    cout << "Chess Board representations: " << endl;
    solve(0,chess,n);
}