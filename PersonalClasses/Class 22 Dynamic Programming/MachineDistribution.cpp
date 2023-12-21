/*
	按照公司的顺序来分配机器
		第一阶段：把 M 台设备分给第一个公司
				  记录获得的各个盈利值
		第二阶段：把 M 设备分给前俩个公司 
				  记录获得的各个盈利值
				  之后和第一阶段记录的盈利值进行比较
		第 N阶段：M --> N
		
		设数组F[i][j]表示我的第 i 个公司分配 j台机器的最大盈利 
			数组F[i-1][k]表示前 i-1 个公司分配 k 台设别获得的最大盈利
			用 value[i][j] 表示第 i 个公司分配 j 台设备的盈利
			
			F[i-1][0] + value[i][j]		前 i-1 个公司分配 0 台设备最大盈利 + 第 i 个公司分配的 j 台机器的盈利 
			F[i-1][1] + value[i][j-1]
			F[i-1][2] + value[i][j-2]
			.
			.
			.
			F[i-1][j-1] + value[i][1]
			F[i-1][j] + value[i][0]
			
			value[i][j] 的值为定值，为了前面每个式子的值最大
				必须使第 i-1 阶段的各个值都最大
				阶段 i 的 状态只能由 i-1中状态决定
				
			由此确定当前问题具备最优子结构和无后效性原则
			F[i][j] = Max{F[i-1][k] + value[i][j-k]}
			
			初始值：F[0][0] = 0,F[n][m] 就是所求的最大盈利值 
		
		
		
*/
#include<iostream>
#include<cstring> 
using namespace std;
long maxl,f[11][20],value[11][20];
int show(int i,int j){
	int k;
	if(i == 0){
		return 0;
	}
	for(k = 0; k <= j; k++){
		//递归求各个公司的分配机器数量 
		if(maxl == f[i-1][k] + value[i][j-k]){
			maxl = f[i-1][k];
			show(i-1,k);
			cout << i << " " << j-k << endl;
			break;
		}
	}
} 

int main(){

	long m,n,i,j,k;
	cin >> n >> m;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			cin >> value[i][j];
		}
	}
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			maxl = 0;
			for(k = 0 ; k <= j; k++){
				if(f[i-1][k] + value[i][j-k] > maxl){
					maxl = f[i-1][k] + value[i][j-k];
				}
			}
			f[i][j] = maxl;
		}
	}
	//输出最大盈利 
	cout << f[n][m] << endl;
	//输出分配情况 
	show(n,m);

	return 0;
}
