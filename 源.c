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
				ģ��ʵ��
void* my_memcpy(void* dest, const void* src, size_t num)
{
	void* p = dest;
	void* p2 = src;
	assert(dest && src);
	while (num--) 
	{
		*(char*)dest = *(char*)src;			// ����C���Ա�׼����������
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
			++(char*)dest;					//  ��ǰ���
			++(char*)src;
		}
	}

	 ���� 1
	else if (dest > src&& dest<(char*)src+n)
	{
		*((char*)dest + n-1) = *((char*)src + n-1);
		--(char*)dest + n;				//	�Ӻ���ǰ
		--(char*)src + n;
	}
	 ���� 2
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
			 01 00 00 00 | 02 00 00 00 | ... | 07 00 00 00 -> +num -1 ����07 00 00 00����00
		}
	}

	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	�ڴ��д洢 01 00 00 00 | 02 00 00 00 | 03 00 00 00 |....
	int arr2[5] = { 0 };
	strcpy(arr2, arr1);
	 ��������char*  const char*
	 strcpyһ�ο���һ���ֽ�,01 00,����01�����00=\0��ֱ��ͣ��,�����޷�������ַ

	memcpy(arr2, arr1,sizeof(arr1));
	��������void* const void*  �޷�������(�ֽ���)
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
	C���Ա�׼��
  memcpy - �������ص����ڴ漴��
  memmove - �����ص����ڴ��벻�ص��� 

				memcmp - �ڴ�Ƚ�

int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,5,4,3 }; 
	int ret = memcmp(arr1, arr2,20);
											�ֽ�����һ������4�ֽ�
							  >  ���ش���0����
							  =  ����0
							  <  ����С��0����
	printf("%d ", ret);
	return 0;
}

					memset  -  �ڴ�����
int main()
{
	/*char arr[10] = "0";
	memset(arr, '*', 10);*/
	int arr[10] = { 0 };
	 00 00 00 00 00 ... ��40�ֽ�
	 01 01 01 01 01 01 01 01 01 01
	  1010101    1010101     101
		 16����
	memset(arr,		  1,		10);
		  Ŀ�ĵ�   ��ĳ�ʲô	�ֽ���

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}