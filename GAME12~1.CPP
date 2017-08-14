//sign up and sign in
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
void page1();
void page1player();
void logo();
void looks();
void clean();
void maingame();
void map();
void map1();
void player();
void player1();
void player3();
void player4();
void loss();
void homepage();
void win(long int hc);
void rules();
void highscr();
void cross(int a,int b,int lx,int ly,int rx,int ry,int &ctr);
int cross1(int x,int y);
void invalid();
void layout2();
void player5();
class records
{
    char name[30],gamingname[30];
    public:
    void disp();
    void login();
    void wtf();
    char age[14];
    int highscore;
    records()
    {
     highscore = 0;
    }
}ch1;
void records::login()
{

    clean();
    char m[14];
    char up2;
    logo();
    setfillstyle(SOLID_FILL,BLUE);
    bar(9,49,311,451);
    rectangle(420,75,540,100);
    gotoxy(56,6);cout<<" SIGN  IN ";
    gotoxy(49,15);cout<<"ID Number : RA";
    gets(m);
    ifstream ifile("game121.txt");
    ifile.seekg(0,ios::beg);
    ifile.read((char*)&ch1,sizeof(ch1));
    while(!ifile.eof())
    {
	if (strcmp(m,age)==0)
	{
	 gotoxy(14,15);cout<<" (Valid Entry) " ;
	 outtextxy(15,463,"                       Press any key to continue...");
	 up2=getch();
	 clean();
	 disp();
	 maingame();
	}
	ifile.read((char*)&ch1,sizeof(ch1));
    }
    ifile.close();
    gotoxy(14,15);cout<<" (Invalid Entry) " ;
    outtextxy(15,463,"                       Press any key to continue...");
    up2=getch();
    cout<<up2;
    clean();
    page1player();
}

