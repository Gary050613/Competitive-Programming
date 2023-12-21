#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a1[1001]={},b1[1001]={};
    int a[1001]={},b[1001]={},c[1001]={};
    int lena, lenb, lenc=0,x=0,i;
    cin>>a1>>b1;
    lena=strlen(a1);
    lenb=strlen(b1);
    for(i=0;i<lena;i++) {
    	a[lena-i-1]=a1[i]-48;
	}
    for(i=0;i<lenb;i++) {
    	b[lenb-i-1]=b1[i]-48;
	}
    while((lenc<lena)||(lenc<lenb)){
        c[lenc]=a[lenc]+b[lenc]+x;
        x=c[lenc]/10;
        c[lenc]=c[lenc]%10;
        lenc++;
    }
    c[lenc]=x;
    if(c[lenc]==0){
        lenc--;
    }
    for(i=lenc;i>=0;i--){
        cout<<c[i];
    }
    cout<<endl;
    return 0;
}
