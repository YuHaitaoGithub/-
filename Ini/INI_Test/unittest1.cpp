#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Ini\ini.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#define LINE 100
struct Buffer{ int Rtn_value; char buffer[LINE]; int Line[LINE]; char key_buf[LINE][LINE]; };
namespace INI_Test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码
			const char * Filename = "..\\..\\..\\int.ini";
			const char * Mode_r = "r";
			struct Buffer display = SectionGet(Filename, Mode_r);
			struct Buffer diy_key = KeyGet(display.Line[0], Filename, Mode_r);
			char *p1 = &diy_key.key_buf[0][2];
			char *p2 = &diy_key.key_buf[1][2];
			int a = atoi(p1);
			int b = atoi(p2);
			Assert::AreEqual(a + b, 5);
		}

	};
}