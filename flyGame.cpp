#include "flyGame.h"
#include <ctime>
#include <winbgim.h>
#include <iostream>
using namespace std;

flyGame::flyGame(){
	this -> length = 1;
	this -> s = new fly[length];
	this -> score = 0;
}

flyGame::~flyGame(){

	delete[] s;
}

int flyGame::getScore(){
	return this -> score;
}

int flyGame::getLength(){
	return this -> length;
}



	void flyGame::fliesMove(){
		int n = this -> length;
			for (int i = 0; i < n; i++) {
		            	s[i].update();
		            	s[i].move();
		        		s[i].checkPosition();
				}
	}

void flyGame::drawFliesMove(){
			int count = 0;
			int n =this -> length;
			for (int i = 0;i < n;i++){
					if(s[i].alive > 0 && s[i].isDraw==true) {
						setfillstyle (1,10);
						



						s[i].drawFly();
						count++;			
						setcolor(15);
						setfillstyle (1,15);

						s[i].removeFlyWhenMove();
						setcolor(15);
						setfillstyle (1,15);
						delay(10);
					}
				}
}

void flyGame::addFly(int num){
			int n = this -> length;
			n += num;

					
			fly* temp = new fly[n];	
			for (int j = 0; j < n - 1 ; j++) {
					  *(temp + j) = *(s + j);
				}
			delete[]s;
					
			s = new fly[n]; 
			for (int j = 0; j <n - 1  ; j++) {
			  *(s + j) = *(temp + j);
			}
			delete[] temp;
			this -> length = n;
			delay(10);

}

void flyGame::removeFly(int i){
	
		int n = this -> length;	
		n = n - 1;			
							
		fly* temp = new fly[n];
		for (int j = 0; j < i ; j++) {
			 *(temp + j) = *(s + j);
				}
		for (int j = i+1; j < n + 1 ; j++) {
		    *(temp + (j-1)) = *(s + j);
				}
		delete[]s;
							
		s = new fly[n]; 
		for (int j = 0; j < n  ; j++) {
		   *(s + j) = *(temp + j);
			}
		delete[] temp;
		
		this -> length = n;
		delay(10);
}

void flyGame::checkClick(){
			int clickX = 0, clickY = 0;
			int n = this -> length;
			int isRemove = 0;
			getmouseclick(WM_LBUTTONDOWN, clickX, clickY);
			if (clickX != 0 && clickY!= 0){
				for( int i=0;i< n ;i++){
					if (s[i].alive > 0){
						if (  clickX >= s[i].getX()-50 && clickX <= s[i].getX()+50 && clickY >= s[i].getY()-50 && clickY <= s[i].getY()+50){
							s[i].alive = s[i].alive - 1;
							if (s[i].alive <= 0){
								setcolor(15);
								setfillstyle (1,15);
								s[i].removeFlyWhenClick();
								this -> score+=10;
								s[i].isDraw = false;
								removeFly(i);
								isRemove=1;
								}
							}
						}
					if (isRemove == 1){ break;}
					}
			}
}

void flyGame::removeAll(){
	delete[] s; 
	this -> length = 1;
	this -> score = 0;
	s = new fly[length];

}
