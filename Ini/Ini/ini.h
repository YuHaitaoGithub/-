#pragma once
int semicolon_juage(int grade, int len, char *buf);
int bracket_juage(int num, int len, char *buf);
int Equal_sign(int len, char *buf);
int key_juage(int len, char *buf);

struct Buffer KeyGet(int line, const char * _Filename, const char * _Mode);
struct Buffer SectionGet( const char * _Filename,  const char * _Mode);

