#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;
bool gameover;
int tailx[50],taily[50];
int ntail;
const int width=20;
const int height=20;
int x,y,fx,fy,score;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void settings()
{
	gameover=false;
	dir=STOP;
	x=width/2;
	y=width/2;
	fx=rand() %width;
	fy=rand() %height;
	score=0;
	
}
void visual()
{
	system("cls");
	for(int i=0;i<width+2;i++)
	{
		cout<<"+";
	}
	cout<<endl;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)
			{
				cout<<"+";}
				
			if (i==y &&j==x)
				{cout<<"0";}
			else if(i==fy && j==fx)
			{cout<<"*";}
		    else
			{
				bool printtail=false;
				for(int k=0;k<ntail;k++)
				{
					if(tailx[k]==j && taily[k]==i)
					{
						cout<<"0";
						printtail=true;
					}
				}
				if(!printtail)
					
				cout<<" ";
				}
				
			
          
			   if(j+1==width)
			    	{cout<<"+";}
		         	
            
		}
		cout<<endl;
	}
	for(int i=0;i<width+2;i++)
	{
		cout<<"+";
	}
	cout<<endl<<"Score"<<score<<endl;
}
void logic()
{
	int prevx=tailx[0];
	int prevy=taily[0];
	int prev2x,prev2y;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<ntail;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}	
	
	switch(dir)
	{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y++;
			break;
		case DOWN:
			y--;
			break;
		
	}
	if(x>=width)
		x=0;
	else if(x<0)
		x=width-1;
	if(y>=width)
		y=0;
	else if(y<0)
		y=width-1;
	for(int i=0;i<ntail;i++)
	{
		if(tailx[i]==x && taily[i]==y)
		{
			gameover=true;
		}
	}
	if(x==fx && y==fy)
	{
		score+=1;
		fx=rand() %width;
		fy=rand() %height;
		ntail++;
	}
}

void input()
{
	if(_kbhit())
	{
		switch (_getch())
		{
			case 'a':
			dir=LEFT;
			break;
			case 'd':
			dir=RIGHT;
			break;
			case 's':
			dir=UP;
			break;
			case 'w':
			dir=DOWN;
			break;
			case 'x':
			gameover=true;
			break;
		}
		
	}
		
}
int main()
{
	settings();
	while(!gameover)
	{
		visual();
		input();
		logic();
		Sleep(10);
	}
	return 0;
}
