/* 孤儿进程组
 * 当
 */

#include <iostream>
#include <signal.h>
#include <string.h>
#include <unistd.h>

using namespace std;

static void handler(int sig) {
    cout << "PID=" << getpid() <<": caught signal " << sig << "(" << strsignal(sig) << ")" << endl;
}

int orphan_pgp_34_7(int argc, char* argv[]) {
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = handler;
    sigaction(SIGHUP, &sa, NULL);
    sigaction(SIGCONT, &sa, NULL);

    cout << "PARENT: PID=" << getpid() << ", PPID=" << getppid() << ", PGID" << getpgrp() << ", SID=" << getsid(0) << endl;

    for(int j = 1; j < argc; j++) {
        switch(fork()) {
            case 0:
                cout << "CHILD: PID=" << getpid() << ", PPID=" << getppid() << ", PGID" << getpgrp() << ", SID=" << getsid(0) << endl;
                if(argv[j][0] == 's') {
                    cout << "PID=" << getpid() << " stoping" << endl;
                    raise(SIGSTOP);
                }
                else {
                    alarm(60);
                    cout << "PID=" << getpid() << " pausing" << endl;
                }
                exit(0);
            default:
                break;
        }
    }

    sleep(10);
    cout << "PARENT exiting" << endl;
    exit(0);
}