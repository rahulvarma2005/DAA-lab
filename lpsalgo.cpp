#include <iostream>

using namespace std;

void calcLPS(string p, int LPS[])
{
    LPS[0] = 0;
    int i=0,j=1;

    while(j<p.length())
    {
        if(p[i]==p[j])
        {
            LPS[j]=i+1;
            i++;
            j++;
        }
        else
        {
            if(i==0)
            {
                LPS[j]=0;
                j++;
            }
            else
            {
                i=LPS[i-1];
            }
        }
    }
}

int main()
{
    string p = "abababc";
    int LPS[p.length()]={0};

    calcLPS(p,LPS);
}