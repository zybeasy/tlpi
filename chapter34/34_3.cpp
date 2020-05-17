#include <iostream>

#include <signal.h>
#include <unistd.h>

using namespace std;

static void handler(int sig) {}

void sighub_34_3(int argc, char* argv[]) {

    setbuf(stdout, NULL);

    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = handler;

    sigaction(SIGHUP, &sa, NULL);

    pid_t child = fork();

    if(child == 0 && argc > 1)
        /*
         * 子进程创建自己的进程组，这样shell退出的时候，就不会向这个进程发送SIGHUP
         * shell退出的时候只会向自己创建的进程组发送SIGHUB信号，既是该进程与shell位于同一session
         */
        setpgid(0, 0);

    cout << "PID=" << getpid() << " PPID=" << getppid() << " PGID=" << getpgrp() << " SID=" << getsid(0) << endl;

    // 定时处理，SIGALRM信号默认是终止进程；此处用于终结for循环
    alarm(60);

    for(;;) {
        /*
         * pause挂起进程，直到收到信号
         * 若信号处理是终结进程，则pause没有机会执行
         * 若忽略信号，则还是挂起，pause返回
         * 否则信号处理函数执行完以后，pause返回-1，errno设置EINTR，所以pause只有出错返回值，表示被信号中断
         */
        pause();
        cout << getpid() << ": caught SIGHUP" << endl;
    }
}

/* 执行说明
 * 1.
 */
