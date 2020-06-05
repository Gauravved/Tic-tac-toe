#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void turnx (int,char,int ar[3][3]);
int checkwin(int ar[3][3],char,int,int);
int main()
{

	int i=0,j=0,place=0;
	int n=0,f[3][3]={0,0,0,0,0,0,0,0,0},m[9];
	char ch;
	system("CLS");
	int pass=0,s=0;
	lable:
	system("CLS");
	//Enter correct password to enter
	printf("Enter the password:");
	scanf("%d",&pass);
	system("CLS");
	if(pass==1353)
	{
		//The loading screen
		printf("\n\n\n\n\n\n\n\t\t\t\t\t **TIC-TAC-TOE** ");
		printf("\n\n\t\t Loading");
		for(i=0;i<3;i++)
		{
			printf(".",i);
			Sleep(1000);
		}
		system("CLS");
	do
	{
	int imp[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int player=0,layer=0,k=0;
	char play='y';
	//The order in the player are allowed to play
	printf("\t\t\t--TIC-TAC-TOE--\n");
	printf("The order is:\n");
	for(i=0;i<3;i++)
	{
		printf("\t\t\t|---|---|---|\n");
		printf("\t\t\t");
		for(j=0;j<3;j++)
		{
			printf("| %d ",imp[i][j]);
		}
		printf("|");
		printf("\n");
	}
	printf("\t\t\t|---|---|---|\n");
	//Enter the player you want
	printf("\nEnter 1 for player 1 (X) or 2 for player 2 (O):");
	scanf("%d",&player);
	//If player is X
	if(player==1)
	{
		n=0;
		play='X';
		printf("You are player 1 (x)");
		while(n < 9)
		{
			if(n % 2 == 0)
			{
				play='X';
				layer=1;
				//Enter the postion for x
				printf("\nEnter the number where you want to place %c :",play);
				scanf("%d",&place);
				system("CLS");
				//To check whether the postion entered  is apropriate or not
				m[n]=place;
				for(i=-1;i<n;i++)
				{
					if(m[i]==m[n] || place>=10)
					{
						printf("Enter appropriate number. The number is either taken or invalid\n\n");
						n--;
						break;
					}
				}
				//If the postion is appropriate X is assigned the value of it
				turnx(place,play,imp);
			}
			else
			{
				play='O';
				layer=2;
				//Enter the Position of O
				printf("\nEnter the number where you want to place %c :",play);
				scanf("%d",&place);
				system("CLS");
				//To check whether the enetered number is appropriate or not
				m[n]=place;
				for(i=0;i<n;i++)
				{
					if(m[i]==m[n] || place>=10)
					{
						printf("Enter appropriate number. The number is either taken or invalid\n\n");
						n--;
						break;
					}
				}
				//If the number is appropriate the O is assigned to the postion
				turnx(place,play,imp);
			}
			//To check whether anyone won
			k=checkwin(imp,play,layer,k);
			if(k==1)
			{
				break;
			}
			n++;
		}
		//To check if the game draw ate the end after the loop breaks
		if(k!=1)
		{
			printf("\n\n\t\t\t The game is draw!!!");
		}
	}
	//If player is O
	else if (player==2)
	{
		n=0;
		play='O';
		printf("You have chosen player 2 (%c)",play);
		while(n<9)
		{
			if(n%2==0)
			{
				play='O';
				layer=2;
				//Enter the postion to O
				printf("\nEnter the number where you want to place %c :",play);
				scanf("%d",&place);
				system("CLS");
				//To check if the postion is Appropriate or not
				m[n]=place;
				for(i=-1;i<n;i++)
				{
					if(m[i]==m[n] || place>=10)
					{
						printf("Enter appropriate number. The number is either taken or invalid\n\n");
						n--;
						break;
					}
				}
				//If the position is appropriate O is Assigned the value
				turnx(place,play,imp);
			}
			else
			{
				play='X';
				layer=1;
				//Enter the position for X
				printf("\nEnter the number where you want to place %c :",play);
				scanf("%d",&place);
				system("CLS");
				//To check if postion is Appropriate or not
				m[n]=place;
				for(i=0;i<n;i++)
				{
					if(m[i]==m[n] || place>=10)
					{
						printf("Enter appropriate number. The number is either taken or invalid\n\n");
						n--;
						break;
					}
				}
				//If the position is appropriate X is assigned to the value 
				turnx(place,play,imp);
			}
			//To see if anyone won
			k=checkwin(imp,play,layer,k);
			if(k==1)
			{
				break;
			}
			n++;
		}
		//To check if the game is draw or not after the loop ends
		if(k!=1)
		{
			printf("\n\n\t\t\t The game is draw!!!");
		}
	}
	else
	{
		printf("Enter appropriate number");
	}
	//If you want to play again
	printf("\n\n\n\nDo you want to play again? [y/n]:");
	scanf("%s",&ch);
	system("CLS");
	}while(ch=='y' || ch=='Y');
}
//If the password Entered is incorrect
	else if(pass!=1353)
	{
		s++;
		if(s<3)
		{
			goto lable;
		}
		//If you have tried 3 time you will have to wait for 30 seconds
		else if(s>=3)
		{
			for(i=30;i>0;i--)
			{
				system("CLS");
				printf("You have tried 3 times");
				printf("\nPlease wait for %d seconds",i);
				Sleep(1000);
			}
			goto lable;
		}
		}
		return 0;
	}
///Logic to assign the position to X or O
void turnx(int a,char c,int ar[3][3])
{
       int i,j;
       for(i=0;i<3;i++)
		{
			printf("\t\t\t|---|---|---|\n");
			printf("\t\t\t");
			for(j=0;j<3;j++)
			{
				if(a!=ar[i][j])
				{
					if(ar[i][j]!=1&&ar[i][j]!=2&&ar[i][j]!=3&&ar[i][j]!=4&&ar[i][j]!=5&&ar[i][j]!=6&&ar[i][j]!=7&&ar[i][j]!=8&&ar[i][j]!=9)
					{
						printf("| %c ",ar[i][j]);
					}
					else
					{
						printf("| %d ",ar[i][j]);
					}
				}
				else
				{
					ar[i][j]=c;
					printf("| %c ",c);
				}
			}
			printf("|");
			printf("\n");
		}
		printf("\t\t\t|---|---|---|");
	}
//To see if anyone won the game  
int checkwin(int ar[3][3],char c,int a,int k)
{
	int i,j;
	if(ar[0][0]==ar[1][0]&&ar[1][0]==ar[2][0] || ar[0][0]==ar[0][1]&&ar[0][1]==ar[0][2] || ar[1][0]==ar[1][1]&&ar[1][1]==ar[1][2] || ar[2][0]==ar[2][1]&&ar[2][1]==ar[2][2] || ar[0][1]==ar[1][1]&&ar[1][1]==ar[2][1] || ar[0][2]==ar[1][2]&&ar[1][2]==ar[2][2] ||ar[0][0]==ar[1][1]&&ar[1][1]==ar[2][2] || ar[0][2]==ar[1][1]&&ar[1][1]==ar[2][0])
	{
		printf("\n\n\t\tCongratulations!!! Player %d (%c) wins..... ",a,c);
		k=1;
	}
	return(k);
}
