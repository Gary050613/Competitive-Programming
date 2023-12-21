```c++
#include<iostream>
#include<stack>
#include<cstring>
#include<algorithm>
#include<cstdio>
/*
t 组简化代码 
  每组 l 行 
  
模拟循环，判断语法是否有误，并计算复杂度 
*/
using namespace std;
const int maxl = 105;
int t,l,w;
string o;
string code[maxl];
//模拟循环 
//用于获得字符串 c 的下标为 x 的中的正整数，之后将 F x 1 n 中的 n 也看作正整数，方便后面循环处理 
int sread(int &x,string c){
	int res = 0;
	int len = c.size();
	while(c[x] <'0' || c[x] > '9' && x < c.size()){
		if(c[x] == 'n'){
			//注意，每次 ++x 
			++x;
			return 1000000;
		}
		++x;
	}
	while(c[x] >= '0' && c[x] <= '9'){
		res *= 10;
		res += c[x] -'0';
		++x;
	}
	return res;
}
//获取复杂度
//如果没有 n ，那么复杂度为 n^0,
//如果有，则为n^w，那么可以用一个 w 来保存复杂度 
int geto(){
	// x = 3：从下标 3 处开始，O(1) 或着 O(n^w) 
	int res = 0, x = 3;
	int len = o.size();
	if(o[2] == 'n'){
		//如果为 O(n^w)，获取w，否则 w 为 0 
		res = sread(x,o);
	}
	else{
		res = 0;
	}
	return res;
}
//计算是否有误
//若返回值为 -1，则代表语法有误，否则则代表代码的复杂度（now 记录） 
int check(){
	int res = 0,now = 0;
	int a,b,x;
	//模拟的时候使用栈 
	stack<int> s;
	//如果遇到 F ，则获取变量名，用 k 保存，获取 F x i j  中的 i j，分别用 a b 来保持
	//将 k 进栈
	//如果 b < a ，则没有进入循环，那么用 flag 去保存最早没有进入的 k，如果都进入了，则 flag = -1
	//如果 a <= b, 则进入循环，若 b-a > 1000,并且 flag = -1，则本层循环对复杂度有贡献，执行 now++
	//			   同时用 ef[26] 保存 now++时的 k 的值 ，之后判断 k 是否对复杂度有贡献，如果有则 now--，ef[k] = false 
	int flag = -1;
	bool ins[26] = {0};
	bool ef[26] = {0};
	for(int i = 1; i <= l; i++){
		if(code[i][0] == 'F'){
			int k = code[i][2] - 'a';
			if(ins[k]) return -1;
			s.push(k);
			ins[k] = true;
			x = 4;
			a = sread(x,code[i]);
			b = sread(x,code[i]);
			if(b-a > 1000){
				if(flag == -1){
					now++;
					res = max(res,now);
					ef[k] = true;
				}
			}
			if(a>b){
				if(flag == -1){
					flag = k;
				}
			}
		}
		if(code[i][0] == 'E'){
			if(s.empty()){
				return -1;
			}
			int k = s.top();
			s.pop();
			ins[k] = false;
			if(ef[k]){
				ef[k] = false;
				now--;
			}
		}
	}
	if(s.size()){
		return -1;
	}
	return res;
}
/*
	F 和 E 不匹配
		1. F 比 E 多 ：k出栈的时候判断栈是否为 空，如果为空则语法错误，return -1 
		2. F 比 E 少 ：遍历完代码判断 栈是否不为空，如果不为空，则语法有错误，return -1 

	bool ins[26] 表示当前哪些变量被用过，则需要在原来的基础上
	如果 k 入栈时，判断 k 是否已经被用过了， k 是否在栈中，如果用过则有语法错误，return -1
	如果 k 出栈时，判断栈是否为空，如果为空，则有语法错误，return -1
*/ 
int main(){
	//读入 t 
	scanf("%d",&t);
	while(t--){
		int ww;
		//注意这里 %d 后面的空格，输入中 l 后面有一个空格 
		scanf("%d ",&l);
		//getline(cin,0) 读入一整行代码 
		getline(cin,o);
		w = geto();
		for(int i = 1; i <= l; i++){
			getline(cin,code[i]);
		}
		ww = check();
		if(ww == -1){
			puts("ERR"); 
		}
		else{
			if(ww == w){
				puts("Yes");
			}
			else{
				puts("No");
			}
		}
	}

	return 0;
}

/*
8
2 O(1)
F i 1 1
E
2 O(n^1)
F x 1 n
E
1 O(1)
F x 1 n
4 O(n^2)
F x 5 n
F y 10 n
E
E
4 O(n^2)
F x 9 n
E
F y 2 n
E
4 O(n^1)
F x 9 n
F y n 4
E
E
4 O(1)
F y n 4
F x 9 n
E
E
4 O(n^2)
F x 1 n
F x 1 10
E
E
*/ 
```