void records::disp()
{
 clean();
 char asd;
 looks();
 setcolor(15);
 rectangle(5,5,getmaxx()-5,getmaxy()-5);
 rectangle(10,10,getmaxx()-10,getmaxy()-10);
 gotoxy(24,10);cout<<"WELCOME  :   "<<ch1.name<<" ( RA"<<ch1.age<<" )";
 while(asd!=' ')
 asd=getch();
 rules();
}
void invalid()
{
 gotoxy(45,17);cout<<" (Invalid Entry)...  TRY AGAIN ! ";
 outtextxy(15,463,"                       Press any key to continue...");
}
void page1()
{
 clean();
 logo();
 setfillstyle(SOLID_FILL,BLUE);
 bar(9,49,311,451);
 setfillstyle(SOLID_FILL,RED);
 bar(311,49,631,451);
 gotoxy(58,12);cout<<" SIGN  IN ";
 gotoxy(13,12);cout<<" SIGN  UP ";
 setcolor(10);
 outtextxy(307,181,"");
 setcolor(10);
 outtextxy(15,280,"       Press A to sign up                          Press D to sign in");
 setcolor(15);
 outtextxy(15,463,"                          Press spacebar to exit                          ");
 setcolor(3);
 outtextxy(30,221,"   (To Create New Account)                   (To Login Existing Account)");
}
void page1player()
{
 int x;
 char as;
 as:
 page1();
 as=getch();
 if(as=='a'||as=='A')
 {
  for(x=307;x>=177;x--)
  {
   delay(8);
   setcolor(0);
   outtextxy(x,181,"");
   setcolor(10);
   outtextxy(x-1,181,"");
  }
  ch1.wtf();
 }
 else if(as=='d'||as=='D')
 {
  for(x=307;x<=449;x++)
  {
   delay(8);
   setcolor(0);
   outtextxy(x,181,"");
   setcolor(10);
   outtextxy(x+1,181,"");
  }
  setcolor(15);
  ch1.login();
 }
 else if(as==' ')
 {
  clean();
  exit(0);
 }
 else
  goto as;
}
void logo()
{
    int z;
    rectangle(0,0,getmaxx(),getmaxy());
    rectangle(4,44,636,456);
    setfillstyle(SOLID_FILL,WHITE);
    bar(255,5,257,34);
    for(z=0;z<=10;z++)
    {
       bar(255+z,5+z,257+z,5+z);
    }
    for(z=0;z<=10;z++)
    {
     bar(265+z,15-z,267+z,15-z);
    }
    bar(275,5,277,34);
    setfillstyle(SOLID_FILL,GREEN);
    for(z=0;z<=15;z++)
    {
     bar(307-z,5+z+z,309-z,5+z+z);
    }
    for(z=0;z<=15;z++)
    {
     bar(307+z,5+z+z,309+z,5+z+z);
    }
    bar(301,17,315,19);
    setfillstyle(SOLID_FILL,WHITE);
    bar(338,5,353,7);
    for(z=0;z<=15;z++)
    {
      bar(352-z,5+z+z,354-z,5+z+z);
    }
    bar(338,33,353,35);
    bar(370,5,372,35);
    bar(370,5,386,7);
    bar(370,33,386,35);
    bar(370,17,378,19);
}
void records::wtf()
{
    char skrillex[14];
    int tre=0;
    records();
    ofstream ofile;
    ofile.open("game121.txt", ios::app);
    int i;
    char top1,up1;
    char arr[30];
    top1:
    clean();
    logo();
    setfillstyle(SOLID_FILL,RED);
    bar(311,49,631,451);
    rectangle(85,75,200,100);
    gotoxy(14,6);cout<<" SIGN  UP ";
    gotoxy(7,13);cout<<"(Only Alphabets Allowed)";
    gotoxy(7,11);cout<<"LOGIN NAME :  ";
    gets(name);
    if(strlen(name)>=1)
    {
     for(i=0;name[i]!='\0';i++)
     {
      if(isalpha(name[i]))
      {
       gotoxy(56,11);cout<<" (Valid Entry) ";
      }
      else
      {
       gotoxy(45,11);cout<<" (Invalid Entry)...  TRY AGAIN ! ";
       outtextxy(15,463,"                       Press any key to continue...");
       up1=getch();
       goto top1;
      }
     }
    }
    else
    {
     gotoxy(45,11);cout<<" (Invalid Entry)...  TRY AGAIN ! ";
     outtextxy(15,463,"                       Press any key to continue...");
     up1=getch();
     goto top1;
    }
    gotoxy(7,19);cout<<"(ON YOUR ID CARD)";
    gotoxy(7,17);cout<<"ID NUMBER : RA";
    //__________________________________________________
    gets(age);
    strcpy(skrillex,age);
    if(strlen(age)==13)
    {
     for(i=0;age[i]!='\0';i++)
     {
      if(isdigit(age[i]))
      {
       gotoxy(56,17);cout<<" (Valid Entry) " ;
      }
      else
      {
       invalid();
       up1=getch();
       page1player();
      }
     }
    }
    else
    {
     invalid();
     up1=getch();
     page1player();
    }
    gotoxy(7,25);cout<<"(Atleast 3 characters) ";
    gotoxy(7,23);cout<<"GAMING NAME :  ";
    //------------------------------------------------------
    gets(gamingname);
    if(strlen(gamingname)<3)
    {
     gotoxy(45,23);cout<<" TOO SHORT ! ";
     gotoxy(45,25);cout<<" (Invalid Entry)...  TRY AGAIN ! ";
     outtextxy(15,463,"                       Press any key to continue...");
     up1=getch();
     page1player();
    }
    gotoxy(56,23);cout<<" (Valid Entry) " ;
    ofile.write((char*)&ch1,sizeof(ch1));
    ofile.close();
    outtextxy(15,463,"                       Press any key to continue...");
    up1=getch();
    cout<<up1<<top1;
    disp();
}
void layout2()
{
   int K;
   setfillstyle(SOLID_FILL,WHITE);
   bar(255,65,257,94);
   for(K=0;K<=10;K++)
    bar(255+K,K+65,257+K,K+65);
   for(K=0;K<=10;K++)
    bar(265+K,75-K,267+K,75-K);
   bar(275,65,277,94);
   setfillstyle(SOLID_FILL,GREEN);
   for(K=0;K<=15;K++)
    bar(307-K,K+K+65,309-K,65+K+K);
   for(K=0;K<=15;K++)
    bar(307+K,K+K+65,309+K,K+K+65);
   bar(301,77,315,79);
   setfillstyle(SOLID_FILL,WHITE);
   bar(338,65,353,67);
   for(K=0;K<=15;K++)
    bar(352-K,65+K+K,354-K,K+K+65);
   bar(338,93,353,95);
   bar(370,65,372,95);
   bar(370,65,386,67);
   bar(370,93,386,95);
   bar(370,77,378,79);
}
void looks()
{
 setcolor(15);
 clean();
 clean();
 int K;
 setfillstyle(SOLID_FILL,WHITE);
 layout2();
 rectangle(63-5,200-5,getmaxx()-63+5,420+5);
 bar(63,200,getmaxx()-63,420);
 setfillstyle(SOLID_FILL,BLACK);
 bar(63+5,420-45,103+5,420-5);
 bar(63+5,420-35,573-5,420-15);
 bar(573-45,420-215,573-5,420-215+40),
 bar(63+5,420-115,573-5,420-95);
 bar(63+5,420-205,573-5,420-185);
 bar(573-25,420-95,573-5,420-15);
 bar(63+5,420-115,63+25,420-190);
 outtextxy(533,225,"END");
 outtextxy(103,393,"GO -->");
 setcolor(10);
 outtextxy(83,393,"");
 setcolor(15);
 outtextxy(15,443,"                       Press spacebar to continue...");
}
void clean()
{
  clrscr();
  cleardevice();
}
 void main()
{
 int gd=0,gm;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 page1player();
 getch();
 closegraph();
}
void maingame()
{
 while(1==1)
 {
  char ag;
  homepage();
  ag=getch();
  if(ag=='1')
  {
   map1();
   player1();
  }
  else if(ag=='3')
  {
   map();
   player();
  }
  if(ag=='2')
  {
   map1();
   player3();
  }
  if(ag=='4')
  {
   map();
   player4();
  }
  if(ag=='5')
  {
   map();
   player5();
  }
  else if(ag=='x'||ag=='X')
  {
   rules();
  }

  else if(ag=='z'||ag=='Z')
  {
   clean();
   page1player();
  }
 }
}

