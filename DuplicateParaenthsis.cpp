#include<iostream>
#include<stack>
using namespace std;

bool duplicateParebthesis(string str)
{
    stack<char> s;
    int i=0,count=0;
    while(i<str.length())
    {
        if(str[i]=='(')
        {
            s.push(str[i]);
            count++;
            if(str[++i]=='(')
            {
                s.push(str[i]);
                count++;
                //cout<<count<<endl;
            }
            else{
                 break;
            }
           
        }
        if(str[i]==')' && s.stacktop()=='(')
        {
            count--;
            s.pop();   
            if(str[++i]==')'&& s.stacktop()=='(')
            {
                count--;
                s.pop();
                 // cout<<count<<" after -- "<<endl;
            }

        }
        i++;
    }
    if(count==0)
    {
        return true;

    }
    else{
        return false;
    }
}