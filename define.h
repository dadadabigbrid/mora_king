#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

//enum STATUS{win,lose,ping};

typedef struct hero
{
    char name[15];
    int skills[3];
}HERO;

HERO Hero[15];

/**
    HERO *h;
    h = (HERO*)malloc(sizeof(HERO)*15);
    Hero_get(h);
    ��HERO.data�����ݶ���洢������h����
 */

void Hero_get(HERO* hero)
{
    HERO h;
    int i,j,k;
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

        ch = names[0];
        k = 0;
        while(ch != '\0')
        {
            ch = names[k];
            h.name[k] = names[k];
            k++;
        }
        h.name[k] = '\0';
        h.skills[0] = s1;   h.skills[1] = s2;   h.skills[2] = s3;
        hero[i] = h;
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
                return 2;
            case 1:
                return 1;
            case 2:
                return 0;
        }
    }else if(i == 1)
    {
        switch(j)
        {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 1;
        }
    }else if(i == 2)
    {
        switch(j)
        {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 2;
        }
    }
}


#endif // DEFINE_H_INCLUDED
