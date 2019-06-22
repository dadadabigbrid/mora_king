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

void functionMenu()//���ܲ˵�
{

    printf("*******************************************************\n");
	printf("*\tA.��ʼ��Ϸ\n*\tB.���а�\n*\tC.����\n*\tD.�˳�\n");
	printf("*******************************************************\n");

}

void functionChoice()//����ѡ��
{
	int i=1;
	char choice;

	//printf("���������ѡ��: (����A��)");

	do{
	    system("cls");
        functionMenu();
        printf("���������ѡ��: (����A��)");
        //ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
        setbuf(stdin, NULL);
        scanf("%c",&choice);
        switch(choice)
        {
        case'A':
            //��ʼ��Ϸ
            start_game();
            //i=0;
            break;
        case'B':
            //���а�
            showRank();
            //i = 0;
            break;
        case'C':
            //����
            printf("\t���ѡȡ��λ����Ӣ�ۣ�����������ѡȡ����λӢ��\n\t��������λӢ�������ѡȡһλ��������У�������ʹ��������Ϊ0������Ӧ��������������һ\n\t�ҷ�ѡȡһλӢ�ۣ�Ӣ��������У���Ӧ������������Ҳ��һ\n\t����ҷ�ʤ���ҷ�ʤ��������1������Է�ʤ��������1\n\tһ����Ϸ�ܹ�����8�ζ�ս\n\t��Ҽ���Ѽ\n");
            system("pause");
            break;
        case'D':
            //�˳�
            i=0;
            break;
        default:
            printf("����������������룺 ������A����");
        }
	}while(i);

}

void start_game()
{
    int i;
    int result = 0;

    //���ļ��ж�ȡHero�б�
    Hero_get(Hero);

    HeroRank_get();
    PlayerRank_get();

    //��¼ʱ�Ѿ���ȡ������б�
    //PlayerRank_get();
    dispalyHeroMenu();
    heroChoice(Hero1,Hero2);

    for(i = 0;i < 9;i++)
    {
        result += Battle(Hero1,Hero2);
    }

    if(result > 0)
        printf("\n*******************************************************\n��ϲ�����ջ����ʤ��");
    else
    {
        printf("\n*******************************************************\n");
    }

    HeroRankSort();
    PlayerRankSort();

    readInHeroFile();
    readInPlayerFile();

}

void dispalyHeroMenu()//��ʾӢ�ۼ��似��
{
	int i,mark;//markΪӢ�۱��

	for(i=0;i<15;i++)
    {
        mark=i+1;
        printf("%2d.%12s\t����:%d\tʯͷ:%d\t��:%d\n",mark,Hero[i].name,Hero[i].skills[0],Hero[i].skills[1],Hero[i].skills[2]);
    }
    printf("*******************************************************\n");
}


/*�������ܣ�ѡȡӢ�ۣ������ѡȡ����λӢ�۴���һά����hero1���з�����hero2
����������һά�����׵�ַ
��������ֵ����*/
void heroChoice(HERO *hero1,HERO *hero2)
{
	int i,s1[3]={0},s2[3]={0};

    printf("������Ҫѡȡ��Ӣ�۵ı��:(��:1 2 3)");

	for(i=0;i<3;i++)
    {
        //ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
        setbuf(stdin, NULL);
        scanf("%d",&s1[i]);
        s1[i]=s1[i]-1;
        hero1[i]=Hero[s1[i]];
		while(s1[i]>15||s1[i]<0||!Repetition(s1,i,s1[i]))
        {
            printf("����������Ҫѡȡ��Ӣ�۱�ţ�");
            //ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
            setbuf(stdin, NULL);
            scanf("%d",&s1[i]);
            s1[i]=s1[i]-1;
            hero1[i]=Hero[s1[i]];
        }
        do
		{
			s2[i]=rand()%15;
			hero2[i]=Hero[s2[i]];
		}while(s2[i]>15||s2[i]<0||!Repetition(s2,i,s2[i]));//ȷ��������������ķ�Χ���ظ�����
		//�������ѡȡӢ��
    }

    system("cls");
    printf("*******************************************************\n��ѡ���Ӣ����:\n");

    for(i = 0;i < 3;i++)
    {
        printf("%2d.%12s\t����:%d\tʯͷ:%d\t��:%d\n",i+1,Hero[s1[i]].name,Hero[s1[i]].skills[0],Hero[s1[i]].skills[1],Hero[s1[i]].skills[2]);
    }
    printf("*******************************************************\n");

    printf("�з�ѡ���Ӣ����:\n");
    for(i = 0;i < 3;i++)
    {
        printf("%2d.%12s\t����:%d\tʯͷ:%d\t��:%d\n",i+1,Hero[s2[i]].name,Hero[s2[i]].skills[0],Hero[s2[i]].skills[1],Hero[s2[i]].skills[2]);
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
        printf("�ļ���ʧ��");
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
        printf("�ļ���ʧ��");
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
