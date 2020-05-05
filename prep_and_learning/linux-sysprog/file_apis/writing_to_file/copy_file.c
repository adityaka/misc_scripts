#include<unistd.h>
#include<errno.h>
#include<stdbool.h>
#include<fcntl.h>
#include<sys/stat.h>

#ifdef DEBUG
    #define DEBUGLOG(...) fprintf(stderr, __VA_ARGS__)
#else
    #define DEBUGLOG(...)
#endif


bool copy_file(char *src, char *dst, bool overwrite) {
    int s_fd=-1, d_fd=-1;
    struct stat src_stat;
    struct stat dst_stat;

    if (!src){
        DEBUGLOG("Error : invalid parameter : source file path is null")
        errno = EINVAL;
        return false;
    }

    if(!dst) {
        DEBUGLOG("Error : invalid parameter : destination file path is null")
        errno = EINVAL;
        return false;
    }

    if(stat(src, &src_stat) != 0){
        int orig_error = errno;
        char *err = strerror(errno);
        DEBUGLOG(err);
        errno = orig_error;
        return false;
    }

    if(stat(dst, &dst_stat)== 0) {
        DEBUGLOG("File exists and overwrite is %d " , (int)overwrite);
        if(overwrite) {
            
        }
    }

    /*all stats are good*/
    if((s_fd = open(src, )))

}