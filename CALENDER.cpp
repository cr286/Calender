#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
int totald(int,int);
void showc(int,int,int);
void intro();
void delay();
void converter();
void todaytime();
void main()
{
 ofstream outfile1;
 outfile1.open("event.txt");
 outfile1.close();
 ofstream outfile;
 outfile.open("memo.txt");
 outfile.close();
 introduction:
 intro();
 clrscr();
 int m=0,y=0,d=0,day=0,g=0;
 int readday;
 char readmonth[5],readmemo[50];
 char pass[30],password[]="password";
 char memo[50],event[50],month[5];
 int eventday;
 char eventmonth[5],readevent[50];
 int readday1;
 char readmonth1[5],readevent1[50];
 gotoxy(26,9);
 cout<<"--------------------------";
 gotoxy(26,14);
 cout<<"--------------------------";
 gotoxy(29,10);
 cout<<"ENTER YOUR PASSWORD\n\t\t\t\t";
 int i=0;
 char a;
 for(i=0;;)
 {
 a=getch();
 if(a>='a'&&a<='z'||a>='0'&&a<='9')
 {
 pass[i]=a;
 ++i;
 cout<<"*";
 }
 if(a=='\r')//enter
 {
 pass[i]='\0';//null value
 break;
 }
 }
 if(strcmp(pass,password)==0)
  {
 here:
 clrscr();
 gotoxy(27,9);
 cout<<"----------------------";
 gotoxy(27,13);
 cout<<"----------------------";
 gotoxy(29,10);
 cout<<"ENTER MONTH : ";
 cin>>m;
 gotoxy(29,12);
 cout<<"ENTER YEAR : ";
 cin>>y;
 if(y>0&&y<10000&&m>0&&m<13)
 {
 now:
 d=totald(m,y);
 showc(d,m,y);
 char c;
 do
 {
 ifstream infile1;
  infile1.open("event.txt");
  if(infile1.fail())
  {
  cerr<<"error opening file"<<endl;
  }
  int t=0,d=1;
  if(g<2)
  {
  while(!infile1.eof())
  {if(d>4){break;}
  gotoxy(59,8+t);
  infile1>>readevent;
  cout<<"* "<<readevent<<endl;
  t=t+2;
  delay(500);
  d++,g++;
  }}else
  while(!infile1.eof())
  {if(d>4){break;}
  gotoxy(59,8+t);
  infile1>>readevent;
  cout<<"* "<<readevent<<endl;
  t=t+2;
  d++;
  }
  infile1.close();
  gotoxy(58,2);
  cout<<"CURRENT DATE AND TIME";
  gotoxy(56,3);
  todaytime();
 c=getch();
 switch(c)
 {
  case 72:
  if(++m>12) { ++y; m=1; }
  d=totald(m,y);
  //if(m==1) d++;
  showc(d,m,y);
  break;

  case 80:
  if(--m<1) {--y; m=12; }
  d=totald(m,y);
  //if(m==12) d--;
  showc(d,m,y);
  break;

  case 75:
  d=totald(m,--y);
  showc(d,m,y);
  break;

  case 77:
  d=totald(m,++y);
  showc(d,m,y);
  break;

  case 'g':
  goto here;
  case 'G':
  goto here;
  case '1':
  {goto1:
  clrscr();
  cout<<"ENTER DATE(ex-15 April) : ";
  cin>>day>>month;
  if(day>0&&day<=32)
  {
  cout<<"ENTER MEMO : ";
  cin>>memo;
  outfile.open("memo.txt",ios::app);
  outfile<<day<<"_"<<month<<"_"<<memo<<endl;
  outfile.close();
  goto now;
  }else
  {
  cout<<"YOUR DATE IS INVALID";
  goto goto1;
  }
  }
  case '2':
  {
  clrscr();
  gotoxy(33,1);
  cout<<"MEMO";
  cout<<"\n\n  ";
  ifstream infile;
  infile.open("memo.txt");
  if(infile.fail())
  {
  cerr<<"error opening file"<<endl;
  }

  while(!infile.eof())
  {
  infile>>readmemo;
  cout<<readmemo<<endl;
  }
  infile.close();

  cout<<"\n\n\n";
  cout<<"\n\nPress any key to return.";
  getch();
  goto now;
  }
  case '3':
  {goto2:
  clrscr();
  cout<<"Enter date(ex-15 April) \n ";
  cin>>eventday>>eventmonth;
  if(eventday>0&&eventday<=32)
  {
  cout<<"Enter Event : ";
  cin>>event;
  outfile1.open("event.txt",ios::app);
  outfile1<<eventday<<"_"<<eventmonth<<"_"<<event<<endl;
  outfile1.close();
  goto now;
  }
  else
  cout<<"PLEASE ENTER DATE AS EXAMPLE";
  getch();

  goto goto2;
  }
  case '4':
  {
  clrscr();
  gotoxy(33,1);
  cout<<"EVENTS";
  cout<<"\n\n";
  ifstream infile1;
  infile1.open("event.txt");
  if(infile1.fail())
  {
  cerr<<"error opening file"<<endl;
  }

  while(!infile1.eof())
  {
  infile1>>readevent1;
  cout<<readevent1<<endl;
  }
  infile1.close();

  cout<<"\n\n\n";
  cout<<"\n\nPress any key to return.";
  getch();
  goto now;
  }
  case '5':
    {
  converter();
  goto now;
  }
 }
}while(c!='e');
}
else
{
gotoxy(29,16);
cout<<"INVALID DATE ENTERED";
goto here;
}
}else
{
gotoxy(29,13);
cout<<"INCORRECT PASSWORD";
getch();
goto introduction;
}
}


