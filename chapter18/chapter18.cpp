//
// Created by zy on 2020/6/2.
//

#include <dirent.h>
#include <libgen.h>
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

int chapter18(int argc, char* argv[]) {
    DIR* a = opendir(".");

    struct dirent *de;
    while((de=readdir(a))) {
        cout << de->d_ino << " " << de->d_name << endl;
    }

    closedir(a);

    char pathname[] = "/zhou/wu/";

    char* dir = dirname(pathname);
    cout << setw(20) << setiosflags(ios::left) << "pathname: " << (int*)pathname << " " << pathname << endl
         << setw(20) << setiosflags(ios::left) << "dir: " << (int*)dir << " " << dir << endl
         << setw(20) << setiosflags(ios::left) << "dir+strlen(dir)+1 " << (int*)(dir+strlen(dir)+1) << " " << dir+strlen(dir)+1 << endl;

    return 0;
}