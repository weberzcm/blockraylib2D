#include<bits/stdc++.h>
#include<raylib.h>
#include<chrono>
#define N 100005
#define M 100005
#define int long long
using namespace std;
double x=500,y=400,xsd,ysd,zl=0.8,iiid=-20,bl[N][4]={{0,0,0,0},{300,700,500,100},{900,550,100,50},{450,300,200,200},{1500,600,300,20},{0,900,2000,200}};
int ty,n=5,cx=-1,tmzd,cnt;
struct node
{
	int x,y,mm,tm;
}zd[N];
signed main()
{
	srand((unsigned long long)(new char));
	InitWindow(1920,1000,"GameBlock"); 
	SetTargetFPS(60);
	while(!WindowShouldClose())
	{
		tmzd=min(30ll,tmzd+1);
		if(y<40)
		{
			y=40;
			ysd=0;
		}
		if(y>=940)
		{
			y=940;
			ysd=0;
			ty=0;
		}
		else
		{
			ysd+=zl;
		} 
		if((IsKeyPressed(KEY_W)||IsKeyPressed(KEY_UP))&&(y>=940||ty<=1))
		{
			ty++;
			ysd=-20;
		}
		if(IsKeyDown(KEY_A)||IsKeyDown(KEY_LEFT))
		{
			xsd=-10;
			cx=-1;
		}
		if(IsKeyDown(KEY_D)||IsKeyDown(KEY_RIGHT))
		{
			xsd=10;
			cx=1;
		}
		if(IsKeyDown(KEY_S)||IsKeyDown(KEY_DOWN))
		{
			ysd++;
		}
		if(IsKeyDown(KEY_SPACE)&&tmzd==30)
		{
			tmzd=0;
			zd[++cnt]={x,y,cx,0};
		}
		x+=xsd;
		if(x>1920)x=0;
		else if(x<0)x=1920; 
		for(int i=1;i<=n;i++)
		{
			if(xsd<0)
			{
				xsd=min(xsd+3,0.0);
				if(CheckCollisionRecs({bl[i][0],bl[i][1],bl[i][2],bl[i][3]},{(float)x-40,(float)y-40,80,80}))
				{
					x+=10;
				}
			}
			if(xsd>0)
			{
				xsd=max(xsd-3,0.0);
				if(CheckCollisionRecs({bl[i][0],bl[i][1],bl[i][2],bl[i][3]},{(float)x-40,(float)y-40,80,80}))
				{
					x-=10;
				}
			}
		}
		y+=ysd;
		for(int i=1;i<=n;i++)
		{
			if(CheckCollisionRecs({bl[i][0],bl[i][1],bl[i][2],bl[i][3]},{(float)x-40,(float)y-40,80,80})&&ysd>0)
			{
				ysd=0;
				ty=0;
				while(CheckCollisionRecs({bl[i][0],bl[i][1],bl[i][2],bl[i][3]},{(float)x-40,(float)y-40,80,80}))y-=0.01;
			}
			if(CheckCollisionRecs({bl[i][0],bl[i][1],bl[i][2],bl[i][3]},{(float)x-40,(float)y-40,80,80})&&ysd<0)
			{
				ysd=0;
				while(CheckCollisionRecs({bl[i][0],bl[i][1],bl[i][2],bl[i][3]},{(float)x-40,(float)y-40,80,80}))y+=0.01;
			}
			if(y>=940)y=940; 
		}
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawRectangle(x-40,y-40,80,80,BLUE); 
		if(cx==-1)
		{
			if(iiid>-20)
			{
				DrawCircle(x+iiid,y,10,BLACK);
				iiid-=4;
			} 
			else DrawCircle(x-20,y,10,BLACK);
		}
		else
		{
			if(iiid<20)
			{
				DrawCircle(x+iiid,y,10,BLACK);
				iiid+=4;
			} 
			else DrawCircle(x+20,y,10,BLACK);
		}
		for(int i=1;i<=n;i++)
		{
			DrawRectangle(bl[i][0],bl[i][1],bl[i][2],bl[i][3],BROWN);
		}
//		for(int i=1;i<=cnt;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				if(CheckCollisionRecs({bl[j][0],bl[j][1],bl[j][2],bl[j][3]},{zd[i].x-10,zd[i].y-10,20,20})||zd[i].tm==180)
//				{
//					zd[i]=zd[cnt];
//					cnt--;
//				}
//			}
//			zd[i].x+=15*zd[i].mm;
//			zd[i].tm=min(180ll,zd[i].tm+1);
//			if(zd[i].x<0)zd[i].x=1920;
//			else if(zd[i].x>1920)zd[i].x=0;
//			DrawCircle(zd[i].x,zd[i].y,10,YELLOW);
//		}
		EndDrawing(); 
	}
  return 0;
}

