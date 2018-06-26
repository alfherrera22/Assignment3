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

int main(int argc, char* argv[]){
	// Gets the local time
	time_t rawtime, temp;
  	struct tm * timeinfo, tmp;

  	time(&rawtime);
  	timeinfo = localtime(&rawtime);
	printf("Duration = %s", asctime(timeinfo));
	
	//Use default 25 sec if no argument
	if(argc == 1){ 
		
		pthread_create(&COUNT, NULL, &seek_Time, (void*)STANDARD_TIME);
		pthread_create(&PRINT, NULL, &print_Time, NULL);
		
		// Adds 25 seconds to local time;
		// To be used for while loop
		temp = mktime(timeinfo);
		temp += 25;
		tmp = localtime(&temp);
	}
	
	else if (argc > 1){
		
		long sec;
		
		if((sec = atoi(argv[1])) == 0){
			cout << "Invalid number. Program will exit"<< endl;
			return 0;
		}
		
		else{
			pthread_create(&COUNT, NULL, &seek_Time, (void*)sec);
			pthread_create(&PRINT, NULL, &print_Time, NULL);
			
			// Adds given amount of time to localtime;
			// To be used for while loop
			temp = mktime(timeinfo);
			temp += sec;
			tmp = localtime(&temp);
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
	
	pthread_exit(NULL);
}


void *print_Time(void *i){
	
	cout << 50 << endl;
	
	pthread_exit(NULL);
}
