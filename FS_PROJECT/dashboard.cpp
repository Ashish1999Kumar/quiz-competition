#pragma once
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
answers as;
using namespace std;
extern fstream dfile;
fstream ldr;
fstream ques,answer;
int c, uans[10], k = 0, total = 0, j = 0, code, temp;
int x;
extern user s;
extern index id[50], in;
extern sindex sid[50], sein;

char mans[20], pans[20], sans[20],lf[20],pusn[20],pname[20],ptotal[20],ch;


void dashboard::opener(fstream &sfile, const char *fn, int mode)
{
	sfile.open(fn, mode);
	if (!sfile)
	{
		cout << "unable to open a file" << endl;

		exit(1);
	}
}

void dashboard::unpack()
{
	char dummy[75];
	dfile.getline(usn, 15, '|');
	dfile.getline(name, 20, '|');
	dfile.getline(pass, 20, '|');
	dfile.getline(age, 5, '|');
	dfile.getline(branch, 6, '|');
	dfile.getline(sem, 5, '\n');

}
void dashboard::qunpack()
{
	char dummy[250];
	ques.getline(question, 200, '|');
	ques.getline(op[0], 20, '|');
	ques.getline(op[1], 20, '|');
	ques.getline(op[2], 20, '|');
	ques.getline(op[3], 20, '|');
	ques.getline(ans, 20, '|');
	ques.getline(dummy, 250, '\n');
	

}
void dashboard::welcome(int f)
{
	dfile.seekg(f);
	
	unpack();
db:system("cls");
	for (x = 0; name[x] != '\0'; x++)
		name[x] = toupper(name[x]);
	

	cout << "\t\t\t\t\t\tWelcome:-" <<name<< endl;
	cout << "\n\n\n";
	cout << "\t\t\t  Press 1 to start test" << endl;;
	cout << "\t\t\t  Press 2 to logout"<<endl;
	cout << "\t\t\t  Press 3 for leaderboard" << endl;;
	cout << "\t\t\t  Press 4 for checking your score" << endl;
	cout << "\t\t\t  Press 5 for deleting your account" << endl;
	dfile.close();
	cout << "\t\t\tEnter your choice";
	cin >> c;
	for (;;)
	{
		if (c != 1 && c != 2 && c != 3 && c != 4 && c!=5)
		{
			cout << "\n\n\t\t wrong input ,enter your option again" << endl;
			cout << "\t\t   Enter your Choice:";
			cin >> c;
		}
		else
			break;
	}
	if (c == 1)
	{
		system("cls");
		cout << "1.sports" << endl;
		cout << "2.political" << endl;
		cout << "3.technical" << endl;
		cout << "\n\n";
		cout << "\n\n\t\t  Enter the sub code";
		cin >> code;

		opener(ques, "ques.txt", ios::in);

		/*strcpy_s(mans, usn);
		cout << "masn=" << mans;
		strcat_s(mans, ".txt");
		cout << "\nmans="<<mans;
			opener(answer,mans, ios::out);
			*/
		char buffer[250];
		cout << setiosflags(ios::left);

		while (1)
		{
			k = 0;

			if (ques.eof())
			{
				break;
				cout << "file ends here";
			}
			while (!ques.eof())
			{
				qunpack();
				if (question[0] != '$')
				{

				again:cout << "\n\nquestion:=" << question << endl << "option 1:=" << op[0] << "\t\toption 2:=" << op[1];
					cout << endl << "option 3:=" << op[2] << "\t\toption 4:=" << op[3] << endl;
					cout << "\nEnter your option:=";
					cin >> uans[k];
					if (uans[k] > 4 || uans[k] < 1)
					{
						cout << " invalid answer";
						goto again;
					}

					j = uans[k];

					k++;
					if (strcmp(op[j - 1], ans) == 0)
					{
						
						total++;
					}
					
					


				}
			}
			ques.close();
			
			cout << "\n\nYou have answered all the questions" << endl;
			cout << "Want to review your answers" << endl;
			cout << "press Y/N";
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				system("cls");
				opener(ques, "ques.txt", ios::in);
				cout << setiosflags(ios::left);

				while (1)
				{
					k = 0;

					if (ques.eof())
					{
						break;
						cout << "file ends here";
					}
					while (!ques.eof())
					{
						qunpack();
						if (question[0] != '$')
						{

						notagain:cout << "\n\nquestion:=" << question << endl << "option 1:=" << op[0] << "\t\toption 2:=" << op[1];
							cout << endl << "option 3:=" << op[2] << "\t\toption 4:=" << op[3] << endl;
							cout << "\n\toption u entered=";
							cout << uans[k];
							j = uans[k];
							cout << "\nDo you wanna change the ans";
							cout << "\npress y/N";
							cin >> ch;
							if (ch == 'y' || ch == 'Y')
							{
								cout << "enter your choice";
								cin >> temp;
								uans[k] = temp;
								if (uans[k] > 4 || uans[k] < 1)
								{
									cout << " invalid answer";
									goto notagain;
								}
								if ((strcmp(op[j - 1], ans) == 0) && (strcmp(op[(uans[k]) - 1], ans) != 0))
								{
									total--;
								}
								if ((strcmp(op[j - 1], ans) != 0) && (strcmp(op[(uans[k]) - 1], ans) == 0))
								{
									total++;
								}
							}


							k++;

						


						}
					}
				}

			}
			cout << "\n\n\t\t  Thanks for attempting our Quiz" << endl;
			

			update(code, uans, total, usn);
			cout << "Press any key to Go back to Dashboard" << endl;
			_getch();

			goto db;
		}
	}
	else if(c == 4)
	{

	cout <<"Enter the subject code=";
	cin>>code;
	as.result(usn,code,f);


	}
	else if (c == 5)
	{
	int flag = sec_search();
	if (flag == -1)
		cout << "no data record found";
	else
	{
		s.sremove();
		cout << "deleted successfully";
		in.write();
		sein.swrite();
		
	}

    }
	else if (c == 3)
	{
		cout << "enter the code of the subject";
		cin >> code;
		_itoa_s(code, lf, 20);
		strcat_s(lf, "leader.txt");
		ldr.open(lf, ios::in);
		system("cls");
		cout << "\t\t\tleaderboard" << endl;;
		cout << setw(20)<<"usn" << setw(20) << "name" << setw(20) << "marks" << endl;
			while (!ldr.eof())
			{
				ldr.getline(pusn, 15, '|');
				ldr.getline(pname, 20, '|');
				ldr.getline(ptotal,10, '\n');
				cout << setw(20)<<pusn << setw(20) << pname << setw(20) << ptotal << endl;
				
			}
			cout << "\n\n\tPress any key to go back to the Dashboard";
			_getch();
			goto db;

			ldr.close();

		
	}
	}
	

	


