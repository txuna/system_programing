#include <stdio.h>
#include <stdint.h>
//#define STRLEN(s) (sizeof(s)/sizeof(s[0]))
//x&(x-1)
//inline function
//inline asm
//loop unrolling
//direct vs indirect
//reduce calling function
//병령 처리
//암달의 법칙

int string_len(const char* str);
int get_element(const char* str, int index, char* ch);
void combine(const char* name, int64_t age ,int* dest);
int involution(int64_t age);

int main(void)
{
	int64_t age =0;
	char name[1000] = {0, };
	int src=0;
	printf("input age :");
	scanf("%ld", &age);
	printf("input name :");
	scanf("%s", name);
	for(int i=0;i<100000;i++){
		combine(name, age, &src);
		src = 0;
	}
	//printf("data : %d\n", src);
	return 0;
}

int involution(int64_t age)
{
	int64_t value=1;
	while(1)
	{
		//printf("%ld\n", value);
			if(age == value){
				return 1;
			}
			else if(age < value){
				return 0;
			}
			value *= 2;
	}
	return 0;
}

void combine(const char* name, int64_t age, int* dest)
{
	char ch=0;
	int len = string_len(name);
	for(int i=0;i<len;i++){
		get_element(name, i, &ch);
		*dest = *dest + ch;
	}
	//printf("------------------\n");
	involution(age);
	//
	//printf("------------------\n");
}

int get_element(const char* str, int index, char* ch)
{
	int len=0;
	int cur_len =0;
	for(len=0;str[len] != '\0';len++){
		if(len == index){
			*ch = str[len];
			return 0;
		}
	}
	return 0;
}

int string_len(const char* str)
{
	int len = 0;
	for(len=0;str[len] != '\0';len++);
	return len;
}
