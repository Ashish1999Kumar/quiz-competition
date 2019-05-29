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

class questions
{
	char question[200], op[4][20], ans[20],a[1];
public:
	void opener(fstream &sfile, const char *fn, int mode);
	void read();
	void pack();
	void display();
	void unpack();
	int search();
	void modify(int);
};


