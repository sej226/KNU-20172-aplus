#include "big.h"
void whereXY(int *a, int *b)
{

	int i,in=0;

	MEVENT event;
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS , NULL);
	in=getch();
	
{
	switch(in)
	case KEY_MOUSE:
	getmouse(&event);
	}
	
	*a=event.x;
	*b=event.y;	
	return ;
}

