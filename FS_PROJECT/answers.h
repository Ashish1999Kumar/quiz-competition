#include "pch.h"
#include "user.h"

#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
using namespace std;
void aopener(fstream &file, const char *fn, int mode);
int sec_search();
void update(int code,int ans[],int total, char *usn);
class answers
{
public:
	int sans[10], answer, code, position;
	void read(int code, int ans[], int total);
	void pack(int code, int ans[], int total);
	friend int search(char *);
	void remove();
	
	void unpack();
	void result(char *usn, int code, int f);
};

class ansindex
{
public:
	char code[5],pos[5];
	void initial();
	void write();
};
class anssindex
{
public:
	char code[5],total[5];
	void sinitial();
	void swrite();
};

