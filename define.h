#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

//enum STATUS{win,lose,ping};

#include<stdio.h>
#include<string.h>

typedef struct hero
{
    int flag;
    char name[15];
    int skills[3];
}HERO;

/**
可用于展示玩家排名和英雄排名
*/
typedef struct _hero_rank
{
    int rank;
    char names[15];
    int win;
    int allRound;
}Rank;

Rank HeroRank[15];
Rank *PlayerRank = NULL;
int player;   //当前玩家
int player_num;//玩家列表中玩家的个数

char account[20];


HERO Hero[15];
//我的英雄和敌方英雄
HERO Hero1[3];
HERO Hero2[3];

char reg_name[30]="",reg_pwd[10]="";
char on_name[30],on_pwd[10];

void regist();
int judge();
int dl();

/**
    HERO *h;
    h = (HERO*)malloc(sizeof(HERO)*15);
    Hero_get(h);
    将HERO.data的数据读入存储到数组h里面
*/

void Hero_get(HERO* hero)
{
    HERO h;
    int i,j;
    char names[15];
    char str[50];
    int s1,s2,s3;
    char ch;

    FILE *fp;
    fp = fopen("HERO.data","r");
    if(fp == NULL)
    {
        printf("FILE OPEN FAILEd!");
        return;
    }

    for(i = 0;i < 15;i++)
    {
        fgets(str,50,fp);
        ch = str[0];
        j = 0;
        while(ch  != '#')
        {
            ch = names[j] = str[j];
            j++;
        }
        names[--j] = '\0';
        j++;
        ch = str[j++];
        s1 = (int)(ch - 48);
        j++;
        ch = str[j++];
        s2 = (int)(ch - 48);
        j++;
        ch = str[j++];
        s3 = (int)(ch - 48);

        strcpy(h.name,names);

        h.skills[0] = s1;   h.skills[1] = s2;   h.skills[2] = s3;
        h.flag = i+1;
        hero[i] = h;

    }

    fclose(fp);
}

#endif // DEFINE_H_INCLUDED
