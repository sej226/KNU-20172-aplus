#include "big.h"

int main(){
	double i;
	int x, y, n;
	View();
	init_seats();
	signal(SIGALRM, cntdown);
	signal(SIGIO, on_input);
	enable();
	set_ticker(5000);
	while(1){
		fflush(stdout);	
		pause();
	

	}	
	return 0;
}


int set_ticker(int n){
	struct itimerval new_timeset;
	long	n_sec, n_usecs;
	
	n_sec = n /1000;
	n_usecs = (n % 1000) * 1000L;
	
	new_timeset.it_interval.tv_sec = n_sec;
	new_timeset.it_interval.tv_usec = n_usecs;
	new_timeset.it_value.tv_sec = n_sec;
	new_timeset.it_value.tv_usec = n_usecs;

	return setitimer(ITIMER_REAL, &new_timeset, NULL);
}
void cntdown(int signum){
	int i = 0;
	for(;i<24;i++){
		if(library[i].cnt > 0){
			library[i].cnt--;
			if(library[i].cnt == 0)
				reset_seat(i);		
		}	
		if(library[i].cnt != 0){
			printf("\n%d Seat's information\nOccupier : %lf\nTime : %dmins left\n\n",library[i].seatnum, library[i].occupier, library[i].cnt);
		}
	}
}
int is_occupied(int num){
	if(library[num-1].cnt != 0)
		return 1;
	else
		return 0;
}
void on_input(int signum){
	double input;
	int num,i = 0, j = 0;
	int x, y;
	scanf("%lf", &input);
	if(has_seat(input) != 0){
	//	printf("연장1 or 반납2");
		scanf("%d", &num);
		if(num == 1)
			time_reset(input);
		else
			getback_seat(input);
		return;
	}
	//printf("좌석을 선택해 주세요\n");
	//scanf("%d", &num);
	whereXY(&x, &y);
	num = whatnumber(y,x);
	if(is_occupied(num))
		printf("선택할 수 없습니다.\n");
	else{
		set_seat(input, num);
		//View();
	}		
}

void enable(){
	int flag;
	
	fcntl(0, F_SETOWN, getpid());
	flag = fcntl(0, F_GETFL);
	fcntl(0, F_SETFL, (flag|O_ASYNC));
}
