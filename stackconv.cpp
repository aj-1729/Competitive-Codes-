#include<bits/stdc++.h>
#define int long long
#define MXI 1000000007LL
using namespace std;

bool operand(char x)
{
   if((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9')) 
      return 1;

   return 0;
}

int priority(char x)
{
   if(x == '^') return 2;
   if(x == '*' || x == '/') return 1;
   if(x == '+' || x == '-') return 0;
   else return -1;
}

string infix_to_postfix(string s)
{
   int n = s.size();
   stack<char> st;
   string ans = "";
   int i = 0;
   while(i < n)
   {
      if(operand(s[i])) ans += s[i];
      else if(s[i] == '(') st.push('(');
      else if(s[i] == ')')
      {
         while(!st.empty() && st.top() != '(')
         {
            ans += st.top();
            st.pop();
         }
         st.pop();
      }
      else
      {
         while(!st.empty() && priority(s[i]) <= priority(st.top()))
         {
            ans += st.top();
            st.pop();
         }
         st.push(s[i]);
      }
      i++;
   }
   while(!st.empty()) 
   {
      ans += st.top();
      st.pop();
   }

   return ans;
}

string infix_to_prefix(string s)
{
   reverse(s.begin() , s.end());
   int n = s.size();

   for (int i = 0; i < n; i++)
   {
      if(s[i] == '(') s[i] = ')';
      else if(s[i] == ')') s[i] = '(';
   }

   stack<char> st;
   string ans = "";
   int i = 0;
   while(i < n)
   {
      if(operand(s[i])) ans += s[i];
      else if(s[i] == '(') st.push('(');
      else if(s[i] == ')')
      {
         while(!st.empty() && st.top() != '(')
         {
            ans += st.top();
            st.pop();
         }
         st.pop();
      }
      else
      {
         if(s[i] == '^')
         {
            while(!st.empty() && priority(s[i]) <= priority(st.top()))
            {
               ans += st.top();
               st.pop();
            }
            st.push(s[i]);
         }
         else
         {
            while(!st.empty() && priority(s[i]) < priority(st.top()))
            {
               ans += st.top();
               st.pop();
            }
            st.push(s[i]);
         }
      }
      i++;
   }
   while(!st.empty()) 
   {
      ans += st.top();
      st.pop();
   }

   reverse(ans.begin() , ans.end());

   return ans;
}

string postfix_to_infix(string s)
{
   int n = s.size();
   stack<string> st;
   int i = 0;
   while(i < n)
   {
      if(operand(s[i])) st.push(string(1, s[i]));
      else
      {
         string t1 = st.top();
         st.pop();
         string t2 = st.top();
         st.pop();

         string ans = '(' + t2 + s[i] + t1 + ')';

         st.push(ans);

      }
      i++;
   }

   return st.top();
}

string prefix_to_infix(string s)
{
   int n = s.size();
   stack<string> st;
   int i = n - 1;
   while(i >= 0)
   {
      if(operand(s[i])) st.push(string(1, s[i]));
      else
      {
         string t1 = st.top();
         st.pop();
         string t2 = st.top();
         st.pop();

         string ans = '(' + t1 + s[i] + t2 + ')';

         st.push(ans);

      }
      i --;
   }

   return st.top();
}

string postfix_to_prefix(string s)
{
   int n = s.size();
   stack<string> st;
   int i = 0;
   while(i < n)
   {
      if(operand(s[i])) st.push(string(1, s[i]));
      else
      {
         string t1 = st.top();
         st.pop();
         string t2 = st.top();
         st.pop();

         string ans = string(1, s[i]) + t2 + t1;

         st.push(ans);

      }
      i ++;
   }

   return st.top();
}

string prefix_to_postfix(string s)
{
   int n = s.size();
   stack<string> st;
   int i = n - 1;
   while(i >= 0)
   {
      if(operand(s[i])) st.push(string(1, s[i]));
      else
      {
         string t1 = st.top();
         st.pop();
         string t2 = st.top();
         st.pop();

         string ans = t1 + t2 + string(1, s[i]);

         st.push(ans);

      }
      i --;
   }

   return st.top();
}


int32_t main(){

   ios::sync_with_stdio(false); 
   cin.tie(NULL);

   /*

   */
   string s = "AB-DE+F*/";

   string ans = postfix_to_prefix(s);

   cout << ans << endl;

   return 0;
}