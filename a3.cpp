/*
    Assignment 3 CS 570
    June 27th 2018
    Guy Leonard
    Pierre Kharat
    Alfonso Herrera
*/
 
#include "a3.h"

using namespace std;

int main(int argc, char* argv[]){
	
	if(argc == 1){//Use default 25 sec
		
		work(STANDARD_TIME);
		
	}
	
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
    
	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;	
	
	cout << duration << "\nThank you and good bye" << endl;
	
	return 0;
}
