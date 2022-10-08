#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<assert.h>
					memcpy
struct s
{
	char name[20];
	int age;
};
				模拟实现
void* my_memcpy(void* dest, const void* src, size_t num)
{
	void* p = dest;
	void* p2 = src;
	assert(dest && src);
	while (num--) 
	{
		*(char*)dest = *(char*)src;			// 符合C语言标准，但不完美
		++(char*)dest;
		++(char*)src;
		num--;
	}
	return p;
}

void* my_memmove(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	assert(dest && src);

	if (dest < src || dest>(char*)src + num)
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;					//  从前向后
			++(char*)src;
		}
	}

	 方法 1
	else if (dest > src&& dest<(char*)src+n)
	{
		*((char*)dest + n-1) = *((char*)src + n-1);
		--(char*)dest + n;				//	从后向前
		--(char*)src + n;
	}
	 方法 2
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
			 01 00 00 00 | 02 00 00 00 | ... | 07 00 00 00 -> +num -1 才是07 00 00 00最后的00
		}
	}

	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	内存中存储 01 00 00 00 | 02 00 00 00 | 03 00 00 00 |....
	int arr2[5] = { 0 };
	strcpy(arr2, arr1);
	 接收类型char*  const char*
	 strcpy一次拷贝一个字节,01 00,遇到01后面的00=\0，直接停下,所以无法拷贝地址

	memcpy(arr2, arr1,sizeof(arr1));
	接收类型void* const void*  无符号整数(字节数)
	printf("%s ", arr2);

	struct s arr3[] = { {"chb",21},{"sq",20} };
	struct s arr4[3] = { 0 };
	memcpy(arr4, arr3,sizeof(arr3));
	my_memcpy(arr4, arr3, sizeof(arr3));
	return 0;
}

int main()
{
	int arr[]= { 1,2,3,4,5,6,7,8,9,10 };
	memcpy(arr + 3, arr, 20);

	my_memmove(arr , arr+2, 20);  // ok
				dest < src

	my_memmove(arr + 3, arr, 20);
				dest > src

	my_memmove(arr, arr + 5, 20);	// ok
	          dest > src+n
	memmove(arr+3, arr, 20);
	int i = 0;
	for (i = 0; i < (sizeof(arr) / sizeof(arr[0]));i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
	C语言标准：
  memcpy - 拷贝不重叠的内存即可
  memmove - 拷贝重叠的内存与不重叠的 

				memcmp - 内存比较

int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,5,4,3 }; 
	int ret = memcmp(arr1, arr2,20);
											字节数，一个整型4字节
							  >  返回大于0的数
							  =  返回0
							  <  返回小于0的数
	printf("%d ", ret);
	return 0;
}

					memset  -  内存设置
int main()
{
	/*char arr[10] = "0";
	memset(arr, '*', 10);*/
	int arr[10] = { 0 };
	 00 00 00 00 00 ... 共40字节
	 01 01 01 01 01 01 01 01 01 01
	  1010101    1010101     101
		 16进制
	memset(arr,		  1,		10);
		  目的地   想改成什么	字节数

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}