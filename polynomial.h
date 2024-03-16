#include<iostream>
using namespace std;
 class Polynomial;


class Term
{
 friend Polynomial;
 private:
 int exp;
 int coef;
 Term* next;
 Term(int val,int p)
 {
    coef=val;
    exp=p;
    next=nullptr;
 }
};
class Polynomial
{
 private:
 Term* head;
 public:
 Polynomial()
 {
   head=nullptr;
 }
 void deleteAthead()
 {
   Term * temp=head;
   head=head->next;
    delete temp;
 }
 ~Polynomial()
 {
   if(head)
   {
      while (head)
      {
        deleteAthead();
      }
   }    
}
Polynomial& operator=(const Polynomial& ref)
	{
		if (this == &ref)
		return  *this;
		Term * p =head;
        Term* x=ref.head;
        while (p!=nullptr&& x!=nullptr)
        {
            p->coef=x->coef;
            p->exp=x->exp;
            p=p->next;
            x=x->next;
        }
	
		return *this;
	}
 void addTerm(int coefficient,int power);
    
    int getdegree();
  int getCoefficient(  int power );
  int  evaluate (int value );
  void  Clear ( );
  void  addToCoefficient(int coefficient,int power );
  void derivative ( );
  Polynomial operator+(  Polynomial  obj) ;
  void dispaly();
  Polynomial operator-(Polynomial obj);

};
