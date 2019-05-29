#pragma once
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
void opener(fstream &file, const char *fn, int mode);
int sec_search();

class user
{
	
public:
	char dusn[15], name[20], pass[20], age[5], branch[6], sem[5], a[1];
	void read();
	void pack();
	friend int search(char *);
	void remove(char *u);
	void datadisp();
	void unpack();
	void login();
	void dunpack();
	void del(char *u);
	void sremove();
};
class index
{
public:
	char iusn[15], addr[5];
	void initial();
	void write();
};
class sindex
{
public:
	char sname[20], susn[15];
	void sinitial();
	void swrite();
};

