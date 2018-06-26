/*
    Assignment 3 CS 570
    June 26th 2018
    Guy Leonard
    Pierre Kharat
    Alfonso Herrera
*/
 
#include "a3.h"

using namespace std;

int main(int argc, char* argv[]){
	
	pthread_t COUNT,PRINT;
	
	
	
	//Use default 25 sec if no argument
	if(argc == 1){ 
		
		pthread_create(&COUNT, NULL, &seek_Time, (void*)STANDARD_TIME);
		pthread_create(&PRINT, NULL, &print_Time, NULL);
		
		pthread_join(COUNT,NULL);
		pthread_join(PRINT,NULL);
	}
	
	else if (argc > 1){
		
		int sec;
		
		if((sec = atoi(argv[1])) == 0){
			cout << "Invalid number. Program will exit"<< endl;
			return 0;
		}
		
		else{
			pthread_create(&COUNT, NULL, &seek_Time, (void*)sec);
			pthread_create(&PRINT, NULL, &print_Time, NULL);
			
			pthread_join(COUNT,NULL);
			pthread_join(PRINT,NULL);
		}
	}
	
	return 0;
}


void *seek_Time(void *i){

	time_t rawtime;
  	struct tm * timeinfo;

  	time(&rawtime);
  	timeinfo = localtime(&rawtime);
	
	printf("Duration = %s", asctime(timeinfo));
}


void *print_Time(void *i){
	
	int sec = *((int *) i);
	
	pthread_exit(NULL);
}
