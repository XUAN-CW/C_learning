#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

typedef struct {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
}pixel;//像素

pixel image[1080][1920];
//记录图片的宽和高
int wide_original, high_original;
//记录小块图片的宽和高
int wide_compressed, high_compressed;

//将输入的像素计算为具体数值
unsigned char ToUnsignedChar(char c1, char c2)
{
	unsigned char ch = 0;
	if (c1 >= 'a')
		ch = (c1 - 'a' + 10) * 16;
	else
		ch = (c1 - '0') * 16;

	if (c2 >= 'a')
		ch += c2 - 'a' + 10;
	else
		ch += c2 - '0';
	return ch;
}

void InputImage() {
	cin >> wide_original >> high_original >> wide_compressed >> high_compressed;
	char color[8] = { '\0' };//color用于输入像素#abcdef
	//输入像素，并将输入的像素处理好后存入到pixel数组
	for (int i = 0; i < high_original; i++)
	{
		for (int j = 0; j < wide_original; j++)
		{
			cin >> color;
			//判断特殊情况如#a,将其改为#aaaaaa
			if (color[2] == '\0') {
				for (int i = 2; i < 7; i++) {
					color[i] = color[1];
				}
			}
			//判断特殊情况如#abc,将其改为#aabbcc
			if (color[4] == '\0')
			{
				color[5] = color[3];
				color[6] = color[3];
				color[3] = color[2];
				color[4] = color[2];
				color[2] = color[1];
			}
			//符合格式#abcdef,开始操作
			if (color[7] == '\0')
			{
				image[i][j].red = ToUnsignedChar(color[1], color[2]);
				image[i][j].green = ToUnsignedChar(color[3], color[4]);
				image[i][j].blue = ToUnsignedChar(color[5], color[6]);
			}
		}
	}
}

//将小块的平均像素转换为合适的格式
string transfer(unsigned char num)
{
	string s_num;//num 转成的字符串
	stringstream on;
	on << (int)num;//不知道为什么，unsigned char 不行，要转成 int
	on >> s_num;
	on.clear();
	if (s_num.size() == 1)//只有一位
	{
		//cout << '\\x';
		on << "\\x";//【\x】- 转义符
		on << hex << setw(2) << uppercase << (int)s_num[0];
	}
	else if (s_num.size() == 2)//两位数
	{
		on << "\\x";
		on << hex << setw(2) << uppercase << (int)s_num[0];
		on << "\\x";
		on << hex << setw(2) << uppercase << (int)s_num[1];
	}
	else//三位数
	{
		on << "\\x";
		on << hex << setw(2) << uppercase << (int)s_num[0];
		on << "\\x";
		on << hex << setw(2) << uppercase << (int)s_num[1];
		on << "\\x";
		on << hex << setw(2) << uppercase << (int)s_num[2];
	}
	on >> s_num;
	return s_num;
}

pixel Compress(int i,int j) {
	//每进行一小块像素计算时，都需要把像素R,G,B重置,计算平均值用 unsigned char 容易溢出，所以先用 int 算出总和
	int R = 0, G = 0, B = 0;
	//计算每一小块的像素
	for (int k = i * high_compressed; k < high_compressed * (i + 1); k++)
	{
		for (int h = j * wide_compressed; h < wide_compressed * (j + 1); h++)
		{
			R += image[k][h].red;
			G += image[k][h].green;
			B += image[k][h].blue;
		}
	}
	//对每一小块的像素取平均值
	return { R / (wide_compressed * high_compressed), G / (wide_compressed * high_compressed), B / (wide_compressed * high_compressed) };
}

void Output(pixel currentPixel, pixel lastPixel,bool isEnd) {
	//将计算的像素平均值与PR,PG,PB或者默认值0,0,0比较来输出对应数据格式
	if (currentPixel.red == lastPixel.red && currentPixel.green == lastPixel.green && currentPixel.blue == lastPixel.blue)
	{
		cout << "\\x20"; //如果某个字符的背景色与其前一个字符相同则直接在前一个字符后输入“空格”（\x20）
	}
	else
	{
		if (currentPixel.red == 0 && currentPixel.green == 0 && currentPixel.blue == 0){
			cout << "\\x1B\\x5B\\x30\\x6D\\x20";//【\\x1B\\x5B\\x30\\x6D\\x20】-【ESC[0m'空格'】
		}
		else {
			//ESC[48;2;R;G;Bm'空格'
			cout << "\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B" << transfer(currentPixel.red) << "\\x3B"
				<< transfer(currentPixel.green) << "\\x3B" << transfer(currentPixel.blue) << "\\x6D\\x20";
		}
	}


	//若【该行的最后一个像素块】颜色【不是默认值】则输出 ESC[0m 的格式化表示
	if (isEnd && !(currentPixel.red == 0 && currentPixel.green == 0 && currentPixel.blue == 0)) {
		cout << "\\x1B\\x5B\\x30\\x6D";//【\\x1B\\x5B\\x30\\x6D】-【ESC[0m】
	}
	
}

void compressAndOutput() {
	//进行循环输出小块图片的平均像素，n/q行
	for (int i = 0; i < high_original / high_compressed; i++)
	{
		//PR PG PB分别用于记录上一小块图片的三原色的数值，初始为0，表默认值,每进行新一行的计算时都需要把PR PG PB重置
		pixel last = { 0,0,0 };
		//共有m/p列
		for (int j = 0; j < wide_original / wide_compressed; j++)
		{
			pixel average = Compress(i,j);//将小块图片进行压缩
			Output(average, last, j == wide_original / wide_compressed - 1);//【j == wide_original / wide_compressed - 1】判断是否到行末
			//保存上一个像素点，以便下一个进行对比
			last = { average.red ,average.green ,average.blue };
		}
		cout << "\\x0A";//【\x0A】-【int(65)】 - 换行
	}
}

int main()
{
	InputImage();
	compressAndOutput();
	return 0;
}