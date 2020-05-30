
#include <iostream>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>

using namespace std;

struct tm t;
char date_time[64];

void output_stat(const char* filename, const struct stat* st) {
    cout << "========== " << filename << " ==========" << endl;
    cout << "st_dev:\t\t" << st->st_dev << "\nst_ino\t\t"
         << "\nst_mode\t\t" << st->st_mode << "\nst_nlink\t" << st->st_nlink
         << "\nst_uid\t\t" << st->st_uid << "\nst_gid\t\t" << st->st_gid
         << "\nst_rdev\t\t" << st->st_rdev << "\nst_size\t\t" << st->st_size
         << "\nst_blksize\t" << st->st_blksize << "\nst_blocks\t" << st->st_blocks
         << "\nst_atime\t" << (strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", localtime_r(&(st->st_atim.tv_sec), &t)), date_time)
         << "\nst_mtime\t" << (strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", localtime_r(&(st->st_mtim.tv_sec), &t)), date_time)
         << "\nst_ctime\t" << (strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", localtime_r(&(st->st_ctim.tv_sec), &t)), date_time)
         << endl;
}