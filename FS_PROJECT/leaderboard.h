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
class leaderboard
{
public:
	char lusn[15], lname[20], ltotal[20];
	void initial(int code);
	void write();
	
};
class ldata
{
	public:
	char usn[15], name[20], total[10];
	void read(char *usn, int code, int total);
};
void leader(char *usn,int code,int total);
void lopener(fstream &file, const char *fn, int mode);
