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
    int result;     //0ƽ��,1Ӯ,-1��
}Round;


int PK(int i,int j);
void showSkill(int s);
void writeInFile(Round rou,int h1,int h2,HERO *hero1,HERO *hero2);

int Battle(HERO *hero1,HERO *hero2)
{
    Round rou;
    static int flag = 1;//��¼��ǰΪ�ڼ���
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
        endwait = clock() + ms;//ms�����Ƴ���ʱ��
        printf("���� 5 ����ѡ���սӢ��:");
        while(heroing1 >= 3)//ʱ������
        {
            if(kbhit())
            {
                //ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
                setbuf(stdin, NULL);
                scanf("%d",&heroing1);
                heroing1--;
                break;
            }else if(clock() == endwait)
            {
                printf("\nʱ�䵽\n");
                heroing1 = rand()%3;
            }
            //heroing1 = rand()%3;
        }
        printf("�ҷ���սӢ����:%s",hero1[heroing1].name);
        /*scanf("%d",&heroing1);
        heroing1--;*/
        if(heroing1 >= 3 && (hero1[heroing1].skills[0] != 0 || hero1[heroing1].skills[1] != 0 || hero1[heroing1].skills[2] != 0))
        {
            printf("�������,����������\n");
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

    printf("\n�з���սӢ����:%s",hero2[heroing2].name);
    printf("\n%12s     ",hero1[heroing1].name);
    showSkill(rou.Myskill);
    printf("\n%12s     ",hero2[heroing2].name);
    showSkill(rou.Eneskill);



    rou.result = PK(rou.Myskill,rou.Eneskill);
    switch(rou.result)
    {
    case 0:
        printf("\n��ϲ��,��%d�ֻ��ʤ��",flag);
        (HeroRank[hero1[heroing1].flag].win)++;
        (PlayerRank[player].win)++;
        break;
    case 1:
        printf("\n��\n��%d������",flag);
        break;
    case 2:
        printf("\n��%d��ƽ��",flag);
        break;
    }

    (PlayerRank[player].allRound)++;
    (HeroRank[hero1[heroing1].flag].allRound)++;

    //ÿ�ֽ���֮��Ĵ���
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
        printf("����");
        break;
    case 1:
        printf("ʯͷ");
        break;
    case 2:
        printf("��");
        break;
    }
}

int PK(int i,int j)//�ж�i����Ӯ,0Ӯ,1��,2ƽ��
{
    //����0,ʯͷ1,��2
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
        printf("�ļ���ʧ��");
        return;
    }

    itoa(rou.flag - 1,temp,10);
    fputs("Round ",fp);
    fputs(temp,fp);
    fputs(":",fp);
    fputs("�ҷ���սӢ�� ",fp);
    fputs(hero1[h1].name,fp);
    fputs(",�з���սӢ�� ",fp);
    fputs(hero2[h2].name,fp);
    fputs(",�ҷ����� ",fp);

    switch(rou.Myskill)
    {
    case 0:
        fputs("����",fp);
        break;
    case 1:
        fputs("ʯͷ",fp);
        break;
    case 2:
        fputs("��",fp);
        break;
    }

    fputs(",�з����� ",fp);

    switch(rou.Eneskill)
    {
    case 0:
        fputs("����",fp);
        break;
    case 1:
        fputs("ʯͷ",fp);
        break;
    case 2:
        fputs("��",fp);
        break;
    }

    fputs("\n",fp);
}

#endif // GAME_H_INCLUDED
