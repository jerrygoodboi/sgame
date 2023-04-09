#include <stdlib.h>
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
	struct timespec t;
	long long ms,ts;
	int speed,score,lives,px,py,val,ax,ay;
	        clock_gettime(CLOCK_MONOTONIC,&t);
	ms=(t.tv_sec*1000LL+t.tv_nsec/1000000LL);ts=ms;
	speed=500;score=1;lives=3;px=maxx/2;py=maxy-1;ax=(rand()%maxx);ay=0;
while((val=getch())!=27){
		mvprintw(0,0,"Score:%d",score-1);
		mvprintw(2,0,"Lives:%d",lives);
		if(ts==ms){
		clear();
		mvprintw(ay,ax,"*");
		ay++;
		ts=ms+speed;
		}
	        clock_gettime(CLOCK_MONOTONIC,&t);
	     	ms=(t.tv_sec*1000LL+t.tv_nsec/1000000LL);
		if((val == right || val == 108 )&& px != maxx-3 ){
		px++;
		}
		else if((val==left || val == 104) && px != 0){
		px--;
		}
		move(py, 0);
		 clrtoeol();
		mvprintw(py,px,"===");
		refresh();
		if(ay==maxy){
		if(px==ax||px+2==ax||px+1==ax){
		score++;
		if(score%3==0&&speed>100){
		speed-=50;
		}}
		else{
		lives--;
		}
		ay=0;
		ax=(rand()%maxx);
		}
		if(lives==0){
			break;
		}
	}
	endwin();
	printf("Your Score:%d\nTo play again type \"./plate\" and hit ENTER\n",score);
}
