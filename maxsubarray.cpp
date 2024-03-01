#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int crosssum(int a[], int l, int mid, int h)
{
    int left = -9999,right = -9999;
    int s=0;
    for(int i = mid; i>=l ; i--)
    {
        s+=a[i];
        if(s>left)
        {
            left = s;
        }
    }
    s = 0;

    for(int i = mid+1; i<=h ; i++)
    {
        s+=a[i];
        if(s>right)
        {
            right = s;
        }
    }
    return (left+right);
}

int maxsum(int a[], int l, int h)
{
    if(l == h)
    {
        return a[l];
    }
    else
    {
        int mid = (l+h)/2;
        int ls = maxsum(a,l,mid);
        int rs = maxsum(a,mid+1,h);
        int cs = crosssum(a,l,mid,h);
        int temp = ls>rs?ls:rs;

        return(temp>cs?temp:cs);
    }
}

int main()
{
    cout << "M.Rahul Varma" << endl;
    cout << "22BCI0091" << endl;
    int n;
    cout << "Enter the size of the array: ";
    cin>>n;
    int a[n];

    cout << "Enter the array: ";
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    } //{-2,-5,6,-2,-3,1,5,-6};
    cout << "Sum: " << maxsum(a,0,n-1);   //a,0,7
}