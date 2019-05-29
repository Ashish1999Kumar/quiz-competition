#include "pch.h"
#include "questions.h"


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

extern fstream ifile;
void questions::opener(fstream &sfile, const char *fn, int mode)
{
	sfile.open(fn, mode);
	if (!sfile)
	{
		cout << "unable to open a file" << endl;

		exit(1);
	}
}void questions::read()
{
	fflush(NULL);
	gets_s(a);
	cout << "enter the question:"; gets_s(question);
	cout << "enter option 1:"; gets_s(op[0]);
	cout << "enter option 2:"; gets_s(op[1]);
	cout << "enter option 3:"; gets_s(op[2]);
	cout << "enter option 4:"; gets_s(op[3]);
	cout << "enter answer:"; gets_s(ans);

	pack();
}
// function to pack the student record using delimiter
void questions::pack()
{
	char buffer[250];
	strcpy_s(buffer, question); strcat_s(buffer, "|");
	strcat_s(buffer, op[0]); strcat_s(buffer, "|");
	strcat_s(buffer, op[1]); strcat_s(buffer, "|");
	strcat_s(buffer, op[2]); strcat_s(buffer, "|");
	strcat_s(buffer, op[3]); strcat_s(buffer, "|");
	strcat_s(buffer, ans); strcat_s(buffer, "|");
	ifile.fill('*');
	cout << buffer;
	ifile << setiosflags(ios::left) << setw(sizeof(user)) << buffer << endl;


}
//function to display student record
void questions::display()
{
	char buffer[250];
	cout << setiosflags(ios::left);
	
	while (1)
	{
		unpack();
		if (ifile.eof())
		{
			break;
			cout << "file ends here";
		}
		if (question[0] != '$')
		{

			cout << "question:=" << question << endl << "option 1:="<<op[0]<< "\t\toption 2:=" << op[1];
			cout << endl<<"option 3:=" << op[2] << "\t\toption 4:=" << op[3] << endl;
			cout << "answer:=" << ans;
		}
	}
}
void questions::unpack()
{
	char dummy[250];
	ifile.getline(question, 200, '|');
	ifile.getline(op[0], 20, '|');
	ifile.getline(op[1], 20, '|');
	ifile.getline(op[2], 20, '|');
	ifile.getline(op[3], 20, '|');
	ifile.getline(ans, 20, '|');
	ifile.getline(dummy,250, '\n');


}
//function to search student record based on USN.
int questions::search()
{
	int flag;
	char sques[15];
	cout << "enter the ques to be searched:";
	cin >> sques;
	while (!ifile.eof())
	{
		flag = ifile.tellg();
		unpack();
		if (question[0] != '$' &&strcmp(question, sques) == 0)
		{
			cout << "question:" << question << "\n" << "option 1:" << op[0] << "\n" << "option 2:" << op[1];
			cout << "\n" << "option 3" << op[2] << "\n" << "option 4" << op[3] << "\n" << "answer" << ans;
			return flag;
		}
	}
	return -1;
}
void questions::modify(int recpos)
{
	ifile.seekp(recpos, ios::beg);
	ifile.put('$');
	ifile.seekp(0, ios::end);
	read();
}
