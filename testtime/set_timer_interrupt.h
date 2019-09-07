#ifndef _SET_TIMER_INTERRUPT_H
#define _SET_TIMER_INTERRUPT_H

#include <stdio.h>  
#include <time.h>  
#include <stdlib.h>  
#include <signal.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/time.h>

void set_timer_interrupt(struct itimerspec it,void * sig_handler);  

#endif
