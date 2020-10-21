#pragma once


int Semicolon_juage(int grade, int len, char *buf);
int Bracket_juage(int num, int len, char *buf);
int Equal_sign(int len, char *buf);
int Key_juage(int len, char *buf);

struct Buffer KeyGet(int line, const char * _Filename, const char * _Mode);
struct Buffer SectionGet( const char * _Filename,  const char * _Mode);

