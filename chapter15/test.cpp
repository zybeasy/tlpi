//
// Created by zy on 2020/5/26.
//
#include <iostream>

#include "header.h"

using namespace std;

void func() {
    struct stat st;
    stat("a.data", &st);
    output_stat("a.data", &st);
    lstat("soft_a.data", &st);
    output_stat("soft_a.data", &st);
}
