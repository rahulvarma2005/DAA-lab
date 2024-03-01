#include <iostream>
#include <stack>
using namespace std;

    // int n=5;
    //int target=80;
    // int a[]={10,20,30,40,50};

bool found=false;
stack<int> org,temp;
void print()
{
    while(!org.empty())
    {
        temp.push(org.top());
        org.pop();
    }
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        org.push(temp.top());
        temp.pop();
    }
    cout << endl;
}

void solve(int cursum,int index,int target,int n,int a[])
{
    if(cursum >target)
        return;
    if(cursum==target)
    {
        found=true;
        print();
        return;
    }
    for(int i=index;i<n;i++)
    {
        org.push(a[i]);
        solve(cursum+a[i],i+1,target,n,a);
        org.pop();
    }
}
int main()
{
    cout << "M.Rahul Varma" << endl;
    cout << "22BCI0091" << endl;
    int n,target;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the target sum: ";
    cin>>target;

    int a[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout << "Solution Subsets: " << endl;
    solve(0,0,target,n,a);

    if(found == false)
        cout<<"No solution";
}