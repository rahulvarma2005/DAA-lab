#include <iostream>

using namespace std;

string s1 ="star",s2="tear";

int LCS(int m, int n)
{
    if(m==0||n==0)
        return 0;
    if(s1[m-1]==s2[n-1])
        return 1+LCS(m-1,n-1);
    else
    {
        int first = LCS(m,n-1);
        int second = LCS(m-1,n);
        return first > second?first:second;
    }
}

int main()
{
    int m = s1.size();
    int n = s2.size();

    cout << LCS(m,n);
}