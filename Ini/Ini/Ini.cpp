#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 1024
#define MAX_LINE 2048
struct Buffer{ int Rtn_value; char buffer[MAX_LINE]; int Line[LINE]; };

//int SectionGet(int len,char *buf)
//{
//
//		int j = 0;
//		while (j < len)
//		{
//			if (buf[j] == '[')
//			{
//				j++;
//				int k = j;
//				int i = 0;
//				for (j; j < len; j++)
//				{
//					if (buf[j] == ']')
//					{
//						i = 1;
//						break;
//					}
//				}
//				if (i)
//				{
//					for (k; k < len; k++)
//					{
//						if (buf[k] == ']')
//						{
//							return 1;
//							break;
//						}
//						else printf("%c", buf[k]);
//					}
//					break;
//				}
//				else
//				{
//					return 0;
//					break;
//				}
//			}
//			else j++;
//		}
//	//	return 0;
//}



//int Juage2(int len, char *buf)
//{
//	int k = 0;
//	int a = 0;
//	int b = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (buf[i] == '=')
//		{
//			int c = 0;
//			a = i - 1;
//			while (a >= 0)
//			{
//				if (buf[a] != ' ')
//				{
//					b = i + 1;
//					while (b < len)
//					{
//						if (buf[b] == ' ')
//							b++;
//						else
//						{
//							if (buf[b] == '\n')
//							{
//								k = 0;
//								c = 0;
//								break;
//							}
//							else
//							{
//								k++;
//								c = 1;
//								break;
//							}
//						}
//					}
//					break;
//				}
//				else k = 0;
//				a--;
//			}
//			if (c)
//			{
//				return 1;
//				break;
//			}
//			else 
//			{
//				return 0;
//				break;
//			}
//		}
//	}
//	return k;
//}

/*int Juage3(int len, char *buf)
{
for (int x = 0; x < len; x++)
{
if ((buf[x] == '=') || (buf[x] == ' ') || (buf[x] == ';') || (buf[x] == '\n'))
{
if (buf[x] == '=')
{
printf("   ");
}
else
{
if (buf[x] == '\n')
{
printf("\n");
break;
}
continue;
}
}
else
{
printf("%c", buf[x]);
}
}
return 0;
}*/

/*int main1()
{
char buf[MAX_LINE];
FILE *fp;
if ((fp = fopen("../../int.ini", "r")) == NULL)
{
perror("fail to read");
exit(1);
}
int z = 1;
int p = 0;
int q = 0;
fgets(buf, MAX_LINE, fp);
int len = strlen(buf);
do
{
if (z)
{
if (Juage(len, buf))
{
if (SectionGet(len,buf))
{
q = 1;
z = 0;
printf("\n");
fgets(buf, MAX_LINE, fp);
int len = strlen(buf);
}
else
{
z = 1;
q = 0;
fgets(buf, MAX_LINE, fp);
int len = strlen(buf);
}
}
else
{
z = 1;
q = 0;
fgets(buf, MAX_LINE, fp);
int len = strlen(buf);
}
}
if (q)
{
if (Juage(len, buf))
{
z = 1;
q = 0;
}
else
{
int len = strlen(buf);
if (Juage2(len, buf))
{
Juage3(len,buf);
fgets(buf, MAX_LINE, fp);
int len = strlen(buf);
}
else
{
fgets(buf, MAX_LINE, fp);
int len = strlen(buf);
}
}
}
} while (!feof(fp));
return 0;
fclose(fp);//关闭输入文件
}
*/

//struct Dis main2()
//{
//	Dis display = { {} };
//	char buf[MAX_LINE];  /*缓冲区*/
//	FILE *fp;            /*文件指针*/
//	if ((fp = fopen("../../int.ini", "r")) == NULL)
//	{
//		perror("fail to read");
//		exit(1);
//	}
//	fgets(buf, MAX_LINE, fp);
//	int len = strlen(buf);
//	for (int i = 0; i < len; i++)
//	{
//		display.dis[i] = buf[i];
//	}
//	fclose(fp);
//	return display;
//}

//void main2()
//{
//	
//	Dis Buf;
//	Buf = main2();
//	char *p = Buf.dis;
//	char a[10] = "0";
//	int j = 0;
//	for (int i = 0; i < strlen(p)-1; i++)
//	{
//		if (p[i] != ' ')
//		{
//			a[j] = p[i];
//			j++;
//		}
//		else continue;
//	}
//	printf("%s\n", a);
//	return;
//}
/*
1、判断是否有[，没有扫描下一行，有下一步；
2、判断是否有分号；
*/

//int L_bracket_juage(int len, char *buf)
//{
//	for (int i = 0; i < len; i++)
//	{
//		if (buf[i] == ';')
//		{
//			return 0;
//			break;
//		}
//		else
//		{
//			if (buf[i] == '[')
//			{
//				if ((buf[i + 1] == '\n') || (buf[i + 1] == ']'))
//				{
//					return 0;
//					break;
//				}
//				else
//				{
//					return i;
//					break;
//				}
//			}
//			else return 0;
//		}
//	}
//
//}

int semicolon_juage(int grade, int len, char *buf)
{
	for (grade; grade < len; grade++)
	{
		if (buf[grade] == ';')return grade;
	}
	return 0;
}

