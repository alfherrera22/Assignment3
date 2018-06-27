/*
    Assignment 3 CS 570
    June 26th 2018
    Guy Leonard
    Pierre Kharat
    Alfonso Herrera
*/
 
#include "a3.h"

using namespace std;

// Pthreads
pthread_t COUNT,PRINT;

// These variables will take care of the time
time_t rawtime;
time_t endingtime;
struct tm * timeinfo;
struct tm * endinginfo;
long sec;
		

// Signal that will notify the PRINT thread to terminate
bool sig = true;


/** 
 * This is the main function of the program. The program is in charge of 
 * creating two threads. Each thread will call a different function, seek_Time()
 * and print_Time() respectively. If no argument entered by the user the 
 * program will use the standard 25 seconds. If there is an argument, first 
 * the program will make sure if it is a correct input and if it is it will
 * send the amount of seconds entered.
 * 
 */
int main(int argc, char* argv[]){
	
	time(&rawtime);
  	timeinfo = localtime(&rawtime);
  	
	// Use default 25 sec if no argument
	if(argc == 1){ 
		
		sec = STANDARD_TIME;
		
		// Adds 25 seconds to local time;
		// To be used for while loop
		endingtime = mktime(timeinfo);
		endingtime += sec;
		endinginfo = localtime(&endingtime);
		
		pthread_create(&COUNT, NULL, &seek_Time, NULL);
		pthread_create(&PRINT, NULL, &print_Time, NULL);
		
		pthread_join(COUNT,NULL);
		pthread_join(PRINT,NULL);
		
	} // End if
	
	else if (argc > 1){
		
		// Error checking
		if((sec = atoi(argv[1])) == 0){
			cout << "Invalid number. Program will exit"<< endl;
			return 0;
		} // End if
		
		else{
			
			// Adds given amount of time to localtime;
			// To be used for while loop
			endingtime = mktime(timeinfo);
			endingtime += sec;
			endinginfo = localtime(&endingtime);
			
			pthread_create(&COUNT, NULL, &seek_Time, NULL);
			pthread_create(&PRINT, NULL, &print_Time, NULL);
			
			pthread_join(COUNT,NULL);
			pthread_join(PRINT,NULL);
			
		} // End else
	} // End else
	
	cout << "\nProgram just finished. Have a nice day.\n";
	
	return 0;
} // End main

/**
 * This function will busy wait until the desired time is reached. The way
 * in which we check the time is by using the time() function and adding
 * the amount of seconds that the user previously input.
 * 
 */
void *seek_Time(void *i){
	
  	time(&rawtime);
  	timeinfo = localtime(&rawtime);
	
	// Busy waiting until amount of seconds reached
	sleep(sec);
	
	// When amount of seconds reached we signal the other program to exit
	sig = false;
	
	pthread_exit(NULL);
} // End *seek_Time()

/**
 * This function will print the current time every single second until the 
 * function seek_Time() changes the signal from true to false. After this
 * the program will gracefully exit.
 * 
 */

void *print_Time(void *i){
	
  	time(&rawtime);
  	timeinfo = localtime(&rawtime);
	
	// While loop prints current time until
	// Stopping time is reached
	
	while(sig) {
		
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		printf("%s", asctime(timeinfo));
		sleep(1); // sleep(1) so the loop will only print each second
		
	} // End while
	
	
	pthread_exit(NULL);
} // End *print_Time()

