//Hangman The Game
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<fstream.h>

struct instruct
{
 char step[8],inst[40];
}a,b,c,d;

//**************************************************************************
struct word
{
 char word[15],clue[30];                         //structure for the word and clue
}x;
//**************************************************************************
class hangman
{
 public:
 void file();
 void border();
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
  sound(268);
  delay(50);
  break;
 }
 case 2:
 {
  sound(150);
  delay(35);
 break;
 }
 case 3:
 {
   sound(960);
   delay(200);
   sound(1280);
   delay(300);
   sound(960);
   delay(200);
   sound(1280);
   delay(500);
 break;
 }
 case 4:
 {
  sound(685);
  delay(400);
  sound(535);
  delay(400);
  sound(500);
  delay(600);
  nosound();
 break;
 }
}
nosound();
}

void hangman::border()
{
 clrscr();
 int i;
 cout<<"ษ";
 for (i=0;i<77;i++)                             //Border creation with title
 {
  cout<<"อ";
 }
for (i=0;i<23;i++)
{
 cout<<"\nบ";
}
gotoxy(1,25);
cout<<"ศ";

for (i=0;i<77;i++)
{
 cout<<"อ";
}
gotoxy(79,25);
cout<<"ผ";
gotoxy(79,1);
cout<<"ป";

for (i=2;i<25;i++)
{
 gotoxy(79,i);
 cout<<"บ";
}
 gotoxy(32,1);
{
textcolor(YELLOW);
cputs(" Hangman The Game ");
textcolor(WHITE);
}
}

