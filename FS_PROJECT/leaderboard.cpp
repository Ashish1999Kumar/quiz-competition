#include "pch.h"
#include "dashboard.h"
#include "user.h"
#include"leaderboard.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
char secusr[20];
extern int sindsize, i;
int setotal;
fstream suser, sanswer, leaderfile;
 leaderboard sid[50], sien;
 ldata d;
 char code[5], sectotal[5], susn[15], sname[20];
char lfilename[20];
void leader(char *usn ,int code,int total)
{
	_itoa_s(total, sectotal, 10);
	sien.initial( code);
	d.read(usn,  code, total);
		sien.write( );

}
void lopener(fstream &file, const char *fn, int mode)
{
	file.open(fn, mode);
	if (!file)
	{
		cout << "unable to open a file";

		exit(1);
	}
}
void leaderboard::initial(int code)
{
	_itoa_s(code, lfilename, 15);
	strcat_s(lfilename, "leader.txt");
	leaderfile.open(lfilename, ios::in);
	if (!leaderfile)
	{
		sindsize = 0;
		return;
	}
	for (sindsize = 0;; sindsize++)
	{
		leaderfile.getline(sid[sindsize].lusn, 15, '|');
		leaderfile.getline(sid[sindsize].lname, 20, '|');
		leaderfile.getline(sid[sindsize].ltotal, 10, '\n');
		if (leaderfile.eof())
			break;
	}
	leaderfile.close();
}
void leaderboard::write()
{
	lopener(leaderfile, lfilename, ios::out);
	for (i = 0; i < sindsize; i++)
		leaderfile << sid[i].lusn << "|" << sid[i].lname << "|"<<sid[i].ltotal<<"\n";
	leaderfile.close();
}
void ldata::read(char *usn, int code, int total)
{
	opener(suser, "suser.txt", ios::in);
	while (!suser.eof())
	{
		suser.getline(sname, 20, '|');
		suser.getline(susn, 15, '\n');
		if (strcmp(usn, susn) == 0)
		{
			break;
		}

	}
	suser.close();

	/*int k;
	gets_s(a);
	cout << "enter the usn number="; gets_s(dusn);
	if (search(dusn) >= 0)
	{
		cout << "usn is already present we can't add to index file\n";
		return;
	}
	for (i = indsize; i > 0; i--)
	{
		if (strcmp(dusn, id[i - 1].iusn) < 0)
			id[i] = id[i - 1];
		else
			break;
	}
	opener(dfile, datafile, ios::app);
	cout << "enter the name="; gets_s(name);
	cout << "enter password="; gets_s(pass);
	cout << "enter the age="; gets_s(age);
	cout << "enter the branch="; gets_s(branch);
	cout << "enter the semester="; gets_s(sem);
	pack();
	dfile.seekg(0, ios::end);
	k = dfile.tellg();
	dfile << buffer << "\n";
	strcpy_s(id[i].iusn, dusn);
	_itoa_s(k, id[i].addr, 10);
	indsize++;*/
	for (i = sindsize; i > 0; i--)
	{
		setotal = atoi(sid[i - 1].ltotal);
		if (total>setotal)
			sid[i] = sid[i - 1];
		else if (total==setotal && (strcmp(usn, sid[i - 1].lusn) < 0))
			sid[i] = sid[i - 1];
		else
			break;
	}
	strcpy_s(sid[i].lusn, usn);
	strcpy_s(sid[i].lname, sname);
	_itoa_s(total, sid[i].ltotal, 10);
	
	sindsize++;
	
}
/*int search(char * fusn)
{
	int low = 0, high = indsize - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strcmp(fusn, id[mid].iusn) == 0)
			return mid;
		if (strcmp(fusn, id[mid].iusn) > 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}*/