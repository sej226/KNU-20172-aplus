#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/time.h>
#include <signal.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>

#define SEATNUM	18
typedef struct Seat{
	int seatnum;//좌석번호
	int cnt;//시간 카운트
	double occupier;//사용자 바코드 (학번)
}seat;

seat library[24];
int set_ticker(int);
void cntdown(int);
void init_seats();
void set_seat(double , int);
void on_input(int);
void enable();
int has_seat(double input);
void reset_seat(int);	
void time_reset(double input);
int getback_seat(double input);	
void changestate(int );
void whereXY(int*, int*);
int whatnumber(int , int);
void View();
