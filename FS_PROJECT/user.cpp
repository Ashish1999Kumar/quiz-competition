#include "pch.h"
#include "user.h"
#include"dashboard.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
#define datafile "user.txt"
#define indexfile "puser.txt"
#define sindexfile "suser.txt"
#define quesfile "ques.txt"
extern int i, indsize, sindsize;

using namespace std;
char b[1];
extern fstream dfile, ifile, sifile;
extern char buffer[100], skey[20],lname[20],lpass[20],lusn[20];
extern user s;
extern index id[50], in;
extern sindex sid[50], sien;
dashboard d;

void opener(fstream &file, const char *fn, int mode)
{
	file.open(fn, mode);
	if (!file)
	{
		cout << "unable to open a file";

		exit(1);
	}
}
void index::initial()
{
	ifile.open(indexfile, ios::in);
	if (!ifile)
	{
		indsize = 0;
		return;
	}
	for (indsize = 0;; indsize++)
	{
		ifile.getline(id[indsize].iusn, 15, '|');
		ifile.getline(id[indsize].addr, 5, '\n');
		if (ifile.eof())
			break;
	}
	ifile.close();
}
//function to copy sindex file to array structure
void sindex::sinitial()
{
	sifile.open(sindexfile, ios::in);
	if (!sifile)
	{
		sindsize = 0;
		return;
	}
	for (sindsize = 0;; sindsize++)
	{
		sifile.getline(sid[sindsize].sname, 20, '|');
		sifile.getline(sid[sindsize].susn, 15, '\n');
		if (sifile.eof())
			break;
	}
	sifile.close();
}
// function to update the index file
void index::write()
{
	opener(ifile, indexfile, ios::out);
	for (i = 0; i < indsize; i++)
		ifile << id[i].iusn << "|" << id[i].addr << "\n";
	ifile.close();
}
//function to upadate the secondary file
void sindex::swrite()
{
	
	opener(sifile, sindexfile, ios::out);
	for (i = 0; i < sindsize; i++)
	{
		sifile.seekg(0, ios::end);
		
		sifile << sid[i].sname << "|" << sid[i].susn << "\n";
		
		
	}
}


int search(char * fusn)
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
}
// function to read the student record
void user::read()
{
	int k;
	gets_s(a);
	cout << "\nEnter the usn number="; gets_s(dusn);
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
	cout << "\nEnter the name="; gets_s(name);
	cout << "\nEnter password="; gets_s(pass);
	cout << "\nEnter the age="; gets_s(age);
	cout << "\nEnter the branch="; gets_s(branch);
	cout << "\nEnter the semester="; gets_s(sem);
	pack();
	dfile.seekg(0, ios::end);
	k = dfile.tellg();
	dfile << buffer << "\n";
	dfile.close();
	strcpy_s(id[i].iusn, dusn);
	_itoa_s(k, id[i].addr, 10);
	indsize++;
	for (i = sindsize; i > 0; i--)
	{
		if (strcmp(name, sid[i - 1].sname) < 0)
			sid[i] = sid[i - 1];
		else if ((strcmp(name, sid[i - 1].sname) == 0) && (strcmp(dusn, sid[i - 1].susn) < 0))
			sid[i] = sid[i - 1];
		else
			break;
	}
	strcpy_s(sid[i].sname, name);
	strcpy_s(sid[i].susn, dusn);
	sindsize++;
}
//function to pack
void user::pack()
{
	strcpy_s(buffer, dusn); strcat_s(buffer, "|");
	strcat_s(buffer, name); strcat_s(buffer, "|");
	strcat_s(buffer, pass); strcat_s(buffer, "|");
	strcat_s(buffer, age); strcat_s(buffer, "|");
	strcat_s(buffer, branch); strcat_s(buffer, "|");
	strcat_s(buffer, sem); strcat_s(buffer, "|");
}

void user::dunpack()
{
	
	char dummy[100];
	dfile.getline(dusn, 15, '|');
	dfile.getline(name, 20, '|');
	dfile.getline(pass, 20, '|');
	dfile.getline(age, 5, '|');
	dfile.getline(branch, 6, '|');
	dfile.getline(sem, 5, '|');
	dfile.getline(dummy, 100, '\n');
	cout << endl << dusn << "\t" << name << "\t" << pass << "\t" << age << "\n";
}

