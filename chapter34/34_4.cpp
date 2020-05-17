#include <iostream>

#include <string.h>
#include <signal.h>

#include <unistd.h>

using namespace std;

static void handler(int sig) {
    cout << "PID " << getpid() << ": caught signal " << sig << "(" << strsignal(sig) << ")" << endl;
}

void sighub_34_4(int argc, char* argv[]) {

    setbuf(stdout, NULL);

    pid_t parent = getpid();
    cout << "PID of parent process is:  " << parent << endl;
    cout << "Foreground process group ID is:    " << tcgetpgrp(STDIN_FILENO) << endl;

    struct sigaction sa;
    for(int j = 1; j < argc; ++j) {
        pid_t child = fork();
        if(child == 0) {
            if(argv[j][0] == 'd')   // 'd' 表示子进程进入新的进程组
                setpgid(0, 0);
            sigemptyset(&sa.sa_mask);
            sa.sa_flags = 0;
            sa.sa_handler = handler;
            sigaction(SIGHUP, &sa, NULL);
            break;
        }
    }

    alarm(60);

    cout << "PID=" << getpid() << " PGID=" << getpgrp() << endl;
    for(;;)
        pause();
}

