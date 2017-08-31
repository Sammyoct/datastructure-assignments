/*2. Write a file copy program where the file should be copied only when the destination file is newer than the old file*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

static time_t getFileCreationTime(char *path) {
    struct stat attr;
    if(stat(path, &attr)==0){
        printf("Last modified time: %s", ctime(&attr.st_mtime));
        return attr.st_mtime;
    }
    return 0;
}

char *path1 = "/home/sameer/sameer/n.c";
char *path2 = "/home/sameer/sameer/n2.c";
 
void main(){
    int c;
    FILE *in, *out;
    time_t t1 = getFileCreationTime(path1);
    time_t t2 = getFileCreationTime(path2);
    double t1_sec = difftime(t1,0);
    double t2_sec = difftime(t2,0);
    if(t1 < t2){
        in = fopen(path1,"r");
        out = fopen(path2,"w");
        while((c = fgetc(in)) != EOF)
            fputc(c,out);
        printf("\nt1 is less than t2\n%g\n%g\n",t1_sec,t2_sec);
    }else{
        printf("\nboth are same\n\n%g\n%g\n",t1_sec,t2_sec);
    }
}
