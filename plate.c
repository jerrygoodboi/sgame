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
}
int main(){
	init();
	int x=maxx/2,y=maxy-1,val;
	while((val=getch())!=27){
		if(val == right && x != maxx-3 ){
		x++;
		}
		else if(val==left && x != 0){
		x--;
		}
	clear();
	mvprintw(y,x,"===");
	refresh();
	}
	endwin();
}
