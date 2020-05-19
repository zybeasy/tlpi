//#include "tmp.h"

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

struct Line{
    char *data;
    Line *next;
};


void get_cmdlines() {
    int f = open("/proc/self/cmdline", O_RDONLY);
//    int f = open("data.txt", O_RDONLY);

    char *tmp = NULL;
    int len = 0;
    const int MAX_SIZE = 10;
    char buf[MAX_SIZE];
    int read_len = 0;
    while((read_len = read(f, buf, MAX_SIZE)) != 0) {
        if(tmp){
            char *tmp2 = (char*)malloc(sizeof(char) * (read_len + len));
            memcpy(tmp2, tmp, len);
            memcpy(tmp2+len, buf, read_len);
            free(tmp);
            tmp = tmp2;
        }
        else {
            tmp = (char*)malloc(sizeof(char) * read_len);
            memcpy(tmp, buf, read_len);
        }
        len += read_len;
    }
    close(f);


    Line *head = NULL, *tail = NULL;
    int start = 0, end = 0;
    for(int i = start; i < len; ++i) {
        if(tmp[i] != '\0' && tmp[i] != '\n') {
            continue;
        }
        end = i;
        if(start != end) {
            Line *line = new Line();
            line->data = (char*)malloc(sizeof(char) * (end - start + 1));
            line->next = NULL;
            memcpy(line->data, tmp + start, end - start);
            line->data[end - start] = '\0';

            if(head) {
                tail->next = line;
                tail = line;
            }
            else
                head = tail = line;

            for(i++; i < len; ++i) {
                if(tmp[i] != '\0' && tmp[i] != '\n')
                    break;
            }
            start = i;
        }
    }
    if(start != len) {
        Line *line = new Line();
        line->data = (char*)malloc(sizeof(char) * (len - start + 1));
        memcpy(line->data, tmp + start, len - start);
        line->data[len - start + 1] = '\0';
        line->next = NULL;

        if(head == NULL)
            head = tail = line;
        else
            tail->next = line;
    }

    Line *cur = head;
    while(cur) {
        cout << cur->data << endl;
        cur =cur->next;
    }
}