//**************************************************************************
void hangman::win()
{
char r,select;                                    //If you win
clrscr();
textcolor(WHITE);
border();
textcolor(GREEN+BLINK);
delay(300);
gotoxy(5,6);
cputs("!!! !!!  YY   YY  OOOOO  UU   UU     WW      WW IIIII NN   NN  !!! !!!");
gotoxy(5,7);
cputs("!!! !!!  YY   YY OO   OO UU   UU     WW      WW  III  NNN  NN  !!! !!!");
gotoxy(5,8);
cputs("!!! !!!   YYYYY  OO   OO UU   UU     WW   W  WW  III  NN N NN  !!! !!!");
gotoxy(5,9);
cputs("           YYY   OO   OO UU   UU      WW WWW WW  III  NN  NNN         ");
gotoxy(5,10);
cputs("!!! !!!    YYY    OOOO0   UUUUU        WW   WW  IIIII NN   NN  !!! !!!");


gotoxy(27,13);
cout<<"Would you like to play again?";
gotoxy(35,15);
textcolor(GREEN);
cputs("PLAY AGAIN!!");
gotoxy(30,16);
cputs("No Thanks I'll Exit");

plays(3);
r=getch();

if(r==72)
{
up:
plays(2);
gotoxy(35,15);
textcolor(LIGHTGREEN+BLINK);
cputs("PLAY AGAIN!!");
gotoxy(50,15);
cputs("<=");
textcolor(GREEN);
gotoxy(30,16);
cputs("No Thanks I'll Exit");
gotoxy(50,16);
cputs("   ");

s1:
 select=getch();
 if(select==13)
 {
  plays(1);
  textcolor(WHITE);
  void main();
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
  textcolor(GREEN);
  cputs("PLAY AGAIN!!     ");
  textcolor(LIGHTGREEN+BLINK);
  gotoxy(30,16);
  cputs("No Thanks I'll Exit");
  gotoxy(50,16);
  textcolor(LIGHTGREEN);
  cputs("<=");
  gotoxy(50,15);
  cputs("   ");

s2:
 select=getch();
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
clrscr();                                                //if you lose
textcolor(WHITE);
border();
textcolor(RED+BLINK);
delay(300);
gotoxy(2,6);
cputs("         YY   YY  OOOOO  UU   UU     LL       OOOOO   SSSSS  EEEEEEE        ");
gotoxy(2,7);
cputs("         YY   YY OO   OO UU   UU     LL      OO   OO SS      EE             ");
gotoxy(2,8);
cputs("          YYYYY  OO   OO UU   UU     LL      OO   OO  SSSSS  EEEEE          ");
gotoxy(2,9);
cputs(" ... ...   YYY   OO   OO UU   UU     LL      OO   OO      SS EE      ... ...");
gotoxy(2,10);
cputs(" ... ...   YYY    OOOO0   UUUUU      LLLLLLL  OOOO0   SSSSS  EEEEEEE ... ...");


gotoxy(27,13);
cout<<"Would you like to play again?";
gotoxy(35,15);
textcolor(RED);
cputs("PLAY AGAIN!!");
gotoxy(30,16);
cputs("No Thanks I'll Exit");

plays(4);
r=getch();

if(r==72)
{
 up:
 plays(2);
 gotoxy(35,15);
 textcolor(LIGHTRED+BLINK);
 cputs("PLAY AGAIN!!");
 gotoxy(50,15);
 cputs("<=");
 textcolor(RED);
 gotoxy(30,16);
 cputs("No Thanks I'll Exit");
 gotoxy(50,16);
 cputs("   ");

s1:
 select=getch();
 if(select==13)
 {
  plays(1);
  textcolor(WHITE);
  void main();
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
 textcolor(RED);
 cputs("PLAY AGAIN!!     ");
 textcolor(LIGHTRED+BLINK);
 gotoxy(30,16);
 cputs("No Thanks I'll Exit");
 gotoxy(50,16);
 textcolor(LIGHTRED);
 cputs("<=");
 gotoxy(50,15);
 cputs("   ");

s2:
 select=getch();
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
clrscr();
border();
char g, word2[15];
int count=0,m=0,n=0,i=0,place=0,cwin=0,cwin2=0,flag;
gotoxy(3,24);
cout<<"[THE CHARACTER '/' REPRESENTS A SPACE. PRESS ESC TO EXIT TO MAIN MENU]";
gotoxy(4,3);
textcolor(GREEN);
cputs("Your clue is: ");
textcolor(WHITE);

 gotoxy(19,3);
 for (i=0;i<b;i++)                                     //showing the clue to second player
 {
 cout<<clue[i];
 }
gotoxy(1,3);
cout<<"บ";

gotoxy(31,20);
for(i=0;i<j;i++)
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
textcolor(LIGHTBLUE);
cputs("Guess your letter: ");
textcolor(WHITE);
g=getch();

while(g!=27)
{
 cout<<g;	   //((((((((((((((((((((((((((((((((((((((((((((((((((((((
 cout<<"\b ";

if(g==13)
{
 goto redo;
}

flag=0;


for(i=0;i<j;i++)
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
    delay(250);
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
   textcolor(RED);
   cout<<"("<<count<<")" ;
   cputs(" out of 6 tries");
   gotoxy(62,6);
   cputs("ษอออออออออป");
   gotoxy(62,7);
   cputs("บ");
   gotoxy(72,7);
   cputs("บ");
   gotoxy(62,8);
   cputs("ศอออออออออผ");
   textcolor(WHITE);

   gotoxy(place+63,7);
   cout<<g;
   gotoxy(1,8);
   man(count);
 }

if(count==6)
{
 gotoxy(13 ,20);
 textcolor(RED+BLINK);
 cputs("Actual Word ===>");
 for(i=0;i<j;i++)
 {
 gotoxy(i+31,20);
 cout<<word[i];
 }
 delay(3800);
 goto lose;
}

goto redo;

lose:
{
delay(250);
lose();
}
end:
}
hang();
}

//**************************************************************************
void hangman::enter()
{
 clrscr();
 border();                                                   //Entering in the word and clue
 begining:
 int i=0,j=0,a=0,b=0,m;
 char letter,ch;

gotoxy(27,4);
textcolor(RED+BLINK);
delay(50);
cputs("  !!!PLAYER 1 LOOK AWAY!!!");
gotoxy(2,24);
textcolor(WHITE);

cout<<"[PRESS ENTER ONCE DONE OR ESC TO EXIT TO MAIN MENU]";
gotoxy(3,10);
cout<<"Enter In The Word Of Your Choice (15 letters max): ";

 do
 {
   letter=getch();
   {
    if(letter==27)
    goto bot;
    cout<<letter;
    delay(200);
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
 for(i=0;i<j;i++)
 {
  x.word[i]=tolower(x.word[i]);
 }
 {
 gotoxy(3,13);
 cputs("Enter in a small clue: ");                          //entering the clue
 }


 do
  {
   again:
   ch=getch();
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
clrscr();
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
getch();
hang();
}


//***************************************************************************
void hangman::credits()
{
clrscr();

gotoxy(27,2);
textcolor(YELLOW);
cputs("+-+-+-+-+-+-+-+-+-+-+-+-+-+");
gotoxy(27,3);
cputs("Special Thanks and Credits!");
gotoxy(27,4);
cputs("+-+-+-+-+-+-+-+-+-+-+-+-+-+");

gotoxy(31,6);
textcolor(LIGHTBLUE);
cputs("Main Program Concept");
textcolor(WHITE);
gotoxy(31,7);
cout<<"    Manuel Sabu";                                       //credit code
gotoxy(31,9);
textcolor(GREEN);
cputs("      Support");
textcolor(WHITE);
gotoxy(31,10);
cout<<"    Sabu Emmanuel";
gotoxy(31,12);
textcolor(LIGHTRED);
cputs("   C++ training");
textcolor(WHITE);
gotoxy(31,13);
cout<<"    Ravneet Kaur";
gotoxy(31,15);
textcolor(YELLOW);
cputs("  Program testers");
textcolor(WHITE);
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

getch();
hang();
}
//***************************************************************************
void hangman::file()
{
 clrscr();
 int i=0,r,j,b;
 ifstream s1,s2;
 s1.open("wordlist.txt");
 s2.open("cluelist.txt");

 srand(time(0));
 r=rand()%30+1;

 for(i=0;i<r;i++)
 {
 s1>>x.word;
 s2>>x.clue;
 }
 j=strlen(x.word)+1;
 b=strlen(x.clue)+1;
 game(x.word,x.clue,j,b);

 s1.close();
 s2.close();
 getch();
}

//***************************************************************************
void hangman::load()
{                                            //variable declaration
int j;
clrscr();
gotoxy(31,10);
cputs("--LOADING MAIN MENU--");
gotoxy(32,13);
cout<<"ณ";
gotoxy(49,13);
cout<<"ณ";
 for(j=33;j<49;j++)
 {
  gotoxy(j,13);
  textcolor(BLUE);
  cputs("Û");
  delay(100);
  }
 textcolor(WHITE);
 hang();
}

//***************************************************************************
void hangman::hang()
{
top:
clrscr();
border();
char choice,select;
gotoxy(3,24);
cout<<"[USE ARROW KEYS TO MOVE UP AND DOWN]";

gotoxy(32,9);
textcolor(RED);
cputs("Select your choice");
textcolor(LIGHTBLUE);
for(int i=1;i<35;i++)
 {
 gotoxy(i+1,11);
 delay(10);
 cputs(" ");
 cputs("New  Game");
 }
for(i=1;i<34;i++)
 {
 gotoxy(i+1,12);
 delay(10);
 cputs(" ");
 cputs("Multiplayer");
 }
for(i=1;i<36;i++)                       //animated movements
 {
 gotoxy(i+1,13);
 delay(10);
 cputs(" ");
 cputs("Credits");
 }
for(i=1;i<33;i++)
 {
 gotoxy(i+1,14);
 delay(10);
 cputs(" ");
 cputs("Instructions");
 }
for(i=i;i<37;i++)
 {
 gotoxy(i+1,15);
 delay(10);
 cputs(" ");
 cputs("Exit");
 }
choice=getch();

{
if (choice==72)
up:
 {                                               //color changing option menu
  {
   gotoxy(36,11);
   textcolor(LIGHTBLUE+BLINK);
   cputs("New  Game");
   textcolor(LIGHTBLUE);
   gotoxy(47,11);
   cputs("<=");
   textcolor(BLUE);
   gotoxy(47,12);
   cputs("  ");
   gotoxy(47,15);
   cputs("  ");
   gotoxy(35,12);
   cputs("Multiplayer");
   gotoxy(37,13);
   cputs("Credits");
   gotoxy(34,14);
   cputs("Instructions");
   gotoxy(38,15);
   cputs("Exit");
   plays(2);
  }

s1:
select=getch();
 if(select==13)
  {
  plays(1);
  textcolor(WHITE);
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
   textcolor(LIGHTBLUE+BLINK);
   cputs("Multiplayer");
   textcolor(LIGHTBLUE);
   gotoxy(47,12);
   cputs("<=");
   textcolor(BLUE);
   gotoxy(47,11);
   cputs("  ");
   gotoxy(47,13);
   cputs("  ");
   gotoxy(36,11);
   cputs("New  Game");
   gotoxy(37,13);
   cputs("Credits");
   gotoxy(34,14);
   cputs("Instructions");
   gotoxy(38,15);
   cputs("Exit");
   plays(2);
  }

s2:
select=getch();
 if (select==13)
  {
  plays(1);
  textcolor(WHITE);
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
  textcolor(LIGHTBLUE+BLINK);
  cputs("Credits");
  textcolor(LIGHTBLUE);
  gotoxy(47,13);
  cputs("<=");
  textcolor(BLUE);
  gotoxy(47,12);
  cputs("  ");
  gotoxy(47,14);
  cputs("  ");
  gotoxy(36,11);
  cputs("New  Game");
  gotoxy(35,12);
  cputs("Multiplayer");
  gotoxy(34,14);
  cputs("Instructions");
  gotoxy(38,15);
  cputs("Exit");
  plays(2);
 }

s3:
select=getch();
 if (select==13)
   {
   plays(1);
   textcolor(WHITE);
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
  textcolor(LIGHTBLUE+BLINK);
  cputs("Instructions");
  textcolor(LIGHTBLUE);
  gotoxy(47,14);
  cputs("<=");
  textcolor(BLUE);
  gotoxy(47,15);
  cputs("  ");
  gotoxy(47,13);
  cputs("  ");
  gotoxy(36,11);
  cputs("New  Game");
  gotoxy(35,12);
  cputs("Multiplayer");
  gotoxy(37,13);
  cputs("Credits");
  gotoxy(38,15);
  cputs("Exit");
  plays(2);
 }

s4:
select=getch();
 if (select==13)
   {
   plays(1);
   textcolor(WHITE);
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
  textcolor(LIGHTBLUE+BLINK);
  cputs("Exit");
  textcolor(LIGHTBLUE);
  gotoxy(47,15);
  cputs("<=");
  textcolor(BLUE);
  gotoxy(47,11);
  cputs("  ");
  gotoxy(47,14);
  cputs("  ");
  gotoxy(36,11);
  cputs("New  Game");
  gotoxy(35,12);
  cputs("Multiplayer");
  gotoxy(37,13);
  cputs("Credits");
  gotoxy(34,14);
  cputs("Instructions");
  plays(2);
 }
s5:
select=getch();
 if (select==13)
   {
   plays(1);
   textcolor(WHITE);
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
getch();
}

void main()
{
 s.load();
}