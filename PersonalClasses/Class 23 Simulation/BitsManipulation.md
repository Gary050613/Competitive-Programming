位运算
	基于整数的二进制进行的运算，执行效率高
	常用的运算符一共 6 种
		& ：与 
		| ：或 
		^ ：异或 
		~ ：取反 
		<<：左移 
		>>：右移
		

		将两个整数作为二进制数，对二进制数中表示的每一位逐一运算
		 
		& ：与		只有两个对应位都是1时才是1 
		| ：或 		只要两个对应位中有一个是1就是1 
		^ ：异或 	只有两个对应位不同时才为1
		a^b^b = a
		
		5^6  5:101  = 011(2) = 3(10)
			 6:110
		5&6			  100(2) = 4
		5|6			  111(2) = 7
		
		取反 ~ 
			对一个数 num 进行计算，也就是俗称的 单目运算 
			~ : 会将 num 的补码中得到 0 和 1 全部取反
				如果有符号整数的符号位在，~ 也会将运算符取反
			补码：
				二进制表示下，正数和零的补码为其本身，
							  负数的补码为其对应正数按位取反后+1
			5： 00000101(2)
			~5: 11111010(2) -6 先-1再
				10000101(10) 取反
				10000110 
				-(2^1+2^2) = -6
		num << i :将num的二进制表示向左移动i位 
		num >> i :将num的二进制表示向右移动i位 	
				 11111111 << 1
				111111110 
				 11111111 >> 1	
				01111111
		移位运算中如果出现以下情况，其行为未定义的
			1.右操作数（移位数）时负数
			2.右操作数大于或等于左操作数的位数
				a << -1  a<<32
				左移操作需要确保移位后的结果能够被原数的类型容纳
				右移操作多余的位数会被舍弃，
					无符号数，会左侧补齐0 
					有符号数，则会用最高位的数（符号位）做补齐
						符号位：非符数 0
								负数   1