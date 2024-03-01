    #include<iostream>
    using namespace std;
    int main()
    {
    int n;
    cout << "M.Rahul Varma" << endl;
    cout << "22BCI0091" << endl;
    cout << "Enter the number of stations in each belt: ";
    cin >> n;
    int e[2], x[2];
    cout << "Enter entry times for each line (e0, e1): ";
    cin >> e[0] >> e[1];
    cout << "Enter exit times for each line (x0, x1): ";
    cin >> x[0] >> x[1];
    int a[2][n], t[2][n];
    t[0][0]= 0;
    t[1][0]= 0;
    
    cout << "Enter assembly times for belt 1: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[0][i];
    }

    cout << "Enter assembly times for belt 2: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[1][i];
    }

    cout << "Enter transfer times from belt 1 to belt 2: ";
    for (int i = 1; i < n; i++)
    {
        cin >> t[0][i];
    }

    cout << "Enter transfer times from belt 2 to belt 1: ";
    for (int i = 1; i < n; i++)
    {
        cin >> t[1][i];
    }

    int dp[2][n], path[2][n];
    dp[0][0] = e[0] + a[0][0];
    dp[1][0] = e[1] + a[1][0];
    path[0][0] = 0;
    path[1][0] = 1;

    for (int j = 1; j < n; j++)
    {
        int c1 = dp[0][j - 1] + a[0][j];
        int c2 = dp[1][j - 1] + t[1][j] + a[0][j];
        dp[0][j] = c1 <= c2 ? c1 : c2;
        path[0][j] = c1 <= c2 ? 0 : 1;
        int c3 = dp[0][j - 1] + t[0][j] + a[1][j];
        int c4 = dp[1][j-1] + a[1][j];
        dp[1][j] = c3 <= c4 ? c3 : c4;
        path[1][j] = c3 <= c4 ? 0 : 1;
    }

    int f0 = dp[0][n - 1] + x[0];
    int f1 = dp[1][n - 1] + x[1];
    int f = f0 <= f1 ? f0 : f1;
    cout << "Minimum time to exit: " << f << endl;
    int last = f0 <= f1 ? 0 : 1;
    cout << "Vehicle exited from station " << last << endl;
    }