int bracket_juage(int num, int len, char *buf)
{

	if (buf[num] == '[')
	{
		int key = num + 1;
		int tag = semicolon_juage(key, len, buf);
		int rtn_value = 0;
		int rtn_value1 = 0;
		int rtn_value2 = 0;

		while (buf[key] != '\n')
		{
			if (buf[key] == ']')
			{
				rtn_value = key;
				break;
			}
			else key++;
		}
		if (rtn_value)
		{
			int i = rtn_value - 1;

			for (i; i > num; i--)
			{
				if ((buf[i] != ' ') && (buf[i] != '['))
				{
					if (buf[i] == ';')
					{
						rtn_value1 = 0;
						break;
					}
					else
					{
						rtn_value1 = 1;
						continue;
					}
				}
			}
			if (rtn_value1)
			{
				if (tag)
				{
					return rtn_value;
				}
				else
				{
					rtn_value2 = rtn_value + 1;
					while (buf[rtn_value2] != '\n')
					{
						if (buf[rtn_value2] == ' ')rtn_value++;
						else
						{
							rtn_value = 0;
							break;
						}
					}
					return rtn_value;
				}
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}

	}
	else return 0;
}

int Equal_sign(int len, char *buf)
{
	for (int i = 0; i < len; i++)
	{
		if (buf[i] == '=')return i;
	}
	return 0;
}

int key_juage(int len, char *buf)
{
	int tag = Equal_sign(len, buf);
	int fucy = semicolon_juage(0, len, buf);
	if (tag)
	{
		if ((tag > fucy)&&(fucy))return 0;
		else
		{
			int i = tag - 1;
			int j = tag + 1;
			while (i >= 0)
			{
				if (buf[i] == ' ')
				{
					i--;
				}
				else
				{
					while (j != len)
					{
						if (buf[j] == ' ')j--;
						else return 1;
					}
				}
			}
		}
		return 0;
	}
	else if (fucy)return 1;
	else return 0;
}


struct Buffer SectionGet(_In_z_ const char * _Filename, _In_z_ const char * _Mode)
{
	int line = 0;
	int l = 0;
	int times = 0;
	Buffer section = { 0, { 0 }, { 0 } };
	FILE *fp;
	int tag = 0;
	fp = fopen(_Filename, _Mode);
	char buf[LINE] = { '0' };
	if (NULL == fp)
	{
		printf("no files found\n");
		return section;
	}
	fgets(buf, LINE, fp);
	int len = strlen(buf);
	line = 1;
	do
	{
		tag = bracket_juage(0, len, buf);
		if (tag)
		{
			int i = 1;
			for (i; i < len; i++)
			{
				if ((buf[i] != ' ') && (buf[i] != ']'))
				{
					section.buffer[times] = buf[i];
					times++;
				}
				else continue;
			}
			section.Rtn_value++;
			section.Line[l] = line;
			l++;
			fgets(buf, LINE, fp);
			line++;
			len = strlen(buf);
		}
		else
		{
			fgets(buf, LINE, fp);
			line++;
			len = strlen(buf);
		}
	} while (!feof(fp));
	fclose(fp);
	return section;
}

struct Buffer KeyGet(int line,_In_z_ const char * _Filename, _In_z_ const char * _Mode)
{
	Buffer key = { { 0 },{0}, {0} };
	FILE *fp;
	int tag = 0;
	int len = 0;
	int times = 0;
	int l = 0;
	fp = fopen(_Filename, _Mode);
	char buf[LINE] = { '0' };
	if (NULL == fp)
	{
		printf("no files found\n");
		return key;
	}
	while (line >= 0)
	{
		fgets(buf, LINE, fp);
		len = strlen(buf);
		line--;
	}
	while (!(feof(fp))&&(buf[0] != '['))
	{
		int k = key_juage(len, buf);
		int c = Equal_sign(len, buf);
		if (k)
		{
			for (int i = 0; i <= c; i++) //输入键
			{
				if (buf[i] == ' ')continue;
				else
				{
					key.buffer[times] = buf[i];
					times++;
				}
			}
			for (int j = c + 1; j < len; j++)//存储值
			{
				if (buf[j] = ' ')continue;
				else
				{
					key.buffer[times] = buf[j];
					times++;
				}
			}
			key.Line[l] = c;
			l++;
			fgets(buf, LINE, fp);
			len = strlen(buf);
		}
		else
		{
			fgets(buf, LINE, fp);
			len = strlen(buf);
			times++;
		}
	}
	return key;
}

int main()
{
	_In_z_ const char * Filename = "..\\..\\..\\int.ini";
	_In_z_ const char * Mode_r = "r";
	_In_z_ const char * Mode_w = "w";
	struct Buffer display = SectionGet(Filename, Mode_r);
	struct Buffer diy_key = KeyGet(display.Line[0], Filename, Mode_r);
	//int a = atoi(p+4);
	printf("%s%d\n", display.buffer, display.Rtn_value);
	for (int i = 0; display.Line[i] != 0; i++)
	{
		printf("%d ", display.Line[i]);
	}

	printf("\n%s", diy_key.buffer);
	
	printf("%d ", diy_key.Line[0]);
	return 0;
}

