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
	
	//Use default 25 sec if no argument
	if(argc == 1) { work(STANDARD_TIME); }
	
	else if (argc > 1){
		
		int sec;
		
		if((sec = atoi(argv[1])) == 0){
			cout << "Invalid number. Program will exit"<< endl;
			return 0;
		}
		
		else
			work(sec);
	}
	
	return 0;
}


int work(int sec){

	clock_t start;
    double duration;
	
	

    start = clock();
    sleep(sec);
    
	duration = ( clock() - start ) / CLOCKS_PER_SEC;	
	
	printf("Duration = %4.2f\n",duration);
	
	
	
	return 0;
}



//pid_t PID, PID2;
	
	
	///* This child thread should notify the other child
	 //* upon reaching the specified number of seconds 
	 //*/
	
	//PID = fork();
	
	//if(PID == 0){ //Child proccess executes code here
		
		///* This second child prints the hour, minute, and second 
		 //* of the time of day to the user terminal once every 
		 //* second 
		 //*/
		//PID2 = fork();
		
		//if(PID == 0){ //Child process executes code here
			
			
		//}
		
		//else if(PID > 0){//Parent process executes code here
			
		
		//}
		
		//else{
			//perror("fork() error");
			//exit(-1);		
		//} // End if
		
		
		
		
	//}

	//else if(PID > 0){ //Parent process executes code here
		
		//cout << "\nHave a nice day" << endl;
	//}

	//else{
		//perror("fork() error");
		//exit(-1);		
	//} // End if
