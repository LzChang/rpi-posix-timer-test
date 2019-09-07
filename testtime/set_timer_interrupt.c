#include "set_timer_interrupt.h"

void set_timer_interrupt(struct itimerspec it,void * sig_handler)  
{
    timer_t timerid;  //timer ID
    struct sigevent evp;  

    // int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);  

    // signum--指定的信号编号，可以指定SIGKILL和SIGSTOP以外的所有信号编号  

    // act结构体--设置信号编号为signum的处理方式  

    // oldact结构体--保存上次的处理方式  

    //  

    // struct sigaction   

    // {  

    // void (*sa_handler)(int);         //信号响应函数地址  

    // void (*sa_sigaction)(int, siginfo_t *, void *);   //但sa_flags为SA——SIGINFO时才使用  

    // sigset_t sa_mask;         //说明一个信号集在调用捕捉函数之前，会加入进程的屏蔽中，当捕捉函数返回时，还原  

    // int sa_flags;  

    // void (*sa_restorer)(void);   //未用  

    // };  

    //  
   
    struct sigaction act;  
    memset(&act, 0, sizeof(act));  
    act.sa_handler = sig_handler;  
    act.sa_flags = 0;  

    //  int sigaddset(sigset_t *set, int signum);  //将signum指定的信号加入set信号集  
    //  int sigemptyset(sigset_t *set);          //初始化信号集

    sigemptyset(&act.sa_mask);  
    if (sigaction(SIGUSR1, &act, NULL) == -1)  
    {  
        perror("fail to sigaction");  
        exit(-1);  
    }  

    //   struct sigevent  
    //{  
    //  int sigev_notify; //notification type  
    //  int sigev_signo; //signal number  
    //  union sigval   sigev_value; //signal valu  
    //  void (*sigev_notify_function)(union sigval)  
    //  pthread_attr_t *sigev_notify_attributes  
    // }

    memset(&evp, 0, sizeof(struct sigevent));  
    evp.sigev_signo = SIGUSR1;  
    evp.sigev_notify = SIGEV_SIGNAL;  
    if (timer_create(CLOCK_REALTIME, &evp, &timerid) == -1)  
    {  
        perror("fail to timer_create");  
        exit(-1);  
    }  

    if (timer_settime(timerid, 0, &it, 0) == -1)  
    {  
        perror("fail to timer_settime");  
        exit(-1);  
    }  

}
