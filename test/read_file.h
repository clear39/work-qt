#ifndef READ_FILE_H
#define READ_FILE_H
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <error.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


void test_read_dir(){
    const char* overlay_dir = "/home";
    DIR *dir = opendir(overlay_dir);//
    if (dir == nullptr) {
       return;
    }

    struct dirent *dirent;
    while ((dirent = readdir(dir)) != nullptr) {
       struct stat st;
       char overlay_apk_path[PATH_MAX + 1];
       snprintf(overlay_apk_path, PATH_MAX, "%s/%s", overlay_dir, dirent->d_name);
       printf("overlay_apk_path:%s \n",overlay_apk_path);
       if (stat(overlay_apk_path, &st) < 0) {
           continue;
       }
       if (!S_ISREG(st.st_mode)) {//是否是一个常规文件
           continue;
       }
    }

    closedir(dir);
}

#endif // READ_FILE_H
