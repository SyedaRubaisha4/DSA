#include<iostream>
#include<stack>
using namespace std;

bool balancedParaenthesis(string str)
{
    stack<char> s;
    int i=0;
    while(i<str.length())
    {
        if(str[i]=='('|| str[i]=='{' || str[i]=='[')
        {
            s.push(str[i]);
        }
        else {
        
            if(str[i]==')'&& s.stacktop()=='(')
            {
                s.pop();
            }
             else if (str[i]=='}'&& s.stacktop()=='{')
             {
               s.pop();
             }
             
             else if (str[i]==']'&& s.stacktop()=='[')
             {
               s.pop();
             }
        }
        i++;
    }
    if(!s.isEmpty())
    {
        return false;
    }
    else{
    return true;
    }
}
 