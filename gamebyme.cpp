#include<stdio.h>
#include<stdlib.h>
void turnx (int,char,int ar[3][3]);
int checkwin(int ar[3][3],char,int,int);
int main()
{

	int i=0,j=0,place=0;
	int n=0,f[3][3]={0,0,0,0,0,0,0,0,0},m[9];
	char ch;
	system("CLS");
do
{
	int imp[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int player=0,layer=0,k=0;
	char play='y';
	//The order in which the players should play. The numbers till 9 are allowed
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
	//Enter the player number and accordingly you will be assigned X or O
	printf("\nEnter 1 for player 1 (X) or 2 for player 2 (O):");
	scanf("%d",&player);
	//Play as O
	if(player==1)
	{
		n=0;
		play='X';
		//Place X in the order
		printf("You are player 1 (x)");
		while(n < 9)
		{
			if(n % 2 == 0)
			{
				play='X';
				layer=1;
				//Place X in the order
				printf("\nEnter the number where you want to place %c :",play);
				scanf("%d",&place);
				system("CLS");
				//If the number is taken or invalid this part will tell you
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
				//Assign the position to X 
				turnx(place,play,imp);
			}
			else
			{
				play='O';
				layer=2;
				//Place O in the order
				printf("\nEnter the number where you want to place %c :",play);
				scanf("%d",&place);
				system("CLS");
				//If the number is taken or invalid this part will tell you
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
				//The position will be assigned to O
				turnx(place,play,imp);
			}
			//To see if anyone won the game or not
			k=checkwin(imp,play,layer,k);
			//To see if match is draw if no one won
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
	//Play as O
	else if (player==2)
	{
		n=0;
		play='O';
		//Place O in the order
		printf("You have chosen player 2 (%c)",play);
		while(n<9)
		{
			if(n%2==0)
			{
				play='O';
				layer=2;
				//Place O in the order
				printf("\nEnter the number where you want to place %c :",play);
				scanf("%d",&place);
				system("CLS");
				//This part check whether the entered number is valid or not
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
				//If the part is valid then O will be positioned
				turnx(place,play,imp);
			}
			else
			{
				play='X';
				layer=1;
				//Place X in order
				printf("\nEnter the number where you want to place %c :",play);
				scanf("%d",&place);
				system("CLS");
				//Check whether the number entered is valid or not
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
				//If the number is valid then the postion is assigned to X
				turnx(place,play,imp);
			}
			//To see if anyone won
			k=checkwin(imp,play,layer,k);
			//To see if match is draw if no one won
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
	system("CLS");
}while(ch=='y' || ch=='Y');
}
//The procedure to assign the value of X or O to the number
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
					//If the number is 9 The character of the ascii is printed
					if(ar[i][j] >=10)
					{
						printf("| %c ",ar[i][j]);
					}
					else
					{
						printf("| %d ",ar[i][j]);
					}
				}
				//Here the value is assigned
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
//To see if any one wins
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
