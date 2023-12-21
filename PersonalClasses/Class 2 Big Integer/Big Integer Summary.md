## Big Integer

	### Storing Big Integer

char[] or int[], usually char[] for convenient access to each element. When converting a number stored in char, minus 48 / '0'. When dealing with Hexadecimal, letters A - F are also stored in char. To convert a Hexadecimal character to a integer, for A - F, do minus 'A' + 10 as A - F starts from 10 all the way to 15.

### Calculating Sum

Create two empty char arrays, three integer arrays. Take in the big integer as a char array / string. Get the length of both numbers with strlen() & set a int variable lenc to be 0. Convert the char arrays into two corresponding int arrays with for loop and -48 / -'0'. While the variable lenc is smaller than either of lena or lenb, make the int at c[lenc] equals to a[lenc] + b[lenc] + x(Number brought over). Update x by dividing c[lenc] by 10 and update c[lenc] by modding 10. Finally update lenc. After the while loop, update the number at the leftmost side as it's not included in the while loop cycle. Make c[lenc] = x, then update lenc depending on the value of c[lenc]. When outputting the sum, reverse the sum first as it is stored in reverse order. 

#### Example Code

```c++
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
    for(i=0;i<lena;i++) a[lena-i-1]=a1[i]-48;
    for(i=0;i<lenb;i++) b[lenb-i-1]=b1[i]-48;
    while((lenc<lena)||(lenc<lenb))
    {
        c[lenc]=a[lenc]+b[lenc]+x;
        x=c[lenc]/10;
        
	c[lenc]=c[lenc]%10;
        lenc++;
    }
    c[lenc]=x;
    if(c[lenc]==0)  //处理最高进位 
    {
        lenc--;
    }
    for(i=lenc;i>=0;i--)
    {
        cout<<c[i];
    }
    cout<<endl;
    return 0;
}

```

### Converting Bases

When converting a number to another base, there are two cases:

#### 10 To Another Base

Take the current number, keep modding it by the target base and store the remainder on the right side. Then divide the number itself by the target base. 

##### Example

19 From DEC to BIN

19 % 2 = 1		19 / 2 = 9	 DEC = 9 	BIN = 1

9 % 2 = 1		   9 / 2 = 4	  DEC = 4	 BIN = 11

4 % 2 = 0			4 / 2 = 2 	DEC = 2	 BIN = 011

2 % 2 = 0			2 / 2 = 1	  DEC = 1	BIN = 0011

1 % 2 = 1			1 / 2 = 0	  DEC = 0	BIN = 10011

#### Another Base To 10

The each index and multiply it by base^index from the right. Then the sum will be the number in base 10.

##### Example

10011 From BIN to DEC

**Number**: 1 0 0 1 1

**Indices**:    4 3 2 1 0

10011 in DEC = 16 + 2 + 1 = 19