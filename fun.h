#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED

#include"define.h"
#include<stdlib.h>
#include<time.h>

void Hero_Choice(int* choice,int* enemy_choice)
{
    int i = 0;
    HERO *h = NULL;
    h = (HERO*)malloc(sizeof(HERO)*15);
    Hero_get(h);
    for(i = 0;i < 15;i++)
    {
        printf("%d.%10s\t剪刀:%d,石头:%d,布:%d\n",i + 1,h[i].name,h[i].skills[0],h[i].skills[1],h[i].skills[2]);
    }
    scanf("%d%d%d",&choice[0],&choice[1],&choice[2]);
    if(choice[0] == choice[1] || choice[1] == choice[2] || choice[0] == choice[2])
    {
        printf("不能选择重复的英雄\n请重新选择\n");
        Hero_Choice(choice,enemy_choice);
    }
    srand(time(NULL));
    enemy_choice[0] = rand();
    enemy_choice[1] = rand();
    enemy_choice[2] = rand();
}

void ballet(int* choice,int *enemy)
{
    int i;
    HERO *h = NULL;
    h = (HERO*)malloc(sizeof(HERO)*15);
    Hero_get(h);
    for(i = 0;i < 3;i++)
    {
        printf("%d.%10s\t剪刀:%d,石头:%d,布:%d\n",i + 1,h[choice[i]].name,h[choice[i]].skills[0],h[choice[i]].skills[1],h[choice[i]].skills[2]);
    }
}

#endif // FUN_H_INCLUDED
