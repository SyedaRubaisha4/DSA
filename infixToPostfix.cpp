#include<iostream>
#include<stack>
using namespace std;
void infixToPostfix(string str)
{
    stack<char> s;
    int i=0;
    string pos;
    while(i<str.length())
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            pos+=str[i];
        }
        else if(str[i]=='(')
        {
            s.push(str[i]);
        }
        else if(str[i]==')')
        {
            while(s.stacktop()!='(')
            {
                pos+=s.stacktop();
                s.pop();
            }
        }
        else{
                if(s.isEmpty()||prec(s.stacktop())<prec(str[i]))
                {
                    s.push(str[i]);
                }
                else
                {
                    while(!s.isEmpty())
                    {    
                        pos+=s.stacktop();
                        s.pop();
                    }
                    s.push(str[i]);
                }
        }
        i++;
    }

    while(!s.isEmpty())
    {
        pos+=s.stacktop();
        s.pop();
    }
    for(int i=0;i<pos.length();i++)
    {
        if(pos[i]=='(')
        {
            pos[i]=' ';
        }
    }
    cout<<pos<<endl;
}