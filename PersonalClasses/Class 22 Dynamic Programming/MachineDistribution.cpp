/*
	���չ�˾��˳�����������
		��һ�׶Σ��� M ̨�豸�ָ���һ����˾
				  ��¼��õĸ���ӯ��ֵ
		�ڶ��׶Σ��� M �豸�ָ�ǰ������˾ 
				  ��¼��õĸ���ӯ��ֵ
				  ֮��͵�һ�׶μ�¼��ӯ��ֵ���бȽ�
		�� N�׶Σ�M --> N
		
		������F[i][j]��ʾ�ҵĵ� i ����˾���� j̨���������ӯ�� 
			����F[i-1][k]��ʾǰ i-1 ����˾���� k ̨����õ����ӯ��
			�� value[i][j] ��ʾ�� i ����˾���� j ̨�豸��ӯ��
			
			F[i-1][0] + value[i][j]		ǰ i-1 ����˾���� 0 ̨�豸���ӯ�� + �� i ����˾����� j ̨������ӯ�� 
			F[i-1][1] + value[i][j-1]
			F[i-1][2] + value[i][j-2]
			.
			.
			.
			F[i-1][j-1] + value[i][1]
			F[i-1][j] + value[i][0]
			
			value[i][j] ��ֵΪ��ֵ��Ϊ��ǰ��ÿ��ʽ�ӵ�ֵ���
				����ʹ�� i-1 �׶εĸ���ֵ�����
				�׶� i �� ״ֻ̬���� i-1��״̬����
				
			�ɴ�ȷ����ǰ����߱������ӽṹ���޺�Ч��ԭ��
			F[i][j] = Max{F[i-1][k] + value[i][j-k]}
			
			��ʼֵ��F[0][0] = 0,F[n][m] ������������ӯ��ֵ 
		
		
		
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
		//�ݹ��������˾�ķ���������� 
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
	//������ӯ�� 
	cout << f[n][m] << endl;
	//���������� 
	show(n,m);

	return 0;
}
