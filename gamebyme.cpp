#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
void turnx (int,char,int ar[3][3]);
int checkwin(int ar[3][3],char,int,int);
int main()
{

	int i=0,j=0,place=0;
	int n=0,f[3][3]={0,0,0,0,0,0,0,0,0},m[9];
	char ch;
	//clrscr();
	system("CLS");
do
{
	int imp[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int player=0,layer=0,k=0;
	char play='y';
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
	printf("\nEnter 1 for player 1 (X) or 2 for player 2 (O):");
	scanf("%d",&player);
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
				printf("\nEnter the number where you want to place %c :",play);
				scanf("%d",&place);
				//clrscr();
				system("CLS");
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
				turnx(place,play,imp);
			}
			else
			{
				play='O';
				layer=2;
				printf("\nEnter the number where you want to place %c :",play);
				scanf("%d",&place);
				//clrscr();
				system("CLS");
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
				turnx(place,play,imp);
			}
			k=checkwin(imp,play,layer,k);
			if(k==1)
			{
				break;
			}
			n++;
		}
		if(k!=1)
		{
			printf("\n\n\t\t\t The game is draw!!!");
		}
	}
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
				printf("\nEnter the number where you want to place %c :",play);
				scanf("%d",&place);
				//clrscr();
				system("CLS");
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
				turnx(place,play,imp);
			}
			else
			{
				play='X';
				layer=1;
				printf("\nEnter the number where you want to place %c :",play);
				scanf("%d",&place);
				//clrscr();
				system("CLS");
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
				turnx(place,play,imp);
			}
			k=checkwin(imp,play,layer,k);
			if(k==1)
			{
				break;
			}
			n++;
		}
		if(k!=1)
		{
			printf("\n\n\t\t\t The game is draw!!!");
		}
	}
	else
	{
		printf("Enter appropriate number");
	}
	printf("\n\n\n\nDo you want to play again? [y/n]:");
	scanf("%s",&ch);
	//clrscr();
	system("CLS");
}while(ch=='y' || ch=='Y');
	//getch();
}
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
