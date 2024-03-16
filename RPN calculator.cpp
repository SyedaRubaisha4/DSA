#include<iostream>
#include"stack.cpp"
#include<stack>
using namespace std;

bool isOperator(char c)
{
    if(c=='+')
    {
        return true;
    }
    else if(c=='-')
    {
        return true;
    }
        else if(c=='/')
    {
        return true;
    }
        else if(c=='*')
    {
        return true;
    }
        else if(c=='%')
    {
        return true;
    }
    else if(c=='?')
    {
        return true;
    }
    else if(c=='^')
    {
        return true;
    }
    else{
        return false;
    }
}
    void myRpnCalculator()
    {
        float op1,op2;
        int count=0;
        string  opr;
        int choice=0;
        bool check=1;
        Stack<float>s;
        
        cout<<"ENTER 1 IF YOU WANT TO ADD OPERAND \n";
        cout<<"ENTER 2 IF YOU WNAT TO ADD ANY  ANY OPERATOR\n";
        cout<<"ENTER 3 IF YOU WANT TO TERMINATE CALCULATIONS \n";
       cin>>choice;
        while (choice!=3)
        {
           if(choice==1)
           {
                    cout<<"enter operands \n";
                   cin>>opr;
                    
                    if(opr[0]=='-')
                    {

                           int i=1;
                           int number=0;
                            while(opr[i]!='\0')
                            {
                                number=number*10+(int)(opr[i]-'0');
                                i++;
                            }
                           number=number*(-1);
                            s.push(number);
                           count++;
                    } 
                    else 
                    {
                        for(int i=0;i<opr.size();i++)
                        {
                            if(!isdigit(opr[i]))
                            {
                                check=0;
                            }
                        }
                        if(check==0)
                        {
                            cout<<"#\n";
                            cout<<"YOU AHVE ENTERED INCORECT INPUT : TRY AGAIN \n";
                        }
                        else
                        {   
                            int i=0;
                            int number=0;
                            while(opr[i]!='\0')
                            {
                                number=number*10+(int)(opr[i]-'0');
                                i++;
                            }
                            s.push(number);
                            count++;
                        }    
                    }
           }
            else if(choice==2)
            {
                if(s.isEmpty())
                {
                    cout<<s.Top()<<endl;
                    cout<<"#\n";
                    cout<<"YOU DO NOT ENTER ANY OPERANDS IN STACK \n";
                }
                else if(count>=2)
                {
                    char optr;
                    cout<<"ENTER OPERAOTR\n";
                    cin>>optr;
                    check=isOperator(optr);
                    if(check==true)
                    {
                        if(optr=='+')
                        {
                            op1=s.Top();
                            s.pop();
                            count--;
                            op2=s.Top();
                            s.pop();
                            count--;
                            s.push(op2+op1);
                            count++;
                        }
                        else if(optr=='-')
                        {
                            op1=s.Top();
                            s.pop();
                            count--;
                            op2=s.Top();
                            s.pop();
                            count--;
                            s.push(op2-op1);
                            count++;
                        }
                        else if(optr=='*')
                        {
                            op1=s.Top();
                            s.pop();
                            count--;
                            op2=s.Top();
                            s.pop();
                            count--;
                            s.push(op2*op1);
                            count++;
                        }
                        else if(optr=='/')
                        {
                            op1=s.Top();
                            s.pop();
                            count--;
                            op2=s.Top();
                            s.pop();
                            count--;
                            s.push(op2/op1);    
                            count++;

                        }
                        else if(optr=='%')
                        {
                            int op1,op2;
                            op1=s.Top();
                            s.pop();
                            count--;
                            op2=s.Top();
                            s.pop();
                            count--;
                            s.push(op2%op1);
                            count++;
                        }
                        else if(optr=='?')
                        {
                            Stack<int>a;
                            while(!s.isEmpty())
                            {
                                cout<<s.Top()<<endl;
                                a.push(s.Top());
                                s.pop();
                            }
                            while(!a.isEmpty())
                            {
                                
                                s.push(a.Top());
                                a.pop();
                            }
                        }
                        else if(optr=='^')
                        {
                            cout<<"The top most  element in our stack is :"<<s.Top()<<endl;
                        }
                        else{
                        cout<<"# you have entered invlaid operaotr : TRY AGAIN ;)\n";
                    }
                    }
                    
                }
            
                

                else
                {
                 cout<<"ELEMENTS ARE NOT SUFFICIENT TO DO ANY OPERATION\n";
                }
            }
            cout<<"ENTER 1 IF YOU WANT TO ADD OPERAND \n";
            cout<<"ENTER 2 IF YOU WNAT TO ADD ANY  ANY OPERATOR\n";
            cout<<"ENTER 3 IF YOU WANT TO TERMINATE CALCULATIONS \n";
            
            cin>>choice;
        } 
        
    }
int main()
{
    
  myRpnCalculator();
    return 0;;

    
}
