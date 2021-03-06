#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "big.h"
#define BLANK "       "

int state[25]={0,};

void box2(WINDOW*, int, int, char *);

void  b1 (WINDOW*, int, int ,char *);
void  b2 (WINDOW*, int, int ,char *);
void  b3 (WINDOW*, int, int ,char *);
void  b4 (WINDOW*, int, int ,char *);
void  b5 (WINDOW*, int, int ,char *);
void  b6 (WINDOW*, int, int ,char *);
void  b7 (WINDOW*, int, int ,char *);
void  b8 (WINDOW*, int, int ,char *);

void  b9 (WINDOW*, int, int ,char *);
void  b10 (WINDOW*, int, int ,char *);
void  b11 (WINDOW*, int, int ,char *);
void  b12 (WINDOW*, int, int ,char *);
void  b13 (WINDOW*, int, int ,char *);
void  b14 (WINDOW*, int, int ,char *);
void  b15 (WINDOW*, int, int ,char *);
void  b16 (WINDOW*, int, int ,char *);

void  b17 (WINDOW*, int, int ,char *);
void  b18 (WINDOW*, int, int ,char *);
void  b19 (WINDOW*, int, int ,char *);
void  b20 (WINDOW*, int, int ,char *);
void  b21 (WINDOW*, int, int ,char *);
void  b22 (WINDOW*, int, int ,char *);
void  b23 (WINDOW*, int, int ,char *);
void  b24 (WINDOW*, int, int ,char *);


int total = 24;

void changestate(int seat)
{
	if(state[seat]==1 && library[seat-1].cnt<=0)
	{
	state[seat]=0;
	}
	else if(state[seat]==0 && library[seat-1].cnt >0)

	state[seat]=1;
	
}


void View(){
	int i;
	initscr();
	start_color();
	int k=0,q=0;
	
//	init_pair(1,COLOR_WHITE,COLOR_BLUE);
	
	init_color(2,0 , 1000, 0); //green
	init_color(3, 0, 0, 1000);	//blue	
//	init_pair(1,3,2); //파란글씨 초록배경
	init_pair(1,COLOR_BLUE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_RED);

	init_pair(5,COLOR_WHITE,COLOR_BLACK);
	for(i=0;i<24;i++)
	{
		if(state[i]==1)
		{
			k++;
		}
	
	}	
	q = total - k;
	


	WINDOW * win = newwin(32,124, 0, 0);
	box(win, ' ', ' ');
		
	box2(win,3,100,"  ------------------- ");
	box2(win,4,100,"| KNU-Library-System |");
	box2(win,5,100,"  ------------------- ");

	box2(win,7,103,"Total seat : 24");
//	box2(win,9,103,"Remaning seat : ");
//	box2(win,11,103,"Using seat :  ");

	b1(win,3,8,BLANK);
	b1(win,4,8,BLANK);
	b1(win,5,8,"  [1]  ");
	b1(win,6,8,BLANK);
	b1(win,7,8,BLANK);

	b2(win,3,20,BLANK);
	b2(win,4,20,BLANK);
	b2(win,5,20,"  [2]  ");
	b2(win,6,20,BLANK);
	b2(win,7,20,BLANK);

	b3(win,3,32,BLANK);
	b3(win,4,32,BLANK);
	b3(win,5,32,"  [3]  ");
	b3(win,6,32,BLANK);
	b3(win,7,32,BLANK);

	b4(win,3,44,BLANK);
	b4(win,4,44,BLANK);
	b4(win,5,44,"  [4]  ");
	b4(win,6,44,BLANK);
	b4(win,7,44,BLANK);

	b5(win,3,56,BLANK);
	b5(win,4,56,BLANK);
	b5(win,5,56,"  [5]  ");
	b5(win,6,56,BLANK);
	b5(win,7,56,BLANK);
	
	b6(win,3,68,BLANK);
	b6(win,4,68,BLANK);
	b6(win,5,68,"  [6]  ");
	b6(win,6,68,BLANK);
	b6(win,7,68,BLANK);


	b7(win,3,80,BLANK);
	b7(win,4,80,BLANK);
	b7(win,5,80,"  [7]  ");
	b7(win,6,80,BLANK);
	b7(win,7,80,BLANK);

	b8(win,3,92,BLANK);
	b8(win,4,92,BLANK);
	b8(win,5,92,"  [8]  ");
	b8(win,6,92,BLANK);
	b8(win,7,92,BLANK);

//	mvwprintw(win,4,8,"       ");
//	mvwprintw(win,5,8,"   1   ");
//	wattroff(win,COLOR_PAIR(1));
//	move(LINES,COLS);

	b9(win,13,8,BLANK);
	b9(win,14,8,BLANK);
	b9(win,15,8, "  [9]  ");
	b9(win,16,8,BLANK);
	b9(win,17,8,BLANK);

	b10(win,13,20,BLANK);
	b10(win,14,20,BLANK);
	b10(win,15,20," [10]  ");
	b10(win,16,20,BLANK);
	b10(win,17,20,BLANK);
	
	b11(win,13,32,BLANK);
	b11(win,14,32,BLANK);
	b11(win,15,32," [11]  ");
	b11(win,16,32,BLANK);
	b11(win,17,32,BLANK);

	b12(win,13,44,BLANK);
	b12(win,14,44,BLANK);
	b12(win,15,44," [12]  ");
	b12(win,16,44,BLANK);
	b12(win,17,44,BLANK);
	
	b13(win,13,56,BLANK);
	b13(win,14,56,BLANK);
	b13(win,15,56," [13]  ");
	b13(win,16,56,BLANK);
	b13(win,17,56,BLANK);

	b14(win,13,68,BLANK);
	b14(win,14,68,BLANK);
	b14(win,15,68," [14]  ");
	b14(win,16,68,BLANK);
	b14(win,17,68,BLANK);

	b15(win,13,80,BLANK);
	b15(win,14,80,BLANK);
	b15(win,15,80,"  [15] ");
	b15(win,16,80,BLANK);
	b15(win,17,80,BLANK);

	b16(win,13,92,BLANK);
	b16(win,14,92,BLANK);
	b16(win,15,92,"  [16] ");
	b16(win,16,92,BLANK);
	b16(win,17,92,BLANK);

	b17(win,23,8,BLANK);
	b17(win,24,8,BLANK);
	b17(win,25,8,"  [17] ");
	b17(win,26,8,BLANK);
	b17(win,27,8,BLANK);

	b18(win,23,20,BLANK);
	b18(win,24,20,BLANK);
	b18(win,25,20,"  [18] ");
	b18(win,26,20,BLANK);
	b18(win,27,20,BLANK);


	b19(win,23,32,BLANK);
	b19(win,24,32,BLANK);
	b19(win,25,32,"  [19] ");
	b19(win,26,32,BLANK);
	b19(win,27,32,BLANK);

	b20(win,23,44,BLANK);
	b20(win,24,44,BLANK);
	b20(win,25,44,"  [20] ");
	b20(win,26,44,BLANK);
	b20(win,27,44,BLANK);

	b21(win,23,56,BLANK);
	b21(win,24,56,BLANK);
	b21(win,25,56,"  [21] ");
	b21(win,26,56,BLANK);
	b21(win,27,56,BLANK);

	b22(win,23,68,BLANK);
	b22(win,24,68,BLANK);
	b22(win,25,68,"  [22] ");
	b22(win,26,68,BLANK);
	b22(win,27,68,BLANK);

	b23(win,23,80,BLANK);
	b23(win,24,80,BLANK);
	b23(win,25,80,"  [23] ");
	b23(win,26,80,BLANK);
	b23(win,27,80,BLANK);

	b24(win,23,92,BLANK);
	b24(win,24,92,BLANK);
	b24(win,25,92,"  [24] ");
	b24(win,26,92,BLANK);
	b24(win,27,92,BLANK);
	
//	mvwaddch(win,1,1,'1'|COLOR_PAIR(5));		
//	mvwprintw(1,1,"hello");
//	mvwprintw(win,LINES,COLS," ");
	mvwprintw(win,11,103,"Using seat : %d",k);
	mvwprintw(win,9,103,"Remaing seat : %d",q);

	mvwprintw(win,30,120," ");	
	refresh();
	wrefresh(win);
//	wrefresh(win2);
}
void box2(WINDOW* win, int i, int j, char * arr)
{
	wattron(win,COLOR_PAIR(5)|A_BLINK|A_BOLD);
	mvwprintw(win,i,j,arr);
	wattroff(win,COLOR_PAIR(5));
}