//function to search based on secondary key
int sec_search()
{
	int pos, j, flag = -1;
	cout << "\nenter the name to search(sec key):";
	gets_s(b);
	gets_s(skey);
	cout << "the searched record details are :" << endl;
	cout << setiosflags(ios::left);
	cout << "usn" << "\t\tname" << endl;
	
	for (j = 0; j < sindsize; j++)
		if (strcmp(skey, sid[j].sname) == 0)
		{
			cout << sid[j].susn << "\t\t" << sid[j].sname << endl;
			flag = j;
		}
	return flag;
}
// function to remove the record
void user::remove(char *u)
{
	char rusn[10];
	int pos, spos;
	strcpy_s(rusn, u);
	for (i = 0; i < sindsize; i++)
	{
		if (strcmp(sid[i].susn, rusn) == 0)
		{
			spos = i;
			break;
		}
	}
	if (strcmp(sid[spos].sname, skey) == 0)
	{
		pos = search(rusn);
		dfile.seekp(atoi(id[pos].addr), ios::beg);
		dfile.put('$');
		for (i = pos; i < indsize; i++)
			id[i] = id[i + 1];
		indsize--;
		for (i = spos; i < sindsize; i++)
			sid[i] = sid[i + 1];
		sindsize--;
	}
	else
		cout << "usn number and name doesnot match";
}
//function to display the datafile
void user::datadisp()
{
	cout << setiosflags(ios::left);
	cout << setw(16) << "usn" << setw(16) << "name" << setw(16)<<"pass"<<setw(16) << "age" << setw(16);
	cout << "branch" << setw(16) << "sem"<<endl;
	while (1)
	{
		unpack();
		if (dfile.eof())
			break;
	}
	cout << endl << "the index file details are " << endl;
	cout << setw(10) << "usn" << setw(10) << "address";
	for (i = 0; i < indsize; i++)
		cout << endl << setw(10) << id[i].iusn << setw(10) << id[i].addr;
	cout << endl << "\n the secondary file details are " << endl;
	cout << setw(20) << "name" << setw(15) << "primary reference";
	for (i = 0; i < sindsize; i++)
		cout << endl << setw(20) << sid[i].sname << setw(15) << sid[i].susn;
}
//function to unpack the data file
void user::unpack()
{
	dfile.getline(buffer, 100, '\n');
	i = 0;
	if (buffer[i] != '$')
		while (buffer[i] != '\0')
		{
			if (buffer[i] == '|')
				cout << "\t\t";
			else
				cout << buffer[i];
			i++;
		}
}

//function for login
void user::login()

{
	system("cls");
	int pos, j, flag = -1;
	gets_s(b);
	cout << "\n\n\t\tEnter the Credentials:";
	cout << endl;
	cout << "\n\tEnter usn:";
	gets_s(lusn);
	cout << "\n\tEnter the name:";
	gets_s(lname);
	cout << "\n\tEnter the password:";
	gets_s(lpass);
	
	/*while (!dfile.eof())
	{
		flag = dfile.tellg();
		dunpack();
		if (strcmp(dusn, lusn) == 0)
		{
			cout << "gonna give the address"<<endl;
			cout << flag;
			return flag;
		}
	}*/
	
	
	opener(dfile, datafile, ios::in | ios::out);
	for (j = 0; j < sindsize; j++)
		if (strcmp(lname, sid[j].sname) == 0)
		{
			cout << sid[j].susn << "\t\t" << sid[j].sname << endl;
			flag = j;
		}
	char rusn[10];
	int  spos=0;
	
	for (i = 0; i < sindsize; i++)
	{
		if (strcmp(sid[i].susn, lusn) == 0)
		{
			spos = i;
			break;
		}
	}
		if (strcmp(sid[spos].sname, lname) == 0)
		{
			pos = search(lusn);
			dfile.seekg(atoi(id[pos].addr));
			dunpack();


		}
	
	if (strcmp(pass, lpass) == 0)
	{
		d.welcome(atoi(id[pos].addr));
	}
	else
		cout << "usn number and name doesnot match";
	
}
void user::del(char *u)
{
	remove(u);
}

void user::sremove()
{
	char rusn[10];
	int pos, spos;
	cout << "enter the usn number above listed to delete:";
	cin >> rusn;
	for (i = 0; i < sindsize; i++)
	{
		if (strcmp(sid[i].susn, rusn) == 0)
		{
			spos = i;
			break;
		}
	}
	if (strcmp(sid[spos].sname, skey) == 0)
	{
		opener(dfile, datafile, ios::in | ios::out);
		pos = search(rusn);
		dfile.seekp(atoi(id[pos].addr), ios::beg);
		dfile.put('$');
		dfile.close();
		for (i = pos; i < indsize; i++)
			id[i] = id[i + 1];
		indsize--;
		for (i = spos; i < sindsize; i++)
			sid[i] = sid[i + 1];
		sindsize--;
	}
	else
		cout << "usn number and name doesnot match";
}
