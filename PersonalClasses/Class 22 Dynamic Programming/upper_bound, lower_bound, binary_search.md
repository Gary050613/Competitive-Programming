```c++
#include<iostream>
#include<algorithm> 
using namespace std;
struct node{
	int north;
	int south;
}a[20001];
int n,i,d[20001],len,temp;
bool cmp(node x,node y){
	return x.north < y.north;
}
int main(){
	
	cin >> n;
	for(i = 1; i <= n; i++){
		cin >> a[i].north;
		cin >> a[i].south;
	}
	sort(a+1,a+1+n,cmp);
	//因为最短的不下降子序列是每个数本身
	//所以，我们将第第一个元素放进最长不下降子序列 
	d[++len] = a[1].south;

	for(i = 2; i<= n; i++){
		/*
		
		#include<algorithm> 
			upper_bound(起始地址，结束地址，要查找的数值)
				返回的是第一个大于待查找的数值出现的位置
				返回查找元素的最后一个可安插的位置，
				元素值 > 查找值 的第一个元素的位置
				如果 val 大于数组中全部元素，返回的last
				（数组下标越界） 
				
			lower_bound(起始地址，结束地址，要查找的数值)
				返回数值第一个出现的位置 
				first --> last 返回大于或等于 val 的第一个元素的位置 
				如果所有的元素都小于 val ，则返回 last 的位置，
				而且返回的last 是越界的 
				
			binary_search(起始地址，结束地址，要查找的数值) 
				返回是否存在这么一个数值
				返回值是 bool 
				
		*/
		int db = upper_bound(d+1,d+len+1,a[i].south) - d;
		d[db] = a[i].south;
		if(db > len){
			len++;
		}
	}
	cout << len << endl;

	return 0;
}
```

