#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Node
{
    float val,w;
    float ratio;
}Item;

bool compareRatio(const Item &a, const Item &b) {
    return a.ratio > b.ratio;
}

int main()
{   
    cout << "M.Rahul Varma" << endl;
    cout << "22BCI0091" << endl;
  //  Item a[] = {{60,10},{100,20},{120,30}};

    int n,cap;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity: ";
    cin >> cap;

    Item a[n];
    cout << "Enter the values in order: ";
    for(int i=0;i<n;i++)
    {
        cin >> a[i].val;
    }
    cout << "Enter the weights in order: ";
    for(int i=0;i<n;i++)
    {
        cin >> a[i].w;
    }
   //int n=3, cap=50;
    for(int i=0;i<n;i++)
    {
        a[i].ratio=a[i].val/a[i].w;
    }

    float amt =0;
   // sort(a, a + n, compareRatio);

    for(int i=0;i<n-1;i++)
    {
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j].ratio>a[index].ratio)
                index=j;
        }
      //  swap(a[i],a[index]);


        Item temp=a[i];
        a[i] = a[index];
        a[index]=temp;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i].w <=cap)
        {
            amt +=a[i].val;
            cap-=a[i].w;
        }
        else
        {
            amt +=(cap/a[i].w)*a[i].val;
            cap=0;
        }
    }
    cout << "Total Amount: " << amt;
}