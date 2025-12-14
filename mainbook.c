#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <string.h>
void menu(void);
void password(void);
void namefun(void);
void searchfun(void);
void listfun(void);
void modifyfun(void);
void deletefun(void);
void exitfun(void);
void gotoxy(int x,int y){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main(){
	system("color B");
	password();
	getch();	
}

void namefun(){
	system("cls");
	gotoxy(31,4);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB NEW SECTION \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
	FILE *fptr;
	char name[100];
	char address[100];
	char gmail[100];
	double phone;
	char gender[8];
	fptr=fopen("ebraj.txt","ab+");//ab+ gives us the ability of writing the function and add the second data in the existing one...
	if(fptr==NULL){
		printf("Failed to create the required file.");
	}
	else{
		gotoxy(31,6);
		printf("Name:\t");
		gotoxy(52,6);
		gets(name);
		gotoxy(31,7);
		printf("Address:\t");
		gotoxy(52,7);
		gets(address);
		gotoxy(31,8);
		printf("Gender:\t");
		gotoxy(52,8);
		gets(gender);
		gotoxy(31,9);
		printf("Gmail:\t");
		gotoxy(52,9);
		gets(gmail);
		gotoxy(31,10);
		printf("Phone Number:\t");
		gotoxy(52,10);
		scanf("%lf",&phone);
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
	}
	fclose(fptr);
	system("cls");
	char ch;
	gotoxy(31,4);
	printf("Do you wanna add more datas.Press y for that:");
	Sleep(1000);
	fflush(stdin);
	while((ch=getch())=='y'){
		menu();
	}
}

void searchfun(){
	FILE *fptr;
	int flag=0;
	int res;
	char name[100];
	char address[100];
	char gmail[100];
	double phone;
	char gender[8];
	char name1[100];
	system("cls");
	fflush(stdin);
	gotoxy(18,2);
	printf("\xDB\xDB\xDB Enter the name of the person you want to see the detail:: ");
	gets(name1);
	fptr=fopen("ebraj.txt","r");
	//fflush(stdin);
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0){
			gotoxy(39,4);
			printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Record Found \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
			gotoxy(28,5);
			printf("----------------------------------------");
		gotoxy(31,6.5);
		printf("\xB3\xB2\xB2\xB2 Name:\t%s",name);
		gotoxy(31,7);
		printf("\xB3\xB2\xB2\xB2 Address:\t%s",address);
			gotoxy(31,8);
		printf("\xB3\xB2\xB2\xB2 Gender:\t%s",gender);
		gotoxy(31,9);
		printf("\xB3\xB2\xB2\xB2 Gmail:\t%s",gmail);
		gotoxy(31,10);
		printf("\xB3\xB2\xB2\xB2 Phone Number:\t%.0lf",phone);
		gotoxy(31,11);
			printf("----------------------------------------");
		flag=1;
		Sleep(1000);
			gotoxy(18,12);
			printf("Enter y for menu option.");
	while(getch()=='y'){
		menu();
	}
	}
}
	if(flag==0){
		system("cls");
		gotoxy(39,4);
		printf("No record found.");;
		gotoxy(39,6);
		printf("Enter a to enter file again or double y key to open menu section:");
		if(getch()=='a'){
			system("cls");
			searchfun();
		}
	
	}
