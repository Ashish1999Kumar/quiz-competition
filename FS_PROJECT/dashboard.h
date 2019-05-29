#include "pch.h"
#include "user.h"
#include "answers.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>

using namespace std;
extern fstream ifile;

class dashboard
{
public:
	char usn[15], name[20], age[5], branch[6], sem[5], a[1], pass[20];
	char question[200], op[4][20], ans[20];
	void welcome(int);
	void opener(fstream &sfile, const char *fn, int mode);
	void unpack();
	void qunpack();
};

