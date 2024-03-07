#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    char name[10];
    int score;
    int age;
}student;
int main(void)
{
    FILE *fp=fopen("in.txt","r");
    int num;
    fscanf(fp,"%d",&num);
    student*arr=(student*)malloc(sizeof(student)*num);
    char name[10];
    int i=0;
    while (EOF!=fscanf(fp,"%s %d %d",arr[i].name,&arr[i].score,&arr[i].age))
    {
        i++;
    }
    printf("기준점수 입력: ");
    int standard;
    scanf("%d",&standard);
    printf("\n%d점 이상인 학생들 명단>>\n",standard);
    for (int i=0;i<num;i++)
    {
        if (arr[i].score>=standard)
        {
            printf("이름: %s, 성적: %d, 나이: %d\n",arr[i].name,arr[i].score,arr[i].age);
        }
    }
    free(arr);
    fclose(fp);
    return 0;
}