void b1 (WINDOW* win,int i, int j,char * arr)
{
       if(state[1]==0)
	{
	wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
	}
	else if(state[1]==1)
	{
	wattron(win,COLOR_PAIR(2));
	mvwprintw(win,i,j,arr);
	wattroff(win,COLOR_PAIR(2));
	}
}
void b2 (WINDOW * win,int i, int j,char * arr)
{
 if(state[2]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[2]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));
        }
}

void b3 (WINDOW * win,int i, int j,char * arr)

{

if(state[3]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[3]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }

}


void b4 (WINDOW * win,int i, int j,char * arr)
{
	if(state[4]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[4]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}

void b5 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[5]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[5]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }




}

void b6 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[6]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[6]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }



}

void b7 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[7]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[7]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}

void b8 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[8]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[8]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}

void b9 (WINDOW * win,int i, int j,char * arr)
{

	   if(state[9]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[9]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }

}

void b10 (WINDOW * win,int i, int j,char * arr)
{

	   if(state[10]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[10]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }

}



void b11 (WINDOW * win,int i, int j,char * arr)
{


	   if(state[11]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[11]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }

}

void b12 (WINDOW * win,int i, int j,char * arr)
{

	   if(state[12]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[12]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }

}

void b13 (WINDOW * win,int i, int j,char * arr)
{

	   if(state[13]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[13]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }

}

void b14 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[14]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[14]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}

void b15 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[15]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[15]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}

void b16 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[16]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[16]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}

void b17 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[17]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[17]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}

void b18 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[18]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[18]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}

void b19 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[19]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[19]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}

void b20 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[20]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[20]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}

void b21 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[21]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[21]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}

void b22 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[22]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[22]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}

void b23 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[23]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[23]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}

void b24 (WINDOW * win,int i, int j,char * arr)
{
	   if(state[24]==0)
        {
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(1));
        }
        else if(state[24]==1)
        {
        wattron(win,COLOR_PAIR(2));
        mvwprintw(win,i,j,arr);
        wattroff(win,COLOR_PAIR(2));

        }


}
