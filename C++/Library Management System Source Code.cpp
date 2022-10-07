#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<iomanip.h>
class lib
{
public:
char name[20];
int clas,rollno;
void get()
{cout<<"*******enter the details of the student:"<<endl;
cout<<"enter the name:"<<endl;
gets(name);
cout<<"enter the class:"<<endl;
cin>>clas;
cout<<"enter the rollno:"<<endl;
cin>>rollno;
}
void show()
{
cout<<"********DETAILS ADDED ARE***********:"<<endl;
cout<<name<<endl;
cout<<clas<<endl;
cout<<rollno<<endl;
}
};
void main()
{ clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
setbkcolor(MAGENTA);
setcolor(YELLOW);
rectangle(10,10,630,470);
settextstyle(7,0,6);
outtextxy(200,15,"WELCOME");
outtextxy(250,200,"TO");
settextstyle(7,0,6);
outtextxy(70,370," LIBRARY");
sleep(2);
clearviewport();
setbkcolor(BLACK);
setcolor(YELLOW);
rectangle(8,8,630,470);
settextstyle(7,0,6);
outtextxy (200,15,"DEVELOPED BY");
outtextxy(250,200,"Navi Arora");
settextstyle(7,0,6);
sleep(2);
clearviewport();
int x;
cout<<"enter your choice:"<<endl;
cout<<"1   TO ADD:"<<endl;
cout<<"2 TO SHOW:"<<endl;
cout<<"3 TO SEARCH:"<<endl;
cout<<"4 TO MODIFY:"<<endl;
cout<<"5 TO DELETE:"<<endl;
cout<<"6 TO EXIT:"<<endl;
cin>>x;
switch(x)
{
case 1:
{
 char ch='y';
lib s;
fstream t;
t.open("navi_arora.txt",ios::binary|ios::out|ios::app|ios::in);
while(ch=='y'||ch=='Y')
{
s.get();
t.write((char*)&s,sizeof(lib));
cout<<"do you want to add more(y/n)....:"<<endl;
cin>>ch;
}
}
 
case 2:
{
lib s;
fstream t;
t.open("navi_arora.txt",ios::binary|ios::out|ios::app|ios::in);
t.seekg(0);
while(t.read((char*)&s,sizeof(lib)))
{
s.show();
}
}
break;
case 3:
{ int a[20];
lib s;
fstream t;
t.open("navi_arora.txt",ios::binary|ios::out,ios::app|ios::in);
t.seekg(0);
cout<<"enter the name you want to search:"<<endl;
for(int i=0;i<=20;i++)
{
cin>>a[i];
while(t.read((char*)&s,sizeof(lib)))
{
 
 
s.show();
}
cout<<"name not found:";
}
}
}
}