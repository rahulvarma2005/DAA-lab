#include <iostream>

using namespace std;

int main()
{
    cout << "M.Rahul Varma" << endl;
    cout << "22BCI0091" << endl;

    int num;
    cout << "Enter the number of elements of the array: ";
    cin >> num;

    int r[num];
    cout << "Enter the elements of the array: ";
    
    for(int i=0;i<num;i++)
    {
        cin >> r[i];
    } 
    // int r[] ={13,5,89,3,34};
    int n = num-1;
    //int n=4;

    int c[n][n] = {0};
    for(int diff = 2; diff <=n; diff++)
    {
        for(int i=0;i<n-diff+1;i++)
        {
            int j = i+diff-1;
            int min = INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                int q = c[i][k]+c[k+1][j]+r[i]*r[k+1]*r[j+1];
                if(q<min)
                min=q;
            }
            c[i][j]=min;
           // cout << c[i][j] << endl;
        }
    }
    /* for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << "Minimum cost: "<< c[0][n-1] << endl;
}