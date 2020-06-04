//
// Created by feihong on 2020/6/1.
//

#include <iostream>
#include <sched.h>
#include <sys/resource.h>

#include <unistd.h>

using namespace std;

int chapter35(int argc, char* argv[]) {
    cout << "PID=" << getpid() << " NICE=" << getpriority(PRIO_PROCESS, 0) << endl;

    cout << SCHED_RR << " " << SCHED_BATCH << endl;

    cout << sched_get_priority_min(SCHED_RR) << " " << sched_get_priority_max(SCHED_RR) << endl;

    for(int i = 1; i < 10; ++i)
        cout << sched_getscheduler(i) << " " << i << " XXXXXXXX" << endl;

    return 0;
}