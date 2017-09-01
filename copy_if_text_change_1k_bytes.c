/*4.Write a program to find the 1K blocks which are different between two files*/
#include <stdio.h>
#include <stdlib.h>

char *path1 = "/home/sameer/sameer/n.c";
char *path2 = "/home/sameer/sameer/n2.c";
 
void main(){
    int c1,c2,c3;
    FILE *in, *out, *in1, *out1;
    in = fopen(path1, "r");
    out = fopen(path2, "r");
    unsigned char block[1000];
    size_t bytCount_1, bytCount_2;
    int flag = 0;
    if(in == NULL){
        printf("Can not open %s for reading", path1);
    }else if(out == NULL){
        printf("Can not open %s for reading", path1);
    }else{
        /*c1 = getc(in);
        c2 = getc(out);*/
        /*while((c1 != EOF) && (c2 != EOF)) {*/
        while(!feof(in) && !feof(out)) {
            bytCount_1 = fread(block, 1, 1000, in);
            bytCount_2 = fread(block, 1, 1000, out);
            printf("\n%zu:bytCount_1\n",bytCount_1);
            printf("\n%zu:bytCount_2\n",bytCount_2);
            if(bytCount_1 == bytCount_2){
                printf("Files are identical\n");
            }else{
                flag = 1;
                printf("Files are not identical\n");
            }
        }
        if(flag == 1){
                printf("Files are different hence writing\n");
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
