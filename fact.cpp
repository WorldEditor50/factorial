#include<iostream>
#include<string>		//字符串模板类
#include<fstream>		//文件读写
#include<time.h>
#include"_calc.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	string x3;	//计算结果
	int n;		//输入数字
	long int i;	//数位
	clock_t start, finish;	//计算消耗时间
	ofstream outfile;		//	输出文件
	outfile.open("C:\\Users\\lim\\Desktop\\ssd.txt");//输出文件路径
	while (1)
	{
		cout << "input a number:" << endl;
		cin >> n;
		cout << endl;
		start = clock() / CLOCKS_PER_SEC;

		x3 = fact(n);			//***阶乘

		finish = clock() / CLOCKS_PER_SEC;
		//**************************************计算数位
		i = 0;
		while (x3[i] != '\0')
			++i;				//位数与阶乘的关系i=log(n!)+1
		//*****************************
		outfile << x3 << endl;
		outfile.close();
		//	cout<<endl;
		cout << "the length of number:" << i << endl;
		cout << "elapsed time:" << finish - start << "s" << endl;
	}

	return 0;
}
