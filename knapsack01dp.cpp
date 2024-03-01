#include <iostream>
using namespace std;

int main()
{
    cout << "M.Rahul Varma" << endl;
    cout << "22BCI0091" << endl;
    int n,cap;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the bag: ";
    cin >> cap;

    int w[n];
    float v[n];

    cout << "Enter the weight of each item: ";
    for(int i=0;i<n;i++)
    {
        cin >> w[i];
    }

        cout << "Enter the value of each item: ";
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    }
   //int w[] ={3,2,2};
    //float v[] = {1.8,1,1};
    //int n=3,cap=4;

    int dp[n+1][cap+1];
    for(int i = 0;i<n+1;i++)
    {
        dp[i][0]=0;
    }
    for(int i = 0;i<cap+1;i++)
    {
        dp[0][i]=0;
    }

    for(int i = 1;i<n+1;i++)
    {
        for(int j = 1;j<cap+1;j++)
        {
            int not_inc = 0+dp[i-1][j];
            int inc = -9999;

            if(w[i]<=j)
                inc = v[i]+dp[i-1][j-w[i]];
            dp[i][j]=inc>not_inc?inc:not_inc;
        }
    }
    cout << "Answer: " << dp[n][cap] << endl;

    return 0;
}