int  totald(int m,int y)
{
 long unsigned td11=0;
  for(int i=1990; i<y; i++)
 {
  for(int m=1; m<=12; m++)
  {
   if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    td11=td11+31;
   if(m==4||m==6||m==9||m==11)
    td11=td11+30;
   if(m==2)
   {
    if(i%4==0)
     td11=td11+29;
    else
     td11=td11+28;
   }
  }
 }


 for(int j=1; j<m; j++)
 {
   if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)
    td11=td11+31;
   if(j==4||j==6||j==9||j==11)
    td11=td11+30;
   if(j==2)
   {
    if(y%4==0)
     td11=td11+29;
    else
     td11=td11+28;
   }
 }

 return ((td11+1)%7);
}

void showc(int s,int m,int y)
{
now:
int x[7][6];
int k;
if(s==0)
 k=1;
if(s==1)
 k=0;
if(s==2)
 k=-1;
if(s==3)
 k=-2;
if(s==4)
 k=-3;
if(s==5)
 k=-4;
if(s==6)
 k=-5;

for(int i=0; i<6; i++)
{
 for(int j=0; j<7; j++)
 {
  x[j][i]=k++;
 }
}
clrscr();
cout<<"-------------------------------------------------------------------------------\n";
gotoxy(37,2);
cout<<"CALENDER";
cout<<"\n\n\n\n\t\t\t";
if(m==1) cout<<"JAN\t"<<y;
if(m==2) cout<<"FEB\t"<<y;
if(m==3) cout<<"MAR\t"<<y;
if(m==4) cout<<"APR\t"<<y;
if(m==5) cout<<"MAY\t"<<y;
if(m==6) cout<<"JUNE\t"<<y;
if(m==7) cout<<"JULY\t"<<y;
if(m==8) cout<<"AUG\t"<<y;
if(m==9) cout<<"SEP\t"<<y;
if(m==10) cout<<"OCT\t"<<y;
if(m==11) cout<<"NOV\t"<<y;
if(m==12) cout<<"DEC\t"<<y;

cout<<"\n\n";
for(i=0; i<7; i++)
{
if(i==0) cout<<"SUN\t";
if(i==1) cout<<"MON\t";
if(i==2) cout<<"TUE\t";
if(i==3) cout<<"WED\t";
if(i==4) cout<<"THU\t";
if(i==5) cout<<"FRI\t";
if(i==6) cout<<"SAT\t";
if(x[i][0]>0) cout<<x[i][0]<<"\t"; else cout<<"\t";
cout<<x[i][1]<<"\t"<<x[i][2]<<"\t"<<x[i][3]<<"\t";
if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
 {
  if(x[i][4]<=31) cout<<x[i][4]<<"\t";
  if(x[i][5]<=31) cout<<x[i][5];
 }
else if(m==4||m==6||m==9||m==11)
 {
  if(x[i][4]<=30) cout<<x[i][4]<<"\t";
  if(x[i][5]<=30) cout<<x[i][5];
 }
else if(m==2)
{
 if(y%4==0)
  {
   if(x[i][4]<=29) cout<<x[i][4]<<"\t";
   if(x[i][5]<=29) cout<<x[i][5];
  }
 else
  {
   if(x[i][4]<=28) cout<<x[i][4]<<"\t";
   if(x[i][5]<=28) cout<<x[i][5];
  }
}
cout<<"\n";
}
gotoxy(2,18);
cout<<"UP\t-GO TO NEXT MONTH\nDown\t-GO TO PREVOIUS MONTH\n";
cout<<"LEFT\t-GO TO PREVOIUS YEAR\nRIGHT\t-GO TO NEXT YEAR";
cout<<"\nG\t-GO TO PARTICULAR MONTH\nE\t-EXIT";
gotoxy(56,18);
cout<<"PRESS 1 TO CREATE MEMO";
gotoxy(56,19);
cout<<"PRESS 2 TO SHOW MEMO";
gotoxy(56,20);
cout<<"PRESS 3 TO ADD EVENT";
gotoxy(56,21);
cout<<"PRESS 4 TO SHOW EVENT";
gotoxy(56,22);
cout<<"PRESS 5 TO CONVERT DATE";
gotoxy(63,5);
cout<<"MAIN EVENT";
gotoxy(56,4);
cout<<"------------------------";
gotoxy(56,16);
cout<<"------------------------";
gotoxy(1,25);
cout<<"-------------------------------------------------------------------------------";
gotoxy(1,4);
cout<<"-----------------------------------------------------";
gotoxy(1,16);
cout<<"-----------------------------------------------------";
gotoxy(30,3);
cout<<"**********************";
gotoxy(62,6);
cout<<"************";
}
void intro()
{
clrscr();
gotoxy(29,10);
cout<<"WELCOME TO OUR PROGRAM";
gotoxy(35,12);
cout<<"CALENDER";
gotoxy(28,9);
cout<<"-------------------------";
gotoxy(28,13);
cout<<"-------------------------";
delay(2000);
}

