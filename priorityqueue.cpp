#include <queue>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    priority_queue<int> pq;  //

    pq.push(20); //push in decending order because it is implemented by default in max heap in order 20,15,10,5
    pq.push(10);
    pq.push(5);
    pq.push(15);

    while(!pq.empty())
    {
        cout<<pq.top();
        pq.pop();
    }
}