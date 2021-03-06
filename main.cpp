#include <iostream>
#include <iomanip>

#include <unistd.h>

#include <mcheck.h>
#include <pwd.h>
#include <shadow.h>
#include <limits.h>
#include <signal.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>

#include <netdb.h>

#include "chapter15/header.h"
#include "chapter17/header.h"
#include "chapter18/header.h"
#include "chapter34/header.h"
#include "chapter35/header.h"

#include "tmp/tmp.h"

using namespace std;

int main(int argc, char* argv[]) {

//    sighub_34_3(argc, argv);

//    sighub_34_4(argc, argv);

//    get_cmdlines();

//    orphan_pgp_34_7(argc, argv)

//    chapter17(argc, argv);
//
    chapter35(argc, argv);

//    chapter18(argc, argv);

    cout << NSIG << endl;

    cout << "===================================================" << endl;
    return 0;
}
