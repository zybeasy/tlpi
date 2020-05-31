//
// Created by feihong on 2020/6/1.
//

#include <iostream>
#include <sys/resource.h>

#include <unistd.h>

using namespace std;

int chapter35(int argc, char* argv[]) {
    cout << "PID=" << getpid() << " NICE=" << getpriority(PRIO_PROCESS, 0) << endl;
}