void converter()
{
clrscr();
int sny=2000,snd=1,sey=1943,sem=4,sed=14,i,j,k,totaldayscount=0,nepyear,nepmonth,nepday,nepdiff,months,iey,iem,ied,endday=0,l,day=1;
int nepdays[]={30,32,31,32,31,30,30,30,29,30,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,30,32,31,32,31,30,30,30,29,30,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,29,30,30,29,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,29,30,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,29,30,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,
30,30,29,30,29,31,31,31,31,32,31,31,30,29,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,30,31,32,31,32,31,30,30,30,29,30,29,31,31,31,31,32,31,31,30,29,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,30,32,31,32,31,30,30,30,29,30,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,31,32,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,30,32,31,32,31,30,30,30,29,30,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,30,32,31,32,31,31,29,30,30,29,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,
31,29,30,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,29,30,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,30,29,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,30,31,32,31,32,31,30,30,30,29,30,29,31,31,31,31,32,31,31,30,29,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,30,31,32,31,32,31,30,30,30,29,30,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,31,32,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,30,32,31,32,31,30,30,30,29,30,29,31,31,31,32,31,
31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,30,32,31,32,31,31,29,30,29,30,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,29,30,30,29,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,29,30,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,30,29,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,30,31,32,31,32,31,30,30,30,29,30,29,31,31,31,31,32,31,31,30,29,30,29,30,30,31,31,32,
31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,30,31,31,32,32,31,30,30,30,29,30,30,30,30,32,31,32,31,30,30,30,29,30,30,30,31,31,32,31,31,30,30,30,29,30,30,30,31,31,32,31,31,30,30,30,29,30,30,30,31,32,31,32,30,31,30,30,29,30,30,30,30,32,31,32,31,30,30,30,29,30,30,30,31,31,32,31,31,31,30,30,29,30,30,30,30,31,32,32,30,31,30,30,29,30,30,30,30,32,31,32,31,30,30,30,29,30,30,30,30,32,31,32,31,30,30,30,29,30,30,30};
int monthsofengyear[]={0,31,28,31,30,31,30,31,31,30,31,30,31 };/*months of english year*/
int monthsofengleapyear[]={0,31,29,31,30,31,30,31,31,30,31,30,31 };/*months of english leap year*/
cout<<"This program converts dates from 2000 to 2090 BS only";
cout<<"\nEnter the Nepali Date in BS: ";
cout<<"\nEnter the Year : ";
cin>>nepyear;
cout<<"\nEnter the Month : ";
cin>>nepmonth;
cout<<"\nEnter the Day : ";
cin>>nepday;
/*calculating the no of days between two nepali years*/
nepdiff=nepyear-sny;
if(nepdiff==0)/*when the entered day is equal to the starting limit of the array*/
{for(k=0;k<(nepmonth-1);k++)
{totaldayscount+=nepdays[k];
}
totaldayscount+=nepday-snd;
}
else
{
months=(nepdiff)*12;
for(i=0;i<months;i++)
{
	totaldayscount+=nepdays[i];


}
for(j=i;j<(i+(nepmonth-1));j++)/*here nepmonth is -1 because we need not to add complete month eg if it is ashar 20 the entire day of ashar is not added infact only days upto ashar 20 is added*/
{/*adding the remaining months to the totaldayscount*/
totaldayscount+=nepdays[j];
}
totaldayscount+=nepday-snd;/*here subtracting the snd bcoz it is already added at the beginning of the counting*/

}

/*FINDING EQUIVALENT ENGLISH DATE*/
iey=sey;/*assigning sey sem and sed to different variables because we need to alter the value of sey sem and sed in further programming*/
iem=sem;
ied=sed;
while(totaldayscount!=0)
{
	int l;
		if(iey%4==0)
		l=1;
		else
		l=0;
	if(l==1)
	{
	endday=monthsofengleapyear[iem];}
	else
	{
	endday=monthsofengyear[iem];
	}
	ied++;
	day++;     /*day is initialized as 1*/
	if(ied>endday)
	{iem++;
	ied=1;                /*here dropping the value of ied to 1 because it is the start of new month and we count from 1*/
	if(iem>12)
	{iey++;
	iem=1;                 /* here dropping the value of iem to 1 because it is the start of new year and we start counting from 1 of first month*/
	}
	}
		if(day>7)
		{day=1;
		}
	totaldayscount--;
}
cout<<"The Converted Date in AD: ";
cout<<"\tYear "<<iey<<" AD";
cout<<"\tMonth "<<iem;
cout<<"\tDay "<<ied;
getch();
}
void todaytime(void)
{
time_t current_time;
char* c_time_string;

/* Obtain current time. */
current_time = time(NULL);

 /* Convert to local time format. */
 c_time_string = ctime(&current_time);

 /* Print to stdout. ctime() has already added a terminating newline character. */
 (void) printf("%s", c_time_string);
 }