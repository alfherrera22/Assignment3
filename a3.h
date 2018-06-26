#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>

//If user does not input anything we will use 25 sec
#define STANDARD_TIME 25

void *seek_Time(void *i);
void *print_Time(void *i);
