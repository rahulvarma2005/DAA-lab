#include <iostream>
#include <string>

using namespace std;

int w[] ={3,2,2};
float v[] = {1.8,1,1};

int find(int ind,int cap)
{
    if(ind == 0)
    {
        if(w[ind]<=cap)
        {
            return v[ind];
        }
        else
            return 0;
    }

    else
    {
        int not_inc = 0 + find(ind-1,cap);
        int inc = INT_MIN;
        if(w[ind]<=cap)
        {
            inc = v[ind]+find(ind-1,cap-w[ind]);
        }
        return not_inc>inc?not_inc:inc;
    }
}

int main()
{
    int n = 3;
    int capacity = 4;
    cout << find(n-1,capacity);
}
