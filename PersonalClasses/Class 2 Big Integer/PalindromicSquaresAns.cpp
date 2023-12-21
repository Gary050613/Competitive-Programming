#include<bits/stdc++.h> 
using namespace std;
bool huiwen(string s)//12321 ???????? 
{
 int n = s.length();
 for(int i = 0; i <= n/2; ++i)
 {
  if(s[i] != s[n-i-1]) return false;
 }
 return true;
}
 
 
string ten_to_r(int n, int r)//?????n??r?? 
{
 char str[10005]={0};//??????,??????? 
 stack<int> st;
 while(n!=0)
 {
  st.push(n%r); 
  n = n/r;
 }
 int i = 0;
 while(!st.empty())//??????? 
 {
  int s = st.top();
  if(s >= 10) str[i++] = s - 10 + 'A';// ??10???????,??11->B 12->C 
  else str[i++] = s+'0';//??10??????? 
  st.pop();
  //cout << str[i-1] <<" "<<i<<" "; 
 }
// string ss = str;
 return str;
}
 
string num_to_str(int n)//????? 
{
 string res;
 stringstream ss;
 ss << n;//???n????res 
 ss >> res;//res = ss.str()
 return res; 
}
 
int str_to_num(string s)//????? 
{
 int res;
 stringstream ss;
 ss << s;
 ss >> res;
 return res;
} 
 
int main()
{
 int B;
 cin >> B;
 for(int i = 1; i <= 300; ++i)
 {
  int y = i*i; //???????,???i??B???,????????????? 
  string B1 = ten_to_r(i,B);
  //cout << B1 << endl;
  string B2 = ten_to_r(y,B);
  if(huiwen(B2))
  {
   cout << B1 << " " << B2 << endl;
  }
 }
 return 0;
}
