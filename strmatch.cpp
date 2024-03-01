#include <iostream>
using namespace std;

int main()
{
    string s = "abcbabbabc",p="abb";

    int slen = s.length();
    int plen = p.length();

    int i,j,flag=0;

    for(i=0;i<=(slen-plen);i++)
    {
        j =0;
        while(j<plen && p[j]==s[i+j])
        {
            j++;
        }
        if(j==plen)
        {
            flag = 1;
            cout << i << " ";
        }
    }

    if(flag ==0)
    {
        cout << "pattern not found";
    }
}


















































// shows the index where the pattern starts in the given question string