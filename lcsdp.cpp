#include <iostream>
#include <string>
using namespace std;
//string s1 ="star",s2="tear";

int main()
{   
    cout << "M.Rahul Varma" << endl;
    cout << "22BCI0091" << endl;
    string s1,s2;
    cout << "Enter first word: ";
    cin >> s1;
    cout << "Enter second word: ";
    cin >> s2;
    int m=s1.size(), n=s2.size();

    int dp[m+1][n+1];
    int seq[m+1][n+1];

    for(int i=0;i<m+1;i++)
    {
        for(int j=0; j<n+1;j++)
        {
            dp[i][j] =0;
            seq[i][j] =0;
        }
    }
    
    for(int i=1;i<m+1;i++)
    {
        for(int j=1; j<n+1;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
                seq[i][j] =3;
            }
            else{
                int fir = dp[i][j-1];
                int sec = dp[i-1][j];
                dp[i][j] = fir>=sec?fir:sec;
                seq[i][j] = fir>=sec?1:2;
            }

        }
    }
    cout << "Answer: " <<dp[m][n] << endl;

    int i=m,j=n;
    int last=seq[m][n];
    string output=" ";
    while(i!=0&&j!=0)
    {
        if(last==3)
        {
            output.append(s1.substr(i-1,1));
            i--;j--;
        }
        else if(last==1)
            j--;
        else if(last==2)
            i--;
        last=seq[i][j];
    }

    cout << "Longest common subsequence: ";
    for(int i=output.size()-1;i>=0;i--){
    cout << output[i];}

}

