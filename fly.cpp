#include "fly.h"
#include <iostream>
#include <winbgim.h>

using namespace std;

int randomNum (int n){
		int a;
		a = rand() % n + 1;
	    return a;
	}
fly::fly(){
		this -> alive = 1 ;
		this -> isDraw = true;
//		this -> isIncreaseR = false;
		this ->	MINX = 20;
		this -> MINY = 20; // 20
		this ->	MAXX = 700;
		this -> MAXY = 480;
		this -> x0 = 0;
		this -> y0 = 0;
		this -> r = 10;
		setLeft();
		randomPosition();
		setStartDirection();

}
fly::~fly(){


}	
int fly::getX(){
	
		return this -> x ;
	
	};

int fly::getX0(){
		return this -> x0;
	}

int fly::getY(){
	
		return this -> y;
	
	}

int fly::getY0(){
	
		return this -> y0;
		
	}

void fly::setLeft(){

	this -> left = randomNum(2);
	
};

void fly::update(){
	
	if(this -> alive>0){
		
				this -> x0 = this -> x;
				this ->	y0 = this -> y;
			
			}
				
};



//void fly::checkInitFly(){
//	
//	if(this -> isInitFly == false){
//			setLeft();
//			randomPosition();
//			setStartDirection();
//			this -> isInitFly = true;
//		}
//
//};

void fly::move(){

//	if(this -> alive>0){
			if (this -> left==1){
					this -> toggle = 1;
				}
			else {
					this -> toggle = -1;
				}
	
			switch (randomNum(5))
					{
						case 1:
					        {	this -> directionx = 0;
								this ->directiony = -20;
							if (this -> y == this -> MINY + 30){
								this ->directiony = 0;
								this -> directionx = toggle*20;
							}
								break; }
					    case 2:
					        {this -> directionx = toggle*20 ;
							 this ->	directiony = -20;
							 	if (this -> y == this -> MINY + 30){
								this ->directiony = 0;
							}
							 break;}
					    case 3:
					        {this -> directionx = toggle*20 ;
							 this ->directiony = 0;
							  break;}
					    case 4:
					        {this -> directionx = toggle*20 ;
							this -> directiony = 20;
								if (this -> y == this -> MAXY - 30){
								this ->directiony = 0;
							}
							break;}
					    case 5:
					        {this ->directionx = 0;
							this ->directiony = 20;
								if (this -> y == this -> MAXY - 30){
								this -> directiony = 0;
								this ->directionx = toggle*20;
							}
							break; }
					    default: {	}
					}
			
				this -> x += directionx;
				this -> y += directiony;
	//	}

};

void fly::randomPosition(){
	
	if (this -> left==1){
			this -> x = 60;
			this -> y = 50 + (randomNum(11)-1)*40;
		} else {
			this ->	x = 660;
			this -> y = 50 + (randomNum(11)-1)*40;
	}	 
	
}

void fly::checkPosition(){
	
	//	if(this ->alive>0){
			
			if (this -> x >= MAXX-40) {
				//	this -> isIncreaseR = true;
					this -> x = MAXX - 40;
					this ->left = 2;
					this -> alive ++;
					
					if(this -> alive > 2){this ->  alive = 2;}
					
				};
				
			if (this -> x <= MINX+40) {
				//	this -> isIncreaseR = true;
					this -> x = MINX + 40;
					this -> left = 1;
					this -> alive++;
					if(this -> alive > 2){this -> alive = 2;}
					
				};
				
//			if (this -> y >= MAXY-30) {this -> y = MAXY - 30;};
//			if (this ->y <= MINY+30) {this -> y = MINY + 30;};
//			        if (y >= MAXY) {y = MAXY - 30;};
//			        if (y <= MINY) {y = MINY - 10;};
//		}
}

void fly::setStartDirection(){
	
		if (this -> left==1){
			
			switch (randomNum(5)){
			        
					case 1: 
						{ this -> directionx = 0;this -> directiony = -20;break;}
			
			        case 2: 
						{this -> directionx = 20;this -> directiony = -20;break;}
						
			        case 3:
						{this -> directionx = 20;this -> directiony = 0;break;}
						 
			        case 4:
						{this -> directionx = 20;this -> directiony = 20;break;}
			        
					case 5: 
						{this -> directionx = 0;this -> directiony = 20;}
						
			        default : {}
					}
					
		} else {
			
			switch (randomNum(5)){
				
			        case 1: 
						{this -> directionx = 0;this -> directiony = -20;break;}
			        
			        case 2: 
						{this -> directionx = -20;this -> directiony = -20;break;}
			        
			        case 3: 
						{this -> directionx = -20;this -> directiony = 0;break;}
			        
			        case 4: 
						{this -> directionx = -20;this -> directiony = 20;break;}
			        
			        case 5: 
						{this -> directionx = 0;this -> directiony = 20;}
			        
			        default : {}}
			}

};

void fly::drawFly (){
	
		setbkcolor(15);							
		setcolor(0);
		circle (this -> x, this ->y, this -> r); 
		floodfill (this ->x , this ->y,getcolor());
		setfillstyle(1,0);
		circle (this -> x-5, this ->y-5, this ->r/2); 
		floodfill (this ->x-5 , this ->y-5,getcolor());
		setfillstyle(1,0);
		circle (this -> x-5, this ->y+5, this ->r/2); 
		floodfill (this ->x-5 , this ->y+5,getcolor());
		
	};

void fly::removeFlyWhenMove(){
	
		setcolor(15);	
	//	circle (this -> x0, this ->y0, this ->r); 
		circle (this -> x0, this ->y0, this -> r ); 
		
		floodfill (this ->x0 , this ->y0,getcolor());
		setfillstyle(1,0);
		setcolor(15);
	//	circle (this -> x0-5, this ->y0-5, this ->r/2); 
		circle (this -> x0-5, this ->y0-5, this ->r/2 ); 
		
		floodfill (this ->x0-5 , this ->y0-5,getcolor());
		setfillstyle(1,0);
		setcolor(15);
	//	circle (this -> x0-5, this ->y0+5, this ->r/2); 
		circle (this -> x0-5, this ->y0+5, this ->r/2 ); 
		floodfill (this ->x0-5 , this ->y0+5,getcolor());
		
	}
	
void fly::removeFlyWhenClick(){
	
		setcolor(15);	
		circle (this -> x, this ->y, this ->r); 
		floodfill (this ->x , this ->y,getcolor());
		setfillstyle(1,0);
		setcolor(15);
		circle (this->x-5, this->y-5, this ->r/2); 
		floodfill (this->x-5 , this->y-5,getcolor());
		setfillstyle(1,0);
		setcolor(15);
		circle (this -> x-5, this ->y+5, this ->r/2); 
		floodfill (this ->x-5 , this ->y+5,getcolor());
		
	}
//	
//void fly::increaseR(){
//	if (this -> r < 15 && this -> isIncreaseR == true){
//			this->r += 0;
//	}
//}
//	


