#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char letter; int freq;
    Node *left,*right;
    Node(char l,int f)
    {
        letter = l;
        freq = f; left=NULL; right=NULL;
    }
};

struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return (a->freq>b->freq);
    }
};

void printcode(Node *root,string s)
{
    if(root != NULL)
    {
        if(root -> letter!='*')
        {
            cout << root->letter <<" = " << s << endl;
        }
        printcode(root->left,s+"0");
        printcode(root->right,s+"1");
    }
}

void Huffmann(char c[],int f[],int n)
{
    struct Node *lchild;
    struct Node *rchild;
    priority_queue<Node*, vector<Node*>,compare> pq;

    for(int i=0;i<n;i++)
    {
        pq.push(new Node(c[i],f[i]));
    }
    while(pq.size()!=1)
    {
        lchild = pq.top();
        pq.pop();
        rchild = pq.top();
        pq.pop();

        struct Node *temp = new Node('*',lchild->freq+rchild->freq);
        temp->left = lchild;
        temp->right = rchild;
        pq.push(temp);
    }
    printcode(pq.top(),"");
}

int main()
{
    cout << "M.Rahul Varma" << endl;
    cout << "22BCI0091" << endl;
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;
    char letter[n];
    int freq[n];
    cout << "Enter the character: ";
    for(int i=0;i<n;i++)
    {
        cin >> letter[i];
    }
    cout << "Enter the frequency: ";
    for(int i=0;i<n;i++)
    {
        cin >> freq[i];
    }
   // int n=6,freq[]={5,9,12,13,16,15};
    //char letter[]={'A','B','C','D','E','F'};
    cout << "The Huffmann code is: " << endl;
    Huffmann(letter,freq,n);
}