#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include "ini.h"
#define LINE 100
struct Buffer{ int Rtn_value; char buffer[LINE]; int Line[LINE]; char key_buf[LINE][LINE]; };


int main()
{
	const char * Filename = "..\\..\\..\\int.ini";
	const char * Mode_r = "r";
	const char * Mode_w = "w";
	struct Buffer display = SectionGet(Filename, Mode_r);
	struct Buffer diy_key = KeyGet(display.Line[1], Filename, Mode_r);
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
	system("pause");
	return 0;

}

