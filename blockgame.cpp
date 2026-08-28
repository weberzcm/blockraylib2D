#include<bits/stdc++.h>
#include<raylib.h>
#define N 100005
#define M 100005
#define int long long
using namespace std;
double x=500,y=400,xsd,ysd,zl=0.8,ty,zx[N],cx[N],cy[N],pz[N],score;
int hea=5;
int cnz,cnc;
signed main()
{
	srand((unsigned long long)(new char));
	InitWindow(1920,1000,"GameBlock"); 
	SetTargetFPS(60);
	while(!WindowShouldClose())
	{
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
			ysd=-25;
		}
		if(IsKeyDown(KEY_A)||IsKeyDown(KEY_LEFT))
		{
			xsd=-10;
		}
		if(IsKeyDown(KEY_D)||IsKeyDown(KEY_RIGHT))
		{
			xsd=10;
		}
		if(IsKeyDown(KEY_S)||IsKeyDown(KEY_DOWN))
		{
			ysd++;
		}
		x+=xsd;
		y+=ysd;
		if(x>1920)x=0;
		else if(x<0)x=1920; 
		if(xsd<0)xsd=min(xsd+3,0.0);
		if(xsd>0)xsd=max(xsd-3,0.0);
		int rtr=rand()%40;
		if(rtr==0)
		{
			zx[++cnz]=1920;
		}
		BeginDrawing();
		if(y>=940)y=940; 
		ClearBackground(RAYWHITE);
		DrawRectangle(x-40,y-40,80,80,BLUE); 
		string dgwiuf="score:"+to_string((int)score);
		const char* ccc=dgwiuf.c_str();
		DrawText(ccc,100,100,50,BLACK);
		string dgwiuff="HP¹þ¹þ¹þ:"+to_string((int)hea);
		const char* cccc=dgwiuff.c_str();
		DrawText(cccc,1600,100,50,BLACK);
		for(int i=1;i<=cnz;i++)
		{
			DrawRectangle(zx[i]-20,940,40,40,BROWN); 
			if(CheckCollisionRecs({(float)zx[i]-20,940,40,40},{(float)x-40,(float)y-40,80,80}))
			{
				if(pz[i]==0)
				{
					pz[i]=1;
					hea--;
					if(hea<=0)
					{
						return 0;
					}
				} 
			}
			else
			{
				pz[i]=0;
			}
		}
		EndDrawing(); 
		for(int i=1;i<=cnz;i++)
		{
			zx[i]-=5;
			if(zx[i]<=0)
			{
				zx[i]=zx[cnz];
				pz[i]=pz[cnz];
				cnz--;
			}
		}
		score++;
	}
  return 0;
}

