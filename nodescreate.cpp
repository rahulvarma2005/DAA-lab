#include <queue>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct stud
{
    int age,ht;
    stud(int a,int h)
    {
        age = a; ht=h;
    }
};

struct compare
{
    bool operator()(struct stud s1,struct stud s2)
    {
        return(s1.ht>s2.ht);
    }
};

int main()
{
    priority_queue<struct stud, vector<struct stud>,compare> pq;
    pq.push(stud(30,70));
    pq.push(stud(40,65));

    struct stud temp = pq.top();
    //40,65  //depends on the height of struct
    //30,70
    cout << temp.ht << temp.age;
}
