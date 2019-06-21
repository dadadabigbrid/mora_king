#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include"define.h"
#include"game.h"

void Start()
{
    //functionMenu();
    functionChoice();
}

void functionMenu()//功能菜单
{

    printf("*******************************************************\n");
	printf("*\tA.开始游戏\n*\tB.排行榜\n*\tC.信息查询\n*\tD.帮助\n*\tE.退出\n");
	printf("*******************************************************\n");

}

void functionChoice()//功能选择
{
	int i=1;
	char choice;

	//printf("请输入你的选择: (例：A。)");

	do{
	    system("cls");
        functionMenu();
        printf("请输入你的选择: (例：A。)");
        //使stdin输入流由默认缓冲区转为无缓冲区
        setbuf(stdin, NULL);
        scanf("%c",&choice);
        getchar();
        switch(choice)
        {
        case'A':
            //开始游戏
            start_game();
            //i=0;
            break;
        case'B':
            //排行榜
            showRank();
            //i = 0;
            break;
        case'C':
            //玩家信息查询
            break;
        case'D':
            //帮助
            break;
        case'E':
            //退出
            i=0;
            break;
        default:
            printf("输入错误，请重新输入： （例：A。）");
        }
	}while(i);

}

void start_game()
{
    int i;
    int result = 0;

    //从文件中读取Hero列表
    Hero_get(Hero);

    HeroRank_get();
    PlayerRank_get();

    //登录时已经获取了玩家列表
    //PlayerRank_get();
    dispalyHeroMenu();
    heroChoice(Hero1,Hero2);

    for(i = 0;i < 9;i++)
    {
        result += Battle(Hero1,Hero2);
    }

    if(result > 0)
        printf("\n*******************************************************\n恭喜您最终获得了胜利");
    else
    {
        printf("\n*******************************************************\n");
    }

    HeroRankSort();
    PlayerRankSort();

    readInHeroFile();
    readInPlayerFile();

}

void dispalyHeroMenu()//显示英雄及其技能
{
	int i,mark;//mark为英雄编号

	for(i=0;i<15;i++)
    {
        mark=i+1;
        printf("%2d.%12s\t剪刀:%d\t石头:%d\t布:%d\n",mark,Hero[i].name,Hero[i].skills[0],Hero[i].skills[1],Hero[i].skills[2]);
    }
    printf("*******************************************************\n");
}


/*函数功能：选取英雄，将玩家选取的三位英雄存入一维数组hero1，敌方存入hero2
函数参数：一维数组首地址
函数返回值：无*/
void heroChoice(HERO *hero1,HERO *hero2)
{
	int i,s1[3]={0},s2[3]={0};

    printf("请输入要选取的英雄的编号:(例:1 2 3)");

	for(i=0;i<3;i++)
    {
        //使stdin输入流由默认缓冲区转为无缓冲区
        setbuf(stdin, NULL);
        scanf("%d",&s1[i]);
        s1[i]=s1[i]-1;
        hero1[i]=Hero[s1[i]];
		while(s1[i]>15||s1[i]<0||!Repetition(s1,i,s1[i]))
        {
            printf("请重新输入要选取的英雄编号：");
            //使stdin输入流由默认缓冲区转为无缓冲区
            setbuf(stdin, NULL);
            scanf("%d",&s1[i]);
            s1[i]=s1[i]-1;
            hero1[i]=Hero[s1[i]];
        }
        do
		{
			s2[i]=rand()%15;
			hero2[i]=Hero[s2[i]];
		}while(s2[i]>15||s2[i]<0||!Repetition(s2,i,s2[i]));//确定产生的随机数的范围及重复条件
		//电脑随机选取英雄
    }

    system("cls");
    printf("*******************************************************\n您选择的英雄是:\n");

    for(i = 0;i < 3;i++)
    {
        printf("%2d.%12s\t剪刀:%d\t石头:%d\t布:%d\n",i+1,Hero[s1[i]].name,Hero[s1[i]].skills[0],Hero[s1[i]].skills[1],Hero[s1[i]].skills[2]);
    }
    printf("*******************************************************\n");

    printf("敌方选择的英雄是:\n");
    for(i = 0;i < 3;i++)
    {
        printf("%2d.%12s\t剪刀:%d\t石头:%d\t布:%d\n",i+1,Hero[s2[i]].name,Hero[s2[i]].skills[0],Hero[s2[i]].skills[1],Hero[s2[i]].skills[2]);
    }
}

int Repetition(int *p,int n,int last)
{
    int i;
	for(i=0;i<n;i++,p++)
	{
		if(last==*p)
			return 0;
	}
	return 1;
}

void readInPlayerFile()
{
    FILE *fp;
    char temp[10];
    int i;

    fp = fopen("playerRank.data","w");
    if(fp == NULL)
    {
        printf("文件打开失败");
        return;
    }

    itoa(player_num + 1,temp,10);
    fputs(temp,fp);
    fputs("\n",fp);
    for(i = 0;i <= player_num;i++)
    {
        itoa(PlayerRank[i].rank,temp,10);
        fputs(temp,fp);
        fputs(",",fp);

        fputs(PlayerRank[i].names,fp);
        fputs(",",fp);

        itoa(PlayerRank[i].win,temp,10);
        fputs(temp,fp);
        fputs(",",fp);

        itoa(PlayerRank[i].allRound,temp,10);
        fputs(temp,fp);

        fputs("\n",fp);
    }
    fclose(fp);
}

void readInHeroFile()
{
    FILE *fp;
    char temp[15];
    int i;

    fp = fopen("heroRank.data","w");
    if(fp == NULL)
    {
        printf("文件打开失败");
        return;
    }

    for(i = 0;i < 15;i++)
    {
        itoa(HeroRank[i].rank,temp,10);
        fputs(temp,fp);
        fputs(",",fp);

        fputs(HeroRank[i].names,fp);
        fputs(",",fp);

        itoa(HeroRank[i].win,temp,10);
        fputs(temp,fp);
        fputs(",",fp);

        itoa(HeroRank[i].allRound,temp,10);
        fputs(temp,fp);

        fputs("\n",fp);

    }

}


#endif // MENU_H_INCLUDED
