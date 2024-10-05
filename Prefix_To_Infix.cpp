#include<iostream>
#include<stack>
#include<string>
using namespace std;
void prefix_to_infix(string s)
{
           stack<int>s1;
           string op1,op2;
           string temp;
           for(int i=s.length()-1;i>=0;i--)
           {
                      if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
                      {
                                 op1=s1.top();
                                 s1.pop();
                                 op2=s1.top();
                                 s1.pop();
                                 temp="("+op1+s[i]+op2+")";
                                 s1.push(temp);
                      }
                      else
                                 s1.push(s[i]);
           }
           cout<<"STRING:";
           cout<<s1.top();
}
int main()
{
           string s="K+L-M*N+(O^P)*W/U/V*T+Q";
           prefix_to_infix(s);
           return 0;
}
