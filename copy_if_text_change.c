/*3. Write a file copy program where you will only copy the segments which are different in the destination file*/
#include <stdio.h>
#include <stdlib.h>

char *path1 = "/home/sameer/sameer/n.c";
char *path2 = "/home/sameer/sameer/n2.c";
 
void main(){
    int c1,c2,c3;
    FILE *in, *out, *in1, *out1;
    in = fopen(path1, "r");
    out = fopen(path2, "r");
    if(in == NULL){
        printf("Can not open %s for reading", path1);
    }else if(out == NULL){
        printf("Can not open %s for reading", path1);
    }else{
        c1 = getc(in);
        c2 = getc(out);
        while((c1 != EOF) && (c2 != EOF) && (c1 == c2)) {
            c1 = getc(in);
            c2 = getc(out);
        }

        if(c1 == c2){
            printf("Files are identical\n");
        }else{
            printf("Files are not identical\n");
            in1 = fopen(path1, "r");
            out1 = fopen(path2, "w");
            while((c3 = fgetc(in1)) != EOF)
                fputc(c3,out1);

            fclose(in1);
            fclose(out1);
        }
        fclose(in);
        fclose(out);
      }
}
