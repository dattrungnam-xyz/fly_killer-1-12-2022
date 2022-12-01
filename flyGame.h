#include "fly.h"

class flyGame{
	private:
		int length;
		fly *s;
		int score;
	public:
		flyGame();
		~flyGame();
		
		int getScore();
		int getLength();
		
		void addFly(int);
		
		void removeFly(int);
		
		void removeAll();//
		
		void checkClick();
		

		void fliesMove();
		void drawFliesMove();
		
};	
