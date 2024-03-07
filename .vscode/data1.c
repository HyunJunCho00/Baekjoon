#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int num;
    int min=100,average=0,max=-1;
    int count=0;
    printf("Input number: \n");
    while(fscanf(stdin,"%d\n",&num)!=EOF)
    {
        if (num<=min)
            min=num;
        if (num>=max)
            max=num;
        average+=num;
        count++;
    }
    FILE *fp=fopen("output.txt","w");
    fprintf(fp,"MIN: %d MAX: %d AVG: %d\n",min,max,average/count);
    fclose(fp);
    return 0;
}