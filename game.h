#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include<time.h>
#include<conio.h>
#include"define.h"
#include<string.h>

typedef struct _round
{
    int flag;
    int Myskill;
    int Eneskill;
    int result;     //0平局,1赢,-1输
}Round;


int PK(int i,int j);
void showSkill(int s);
void writeInFile(Round rou,int h1,int h2,HERO *hero1,HERO *hero2);

int Battle(HERO *hero1,HERO *hero2)
{
    Round rou;
    static int flag = 1;//记录当前为第几局
    int heroing1 = 3;
    int heroing2;
    clock_t endwait;
    int ms = 5000;

    rou.Myskill = 3;

    printf("\n*******************************************************");
    printf("\nRound %d:\n",flag);

    srand(time(NULL));

    do
    {
        endwait = clock() + ms;//ms是限制出招时间
        printf("请在 5 秒内选择出战英雄:");
        while(heroing1 >= 3)//时间限制
        {
            if(kbhit())
            {
                //使stdin输入流由默认缓冲区转为无缓冲区
                setbuf(stdin, NULL);
                scanf("%d",&heroing1);
                heroing1--;
                break;
            }else if(clock() == endwait)
            {
                printf("\n时间到\n");
                heroing1 = rand()%3;
            }
            //heroing1 = rand()%3;
        }
        printf("我方出战英雄是:%s",hero1[heroing1].name);
        /*scanf("%d",&heroing1);
        heroing1--;*/
        if(heroing1 >= 3 && (hero1[heroing1].skills[0] != 0 || hero1[heroing1].skills[1] != 0 || hero1[heroing1].skills[2] != 0))
        {
            printf("输入错误,请重新输入\n");
        }
    }while(heroing1 > 2);



    do
    {
        rou.Myskill = rand() % 3;
    }while(hero1[heroing1].skills[rou.Myskill] == 0);
    do
    {
        rou.Eneskill = rand() % 3;
        heroing2 = rand() % 3;
    }while(hero2[heroing2].skills[rou.Eneskill] == 0);

    printf("\n敌方出战英雄是:%s",hero2[heroing2].name);
    printf("\n%12s     ",hero1[heroing1].name);
    showSkill(rou.Myskill);
    printf("\n%12s     ",hero2[heroing2].name);
    showSkill(rou.Eneskill);



    rou.result = PK(rou.Myskill,rou.Eneskill);
    switch(rou.result)
    {
    case 0:
        printf("\n恭喜你,第%d局获得胜利",flag);
        (HeroRank[hero1[heroing1].flag].win)++;
        (PlayerRank[player].win)++;
        break;
    case 1:
        printf("\n菜\n第%d局输了",flag);
        break;
    case 2:
        printf("\n第%d局平局",flag);
        break;
    }

    (PlayerRank[player].allRound)++;
    (HeroRank[hero1[heroing1].flag].allRound)++;

    //每局结束之后的处理
    flag++;
    hero1[heroing1].skills[rou.Myskill]--;
    hero2[heroing2].skills[rou.Eneskill]--;
    rou.flag = flag;
    writeInFile(rou,heroing1,heroing2,hero1,hero2);

    return rou.result;
}

void showSkill(int s)
{
    switch(s)
    {
    case 0:
        printf("剪刀");
        break;
    case 1:
        printf("石头");
        break;
    case 2:
        printf("布");
        break;
    }
}

int PK(int i,int j)//判断i的输赢,0赢,1输,2平局
{
    //剪刀0,石头1,布2
    if(i == 0)
    {
        switch(j)
        {
            case 0:
                return 0;
            case 1:
                return -1;
            case 2:
                return 1;
        }
    }else if(i == 1)
    {
        switch(j)
        {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return -1;
        }
    }else if(i == 2)
    {
        switch(j)
        {
        case 0:
            return -1;
        case 1:
            return 1;
        case 2:
            return 0;
        }
    }
}

void writeInFile(Round rou,int h1,int h2,HERO *hero1,HERO *hero2)
{
    FILE *fp;
    char temp[3];

    //strcat(account,".data");
    fp = fopen(account,"a");
    if(fp == NULL)
    {
        fp = fopen(account,"w");
    }

    if(fp == NULL)
    {
        printf("文件打开失败");
        return;
    }

    itoa(rou.flag - 1,temp,10);
    fputs("Round ",fp);
    fputs(temp,fp);
    fputs(":",fp);
    fputs("我方出战英雄 ",fp);
    fputs(hero1[h1].name,fp);
    fputs(",敌方出战英雄 ",fp);
    fputs(hero2[h2].name,fp);
    fputs(",我方出招 ",fp);

    switch(rou.Myskill)
    {
    case 0:
        fputs("剪刀",fp);
        break;
    case 1:
        fputs("石头",fp);
        break;
    case 2:
        fputs("布",fp);
        break;
    }

    fputs(",敌方出招 ",fp);

    switch(rou.Eneskill)
    {
    case 0:
        fputs("剪刀",fp);
        break;
    case 1:
        fputs("石头",fp);
        break;
    case 2:
        fputs("布",fp);
        break;
    }

    fputs("\n",fp);
}

#endif // GAME_H_INCLUDED