void map()
{
 clean();
 int z;
 logo();
 bar(9,49,631,451);
 setfillstyle(SOLID_FILL,BLACK);
 bar(10,400,60,450);
 bar(60,410,621,441);
 bar(600,350,621,441);
 bar(20,334,621,351);
 for(z=0;z<=60;z+=1)
  bar(20+z,315-z,40+z,335-z);
 for(z=0;z<=65;z+=1)
  bar(80-z,255-z,90-z,265-z);
 for(z=0;z<=70;z+=1)
  bar(15+(2*z),190-z,25+(2*z),200-z);
 bar(150,120,165,300);
 bar(150,295,600,310);
 bar(180,245,600,260);
 bar(585,260,600,310);
 for(z=0;z<=30;z+=1)
  bar(180+(6*z),235-(2*z),195+(6*z),245-(z*2));
 for(z=0;z<=25;z+=1)
  bar(450+(6*z),175+(2*z),465+(6*z),185+(z*2));
 bar(360,175,449,185);
 bar(603,166,615,225);
 bar(210,150,615,165);
 bar(210,70,220,165);
 bar(210,70,580,80);
 bar(580,50,630,100);
 setcolor(7);
 outtextxy(593,73,"END");
 setcolor(15);
 outtextxy(40,425,"GO! -->");
 setcolor(10);
 outtextxy(15,425,"");
 outtextxy(15,463,"   W -> UP    A -> LEFT    S -> DOWN    D -> RIGHT    SPACEBAR -> EXIT");
}
int cross1(int x,int y)
{
    int ct=0,d;
    cross(x,y,11,401,54,444,ct);
    cross(x,y,55,411,614,434,ct);
    cross(x,y,601,335,614,434,ct);
    cross(x,y,21,335,604,344,ct);
    cross(x,y,21,315,36,343,ct);
    for(d=0;d<=58;d+=2)
     cross(x,y,21+d,313-d,36+d,328-d,ct);
    for(d=0;d<63;d+=2)
     cross(x,y,77-d,253-d,82-d,256-d,ct);
    for(d=0;d<=70;d+=2)
    {
     cross(x,y,15+(2*d),191-d,20+(2*d),194-d,ct);
     cross(x,y,17+(2*d),189-d,22+(2*d),192-d,ct);
    }
    cross(x,y,151,121,158,294,ct);
    cross(x,y,151,295,594,304,ct);
    cross(x,y,585,245,594,304,ct);
    cross(x,y,181,245,594,254,ct);
    for(d=0;d<=30;d++)
     cross(x,y,181+(6*d),235-(2*d),196+(6*d),236-(d*2),ct);
    cross(x,y,181,235,188,254,ct);
    cross(x,y,361,175,458,178,ct);
    for(d=0;d<=25;d++)
     cross(x,y,451+(6*d),175+(2*d),458+(6*d),178+(d*2),ct);
    cross(x,y,603,151,608,228,ct);
    cross(x,y,211,151,608,158,ct);
    cross(x,y,211,71,214,158,ct);
    cross(x,y,211,71,578,74,ct);
    if(x==579&&(y==71||y==73))
     return ct;
     //win(tanya);
    if(ct==0)
     loss();
   return 0;
}
void player4()
{
 int x=15,y=425,anshul=1,ct,d;
 long int tanya=100000;
 char as;
 while(1==1)
 {
  as=getch();
  if(as=='d'||as=='D')
  {
   do{
    tanya=tanya-anshul;
    gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
    // cout<<x<<","<<y<<" ";
    int hj=cross1(x,y);
    if(hj==1)
     win(tanya);
    delay(35);
    setcolor(0);
    outtextxy(x++,y,"");
    setcolor(10);
    outtextxy(1+x++,y,"");
   }while(!kbhit());
  }
  else if(as=='a'||as=='A')
  {
   do{
   tanya=tanya-anshul;
   gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
 // cout<<x<<","<<y<<" ";
  int hj=cross1(x,y);
    if(hj==1)
     win(tanya);
   delay(35);
   setcolor(0);
   outtextxy(x--,y,"");
   setcolor(10);
   outtextxy((x--)-1,y,"");
   }while(!kbhit());
  }
  else if(as=='s'||as=='S')
  {
   do{
    tanya=tanya-anshul;
  gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
 // cout<<x<<","<<y<<" ";
  int hj=cross1(x,y);
    if(hj==1)
     win(tanya);
   delay(35);
   setcolor(0);
   outtextxy(x,y++,"");
   setcolor(10);
   outtextxy(x,1+y++,"");
   }while(!kbhit());
  }
  else if(as=='w'||as=='W')
  {
   do{
    tanya=tanya-anshul;
  gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
 // cout<<x<<","<<y<<" ";
  int hj=cross1(x,y);
    if(hj==1)
     win(tanya);
   delay(35);
   setcolor(0);
   outtextxy(x,y--,"");
   setcolor(10);
   outtextxy(x,(y--)-1,"");
   }while(!kbhit());
  }
  else if(as==' ')
  {
   clean();
   return;
  }
 }
}
void player5()
{
 int x=15,y=425,anshul=1,ct,d;
 long int tanya=100000;
 char as;
 while(1==1)
 {
  as=getch();
  if(as=='d'||as=='D')
  {
   do{
    tanya=tanya-anshul;
    gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
    // cout<<x<<","<<y<<" ";
    int hj=cross1(x,y);
    if(hj==1)
     win(tanya);
    delay(15);
    setcolor(0);
    outtextxy(x++,y,"");
    setcolor(10);
    outtextxy(1+x++,y,"");
   }while(!kbhit());
  }
  else if(as=='a'||as=='A')
  {
    do{
    tanya=tanya-anshul;
  gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
 // cout<<x<<","<<y<<" ";
  int hj=cross1(x,y);
    if(hj==1)
     win(tanya);
   delay(15);
   setcolor(0);
   outtextxy(x--,y,"");
   setcolor(10);
   outtextxy((x--)-1,y,"");
   }while(!kbhit());
  }
  else if(as=='s'||as=='S')
  {
   do{
    tanya=tanya-anshul;
  gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
 // cout<<x<<","<<y<<" ";
  int hj=cross1(x,y);
    if(hj==1)
     win(tanya);
   delay(15);
   setcolor(0);
   outtextxy(x,y++,"");
   setcolor(10);
   outtextxy(x,1+y++,"");
   }while(!kbhit());
  }
  else if(as=='w'||as=='W')
  {
   do{
    tanya=tanya-anshul;
  gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
 // cout<<x<<","<<y<<" ";
  int hj=cross1(x,y);
    if(hj==1)
     win(tanya);
   delay(15);
   setcolor(0);
   outtextxy(x,y--,"");
   setcolor(10);
   outtextxy(x,(y--)-1,"");
   }while(!kbhit());
  }
  else if(as==' ')
  {
   clean();
   return;
  }
 }
}
void cross(int a,int b,int lx,int ly,int rx,int ry,int &ctr)
{
 for(int i=lx;i<rx;i+=2)
  for(int j=ly;j<ry;j+=2)
   if(a==i&&b==j)
    ctr++;
}
void player()
{
 int x=15,y=425,anshul=1,ct,d;
 long int tanya=100000;
 char as;
 while(1==1)
 {
  tanya=tanya-anshul;
  gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
  // cout<<x<<","<<y<<" ";
  ct=0;
  cross(x,y,11,401,54,444,ct);
  cross(x,y,55,411,614,434,ct);
  cross(x,y,601,335,614,434,ct);
  cross(x,y,21,335,604,344,ct);
  cross(x,y,21,315,36,343,ct);
  for(d=0;d<=58;d+=2)
   cross(x,y,21+d,313-d,36+d,328-d,ct);
  for(d=0;d<63;d+=2)
   cross(x,y,77-d,253-d,82-d,256-d,ct);
  for(d=0;d<=70;d+=2)
  {
   cross(x,y,15+(2*d),191-d,20+(2*d),194-d,ct);
   cross(x,y,17+(2*d),189-d,22+(2*d),192-d,ct);
  }
  cross(x,y,151,121,158,294,ct);
  cross(x,y,151,295,594,304,ct);
  cross(x,y,585,245,594,304,ct);
  cross(x,y,181,245,594,254,ct);
  for(d=0;d<=30;d++)
   cross(x,y,181+(6*d),235-(2*d),196+(6*d),236-(d*2),ct);
  cross(x,y,181,235,188,254,ct);
  cross(x,y,361,175,458,178,ct);
  for(d=0;d<=25;d++)
   cross(x,y,451+(6*d),175+(2*d),458+(6*d),178+(d*2),ct);
  cross(x,y,603,151,608,228,ct);
  cross(x,y,211,151,608,158,ct);
  cross(x,y,211,71,214,158,ct);
  cross(x,y,211,71,578,74,ct);
  if(x==579&&(y==71||y==73))
  win(tanya);
  if(ct==0)
   loss();
  as=getch();
  if(as=='d'||as=='D')
  {
   setcolor(0);
   outtextxy(x++,y,"");
   setcolor(10);
   outtextxy(1+x++,y,"");
  }
  else if(as=='a'||as=='A')
  {
   setcolor(0);
   outtextxy(x--,y,"");
   setcolor(10);
   outtextxy((x--)-1,y,"");
  }
  else if(as=='s'||as=='S')
  {
   setcolor(0);
   outtextxy(x,y++,"");
   setcolor(10);
   outtextxy(x,1+y++,"");
  }
  else if(as=='w'||as=='W')
  {
   setcolor(0);
   outtextxy(x,y--,"");
   setcolor(10);
   outtextxy(x,(y--)-1,"");
  }
  else if(as==' ')
  {
   clean();
   return;
  }
 }
}
void map1()
{
 clean();
 logo();
 bar(9,49,631,451);
 setfillstyle(SOLID_FILL,BLACK);     //path construction starts from here
 bar(10,400,60,450);      //1
 bar(60,410,620,440);      //2
 bar(600,350,620,440);      //3
 bar(20,260,610,280); //6
 bar(20,260,40,350);      //5
 bar(20,335,620,350);     //4
 bar(600,260,610,180); //7
 bar(40,190,610,180);  //8
 bar(40,190,50,130); //9
 bar(40,120,600,130);    //10
 bar(590,130,600,100); //11
 bar(580,50,630,100); //12
 setcolor(7);
 outtextxy(593,73,"END");
 setcolor(15);
 outtextxy(40,425,"GO! --->");
  setcolor(10);
 outtextxy(15,425,"");
 outtextxy(15,463,"   W -> UP    A -> LEFT    S -> DOWN    D -> RIGHT    SPACEBAR -> EXIT");
}
void player1()
{
 int x=15,y=425,anshul=1,ct,d;
 long int tanya=100000;
 char as;
 while(1==1)
 {
  tanya=tanya-anshul;
  gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
 // cout<<x<<","<<y<<" ";
  ct=0;
  cross(x,y,11,401,54,444,ct);
  cross(x,y,55,411,614,434,ct);
  cross(x,y,601,335,614,434,ct);
  cross(x,y,21,335,604,344,ct);
  cross(x,y,21,261,34,344,ct);
  cross(x,y,21,261,604,274,ct);
  cross(x,y,601,181,604,274,ct);
  cross(x,y,41,181,604,184,ct);
  cross(x,y,41,121,44,184,ct);
  cross(x,y,41,121,594,124,ct);
  cross(x,y,591,97,594,124,ct);
  if((x==591||x==593)&&y==97)
   win(tanya);
  if(ct==0)
  loss();
  as=getch();
  if(as=='d'||as=='D')
  {
   setcolor(0);
   outtextxy(x++,y,"");
   setcolor(10);
   outtextxy(1+x++,y,"");
  }
  else if(as=='a'||as=='A')
  {
   setcolor(0);
   outtextxy(x--,y,"");
   setcolor(10);
   outtextxy((x--)-1,y,"");
  }
  else if(as=='s'||as=='S')
  {
   setcolor(0);
   outtextxy(x,y++,"");
   setcolor(10);
   outtextxy(x,1+y++,"");
  }
  else if(as=='w'||as=='W')
  {
   setcolor(0);
   outtextxy(x,y--,"");
   setcolor(10);
   outtextxy(x,(y--)-1,"");
  }
  else if(as==' ')
  {
   clean();
   return;
  }
 }
}
void player3()
{
 int x=15,y=425,anshul=1,ct,d;
 long int tanya=100000;
 char as;
 while(1==1)
 {
  as=getch();
  if(as=='d'||as=='D')
  {
   do{
    tanya=tanya-anshul;
    gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
    // cout<<x<<","<<y<<" ";
    ct=0;
    cross(x,y,11,401,54,444,ct);
    cross(x,y,55,411,614,434,ct);
    cross(x,y,601,335,614,434,ct);
    cross(x,y,21,335,604,344,ct);
    cross(x,y,21,261,34,344,ct);
    cross(x,y,21,261,604,274,ct);
    cross(x,y,601,181,604,274,ct);
    cross(x,y,41,181,604,184,ct);
    cross(x,y,41,121,44,184,ct);
    cross(x,y,41,121,594,124,ct);
    cross(x,y,591,97,594,124,ct);
    if((x==591||x==593)&&y==97)
     win(tanya);
    if(ct==0)
     loss();
    delay(18);
    setcolor(0);
    outtextxy(x++,y,"");
    setcolor(10);
    outtextxy(1+x++,y,"");
   }while(!kbhit());
  }
  else if(as=='a'||as=='A')
  {
   do{
    tanya=tanya-anshul;
    gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
    // cout<<x<<","<<y<<" ";
    ct=0;
    cross(x,y,11,401,54,444,ct);
    cross(x,y,55,411,614,434,ct);
    cross(x,y,601,335,614,434,ct);
    cross(x,y,21,335,604,344,ct);
    cross(x,y,21,261,34,344,ct);
    cross(x,y,21,261,604,274,ct);
    cross(x,y,601,181,604,274,ct);
    cross(x,y,41,181,604,184,ct);
    cross(x,y,41,121,44,184,ct);
    cross(x,y,41,121,594,124,ct);
    cross(x,y,591,97,594,124,ct);
    if((x==591||x==593)&&y==97)
     win(tanya);
    if(ct==0)
     loss();
    delay(18);
    setcolor(0);
    outtextxy(x--,y,"");
    setcolor(10);
    outtextxy((x--)-1,y,"");
   }while(!kbhit());
  }
  else if(as=='s'||as=='S')
  {
   do{
    tanya=tanya-anshul;
    gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
    // cout<<x<<","<<y<<" ";
    ct=0;
    cross(x,y,11,401,54,444,ct);
    cross(x,y,55,411,614,434,ct);
    cross(x,y,601,335,614,434,ct);
    cross(x,y,21,335,604,344,ct);
    cross(x,y,21,261,34,344,ct);
    cross(x,y,21,261,604,274,ct);
    cross(x,y,601,181,604,274,ct);
    cross(x,y,41,181,604,184,ct);
    cross(x,y,41,121,44,184,ct);
    cross(x,y,41,121,594,124,ct);
    cross(x,y,591,97,594,124,ct);
    if((x==591||x==593)&&y==97)
     win(tanya);
    if(ct==0)
     loss();
    delay(18);
    setcolor(0);
    outtextxy(x,y++,"");
    setcolor(10);
    outtextxy(x,1+y++,"");
   }while(!kbhit());
  }
  else if(as=='w'||as=='W')
  {
   do{
    tanya=tanya-anshul;
    gotoxy(4,5);cout<<" Score = "<<tanya<<" ";
    // cout<<x<<","<<y<<" ";
    ct=0;
    cross(x,y,11,401,54,444,ct);
    cross(x,y,55,411,614,434,ct);
    cross(x,y,601,335,614,434,ct);
    cross(x,y,21,335,604,344,ct);
    cross(x,y,21,261,34,344,ct);
    cross(x,y,21,261,604,274,ct);
    cross(x,y,601,181,604,274,ct);
    cross(x,y,41,181,604,184,ct);
    cross(x,y,41,121,44,184,ct);
    cross(x,y,41,121,594,124,ct);
    cross(x,y,591,97,594,124,ct);
    if((x==591||x==593)&&y==97)
     win(tanya);
    if(ct==0)
     loss();
    delay(18);
    setcolor(0);
    outtextxy(x,y--,"");
    setcolor(10);
    outtextxy(x,(y--)-1,"");
   }while(!kbhit());
  }
  else if(as==' ')
  {
   clean();
   return;
  }
 }
}
void homepage()
{
   clean();
   layout2();
   setcolor(15);
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t > CHOOSE LEVEL TO START :";
   cout<<"\n\t\t\t\t\t  > LEVEL 1 --> PRESS '1'";
   cout<<"\n\t\t\t\t\t  > LEVEL 2 --> PRESS '2'";
   cout<<"\n\t\t\t\t\t  > LEVEL 3 --> PRESS '3'";
   cout<<"\n\t\t\t\t\t  > LEVEL 4 --> PRESS '4'";
   cout<<"\n\t\t\t\t\t  > LEVEL 5 --> PRESS '5'";
   cout<<"\n\n\n\t\t > PRESS 'X' TO VIEW CONTROLS & RULES :";
   cout<<"\n\n\n\t\t > PRESS 'Z' TO EXIT :";
   rectangle(20,150,getmaxx()-20,400);
   rectangle(15,145,getmaxx()-15,405);
   rectangle(5,5,getmaxx()-5,getmaxy()-5);
   rectangle(10,10,getmaxx()-10,getmaxy()-10);
   setfillstyle(SOLID_FILL,BLACK);
   bar(5,110,10,getmaxy()-40);
   bar(getmaxx()-10,110,getmaxx()-5,getmaxy()-40);
}
void rules()
{
  char ad;
  clean();
  layout2();
  outtextxy(130,145," C O N T R O L S :-");
  outtextxy(160,175,"W  -->  UP");
  outtextxy(160,190,"A  -->  LEFT");
  outtextxy(160,205,"S  -->  DOWN");
  outtextxy(160,220,"D  -->  RIGHT");
  outtextxy(160,235,"SPACEBAR  -->  EXIT");
  outtextxy(130,275," R U L E S :-");
  outtextxy(160,305,"> Game ends when  collides with any wall in maze.");
  outtextxy(160,320,"> Highscore is counted if you win.");
  outtextxy(160,335,"> Game pauses automatically if no key is pressed.");
  outtextxy(160,350,"> OR game pauses if any key is pressed(depends on level).");
  outtextxy(210,430,"Press spacebar to continue ...");
  rectangle(5,5,getmaxx()-5,getmaxy()-5);
  rectangle(10,10,getmaxx()-10,getmaxy()-10);
  while(ad!=' ')
  ad=getch();
  maingame();
}
void loss()
{
  char c;
  clean();
  looks();
  setcolor(15);
  rectangle(5,5,getmaxx()-5,getmaxy()-5);
  setcolor(10);
  gotoxy(31,10);cout<<"G A M E      O V E R   ";
  while(c!=' ')
   c=getch();
  maingame();
}
void win(long int hc)
{
  clean();
  char c;
  looks();
  rectangle(5,5,getmaxx()-5,getmaxy()-5);
  setcolor(10);
  gotoxy(22,10);cout<<"Y O U    W I N !     Your Score : "<<hc;
  while(c!=' ')
   c=getch();
  maingame();
}