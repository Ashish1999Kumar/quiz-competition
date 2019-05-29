// FS_PROJECT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include"Source.h"
#include"user.h"
#include"questions.h"
#include "dashboard.h"
#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
#include<windows.graphics.h>
#include<Windows.h>
#include <cwchar>

using namespace std;
#define datafile "user.txt"
#define indexfile "puser.txt"
#define sindexfile "suser.txt"
#define quesfile "ques.txt"
fstream dfile, ifile, sifile;
int i, indsize, sindsize;
char buffer[100], skey[20],lname[20],lpass[20],lusn[20];
user s;
index id[50], in;
sindex sid[50], sein;
char adpas[20];
	
	int main()
	{
		int ch, flag;
		user s;
		questions q;
		dashboard d;
		db:home:system("cls");
		
		cout << "\n\n\n\n";
		cout << "\t\t   Weclome To The Quiz Compidition" << endl;
		cout << "\n\n\n";
		cout << "press 1 to register or login" << "\t\t";
		cout << "press 2 for admin login " << endl<<"\n\n";
		cout << "press 3 for exit " << endl << "\n\n";
		cout << "\t\t   Enter your Choice:";
		cin >> ch;
		for (;;)
		{
			if (ch != 1 && ch != 2 && ch != 3)
			{
				cout << "\n\n\t\t wrong input ,enter your option again" << endl;
				cout << "\t\t   Enter your Choice:";
				cin >> ch;
			}
			else
				break;
		}
		switch (ch)
		{
		case 1:system("cls");
			int ch, flag;
			in.initial();
			sein.sinitial();
			system("cls");
			for (;;)
			{
				system("cls");
				cout<<"\n\n\t\t\t    MENU"<<endl;
				cout << endl << "\t\tPress 1 for making a new account\n\t\tPress 2 for login\n\t\tPress 3 for Home Page\n\t\tPress 4 for exit\n";
				cout << "\n\n\t\t\tEnter your choice:";
				cin >> ch;
				for (;;)
				{
					if (ch != 1 && ch != 2 && ch != 3 &&  ch != 4)
					{
						cout << "\n\n\t\t wrong input ,enter your option again" << endl;
						cout << "\t\t   Enter your Choice:";
						cin >> ch;
					}
					else
						break;
				}
				switch (ch)
				{
				case 1:
					system("cls");
					cout << endl << "Enter your details : " << endl;
					s.read();
					in.write();
					sein.swrite();
					cout << "\n\n\t\tNew account created\n\n\t\tNow u can sign in";
					cout << "\nPress any key to continue";
					_getch();
					system("cls");
					break;
				case 5: opener(dfile, datafile, ios::in);
					cout << "\nthe datafile,indexfile and secondary file" << endl;
					s.datadisp();
					break;
				case 3:goto home;
					break;
				case 7:cout << "To search based on sec key ";
					flag = sec_search();
					if (flag == -1)
						cout << "no data record ";
					break;
				case 6: flag = sec_search();
					if (flag == -1)
						cout << "no data record found";
					else
					{
						s.sremove();
						in.write();
						sein.swrite();
					}
					break;
				case 2:
					system("cls");
					s.login();
					break;
				default: exit(0);
				}
				dfile.close();
				ifile.close();
				sifile.close();
			}
			
				break;

		case 2:system("cls");
			in.initial();
			sein.sinitial();
			cout << "\n\n\t\tenter the admin password";
			cin >> adpas;
			if (strcmp(adpas, "archit95") == 0)
			{
				for (;;)
				{
					system("cls");
					cout << endl << "1.- enter questions\n2-display the quetion file \n3-search for any question \n4.- modify the question \n5.dispaly the user file\n6-home screen" << endl;
					cout << "\nenter the choice:";
					cin >> ch;
					for (;;)
					{
						if (ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch!=5 && ch != 6)
						{
							cout << "\n\n\t\t wrong input ,enter your option again" << endl;
							cout << "\t\t   Enter your Choice:";
							cin >> ch;
						}
						else
							break;
					}
					switch (ch)
					{
					case 1: q.opener(ifile, quesfile, ios::app);
						cout << "enter the questions\n";
						q.read();
						break;
					case 2: q.opener(ifile, quesfile, ios::in);
						system("cls");
						q.display();
						cout << "\n\n\t\tPress any key to go back to the Menu";
						_getch();
						break;
					case 3:q.opener(ifile, quesfile, ios::in);
						cout << "Searching based on question" << endl;
						flag = q.search();
						if (flag == -1)
							cout << "Record not found" << endl;
						cout << "\n\n\t\tPress any key to go back to the Menu";
						_getch();
						break;
					case 4: q.opener(ifile, quesfile, ios::in | ios::out);
						cout << "To modify the record based on question" << endl;
						flag = q.search();
						if (flag == -1) {
							cout << "\n\n\t\tRecord not found" << endl;
							cout << "\n\n\t\tPress any key to go back to the Menu";
							_getch();
						}
						else {
							q.modify(flag);
							cout << "\n\n\t\tPress any key to go back to the Menu";
							_getch();
						}
						break;
					case 5: opener(dfile, datafile, ios::in);
						cout << "\nthe datafile,indexfile and secondary file" << endl;
						s.datadisp();
						dfile.close();	
						cout << "\n\n\t\tPress any key to go back to the Menu";
						_getch();
						break;
					case 6:goto db;
							
					default:
						exit(0);
					}
					ifile.close();
				}
				break;
			}
			else
			{
				cout << "\n\n\t\t wrong password";
				cout << "\n\n\tPress any key to go back to the home page";
				_getch();
				goto db;

			}

		}
	}
	


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
