#include <iostream>
using namespace std;
#include <winbgim.h>
#include <string.h>
#include <stdio.h>
#include <ctime>

#include "flyGame.h"

#define 	MINW 		20
#define 	MINH 		20
#define 	MAXW 		700
#define 	MAXH 		480
#define 	BACKGROUND	15

struct HighScore {
		int score;
		char name[30];
	};

	void modern();//----v
	void showHighScore();
	void getHighScore();
	void checkHighScore(int score);
	void initScore();
	bool isEmpty();
	void showTextBackground(int x,int y,char *str,int color);
	int level;
	bool endGame;
	HighScore  highscore[5];
	char* score_str = new char[20];

	void initScore(){
			if (isEmpty()){
				for (int i = 0;i < 5;i++){
				strcpy(highscore[i].name,"PLAYER");
				highscore[i].score = 0;
				}
				getHighScore();
			}else{
				char arr[20];
				int count = 0;
				FILE *f;
				f = fopen("highscore.txt", "r");
				for (int i = 0;i < 5;){
					while (!feof(f)){
						count++;
						fscanf(f, "%s", arr);
					   if (count%2 == 1){
					   		strcpy(highscore[i].name,arr);
							//printf ("%s\t",ch);
						}
						else{
							highscore[i].score = atoi(arr);
							i++;
							}
					   }
					}
				}
	}

	void showTextBackground(int x,int y,char *str,int color){
		int bk = getbkcolor();
		setbkcolor(color);
		outtextxy(x,y,str);
		delay(200);
		setbkcolor(bk);
	}

	void showText(int x,int y,char *str){
		int c = getcolor();
		int color = rand() % 16 + 1;
		setcolor(color);
		outtextxy(x+3,y,str);
		setcolor(c);
		delay(50);
	}

	bool isEmpty(){
		FILE *fp;
		long size;
		fp = fopen("highscore.txt","r");
		if(fp){
			fseek (fp, 0, SEEK_END);
	        size = ftell(fp);
			fclose(fp);
		}
		return(size == 0);
	}

	void modern(){
	}
	
	void showHighScore(){
		FILE *f;
		f = fopen("highscore.txt", "r");
		char ch[20];
		settextstyle (1,0,5);
		setcolor (15);
		outtextxy (150,50,"HIGH SCORE");
		settextstyle (1,0,4);
		int y = 150,count = 0;
		while (!feof(f)){
			if (count == 10) break;
			count++;
			fscanf(f, "%s", ch);
	   		if (count%2 == 1){
	   			setcolor (10);
	   			outtextxy (180,y,ch);
	   			y+=50;
			}else{
				setcolor (12);
				outtextxy (500,y-50,ch);	   	
			}
		}
		fclose(f);
	}
	void getHighScore (){
		FILE *f;
		f = fopen("highscore.txt", "w");
		for (int i = 0;i < 5;i++){
			fputs(highscore[i].name,f);
			fputs(" ",f);
			fprintf(f,"%d",highscore[i].score);
			fputs("\n",f);
		}
		fclose(f);
	}
	void checkHighScore (int _score){
		char _name[20]={""};
		for (int i = 0;i < 5;i++){
			if (_score > highscore[i].score){
				//to do sth
				settextstyle(1,0,3);
					for (int j = 0;j < 50;j++){
						if (j%2 == 0){
							setcolor (14);
							if (i == 0){
							outtextxy(460,100,"BEST SCORE");
							}
							else{
							outtextxy(460,100,"HIGH SCORE");}
							delay(100);
						}else{
							setcolor (9);
							if (i == 0){
							outtextxy(460,100,"BEST SCORE");}
							else{
							outtextxy(460,100,"HIGH SCORE");}
							delay(100);
						}
					}
					settextstyle(1,0,2);
					setcolor (4);outtextxy(430,150,"Player:");
					delay(100);
					char ch1;
					int x = 0;
					char str[2];
					str[1] = 0;
					while (ch1 != 13 && x < 10){
						do{
							ch1 = getch();
						}while (ch1 < 65 && ch1 >90 || ch1 < 97 && ch1 > 132);
						x++;
						str[0] = ch1;
						strcat(_name,str);
						outtextxy(540,150,_name);
					}
				for (int j = 4;j > i;j--){
					strcpy(highscore[j].name,highscore[j-1].name);
					highscore[j].score = highscore[j-1].score;
				}
				strcpy(highscore[i].name,_name);
				highscore[i].score = _score;
				break;
			}
		}
		getHighScore();
	}
	
	
	int timeGame=14;
	int main (){
		
		int i;
		int score;
		int length;

		flyGame T;

	
		
		initwindow (1100,700); 
		initScore();	

		int x = 0;
		char *a = new char[5];
		while (x <= 100){					
		cleardevice();
		setcolor (10);settextstyle(4,0,5);outtextxy (60,200,"Game Loading...");
		sprintf (a,"%d",x);
		setcolor (4);
		outtextxy (550,200,strcat(a,"%"));
		if (x == 100)
			{delay (500);}
			delay (20);
				x++;
		}
		
		while (true){
		x1:
		int bk = getbkcolor();
		cleardevice();
		setbkcolor(0);
		cleardevice();
		clearmouseclick(WM_LBUTTONDOWN);
	//	PlaySound(TEXT("faded.wav"), NULL , SND_ASYNC);
		while (!ismouseclick(WM_LBUTTONDOWN) || mousex() < 200 || mousey() > 465 || mousey() < 190 || mousex() > 580 ){
			settextstyle(1,0,6);
			setcolor (10);
			outtextxy(120,70,"GAME MENU");
			
			settextstyle(10,0,5);
			
			showText (220,200,"NEW GAME");
			showText (220,270,"HIGH SCORE");
			showText (220,340,"QUIT GAME");
			showText (220,410,"ABOUT");
		}
		clearmouseclick(WM_LBUTTONDOWN);
		if (mousey() <= 255){
			showTextBackground(220,200,"NEW GAME",15);
			x2:
				
			T.removeAll();
	
			setbkcolor(0);
			cleardevice();
			int nameFunction;
			clearmouseclick(WM_LBUTTONDOWN);
			while (!ismouseclick(WM_LBUTTONDOWN) || mousex() < 290 || mousex() > 520 || mousey() < 240 || mousey() > 400){
				settextstyle(1,0,6);setcolor(10);
				outtextxy (150,150,"GAME TIME");
				setcolor(15);settextstyle(1,0,4);
				showTextBackground(250,250,"15s",0);
				showTextBackground (350,250,"30s",0);
				showTextBackground(450,250,"45s",0);
		
			}
			nameFunction = 1;
			
			if (ismouseclick(WM_LBUTTONDOWN) && mousex() >= 250 && mousex() <= 700 && mousey() >= 240 && mousey() <= 400){
				if(mousex() <= 340) {timeGame = 15;}
				else if ( mousex()<=440){timeGame = 30;}
				else if ( mousex()<=540) {timeGame = 45;}
			
				
				else {timeGame = 30;}
			}

		//	timeGame = 60;
			
			setbkcolor(0);
			cleardevice();
			setcolor(4);settextstyle(4,0,3);
			outtextxy(10,310,"YOUR CHOICE :");
			settextstyle (4,0,6);
			setcolor (10);
			outtextxy (150,200,"LEVEL 1 - 5");
			setcolor(4);settextstyle(4,0,3);
			outtextxy(10,310,"YOUR CHOICE :");
			int xx = 330;
			char str1[2];
			clearmouseclick(WM_LBUTTONDOWN);

			while (!ismouseclick(WM_LBUTTONDOWN) || mousex() < 300 || mousex() > 790 || mousey() < 280 || mousey() > 350){
//			if (xx <750){
			//	for(int i = 1;i <= 5;i++){
				
					settextstyle(4,0,4);
				showTextBackground(330,300,"1",0);
				showTextBackground(430,300,"2",0);
				showTextBackground(530,300,"3",0);
				showTextBackground(630,300,"4",0);
				showTextBackground(730,300,"5",0);
				
				}
			
//			}//
			if (ismouseclick(WM_LBUTTONDOWN) && mousex() >= 300 && mousex() <= 790 && mousey() >= 280 && mousey() <= 350){
				if(mousex() <= 390) level = 1;
				else if(mousex() <= 490) level = 2;
				else if(mousex() <= 590) level = 3;
				else if(mousex() <= 690) level = 4;
				else level = 5;
			}
			
			PlaySound(TEXT("start.wav"), NULL , SND_ASYNC);
			
			
		//<----------------start game-------------------->	
		

		setbkcolor (15);
		cleardevice ();
		setwindowtitle ("Game dap ruoi @_@");
				
		setfillstyle (1,13);
		bar (MINW,MINH,MAXW,MINH+5);
		bar (MAXW,MINH,MAXW-5,MAXH);
		bar (MAXW,MAXH,MINW,MAXH-5);
		bar (MINW,MINH,MINW+5,MAXH);
//		setfillstyle(1,14);
//		floodfill(900, 800, 14);
		setcolor (0);
	
		int bk = getbkcolor();
	//	setfillstyle (2,4);
	//	bar (25,25,415,215);
	
//		floodfill(500, 500, 4);
		setcolor (14); 
		srand ( time(NULL));

			endGame = false;
			int startTime = time(NULL);
			int currentTime = 0;
			int timeRemain;
			int preTimePlay = 0 ;

			while (!endGame){
			x3:

			currentTime = time(NULL);
			int timePlay = currentTime - startTime;
			
			if (timePlay == timeGame){endGame = true;}
			delay (250 - (level-1)*40);
			timeRemain = timeGame-timePlay; 

//			T.setDefault();

			T.fliesMove();
			T.drawFliesMove();
			T.checkClick();
			
			
			score = T.getScore();
			length = T.getLength();
			
			int x = getcolor();
			setfillstyle (1,BACKGROUND);
			setcolor (BACKGROUND);
				int b = getcolor ();
				
				setcolor (2);
				sprintf(score_str,"%d",score);
			    settextstyle(4,0,3);
			    outtextxy(800,20,"SCORE:");
			    
			    setcolor(12);
			    outtextxy(950,20,score_str);
			    
			    sprintf(score_str,"%d",timeRemain);
			    settextstyle(4,0,3);
			    outtextxy(800,60,"TIME:");
			    setcolor(12);
			    outtextxy(950,60,score_str);
			    
				sprintf(score_str,"%d",length);
			    settextstyle(4,0,3);
			    
			    setcolor(9);
			    outtextxy(800,100,"Fly:");
			    
			    outtextxy(950,100,score_str);
			    setcolor(b);

				if (timePlay - preTimePlay == 1 && timePlay != 0 ){
					T.addFly(1);
					preTimePlay = timePlay;		
				}
			if (endGame == false){	goto x3;}
		}
		
		//<-------------------- loop game--------------------------->
		
			PlaySound(TEXT("endGame.wav"), NULL , SND_ASYNC);
			settextstyle (1,0,4);
			setcolor (0);
			outtextxy (100,110,"GAME OVER!");
			setcolor (8);
			settextstyle (1,0,2);

			//Here is check high score
			checkHighScore(score);
			setcolor(10);settextstyle(4,0,5);
			outtextxy (100,200,"Play Again ?");
			settextstyle(4,0,3);
			setcolor(1);
			clearmouseclick(WM_LBUTTONDOWN);
			while (!ismouseclick(WM_LBUTTONDOWN)){
				showTextBackground(150,270,"YES",12);showTextBackground(300,270,"NO",7);
			}
			if(ismouseclick(WM_LBUTTONDOWN)){
				if (mousex() >= 140 && mousex() <= 230 && mousey() >= 260 && mousey() <= 310){
					showTextBackground(150,270,"YES",7);
					delay(100);
					goto x2;
				}
				else if(mousex() >= 290 && mousex() <= 360 && mousey() >= 260 && mousey() <= 310){
					showTextBackground(300,270,"NO",12);
					delay(100);
					goto x1;
				}
	        	}
	    	}else if (mousey() <= 325){
				showTextBackground(220,270,"HIGH SCORE",15);
				cleardevice();
				showHighScore();
				while (!ismouseclick(WM_LBUTTONDOWN)){
					delay(0);
				}
				goto x1;
			}else if(mousey() <= 395){
				showTextBackground (220,340,"QUIT GAME",15);
				exit(0);
			}else{
				
			cleardevice();
			settextstyle (1,0,4);
			setcolor (15);
			int x = getcolor();
			while(!ismouseclick(WM_LBUTTONDOWN)){
				settextstyle(10,0,6);setcolor(15);
				
				outtextxy(290,20,"ABOUT");
			
				settextstyle(10,0,4);
				showText(290,150,"DE TAI: 5");
			
				showText(200,270,"SINH VIEN THUC HIEN");
				
				showText(120,320,"NGUYEN QUOC DAT - NGUYEN MINH VU");
				
				showText(180,390,"GIANG VIEN HUONG DAN");
				
				showText(220,440,"NGUYEN VAN NGUYEN");
			}
			setcolor(x);
			settextstyle (1,0,2);
			setcolor (4);
			goto x1;
			}
		}
		delete score_str;
		getch();
		closegraph ();
	    return 0;
	}






	






