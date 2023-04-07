#define right 261
#define left 260
#include <ncurses.h>
#include <time.h>
int maxx,maxy;
void init(){
	initscr();
	curs_set(0);
	keypad(stdscr,TRUE);
	nodelay(stdscr,1);
	getmaxyx(stdscr,maxy,maxx);
	srand(time(0));
}
int main(){
	init();
	time_t sec=time(0),temp=time(0);
	int score=0,px=maxx/2,py=maxy-1,val,ax=(rand()%maxx),ay=0;
	while((val = getch()) != 27){
		mvprintw(0,0,"Score:%d",score);
		if(temp==sec){
		clear();
		mvprintw(ay,ax,"*");
		ay++;
		temp=sec+1;
		}
		sec=time(0);
		if(val == right && px != maxx-3 ){
		px++;
		}
		else if(val==left && px != 0){
		px--;
		}
		move(py, 0);
		 clrtoeol();
		mvprintw(py,px,"===");
		refresh();
		if(ay==maxy){
		if(px==ax||px+2==ax||px+1==ax){
		score++;
		}
		ay=0;
		ax=(rand()%maxx);
		}
	}
	endwin();
}
