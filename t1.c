/*mydiff prog compare two files and print the difference between two files*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void )
{
    FILE *fp1, *fp2;

    char line1[200], line2[200];

    int file_count = 0;
    fp1=fopen("/home/sameer/sameer/tt1.c", "r");
    fp2=fopen("/home/sameer/sameer/tt2.c","r");

    while(!feof(fp1))
    {
        fgets(line1, sizeof(line1), fp1);
        fgets(line2, sizeof(line2), fp2);
        file_count++;

        if(strcmp(line1,line2)==0)
        {
            printf("Both files are equal");
        }
        else
        {
            printf("File1:%s", line1);
            printf("\n");
            printf("File2:%s", line2);
        }
    }
    fclose(fp1);
    fclose(fp2);
}
