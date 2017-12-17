#include "big.h"

int main(){
	double i;
	int x, y, n;
	View();
	init_seats();
	signal(SIGALRM, cntdown);
	signal(SIGIO, on_input);
	enable();
	set_ticker(1000);
	while(1){
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
			changestate(i+1);
			if(library[i].cnt == 0)
				reset_seat(i);		
		}	
	}
	View();

}
int is_occupied(int num){
	if(library[num-1].cnt != 0)
		return 1;
	else
		return 0;
}
int to_int(char num){
	num -= 48;
	return num;
}
void on_input(int signum){
	double input;
	char num;
	int i = 0, j = 0, numi;
	int x, y;
	scanf("%lf", &input);
	if(has_seat(input) != 0){
		scanf("%c", &num);
		while(1){
			numi = to_int(num);
			if(numi == 1){
				time_reset(input);
				break;
			}
			else if(numi == 2)
			{		
				j = getback_seat(input);
				changestate(j+1);
				View();	
				break;		
			}
			else{
				scanf("%c", &num);
				continue;
			}
		}
		return;
	}
	whereXY(&x, &y);
	i = whatnumber(y,x);
	if(is_occupied(i))
		printf("선택할 수 없습니다.\n");
	else{
		set_seat(input, i);
		changestate(i);
		View();
	}		
}

void enable(){
	int flag;
	
	fcntl(0, F_SETOWN, getpid());
	flag = fcntl(0, F_GETFL);
	fcntl(0, F_SETFL, (flag|O_ASYNC));
}
