#include<iostream>
#include<queue>
using namespace std;

string removelastitem(string s)
{
   
    for(int i=s.length()-1;i>=0;i--)
    {
        s[i]=s[i-1];
      
    }
   
    return s;
}

void binaryNumbers(int n)
{
    queue<string>q;
    string a;
    q.push("1");
    for(int i=1;i<=n;i++)
    {
       a=q.front();
        cout<<q.front()<<endl;
        q.pop();
        a=a+"0";
        q.push(a);
        a=removelastitem(a);
        a=a+"1";
        q.push(a);
        a=removelastitem(a);
         

     }
     // print queue

    for(int i=1;i<=q.size();i++)
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    
}

int main()
{
    binaryNumbers(4);
    return 0;
}