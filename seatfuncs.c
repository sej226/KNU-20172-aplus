#include "big.h"
void init_seats(){
	int i;
	for(i = 0; i < 24; i++){
		library[i].seatnum = i+1;
		library[i].cnt = 0;
		library[i].occupier = 0;
	}
}
void reset_seat(int i){
	library[i].occupier = 0;
}

void set_seat(double user, int num){
	library[num-1].cnt = 7;
	library[num-1].occupier = user;
}
int has_seat(double input){
	int i;
	for(i= 0 ; i<24; i++){
		if(library[i].occupier == input)
			return i;
	}
	return 0;
}

void time_reset(double input){
	int i; 
	i = has_seat(input);
	if(i){
		library[i].cnt = 7;
	}
}
void getback_seat(double input){
	int i;
	i = has_seat(input);
	if(i){
		library[i].cnt = 0;
		library[i].occupier = 0;
	}
}
