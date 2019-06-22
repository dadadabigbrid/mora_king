#ifndef RANK_H_INCLUDED
#define RANK_H_INCLUDED

#include"define.h"

void HeroRank_get();
void PlayerRank_get();
void display_heroRank();
void display_playerRank();

void showRank()
{
    char choice;
    int i = 1;

	while(i)
    {
        system("cls");
        printf("*\tA.查看玩家排行榜\n*\tB.查看英雄胜率榜\n*\tC.退出\n");
        //使stdin输入流由默认缓冲区转为无缓冲区
        setbuf(stdin, NULL);
        scanf("%c",&choice);
        switch(choice)
        {
        case'A':
            PlayerRank_get();
            PlayerRankSort();
            display_playerRank();
            system("pause");
            break;
        case'B':
            HeroRank_get();
            HeroRankSort();
            display_heroRank();
            system("pause");
            break;
        case'C':
            i = 0;
            break;
        default:
            printf("输入错误，请重新输入： （例：A。）\n");
            system("pause");
        }
	}

}

void HeroRank_get()
{
    FILE *fp;
    int i,j,k;
    char str[100];
    char ch;
    char temp[15];

    fp = fopen("heroRank.data","r");
    if(fp == NULL)
    {
        printf("FILE OPEN FAILEd!");
        return;
    }

    for(i = 0;i < 15;i++)
    {
        fgets(str,50,fp);
        ch = str[0];
        j = k = 0;
        while(ch != ',')
        {
            ch = temp[k++] = str[j];
            j++;
        }
        temp[--k] = '\0';
        HeroRank[i].rank = atoi(temp);
        ch = temp[j];
        k = 0;
        while(ch != ',')
        {
            ch = temp[k++] = str[j];
            j++;
        }
        temp[--k] = '\0';
        strcpy(HeroRank[i].names,temp);
        ch = temp[j];
        k = 0;
        while(ch != ',')
        {
            ch = temp[k++] = str[j];
            j++;
        }
        temp[--k] = '\0';
        HeroRank[i].win = atoi(temp);
        ch = temp[j];
        k = 0;
        while(ch != '\n')
        {
            ch = temp[k++] = str[j];
            j++;
        }
        temp[--k] = '\0';
        HeroRank[i].allRound = atoi(temp);
    }
    fclose(fp);

}

void PlayerRank_get()
{
    FILE *fp;
    int i,j,k;
    char str[100];
    char ch;
    char temp[15];
    int n;

    fp = fopen("playerRank.data","r");
    if(fp == NULL)
    {
        printf("FILE OPEN FAILEd!");
        return;
    }

    fgets(temp,5,fp);
    n = atoi(temp);
    player_num = n;
    PlayerRank = (Rank*)malloc(sizeof(Rank)*n);

    for(i = 0;i < n;i++)
    {
        fgets(str,100,fp);
        j = k = 0;
        ch = str[0];
        while(ch != ',')
        {
            ch = temp[k++] = str[j];
            j++;
        }
        temp[--k] = '\0';
        PlayerRank[i].rank = atoi(temp);

        ch = temp[j];
        k = 0;
        while(ch != ',')
        {
            ch = temp[k++] = str[j];
            j++;
        }
        temp[--k] = '\0';
        strcpy(PlayerRank[i].names,temp);

        ch = temp[j];
        k = 0;
        while(ch != ',')
        {
            ch = temp[k++] = str[j];
            j++;
        }
        temp[--k] = '\0';
        PlayerRank[i].win = atoi(temp);

        ch = temp[j];
        k = 0;
        while(ch != '\n')
        {
            ch = temp[k++] = str[j];
            j++;
        }
        temp[--k] = '\0';
        PlayerRank[i].allRound = atoi(temp);
    }
    fclose(fp);

    for(i = 0;i < n;i++)
    {
        if(strcmp(account,PlayerRank[i].names) == 0)
        {
            player = i;
            break;
        }

    }
}

void display_heroRank()
{
    int i;
    double sl[15];

    for(i = 0;i < 15;i++)
    {
        sl[i] = (double)HeroRank[i].win / HeroRank[i].allRound;
    }

    printf("*************************************************************************************\n");
    for(i = 0;i < 15;i++)
    {
        printf("排名%d:%10s\t胜场%5d\t总场数%5d\t胜率%5.2lf\n",i+1,HeroRank[i].names,HeroRank[i].win,HeroRank[i].allRound,sl[i]);
    }
}

void display_playerRank()
{
    FILE *fp = fopen("playerRank.data","r");
    int n;
    int i;
    char temp[10];
    double *sl;

    if(fp == NULL)
    {
        printf("FILE OPEN FAILEd!");
        return;
    }

    fgets(temp,10,fp);
    n = atoi(temp);
    sl = (double *)malloc(sizeof(double)*n);

    for(i = 0;i < n;i++)
    {
        sl[i] = (double)PlayerRank[i].win / PlayerRank[i].allRound;
    }

    printf("*************************************************************************************\n");
    for(i = 0;i < n;i++)
    {
        printf("排名%d:%10s\t胜场%5d\t总场数%5d\t胜率%5.2lf\n",i+1,PlayerRank[i].names,PlayerRank[i].win,PlayerRank[i].allRound,sl[i]);
    }
    fclose(fp);
    free(sl);
}

void HeroRankSort()
{
    RankSort(HeroRank,15);
}

void PlayerRankSort()
{
    /*FILE *fp;
    int n;
    char temp[10];

    fp = fopen("playerRank.data","r");
    if(fp == NULL)
    {
        printf("FILE OPEN FAILEd!");
        return;
    }

    fgets(temp,10,fp);

    n = atoi(temp);*/

    RankSort(PlayerRank,player_num);

   // fclose(fp);
}

void RankSort(Rank *r,int n)
{
    double *sl;
    int i,j;
    Rank rt;
    int it;
    sl = malloc(sizeof(double)*n);
    for(i = 0;i < 15;i++)
    {
        sl[i] = (double)r[i].win / r[i].allRound;
    }
    for(i = 0;i < n - 1;i++)
    {
        for(j = i + 1;j < n;j++)
        {
            if(sl[i] < sl[j])
            {
                rt = r[i];
                r[i] = r[j];
                r[j] = rt;
            }
        }
    }
    free(sl);
}

#endif // RANK_H_INCLUDED
