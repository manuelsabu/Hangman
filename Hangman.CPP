//Hangman The Game
#include<iostream>
#include<curses.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<fstream>
#include <termios.h>
#include <stdio.h>

using namespace std;


//gotoxy function
void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

struct instruct
{
 char step[8],inst[40];
}a,b,c,d;

//**************************************************************************
struct word
{
 char word[15],clue[30];                         //structure for the word and clue
}x;

static struct termios old, new1;

/* Initialize new1 terminal i/o settings */
void initTermios(int echo)
{
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    new1 = old; /* make new1 settings same as old settings */
    new1.c_lflag &= ~ICANON; /* disable buffered i/o */
    new1.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
    tcsetattr(0, TCSANOW, &new1); /* use these new1 terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* Read 1 character without echo */
char getch1()
{
    return getch_(0);
}

/* Read 1 character with echo */
char getche(void)
{
    return getch_(1);
}

//**************************************************************************
class hangman
{
 public:
 void file();
 void border1();
 void plays(int);
 void hang();
 void man(int);
 void win();
 void lose();
 void game(char[],char[],int,int);
 void enter();
 void instruction();
 void credits();
 void load();
    
}s;
//**************************************************************************

void hangman::plays(int n)
{
switch(n)
{
 case 1:
 {
  //sound(268);
  //delay(50);
  break;
 }
 case 2:
 {
  //sound(150);
  //delay(35);
 break;
 }
 case 3:
 {
   //sound(960);
   //delay(200);
   //sound(1280);
   //delay(300);
   //sound(960);
   //delay(200);
   //sound(1280);
   //delay(500);
 break;
 }
 case 4:
 {
  //sound(685);
  //delay(400);
  //sound(535);
  //delay(400);
  //sound(500);
  //delay(600);
  //nosound();
 break;
 }
}
//nosound();
}

void hangman::border1()
{
 system("clear");
 int i;
 cout<<"ษ";
 for (int i=0;i<77;i++)                             //border1 creation with title
 {
  cout<<"อ";
 }
for (int i=0;i<23;i++)
{
 cout<<"\nบ";
}
gotoxy(1,25);
cout<<"ศ";

for (int i=0;i<77;i++)
{
 cout<<"อ";
}
gotoxy(79,25);
cout<<"ผ";
gotoxy(79,1);
cout<<"ป";

for (int i=2;i<25;i++)
{
 gotoxy(79,i);
 cout<<"บ";
}
 gotoxy(32,1);
{
//////textcolor(YELLOW);
puts(" Hangman The Game ");
////textcolor(WHITE);
}
}

//**************************************************************************
void hangman::win()
{
char r,select;                                    //If you win
system("clear");
////textcolor(WHITE);
border1();
////textcolor(GREEN+BLINK);
//delay(300);
gotoxy(5,6);
puts("!!! !!!  YY   YY  OOOOO  UU   UU     WW      WW IIIII NN   NN  !!! !!!");
gotoxy(5,7);
puts("!!! !!!  YY   YY OO   OO UU   UU     WW      WW  III  NNN  NN  !!! !!!");
gotoxy(5,8);
puts("!!! !!!   YYYYY  OO   OO UU   UU     WW   W  WW  III  NN N NN  !!! !!!");
gotoxy(5,9);
puts("           YYY   OO   OO UU   UU      WW WWW WW  III  NN  NNN         ");
gotoxy(5,10);
puts("!!! !!!    YYY    OOOO0   UUUUU        WW   WW  IIIII NN   NN  !!! !!!");


gotoxy(27,13);
cout<<"Would you like to play again?";
gotoxy(35,15);
////textcolor(GREEN);
puts("PLAY AGAIN!!");
gotoxy(30,16);
puts("No Thanks I'll Exit");

plays(3);
r=getch1();

if(r==72)
{
up:
plays(2);
gotoxy(35,15);
////textcolor(LIGHTGREEN+BLINK);
puts("PLAY AGAIN!!");
gotoxy(50,15);
puts("<=");
//textcolor(GREEN);
gotoxy(30,16);
puts("No Thanks I'll Exit");
gotoxy(50,16);
puts("   ");

s1:
 select=getch1();
 if(select==13)
 {
  plays(1);
  //textcolor(WHITE);
  int main();
  main();
 }
 else if(select==80)
 {
  goto down;
 }
 else
 {
  goto s1;
 }
}

 else
 {
  down:
  plays(2);
  gotoxy(35,15);
  //textcolor(GREEN);
  puts("PLAY AGAIN!!     ");
  //textcolor(LIGHTGREEN+BLINK);
  gotoxy(30,16);
  puts("No Thanks I'll Exit");
  gotoxy(50,16);
  //textcolor(LIGHTGREEN);
  puts("<=");
  gotoxy(50,15);
  puts("   ");

s2:
 select=getch1();
 if(select==13)
  {
   plays(1);
   exit(0);
  }
  else if(select==72)
  {
   goto up;
  }
  else
  {
   goto s2;
  }
 }
}


//**************************************************************************
void hangman::lose()
{
char r,select;
system("clear");                                                //if you lose
//textcolor(WHITE);
border1();
//textcolor(RED+BLINK);
//delay(300);
gotoxy(2,6);
puts("         YY   YY  OOOOO  UU   UU     LL       OOOOO   SSSSS  EEEEEEE        ");
gotoxy(2,7);
puts("         YY   YY OO   OO UU   UU     LL      OO   OO SS      EE             ");
gotoxy(2,8);
puts("          YYYYY  OO   OO UU   UU     LL      OO   OO  SSSSS  EEEEE          ");
gotoxy(2,9);
puts(" ... ...   YYY   OO   OO UU   UU     LL      OO   OO      SS EE      ... ...");
gotoxy(2,10);
puts(" ... ...   YYY    OOOO0   UUUUU      LLLLLLL  OOOO0   SSSSS  EEEEEEE ... ...");


gotoxy(27,13);
cout<<"Would you like to play again?";
gotoxy(35,15);
//textcolor(RED);
puts("PLAY AGAIN!!");
gotoxy(30,16);
puts("No Thanks I'll Exit");

plays(4);
r=getch1();

if(r==72)
{
 up:
 plays(2);
 gotoxy(35,15);
 //textcolor(LIGHTRED+BLINK);
 puts("PLAY AGAIN!!");
 gotoxy(50,15);
 puts("<=");
 //textcolor(RED);
 gotoxy(30,16);
 puts("No Thanks I'll Exit");
 gotoxy(50,16);
 puts("   ");

s1:
 select=getch1();
 if(select==13)
 {
  plays(1);
  //textcolor(WHITE);
  int main();
  main();
 }
 else if(select==80)
 {
  goto down;
 }
 else
 {
  goto s1;
 }
}

else
{
 down:
 plays(2);
 gotoxy(35,15);
 //textcolor(RED);
 puts("PLAY AGAIN!!     ");
 //textcolor(LIGHTRED+BLINK);
 gotoxy(30,16);
 puts("No Thanks I'll Exit");
 gotoxy(50,16);
 //textcolor(LIGHTRED);
 puts("<=");
 gotoxy(50,15);
 puts("   ");

s2:
 select=getch1();
 if(select==13)
  {
   plays(1);
   exit(0);
  }
  else if(select==72)
  {
   goto up;
  }
  else
  {
   goto s2;
  }
 }
}

//**************************************************************************
void hangman::man(int x)
{
 switch(x)
 {
  case 0:
  { gotoxy(1,8);
	cout << "บ\t\t\t\t_______  " << endl;                       //first picture
	cout << "บ\t\t\t\t|     |  " << endl;
	cout << "บ\t\t\t\t|        " << endl;
	cout << "บ\t\t\t\t|        " << endl;
	cout << "บ\t\t\t\t|        " << endl;
	cout << "บ\t\t\t\t|        " << endl;
   break;
  }

  case 1:
  { gotoxy(1,8);
	cout << "บ\t\t\t\t_______  " << endl;                      //first wrong guess
	cout << "บ\t\t\t\t|     |  " << endl;
	cout << "บ\t\t\t\t|     O  " << endl;
	cout << "บ\t\t\t\t|        " << endl;
	cout << "บ\t\t\t\t|        " << endl;
	cout << "บ\t\t\t\t|        " << endl;
   break;
  }

  case 2:
  { gotoxy(1,8);
	cout << "บ\t\t\t\t_______  " << endl;                      //second wrong guess
	cout << "บ\t\t\t\t|     |  " << endl;
	cout << "บ\t\t\t\t|     O  " << endl;
	cout << "บ\t\t\t\t|     I  " << endl;
	cout << "บ\t\t\t\t|        " << endl;
	cout << "บ\t\t\t\t|        " << endl;
  break;
  }

  case 3:
  { gotoxy(1,8);
	cout << "บ\t\t\t\t_______  " << endl;                     //third wrong guess
	cout << "บ\t\t\t\t|     |  " << endl;
	cout << "บ\t\t\t\t|     O  " << endl;
	cout << "บ\t\t\t\t|    /I  " << endl;
	cout << "บ\t\t\t\t|        " << endl;
	cout << "บ\t\t\t\t|        " << endl;
   break;
  }

  case 4:
  { gotoxy(1,8);
	cout << "บ\t\t\t\t_______  " << endl;                     //fourth wrong guess
	cout << "บ\t\t\t\t|     |  " << endl;
	cout << "บ\t\t\t\t|     O  " << endl;
	cout << "บ\t\t\t\t|    /I\\" << endl;
	cout << "บ\t\t\t\t|        " << endl;
	cout << "บ\t\t\t\t|        " << endl;
   break;
  }

  case 5:
  { gotoxy(1,8);
	cout << "บ\t\t\t\t_______  " << endl;                     //fifth wrong guess
	cout << "บ\t\t\t\t|     |  " << endl;
	cout << "บ\t\t\t\t|     O  " << endl;
	cout << "บ\t\t\t\t|    /I\\" << endl;
	cout << "บ\t\t\t\t|    /   " << endl;
	cout << "บ\t\t\t\t|        " << endl;
   break;
  }

  case 6:
  { gotoxy(1,8);
	cout << "บ\t\t\t\t_______  " << endl;                     //last wrong guess
	cout << "บ\t\t\t\t|     |  " << endl;
	cout << "บ\t\t\t\t|     0  " << endl;
	cout << "บ\t\t\t\t|    /I\\" << endl;
	cout << "บ\t\t\t\t|    / \\" << endl;
	cout << "บ\t\t\t\t|        " << endl;
   break;
  }
 }
}


//**************************************************************************
void hangman::game(char word[],char clue[],int j,int b)          //main game starts
{
system("clear");
border1();
char g, word2[15];
int count=0,m=0,n=0,i=0,place=0,cwin=0,cwin2=0,flag;
gotoxy(3,24);
cout<<"[THE CHARACTER '/' REPRESENTS A SPACE. PRESS ESC TO EXIT TO MAIN MENU]";
gotoxy(4,3);
//textcolor(GREEN);
puts("Your clue is: ");
//textcolor(WHITE);

 gotoxy(19,3);
 for (int i=0;i<b;i++)                                     //showing the clue to second player
 {
 cout<<clue[i];
 }
gotoxy(1,3);
cout<<"บ";

gotoxy(31,20);
for(int i=0;i<j;i++)
 {
  if(word[i]==' '||word[i]=='-')
  {
   gotoxy(i+31,20);
   cout<<"/";
   word2[i]=word[i];
  }
  else
   if(isalnum(word[i]))
   {
    if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u')
    {
    gotoxy(i+31,20);
    cout<<word[i];
    word2[i]=word[i];
    }
    else
    {
    gotoxy(i+31,20);
    cout<<"-";                                       //displaying vowels and spaces and saving them
    }
   }
  }
gotoxy(1,8);
man(0);


redo:
gotoxy(1,17);
cout<<"บ";
gotoxy(31,17);                                       //guessing the letter and verifying
//textcolor(LIGHTBLUE);
puts("Guess your letter: ");
//textcolor(WHITE);
g=getch1();

while(g!=27)
{
 cout<<g;	   //((((((((((((((((((((((((((((((((((((((((((((((((((((((
 cout<<"\b ";

if(g==13)
{
 goto redo;
}

flag=0;


for(int i=0;i<j;i++)
 {
  if(word[i]==g)
   {
    gotoxy(i+31,20);
    cout<<g;
    word2[i]=word[i];                   //win condition
    flag=1;
     for(m=0;m<j;m++)
     {
      if(word2[m]==word[m])
      {
       cwin++;                             //array checker 1
      }
     }

     for(n=0;n<j;n++)
     {
      if(word2[n]==word[n])                //array checker 2 incase error in 1st checker
      {
       cwin2++;
      }
     }

    if(cwin==(j-1)&&cwin2==(j-1))
    {
    //delay(250);
    win();
    goto end;
    }
    else
     if(cwin!=(j-1)||cwin2!=(j-1))
    {
     cwin=0;
     cwin2=0;
    }

  }
 }


if(flag!=1)                                        //if wrong letter then counter starts
 {
   place++;
   count++;
   gotoxy(60,3);
   //textcolor(RED);
   cout<<"("<<count<<")" ;
   puts(" out of 6 tries");
   gotoxy(62,6);
   puts("ษอออออออออป");
   gotoxy(62,7);
   puts("บ");
   gotoxy(72,7);
   puts("บ");
   gotoxy(62,8);
   puts("ศอออออออออผ");
   //textcolor(WHITE);

   gotoxy(place+63,7);
   cout<<g;
   gotoxy(1,8);
   man(count);
 }

if(count==6)
{
 gotoxy(13 ,20);
 //textcolor(RED+BLINK);
 puts("Actual Word ===>");
 for(int i=0;i<j;i++)
 {
 gotoxy(i+31,20);
 cout<<word[i];
 }
 //delay(3800);
 goto lose;
}

goto redo;

lose:
{
//delay(250);
lose();
}
}
end:
hang();
}

//**************************************************************************
void hangman::enter()
{
 system("clear");
 border1();                                                   //Entering in the word and clue
 begining:
 int i=0,j=0,a=0,b=0,m;
 char letter,ch;

gotoxy(27,4);
//textcolor(RED+BLINK);
//delay(50);
puts("  !!!PLAYER 1 LOOK AWAY!!!");
gotoxy(2,24);
//textcolor(WHITE);

cout<<"[PRESS ENTER ONCE DONE OR ESC TO EXIT TO MAIN MENU]";
gotoxy(3,10);
cout<<"Enter In The Word Of Your Choice (15 letters max): ";

 do
 {
   letter=getch1();
   {
    if(letter==27)
    goto bot;
    cout<<letter;
    //delay(200);
    cout<<"\b*";                                             //showing every letter first and then *
    x.word[i]=letter;
    i++;

    if(i==14)
    {
     j=14;
     goto out;
    }
    if(letter==8)
    {
     for(m=0;m<i;m++)
     {
      gotoxy(m+54,10);
      cout<<" ";
     }
     goto begining;
    }
    if(letter==13)
    {
     j=i;
     cout<<"\bบ";
    }
   }
 }while(letter!=13);

out:
 for(int i=0;i<j;i++)
 {
  x.word[i]=tolower(x.word[i]);
 }
 {
 gotoxy(3,13);
 puts("Enter in a small clue: ");                          //entering the clue
 }


 do
  {
   again:
   ch=getch1();
   if(ch==27)
   goto bot;
   if(ch==8)
   {
    if(a==0)
    {
     goto again;
    }
    a--;
    cout<<"\b \b";
    goto again;
   }

   if(a==29)
   {
    b=29;
    goto end;
   }
  cout<<ch;
  x.clue[a]=ch;
  a++;
  b=a;

 }while(ch!=13);

end:
game(x.word,x.clue,j,b);
bot:
hang();
}

//***************************************************************************

void hangman::instruction()
{
system("clear");
gotoxy(33,2);
cout<<"Instructions";
gotoxy(1,5);
cout<<"Step 1:";
cout<<"\n  Select \"new game\" or \"Multiplayer\" from the menu";
cout<<"\n\nStep 2:";
cout<<"\n  The game starts and you must guess the letters of the word.";
cout<<"\n\nStep 3:";
cout<<"\n  Vowles and shown and spaces are represented as /";
cout<<"\n\nStep 4:";
cout<<"\n  You may only make 6 mistakes before its game over.";
cout<<
getch1();
hang();
}


//***************************************************************************
void hangman::credits()
{
system("clear");

gotoxy(27,2);
//textcolor(YELLOW);
puts("+-+-+-+-+-+-+-+-+-+-+-+-+-+");
gotoxy(27,3);
puts("Special Thanks and Credits!");
gotoxy(27,4);
puts("+-+-+-+-+-+-+-+-+-+-+-+-+-+");

gotoxy(31,6);
//textcolor(LIGHTBLUE);
puts("Main Program Concept");
//textcolor(WHITE);
gotoxy(31,7);
cout<<"    Manuel Sabu";                                       //credit code
gotoxy(31,9);
//textcolor(GREEN);
puts("      Support");
//textcolor(WHITE);
gotoxy(31,10);
cout<<"    Sabu Emmanuel";
gotoxy(31,12);
//textcolor(LIGHTRED);
puts("   C++ training");
//textcolor(WHITE);
gotoxy(31,13);
cout<<"    Ravneet Kaur";
gotoxy(31,15);
//textcolor(YELLOW);
puts("  Program testers");
//textcolor(WHITE);
gotoxy(31,16);
cout<<"    Mikhail Sabu";
gotoxy(31,17);
cout<<"    Jaya Joseph";
gotoxy(31,18);
cout<<"    Sharath Rajesh";
gotoxy(31,19);
cout<<"    Harita Prakash";
gotoxy(31,20);
cout<<"    Xerxes Ghista";
gotoxy(3,24);
cout<<"[PRESS ANY KEY TO GO BACK TO MAIN MENU]";

getch1();
hang();
}
//***************************************************************************
void hangman::file()
{
 system("clear");
 int i=0,r,j,b;
 ifstream s1,s2;
 s1.open("wordlist.txt");
 s2.open("cluelist.txt");

 srand(time(0));
 r=rand()%30+1;

 for(int i=0;i<r;i++)
 {
 s1>>x.word;
 s2>>x.clue;
 }
 j=strlen(x.word)+1;
 b=strlen(x.clue)+1;
 game(x.word,x.clue,j,b);

 s1.close();
 s2.close();
 getch1();
}

//***************************************************************************
void hangman::load()
{                                            //variable declaration
int j;
system("clear");
gotoxy(31,10);
puts("--LOADING MAIN MENU--");
gotoxy(32,13);
cout<<"ณ";
gotoxy(49,13);
cout<<"ณ";
 for(j=33;j<49;j++)
 {
  gotoxy(j,13);
  //textcolor(BLUE);
  puts("Û");
  //delay(100);
  }
 //textcolor(WHITE);
 hang();
}

//***************************************************************************
void hangman::hang()
{
top:
system("clear");
border1();
char choice,select;
gotoxy(3,24);
cout<<"[USE ARROW KEYS TO MOVE UP AND DOWN]";

gotoxy(32,9);
//textcolor(RED);
puts("Select your choice");
//textcolor(LIGHTBLUE);
for(int i=1;i<35;i++)
 {
 gotoxy(i+1,11);
 //delay(10);
 puts(" ");
 puts("New  Game");
 }
for(int i=1;i<34;i++)
 {
 gotoxy(i+1,12);
 //delay(10);
 puts(" ");
 puts("Multiplayer");
 }
for(int i=1;i<36;i++)                       //animated movements
 {
 gotoxy(i+1,13);
 //delay(10);
 puts(" ");
 puts("Credits");
 }
for(int i=1;i<33;i++)
 {
 gotoxy(i+1,14);
 //delay(10);
 puts(" ");
 puts("Instructions");
 }
for(int i=i;i<37;i++)
 {
 gotoxy(i+1,15);
 //delay(10);
 puts(" ");
 puts("Exit");
 }
choice=getch1();

{
if (choice==72)
up:
 {                                               //color changing option menu
  {
   gotoxy(36,11);
   //textcolor(LIGHTBLUE+BLINK);
   puts("New  Game");
   //textcolor(LIGHTBLUE);
   gotoxy(47,11);
   puts("<=");
   //textcolor(BLUE);
   gotoxy(47,12);
   puts("  ");
   gotoxy(47,15);
   puts("  ");
   gotoxy(35,12);
   puts("Multiplayer");
   gotoxy(37,13);
   puts("Credits");
   gotoxy(34,14);
   puts("Instructions");
   gotoxy(38,15);
   puts("Exit");
   plays(2);
  }

s1:
select=getch1();
 if(select==13)
  {
  plays(1);
  //textcolor(WHITE);
  file();                                        //Single player
  }
 else if(select==80)
  {
  goto mid1;                                     //selecting an option
  }
 else if(select==72)
  {
  goto end;
  }
 else
  {
  goto s1;
  }
 }
 else if(choice==1)
 {

  mid1:
  {
   gotoxy(35,12);
   //textcolor(LIGHTBLUE+BLINK);
   puts("Multiplayer");
   //textcolor(LIGHTBLUE);
   gotoxy(47,12);
   puts("<=");
   //textcolor(BLUE);
   gotoxy(47,11);
   puts("  ");
   gotoxy(47,13);
   puts("  ");
   gotoxy(36,11);
   puts("New  Game");
   gotoxy(37,13);
   puts("Credits");
   gotoxy(34,14);
   puts("Instructions");
   gotoxy(38,15);
   puts("Exit");
   plays(2);
  }

s2:
select=getch1();
 if (select==13)
  {
  plays(1);
  //textcolor(WHITE);
  enter();                                       //Multiplayer
  goto top;
  }
 else if (select==72)
  {
  goto up;
  }
 else if(select==80)
  {
  goto mid2;
  }
 else
  {
  goto s2;
  }
 }

if(choice==80)
{

 mid2:
 {
  gotoxy(37,13);
  //textcolor(LIGHTBLUE+BLINK);
  puts("Credits");
  //textcolor(LIGHTBLUE);
  gotoxy(47,13);
  puts("<=");
  //textcolor(BLUE);
  gotoxy(47,12);
  puts("  ");
  gotoxy(47,14);
  puts("  ");
  gotoxy(36,11);
  puts("New  Game");
  gotoxy(35,12);
  puts("Multiplayer");
  gotoxy(34,14);
  puts("Instructions");
  gotoxy(38,15);
  puts("Exit");
  plays(2);
 }

s3:
select=getch1();
 if (select==13)
   {
   plays(1);
   //textcolor(WHITE);
   credits();				         //credits
   }
  else if (select==72)
   {
   goto mid1;
   }
  else if(select==80)
   {
   goto mid3;
   }
  else
   {
   goto s3;
   }
  }

else if(choice==2)
{
 mid3:
 {
  gotoxy(34,14);
  //textcolor(LIGHTBLUE+BLINK);
  puts("Instructions");
  //textcolor(LIGHTBLUE);
  gotoxy(47,14);
  puts("<=");
  //textcolor(BLUE);
  gotoxy(47,15);
  puts("  ");
  gotoxy(47,13);
  puts("  ");
  gotoxy(36,11);
  puts("New  Game");
  gotoxy(35,12);
  puts("Multiplayer");
  gotoxy(37,13);
  puts("Credits");
  gotoxy(38,15);
  puts("Exit");
  plays(2);
 }

s4:
select=getch1();
 if (select==13)
   {
   plays(1);
   //textcolor(WHITE);
   instruction();                                //instructions
   }
  else if (select==72)
   {
   goto mid2;
   }
  else if(select==80)
   {
   goto end;
   }
  else
   {
   goto s4;
   }
}
else
{
 end:
 {
  gotoxy(38,15);
  //textcolor(LIGHTBLUE+BLINK);
  puts("Exit");
  //textcolor(LIGHTBLUE);
  gotoxy(47,15);
  puts("<=");
  //textcolor(BLUE);
  gotoxy(47,11);
  puts("  ");
  gotoxy(47,14);
  puts("  ");
  gotoxy(36,11);
  puts("New  Game");
  gotoxy(35,12);
  puts("Multiplayer");
  gotoxy(37,13);
  puts("Credits");
  gotoxy(34,14);
  puts("Instructions");
  plays(2);
 }
s5:
select=getch1();
 if (select==13)
   {
   plays(1);
   //textcolor(WHITE);
   exit(0);                                      //exit
   }
  else if (select==72)
   {
   goto mid3;
   }
  else if(select==80)
   {
   goto up;
   }
  else
   {
   goto s5;
   }
  }
 }
getch1();
}

int main()
{
 s.load();
}
