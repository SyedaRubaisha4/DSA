#include<iostream>
#include<queue>
using namespace std;





bool search(queue<int>q,int no,int size )
{
    
  for(int i=0;i<size;i++)
  {
    if(q.front()==no)
    {
        return true;
    }
    q.pop();
  }
  return false;
}
void printQueue(queue<int>q,int size)
{
  cout<<"pages in memory is : ";
  for(int i=0;i<size;i++)
  {
    cout<<q.front()<<" ";
    q.pop();
  }
   cout<<endl;
}
void pageReplacementalgo()
{
   int size=3;
   cout<<"enter  the size of the memory queue \n";
   cin>>size;
   queue<int>q;
   int page,choice=0,pageHit=0,pageFault=0;
   bool s;
    while(choice!=-1)
    {
      cout<<" enter pages in memory \n";
      cin>>page;
      s=search(q,page,size);
      if(s==false)
      {     
        pageFault++;
        if(pageFault>size)
        {
          q.pop();
          q.push(page);
          printQueue(q,size);
        }
        else
        {
         q.push(page); 
         printQueue(q,q.size());
        }
      }
      else
      {
        pageHit++;
        printQueue(q,size);
      }
    
      cout<<" enter -1 to stop and otter than it to continue\n";
      cin>>choice;
    }


    cout<<"page faults are: "<<pageFault<<endl;
    cout<<"page hits are: "<<pageHit<<endl;
}
int main()
{
    //pageReplacementalgo();
    int j=2;
    while(j>=1)
    {
      j=j-1;
      cout<<j<<endl;
      cout<<"surprise \n";
    }
    return 0;
}