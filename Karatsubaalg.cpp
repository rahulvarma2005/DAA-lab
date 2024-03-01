#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int karat(int a, int b)
{
    string as = to_string(a);
    string bs  = to_string(b);
    int alen = as.length();
    int blen = bs.length();

    if(alen == 1 && blen == 1)
    {
        return a*b;
    }
    else
    {
        int n = alen>blen?alen:blen;
        int m = ceil(n/2.0);

        while(alen != n)
        {
            as = "0" + as;
            alen++;
        }
        while(blen != n)
        {
            bs = "0" + bs;
            blen++;
        }

        int aL = stoi(as.substr(0,n/2));
        int aR = stoi(as.substr(n/2,n-n/2));
        int bL = stoi(bs.substr(0,n/2));
        int bR = stoi(bs.substr(n/2,n-n/2));

        int x1 = karat(aL,bL);
        int x2 = karat(aL+aR,bL+bR);
        int x3 = karat(aR,bR);

        return x1*pow(10,2*m)+(x2-x1-x3)*pow(10,m)+x3;
    }
}

int main()
{
    cout << "M.Rahul Varma" << endl;
    cout << "22BCI0091" << endl;

    int n1,n2;
    cout << "Enter first number: ";
    cin >> n1;
    cout << "Enter second number: ";
    cin >> n2;
    cout << "Solution: " << karat(n1,n2);  //1948,2215
}
