#include<iostream>
#include<cmath>
#include"polynomial.h"
using namespace std;
void Polynomial:: addTerm(int coefficient,int power)
    {
        // if(!head)
        // {
        //     Term *p=new Term (coefficient,power);
        //      p->next=head;
        //      head=p;
        // }
        // else{
        //     Term*p=head;
        //     while (p->next!=nullptr)
        //     {
        //         p=p->next;
        //     }
        //     Term* x=new Term(coefficient,power);
        //     p->next=x;
            
        // }

           
             Term *p=new Term (coefficient,power);
           
             if(!head)
             {
                head=p;
                p->next=nullptr;
                return;
             }
            Term * temp=head;
             Term *x=head->next;
             if(p->exp==0)
             {
                while(temp->next!=nullptr)
                {
                    temp=temp->next;
                }
                temp->next=p;
                p->next=nullptr;
             }
             else if(p->exp>head->exp)
             {
                p->next=head;
                head=p;
             }
             else{
                while(x&&x->exp>p->exp)
                {
                    temp=temp->next;
                    x=x->next;
                }
                temp->next=p;
                p->next=x;
             }
             
	}
    

    void Polynomial::dispaly()
    {
        Term* p=head;
        while (p!=nullptr)
        {
            cout<<p->coef<<"x"<<p->exp;

            p=p->next;
            cout<<"+";
        }
        cout<<endl;
    }

    int Polynomial::getdegree()
    {
        Term* p=head;
            if(!head)
            {
                return -1;
            }
            else
            {
                
            return head->exp;
        
            }
                
    }
    int Polynomial::getCoefficient(int power)
    {
        Term* p=head;
        int  coefficient=0;
        while (p!=nullptr)
        {
            if(p->exp==power)
            {
                coefficient=p->coef;
            }
            p=p->next;
        }
        return coefficient;
        
    }
    void Polynomial::Clear()
    {
        Term *p=head;
        while(p!=nullptr)
        {
            p->coef=0;
            p=p->next;
        }
    }
    void Polynomial::addToCoefficient(int val,int power)
    {
        Term* p=head;
        while (p!=nullptr)
        {
            if(p->exp==power)
            {
                p->coef+=val;
            }
            p=p->next;
        }
        
    }
    void Polynomial::derivative()
    {
       Term* p=head;
       
       while (p!=NULL)
       {
          p->coef=p->coef*p->exp;
         if(p->exp==0)
          {
            p->exp=0;
          }
          else
          {
            p->exp -=1;
          }
          p=p->next;
       }
       cout<<endl;   
    }
    Polynomial Polynomial::operator+ (  Polynomial obj) 
    {
        Term * p=head;
        Term * x=obj.head;
        Polynomial ans;
        int c=0;
        int e=0;
        while(p!=nullptr&& x!=nullptr)
        {
           
            if(p->exp==x->exp)
            {
                c=p->coef+x->coef;
                e=p->exp;
                ans.addTerm(c,e);
            }
            else if(p->exp > x->exp)
            {
                c=p->coef;
                e=p->exp;
                ans.addTerm(c,e);
                c=x->coef;
                e=x->exp;
                ans.addTerm(c,e);
            }
            else if(p->exp < x->exp)
            {
                c=x->coef;
                e=x->exp;
                ans.addTerm(c,e);
                c=p->coef;
                e=p->exp;
                ans.addTerm(c,e);
            }

            p=p->next;
            x=x->next;
        }
        ans.dispaly();
        return ans;
    }
     Polynomial Polynomial::operator - (Polynomial obj)
    {
        Term * p=head;
        Term * x=obj.head;
        
        x=obj.head;
        Polynomial ans;
        int c=0;
        int e=0;
        while(p!=nullptr&& x!=nullptr)
        {
            if(p->exp==x->exp)
            {
                c=p->coef -  x->coef;
                e=p->exp;
                ans.addTerm(c,e);
            }
            else if(p->exp > x->exp)
            {
                c=p->coef;
                e=p->exp;
                ans.addTerm(c,e);
                c=x->coef;
                e=x->exp;
                ans.addTerm(c,e);
            }
            else if(p->exp < x->exp)
            {
                c=x->coef;
                e=x->exp;
                ans.addTerm(c,e);
                c=p->coef;
                e=p->exp;
                ans.addTerm(c,e);
            }

            p=p->next;
            x=x->next;
        }
        cout<<endl;
        return ans;
    }
    int Polynomial::evaluate(int val)
    {
        Term * p=head;
        int ans=0;
        while (p!=nullptr)
        {
            ans+=p->coef*(pow(val,p->exp));
            p=p->next;
        }
        return ans;
        
    }
    int main()
    {
        Polynomial p;
        p.addTerm(1,1); 
        p.addTerm(3,4);
        p.addTerm(5,8);
        p.addTerm(-4,9);
        p.dispaly();
        Polynomial x;
        x.addTerm(3,1);
        x.addTerm(8,4);
        x.addTerm(5,8);
        x.addTerm(6,9);
        x.dispaly();
        Polynomial ans=p+x;
        ans.dispaly();
        Polynomial a=p-x;
        a.dispaly();
        
    //     cout<<"degree of polynomial is : "<<p.getdegree()<<endl; 
    //     cout<<"coefficient is of polynomial is : "<<p.getCoefficient(3)<<endl;
    //    // cout<<"cleared the polynomial "<<endl;
    //     //p.Clear();
    //     cout<<"add the coefficient : ";
    //     p.addToCoefficient(10,1);
    //     p.dispaly();
       // cout<<"derivative of polynomial class is ";
        p.derivative();
       // p.dispaly();
    }
