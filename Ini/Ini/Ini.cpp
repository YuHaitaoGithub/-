#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 100
struct Buffer{ int Rtn_value; char buffer[LINE]; int Line[LINE]; char key_buf[LINE][LINE]; };



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


struct Buffer SectionGet(const char * _Filename,  const char * _Mode)
{
	int line = 0;
	int l = 0;
	int times = 0;
	Buffer section = { 0, { 0 }, { 0 }, {0} };
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

struct Buffer KeyGet(int line,const char * _Filename,  const char * _Mode)
{
	int line1 = line;
	int line2 = 0;
	Buffer key = { { 0 }, { 0 }, { 0 }, {0} };
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
	while (line1 >= 0)
	{
		fgets(buf, LINE, fp);
		len = strlen(buf);
		line1--;
	}
	line++;
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

					key.key_buf[line2][times] = buf[i];
					times++;
					
				}
			}
			for (int j = c + 1; j < len; j++)//存储值
			{
				if (buf[j] == ' ')continue;
				else
				{
					key.key_buf[line2][times] = buf[j];
					times++;
				}
			}
			key.Line[l] = c + 1;
		//	key.Line[l+1] = ' ';
			key.Line[++l] = line;
		//	key.Line[l+3] = '\n';
			l++;
			fgets(buf, LINE, fp);
			len = strlen(buf);
			line++;
			line2++;
			times = 0;
		}
		else
		{
			fgets(buf, LINE, fp);
			len = strlen(buf);
			line++;
		//	times++;
		//	line2++;
		}
	}
	return key;
}

int main()
{
	 const char * Filename = "..\\..\\..\\int.ini";
	 const char * Mode_r = "r";
	const char * Mode_w = "w";
	struct Buffer display = SectionGet(Filename, Mode_r);
	struct Buffer diy_key = KeyGet(display.Line[0], Filename, Mode_r);
	//int a = atoi(p+4);
	printf("%s%d\n", display.buffer, display.Rtn_value);
	for (int i = 0; display.Line[i] != 0; i++)
	{
		printf("%d ", display.Line[i]);
	}

	printf("\n%s%s", diy_key.key_buf[0],diy_key.key_buf[1]);
	for (int j = 0; diy_key.Line[j] != 0; j++)
	{
		printf("第%d个 第%d行\n", diy_key.Line[j], diy_key.Line[++j]);
	}
	return 0;

}

