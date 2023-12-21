#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	string sa = to_string(a), sb = to_string(b);
	for(int i = 0;i<min(sa.length(), sb.length());i++){
		if(sa[i] > sb[i]) return true;
		else if(sa[i] < sb[i]) return false;
	}
	if(sa.length()<sb.length()) return true;
	else return false;
};

int main(){
	int N, nums[101]={0};
	cin >> N;
	for(int i = 0;i<N;i++) cin >> nums[i];
	sort(nums, nums+N, cmp);
	string ans = "";
	for(int i = 0;i<N;i++) ans = ans + to_string(nums[i]);
	cout << ans << endl;
	return 0;
}


