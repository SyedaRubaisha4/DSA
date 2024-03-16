#include<iostream>
#include<stack>
using namespace std;
int findIndex(int * arr, int size,int key)
{
   for(int i=0;i<size;i++)
   {
    if(arr[i]==key)
    {
        return i;
    }
   }
}
void postfix(string s)
{
    stack<int>st;
    int i=0;
    while(i<s.length())
    {
        if(s[i]>='0'&& s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else{
            int op1=st.stacktop();
            st.pop();
            int op2=st.stacktop();
            st.pop();
            
            
        }
    }
}

// task 4
void nextGreater(int  *arr,int size)
{
            stack<int>s;
            stack<int>x;
            int index=0,i;
            for( i=0;i<size;i++)
            {
                s.push(arr[i]);
            }
            int * start=&arr[0];
    

           for( i=0;i<size;i++)
           {
             index=findIndex(arr,size,s.stacktop());
             if(index==size-1)
             {
                for(int j=0;j<index;j++)
                {
                    if(arr[j]>s.stacktop())
                    {
                        x.push(arr[j]);
                        s.pop();
                        break;
                    }
                }
             }
             else{
                for (int j = index,y=0; j < size; j++)
                {
                    index=s.stacktop();
                    if(arr[j]>s.stacktop())
                    {
                        x.push(arr[j]);
                        s.pop();
                        break;
                    } 
                   else if(j==size-1&&index==s.stacktop())
                    {
                        if(start[y]>s.stacktop())
                        {
                            x.push(start[y]);
                            s.pop();
                            break;
                        }
                    }
                } 
                if(index==s.stacktop())
                {
                    x.push(-1); 
                    s.pop();
                }  
            }
            }


        for(int i=0;i<size;i++)
        {
            cout<<x.stacktop()<<" ";
            x.pop();
        }

}