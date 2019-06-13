#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include"define.h"


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
	printf("请输入你的选择: (例：A。)");
	do{
        scanf("%c",&choice);
        getchar();
        switch(choice)
        {
        case'A':
            //开始游戏
            start_game();
            i=0;
            break;
        case'B':
            //排行榜
            i=0;
            break;
        case'C':
            //玩家信息查询
            i=0;
            break;
        case'D':
            //帮助
            i=0;
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
    //从文件中读取Hero列表
    Hero_get(Hero);
    dispalyHeroMenu();
}
void dispalyHeroMenu()//显示英雄及其技能
{
	int i,mark;//mark为英雄编号
	for(i=0;i<15;i++)
    {
        mark=i+1;
        printf("%2d.%12s\t剪刀:%d\t石头:%d\t布:%d\n",mark,Hero[i].name,Hero[i].skills[1],Hero[i].skills[2],Hero[i].skills[3]);
    }
    printf("*******************************************************\n");
}


/*函数功能：选取英雄，将玩家选取的三位英雄存入一维数组hero1，敌方存入hero2
函数参数：一维数组首地址
函数返回值：无*/
void heroChoice(HERO *hero1,HERO *hero2)
{
	int i,s1[3]={0},s2[3]={0};
    printf("请输入要选取的英雄的编号：（例：1回车2回车3回车）");
	for(i=0;i<3;i++)
    {
        scanf("%d",&s1[i]);
        s1[i]=s1[i]-1;
        hero1[i]=Hero[s1[i]];
		while(s1[i]>15||s1[i]<0||!Repetition(s1,i,s1[i]))
        {
            printf("请重新输入要选取的英雄编号：");
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


#endif // MENU_H_INCLUDED
