#define right 261
#define left 260
#include <ncurses.h>
int maxx,maxy;
void init(){
	initscr();
	curs_set(0);
	keypad(stdscr,TRUE);
	getmaxyx(stdscr,maxy,maxx);
		clear();
	mvprintw(maxy-1,maxx/2,"===");
	refresh();
	srand(time(0));
}
int main(){
	init();
	int px=maxx/2,py=maxy-1,val,ax=(rand()%maxx),ay=0;
	while((val=getch())!=27){
		clear();
		mvprintw(ay,ax,"*");
		ay++;
		if(val == right && px != maxx-3 ){
		px++;
		}
		else if(val==left && px != 0){
		px--;
		}
	//clear();
	mvprintw(py,px,"===");
	refresh();
	}
/*	while(1){
	mvprintw(ay,ax,"*");
	refresh
	}*/
	endwin();
}
