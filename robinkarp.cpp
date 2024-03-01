#include <iostream>
#define prime 13

using namespace std;

int main()
{
    string s = "ABCCDDAEFGCDDF";
    string p ="CDD";
    int slen=s.length(),plen=p.length();
    int sh=0,ph=0,h=1,maxchar=10;

    for(int i=0;i<plen-1;i++)
    {
        h=(h*maxchar)%prime;
    }
    for(int i=0;i<plen;i++)
    {
        sh =(sh*maxchar+s[i]-65+1)%prime;
        ph=(ph*maxchar+s[i]-65+1)%prime;
    }
    for(int i=0;i<slen-plen;i++)
    {
        if(sh==ph)
        {
            int flag=0,count=0;
            for(int j=0;j<plen;j++)
            {
                if(s[i+j] == p[j])
                count++;

                else
                break;
            }
            
            if(count==plen)
            {
                flag=1;
                cout << "found at " << i << endl;
            }
        }

        sh=((sh-(s[i]-65+1)*h)*maxchar+s[i+plen]-65+1)%prime;

        while(sh<0)
        {
            sh +=prime;
        }
    }
}
