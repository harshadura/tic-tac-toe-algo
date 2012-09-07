/*
 (c)2010 Dura.
 Tuck Tik Took (Version 2.0)
 Last Update : 2010 Dec 19
 Feedback : harshadura@gmail.com
 */

 #include<iostream>
 #include <time.h>
 #include <stdlib.h>

 using namespace std;

 int Check(char Ar[3][3]);
 int checkLoss(char Ar[3][3]);
 int checkAggMove(char Ar[3][3]);
 void Wait(int seconds);
 void Progress();
 void ShowBoard(char Ar[3][3]);
 void ComsMove(char Ar[3][3]);
 void PlayerMove(char Ar[3][3]);
 void RandomMove(char Ar[3][3]);
 void AShowBoard(char Ar[3][3]);

 int main()
 {
 Start:
 cout<<"===================================\n";
 cout<<"     << Tuck Tik Took  >> \n";
 cout<<"        [Version 2.0]  \n";
 cout<<"-----------------------------------\n";
 cout<<"  dURA(R) Solutions(C) 2010 June   \n";
 cout<<"===================================\n\n";
 cout<<"   dURA-O  |  Player-X\n\n";

 char y;
 char Ar[3][3]={'1','2','3','4','5','6','7','8','9'};

 ShowBoard(Ar);

 Begin:
 int x=0;

 //Players Move Functions
 if (!(Ar[0][0]=='1' || Ar[0][1]=='2' || Ar[0][2]=='3' || Ar[1][0]=='4' || Ar[1][1]=='5' || Ar[1][2]=='6' || Ar[2][0]=='7' || Ar[2][1]=='8' || Ar[2][2]=='9'))
 {cout<<"\nMatch Ends Up in a Draw !!!\n";
 goto Last;}

 PlayerMove(Ar);
 cout<<"\n\n----- Players Move -------\n\n";
 ShowBoard(Ar);

 x=Check(Ar);
 if(x==1 || x==2)
 goto Last;

 if (!(Ar[0][0]=='1' || Ar[0][1]=='2' || Ar[0][2]=='3' || Ar[1][0]=='4' || Ar[1][1]=='5' || Ar[1][2]=='6' || Ar[2][0]=='7' || Ar[2][1]=='8' || Ar[2][2]=='9'))
 {cout<<"\nMatch Ends Up in a Draw !!!\n";
 goto Last;}

 Progress();

 //Coms Move Functions
 ComsMove(Ar);
 cout<<"------- dURAs Move -------\n\n";
 AShowBoard(Ar);
 x=Check(Ar);
 if(x==1 || x==2)
 goto Last;

 goto Begin;

 Last:
 cout<<"\n\nGame Over !! \n";
 cout<<"\n\nDo Want to Play Again (y/n) : ";
 cin>>y;
 if(y=='y')
 {system("cls");goto Start;}
 else
 return 0;
 }

 int Check(char Ar[3][3])
 {
 int x=0;

 if (Ar[0][0]=='X' && Ar[0][1]=='X' && Ar[0][2]=='X') x=1;
 if (Ar[1][0]=='X' && Ar[1][1]=='X' && Ar[1][2]=='X') x=1;
 if (Ar[2][0]=='X' && Ar[2][1]=='X' && Ar[2][2]=='X') x=1;
 if (Ar[0][0]=='X' && Ar[1][0]=='X' && Ar[2][0]=='X') x=1;
 if (Ar[0][1]=='X' && Ar[1][1]=='X' && Ar[2][1]=='X') x=1;
 if (Ar[0][2]=='X' && Ar[1][2]=='X' && Ar[2][2]=='X') x=1;
 if (Ar[0][0]=='X' && Ar[1][1]=='X' && Ar[2][2]=='X') x=1;
 if (Ar[2][0]=='X' && Ar[1][1]=='X' && Ar[0][2]=='X') x=1;

 if (Ar[0][0]=='O' && Ar[0][1]=='O' && Ar[0][2]=='O') x=2;
 if (Ar[1][0]=='O' && Ar[1][1]=='O' && Ar[1][2]=='O') x=2;
 if (Ar[2][0]=='O' && Ar[2][1]=='O' && Ar[2][2]=='O') x=2;
 if (Ar[0][0]=='O' && Ar[1][0]=='O' && Ar[2][0]=='O') x=2;
 if (Ar[0][1]=='O' && Ar[1][1]=='O' && Ar[2][1]=='O') x=2;
 if (Ar[0][2]=='O' && Ar[1][2]=='O' && Ar[2][2]=='O') x=2;
 if (Ar[0][0]=='O' && Ar[1][1]=='O' && Ar[2][2]=='O') x=2;
 if (Ar[2][0]=='O' && Ar[1][1]=='O' && Ar[0][2]=='O') x=2;

 if(x==1)
 cout<<"\n\nPlayer Wins the Game!!! \n";
 else if(x==2)
 cout<<"\n\ndURA Wins the Game!!! \n";

 return x;
 }

 void RandomMove(char Ar[3][3])
 {int i,j;

 if(Ar[1][1]=='5')
 {Ar[1][1]='O';
 goto last;}

 for(i=0;i<3;i++)
 {
 for(j=0;j<3;j++)
 {
 if (Ar[i][j]=='1' || Ar[i][j]=='2' || Ar[i][j]=='3' || Ar[i][j]=='4' || Ar[i][j]=='5' || Ar[i][j]=='6' || Ar[i][j]=='7' || Ar[i][j]=='8' || Ar[i][j]=='9')
 {Ar[i][j]='O';
 goto last;}
 }
 }
 last:
 cout<<"";
 }

 void Progress()
 {
 cout<<"\n\dURA is Thinking...  ";
 for(int i=0;i<5;i++)
 {cout<<">";
 Wait(1);}
 cout<<"\n\nOK!! Friend";
 Wait(1);
 cout<<"\ndURA got the Point..!!\n";
 Wait(2);
 }

 void ComsMove(char Ar[3][3])
 {
 int Ans;

 Ans=checkAggMove(Ar);
 if (Ans==1)
 goto skip;

 Ans=checkLoss(Ar);
 if (Ans==1)
 goto skip;

 RandomMove(Ar);

 skip:
 cout<<"\n";
 }

 void Wait(int seconds)
 {
 clock_t endwait;
 endwait = clock () + seconds * CLK_TCK ;
 while (clock() < endwait) {}
 }

 int checkAggMove(char Ar[3][3])
 {
 int Flag=0;

 if (Ar[0][0]=='O' && Ar[1][0]=='O' && Ar[2][0]=='7') {Ar[2][0]='O';Flag=1;goto last;}
 if (Ar[0][0]=='O' && Ar[2][0]=='O' && Ar[1][0]=='4') {Ar[1][0]='O';Flag=1;goto last;}
 if (Ar[1][0]=='O' && Ar[2][0]=='O' && Ar[0][0]=='1') {Ar[2][0]='O';Flag=1;goto last;}

 if (Ar[0][1]=='O' && Ar[1][1]=='O' && Ar[2][1]=='8') {Ar[2][1]='O';Flag=1;goto last;}
 if (Ar[0][0]=='O' && Ar[2][1]=='O' && Ar[1][1]=='5') {Ar[1][1]='O';Flag=1;goto last;}
 if (Ar[1][1]=='O' && Ar[2][1]=='O' && Ar[0][1]=='2') {Ar[0][1]='O';Flag=1;goto last;}

 if (Ar[0][2]=='O' && Ar[1][2]=='O' && Ar[2][2]=='9') {Ar[2][2]='O';Flag=1;goto last;}
 if (Ar[0][2]=='O' && Ar[2][2]=='O' && Ar[1][2]=='6') {Ar[1][2]='O';Flag=1;goto last;}
 if (Ar[1][2]=='O' && Ar[2][2]=='O' && Ar[0][2]=='3') {Ar[0][2]='O';Flag=1;goto last;}

 //Columns
 if (Ar[0][0]=='O' && Ar[0][1]=='O' && Ar[0][2]=='3') {Ar[0][2]='O';Flag=1;goto last;}
 if (Ar[0][0]=='O' && Ar[0][2]=='O' && Ar[0][1]=='2') {Ar[0][1]='O';Flag=1;goto last;}
 if (Ar[0][1]=='O' && Ar[0][2]=='O' && Ar[0][0]=='1') {Ar[0][0]='O';Flag=1;goto last;}

 if (Ar[1][0]=='O' && Ar[1][1]=='O' && Ar[1][2]=='6') {Ar[1][2]='O';Flag=1;goto last;}
 if (Ar[1][0]=='O' && Ar[1][2]=='O' && Ar[1][1]=='5') {Ar[1][1]='O';Flag=1;goto last;}
 if (Ar[1][1]=='O' && Ar[1][2]=='O' && Ar[1][0]=='4') {Ar[1][0]='O';Flag=1;goto last;}

 if (Ar[2][0]=='O' && Ar[2][1]=='O' && Ar[2][2]=='9') {Ar[2][2]='O';Flag=1;goto last;}
 if (Ar[2][0]=='O' && Ar[2][2]=='O' && Ar[2][1]=='8') {Ar[2][1]='O';Flag=1;goto last;}
 if (Ar[2][1]=='O' && Ar[2][2]=='O' && Ar[2][0]=='7') {Ar[2][0]='O';Flag=1;goto last;}

 //Axels
 if (Ar[0][0]=='O' && Ar[1][1]=='O' && Ar[2][2]=='9') {Ar[2][2]='O';Flag=1;goto last;}
 if (Ar[0][0]=='O' && Ar[2][2]=='O' && Ar[1][1]=='5') {Ar[1][1]='O';Flag=1;goto last;}
 if (Ar[1][1]=='O' && Ar[2][2]=='O' && Ar[0][0]=='1') {Ar[0][0]='O';Flag=1;goto last;}

 if (Ar[0][2]=='O' && Ar[1][1]=='O' && Ar[2][0]=='7') {Ar[2][0]='O';Flag=1;goto last;}
 if (Ar[0][2]=='O' && Ar[2][0]=='O' && Ar[1][1]=='5') {Ar[1][1]='O';Flag=1;goto last;}
 if (Ar[2][0]=='O' && Ar[1][1]=='O' && Ar[0][2]=='3') {Ar[0][2]='O';Flag=1;goto last;}

 last:
 return Flag;
 }

 int checkLoss(char Ar[3][3])
 {
 int Flag=0;
 //Duras Combinations Of TTT

 if(Ar[1][1]=='5')
 {Ar[1][1]='O';Flag=1;goto last;}

 //Rows
 if (Ar[0][0]=='X' && Ar[1][0]=='X' && Ar[2][0]=='7') {Ar[2][0]='O';Flag=1;goto last;}
 if (Ar[0][0]=='X' && Ar[2][0]=='X' && Ar[1][0]=='4') {Ar[1][0]='O';Flag=1;goto last;}
 if (Ar[1][0]=='X' && Ar[2][0]=='X' && Ar[0][0]=='1') {Ar[2][0]='O';Flag=1;goto last;}

 if (Ar[0][1]=='X' && Ar[1][1]=='X' && Ar[2][1]=='8') {Ar[2][1]='O';Flag=1;goto last;}
 if (Ar[0][0]=='X' && Ar[2][1]=='X' && Ar[1][1]=='5') {Ar[1][1]='O';Flag=1;goto last;}
 if (Ar[1][1]=='X' && Ar[2][1]=='X' && Ar[0][1]=='2') {Ar[0][1]='O';Flag=1;goto last;}

 if (Ar[0][2]=='X' && Ar[1][2]=='X' && Ar[2][2]=='9') {Ar[2][2]='O';Flag=1;goto last;}
 if (Ar[0][2]=='X' && Ar[2][2]=='X' && Ar[1][2]=='6') {Ar[1][2]='O';Flag=1;goto last;}
 if (Ar[1][2]=='X' && Ar[2][2]=='X' && Ar[0][2]=='3') {Ar[0][2]='O';Flag=1;goto last;}

 //Columns
 if (Ar[0][0]=='X' && Ar[0][1]=='X' && Ar[0][2]=='3') {Ar[0][2]='O';Flag=1;goto last;}
 if (Ar[0][0]=='X' && Ar[0][2]=='X' && Ar[0][1]=='2') {Ar[0][1]='O';Flag=1;goto last;}
 if (Ar[0][1]=='X' && Ar[0][2]=='X' && Ar[0][0]=='1') {Ar[0][0]='O';Flag=1;goto last;}

 if (Ar[1][0]=='X' && Ar[1][1]=='X' && Ar[1][2]=='6') {Ar[1][2]='O';Flag=1;goto last;}
 if (Ar[1][0]=='X' && Ar[1][2]=='X' && Ar[1][1]=='5') {Ar[1][1]='O';Flag=1;goto last;}
 if (Ar[1][1]=='X' && Ar[1][2]=='X' && Ar[1][0]=='4') {Ar[1][0]='O';Flag=1;goto last;}

 if (Ar[2][0]=='X' && Ar[2][1]=='X' && Ar[2][2]=='9') {Ar[2][2]='O';Flag=1;goto last;}
 if (Ar[2][0]=='X' && Ar[2][2]=='X' && Ar[2][1]=='8') {Ar[2][1]='O';Flag=1;goto last;}
 if (Ar[2][1]=='X' && Ar[2][2]=='X' && Ar[2][0]=='7') {Ar[2][0]='O';Flag=1;goto last;}

 //Axels
 if (Ar[0][0]=='X' && Ar[1][1]=='X' && Ar[2][2]=='9') {Ar[2][2]='O';Flag=1;goto last;}
 if (Ar[0][0]=='X' && Ar[2][2]=='X' && Ar[1][1]=='5') {Ar[1][1]='O';Flag=1;goto last;}
 if (Ar[1][1]=='X' && Ar[2][2]=='X' && Ar[0][0]=='1') {Ar[0][0]='O';Flag=1;goto last;}

 if (Ar[0][2]=='X' && Ar[1][1]=='X' && Ar[2][0]=='7') {Ar[2][0]='O';Flag=1;goto last;}
 if (Ar[0][2]=='X' && Ar[2][0]=='X' && Ar[1][1]=='5') {Ar[1][1]='O';Flag=1;goto last;}
 if (Ar[2][0]=='X' && Ar[1][1]=='X' && Ar[0][2]=='3') {Ar[0][2]='O';Flag=1;goto last;}

 //checkUpsetMoves

 //Salutes 4 Navodth Bhanuka....
 if (Ar[0][0]=='X' && Ar[2][2]=='X' && Ar[2][0]=='7') {Ar[2][0]='O';Flag=1;goto last;}
 if (Ar[0][0]=='X' && Ar[2][2]=='X' && Ar[0][2]=='3') {Ar[0][2]='O';Flag=1;goto last;}

 if (Ar[2][0]=='X' && Ar[0][2]=='X' && Ar[0][0]=='1') {Ar[0][0]='O';Flag=1;goto last;}
 if (Ar[2][0]=='X' && Ar[0][2]=='X' && Ar[2][2]=='9') {Ar[2][2]='O';Flag=1;goto last;}

 if (Ar[0][0]=='X' && Ar[0][2]=='3') {Ar[0][2]='O';Flag=1;goto last;}
 if (Ar[0][0]=='X' && Ar[2][0]=='7') {Ar[2][0]='O';Flag=1;goto last;}
 if (Ar[2][2]=='X' && Ar[0][2]=='3') {Ar[0][2]='O';Flag=1;goto last;}
 if (Ar[2][2]=='X' && Ar[2][0]=='7') {Ar[2][0]='O';Flag=1;goto last;}

 if (Ar[0][2]=='X' && Ar[0][0]=='1') {Ar[0][0]='O';Flag=1;goto last;}
 if (Ar[0][2]=='X' && Ar[2][2]=='9') {Ar[2][2]='O';Flag=1;goto last;}
 if (Ar[2][0]=='X' && Ar[0][0]=='1') {Ar[0][0]='O';Flag=1;goto last;}
 if (Ar[2][0]=='X' && Ar[2][2]=='9') {Ar[2][2]='O';Flag=1;goto last;}

 /////////////////////

 if (Ar[0][0]=='O' && Ar[2][2]=='9') {Ar[2][2]='O';Flag=1;goto last;}
 if (Ar[0][2]=='O' && Ar[2][0]=='7') {Ar[2][0]='O';Flag=1;goto last;}
 if (Ar[2][0]=='O' && Ar[0][2]=='3') {Ar[0][2]='O';Flag=1;goto last;}
 if (Ar[2][2]=='O' && Ar[0][0]=='1') {Ar[0][0]='O';Flag=1;goto last;}

 /*
 00 01 02  |  1 2 3
 10 11 12  |  4 5 6
 20 21 22  |  7 8 9
 */

 if (Ar[0][0]=='X' && Ar[2][2]=='X' && Ar[2][1]=='8') {Ar[2][1]='O';Flag=1;goto last;}
 if (Ar[0][0]=='X' && Ar[2][2]=='X' && Ar[0][1]=='2') {Ar[0][1]='O';Flag=1;goto last;}
 if (Ar[0][0]=='X' && Ar[2][2]=='X' && Ar[1][0]=='4') {Ar[1][0]='O';Flag=1;goto last;}
 if (Ar[0][0]=='X' && Ar[2][2]=='X' && Ar[1][2]=='6') {Ar[1][0]='O';Flag=1;goto last;}

 if (Ar[2][0]=='O' && Ar[0][2]=='O' && Ar[2][2]=='9') {Ar[2][2]='O';Flag=1;goto last;}
 if (Ar[2][0]=='O' && Ar[0][2]=='O' && Ar[0][0]=='1') {Ar[0][0]='O';Flag=1;goto last;}

 // ............

 last:
 return Flag;
 }

 void AShowBoard(char Ar[3][3])
 {
 cout<<"-------------\n";Wait(1);
 cout<<"| "<<Ar[0][0]<<" | "<<Ar[0][1]<<" | "<<Ar[0][2]<<" |\n";Wait(1);
 cout<<"-------------\n";Wait(1);
 cout<<"| "<<Ar[1][0]<<" | "<<Ar[1][1]<<" | "<<Ar[1][2]<<" |\n";Wait(1);
 cout<<"-------------\n";Wait(1);
 cout<<"| "<<Ar[2][0]<<" | "<<Ar[2][1]<<" | "<<Ar[2][2]<<" |\n";Wait(1);
 cout<<"-------------\n";Wait(1);
 }

 void ShowBoard(char Ar[3][3])
 {
 cout<<"-------------\n";
 cout<<"| "<<Ar[0][0]<<" | "<<Ar[0][1]<<" | "<<Ar[0][2]<<" |\n";
 cout<<"-------------\n";
 cout<<"| "<<Ar[1][0]<<" | "<<Ar[1][1]<<" | "<<Ar[1][2]<<" |\n";
 cout<<"-------------\n";
 cout<<"| "<<Ar[2][0]<<" | "<<Ar[2][1]<<" | "<<Ar[2][2]<<" |\n";
 cout<<"-------------\n";
 }

 void PlayerMove(char Ar[3][3])
 {
 int r,c;
 int move;

 begin:
 cout<<"\nPlayers Turn,\nEnter the Position : ";
 cin>>move;

 switch (move)
 {
 case 1 : r=0;c=0;break;
 case 2 : r=0;c=1;break;
 case 3 : r=0;c=2;break;
 case 4 : r=1;c=0;break;
 case 5 : r=1;c=1;break;
 case 6 : r=1;c=2;break;
 case 7 : r=2;c=0;break;
 case 8 : r=2;c=1;break;
 case 9 : r=2;c=2;break;
 default : cout<<"\nIllegal move!!!\n";goto begin;break;
 }

 if (Ar[r][c]=='O' || Ar[r][c]=='X')
 {cout<<"Illegal move,This Position is Reserved !!!!\n";
 goto begin;}
 else
 Ar[r][c]='X';

 }
 
 