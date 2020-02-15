#pragma once
void change_1(int);
void change_2(int*);

void change_1(int a)
{
	a++;
}

void change_2(int*a)
{
	* a+= 1;
	(*a)++;
	*a++;//本句无效
}

/*
 我们通常定义一个整型指针变量a，那么*a是a指向的整型变量的值
 如果要使该值自增，单独写一条语句：*a++；将会带来问题，因为优先级问题
 所以要写成(*a)++； 或者++*a;因为单条语句中a++和++a并无区别。
*/