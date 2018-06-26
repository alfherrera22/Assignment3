/*
    Assignment 3 CS 570
    June 26th 2018
    Guy Leonard
    Pierre Kharat
    Alfonso Herrera
*/
 
#include "a3.h"

using namespace std;

pthread_t COUNT,PRINT;

time_t rawtime;
time_t endingtime;
struct tm * timeinfo;
struct tm * endinginfo;

int main(int argc, char* argv[]){
	time(&rawtime);
  	timeinfo = localtime(&rawtime);
	printf("Duration = %s", asctime(timeinfo));
	
	//Use default 25 sec if no argument
	if(argc == 1){ 
		
		pthread_create(&COUNT, NULL, &seek_Time, (void*)STANDARD_TIME);
		pthread_create(&PRINT, NULL, &print_Time, NULL);
		
		// Adds 25 seconds to local time;
		// To be used for while loop
		endingtime = mktime(timeinfo);
		endingtime += 25;
		endinginfo = localtime(&endingtime);
	} // End if
	
	else if (argc > 1){
		
		long sec;
		
		if((sec = atoi(argv[1])) == 0){
			cout << "Invalid number. Program will exit"<< endl;
			return 0;
		} // End if
		
		else{
			pthread_create(&COUNT, NULL, &seek_Time, (void*)sec);
			pthread_create(&PRINT, NULL, &print_Time, NULL);
			
			// Adds given amount of time to localtime;
			// To be used for while loop
			endingtime = mktime(timeinfo);
			endingtime += sec;
			endinginfo = localtime(&endingtime);
		} // End else
	} // End else
	
	return 0;
} // End main


void *seek_Time(void *i){
  	time(&rawtime);
  	timeinfo = localtime(&rawtime);
	
	printf("Duration = %s", asctime(timeinfo));
	
	pthread_exit(NULL);
} // End *seek_Time()


void *print_Time(void *i){
  	time(&rawtime);
  	timeinfo = localtime(&rawtime);
	
	// While loop prints current time until
	// Stopping time is reached
	while(mktime(timeinfo) != endingtime) {
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		printf("Duration = %s", asctime(timeinfo));
	} // End while
	
	pthread_exit(NULL);
} // End *print_Time()
