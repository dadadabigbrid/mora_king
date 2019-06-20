#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include"define.h"
#include<stdlib.h>
#include<string.h>

/**
  *����login()��������
  ����ֵ0��¼ʧ�ܣ�1��¼�ɹ�
*/

void regist();
int judge();
int dl();
int check(char* reg_pwd);
int login();
void add_account(char**str,char *n);

int login()
{
    //�������
	int id;
	//int j = 0;
	int j = 0;
	//int choice[3];
	//int enemy_choice[3];
	while(j == 0)
	{
		system("cls");
		//�������
		printf("\n\n\t\t\t����ũҩ����ϵͳ\n\n");

		printf("\t\t\t1:ע��\n");
		printf("\t\t\t2:��¼\n");
		printf("\t\t\t0:�˳�\n\n");

		//���빦�ܱ��
		printf("\t\t��ѡ���ܱ�ţ�");
		setbuf(stdin, NULL);
		scanf("%d",&id);

		//�ж�
		switch(id)
		{
			case 1:
			    regist();
			    break;
			case 2:
				if(judge()==1)
					j = dl();
				break;
			case 0:
			    exit(1);
			    break;
			default:
				printf("\n\t\t������Ĺ��ܱ���������������룡\n");
				system("pause");
				continue;
		}

	}

	system("cls");
	if(j == 0)
    {
        printf("Login Failed!\n");
        return 0;
    }
    printf("Login Sucess!\n");
    return 1;
    //Hero_Choice(choice,enemy_choice);
}
//�û�ע��ϵͳ
void regist()
{
    FILE *fp = fopen("account.data","r");
    int n;
    int i;
    char **str;
    char temp[5];

    if(fp == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
        return;
    }
    fgets(temp,20,fp);
    n = atoi(temp);
    str = (char**)malloc(sizeof(char*)*(n+1));
    for(i = 0;i < n + 1;i++)
    {
        str[i] = (char*)malloc(sizeof(char)*20);
        if(i < n)
            fgets(str[i],20,fp);
    }
    i--;
    fclose(fp);
	//����
	system("pause");
	system("cls");

	printf("\n\n\t\t\t��ӭʹ������ũҩע��ϵͳ\n\n");
	while(1)
	{
		//�����û���
		printf("\t\t�������û���[���ܴ���10���ַ�]��");
		scanf("%s",reg_name);

		if(check(reg_name))
		{
		    printf("\n\t\t���û����ѱ�ע�ᣬ����������\n\n");
		    continue;
		}


		//�ж��û���
		//TODO:�ж��Ƿ��������ַ�
		if(strlen(reg_name)<=10)
		{
			while(1)
			{
				//��������
				printf("\n\t\t����������[���볤��Ϊ��λ]��");
				scanf("%s",reg_pwd);

				//�ж�����
				if(strlen(reg_pwd)==8)
				{
                    printf("\n\n\t\tע��ɹ��������û�����%s,������%s\n\n",reg_name,reg_pwd);
                    strcat(reg_name,"#");
                    strcat(reg_name,reg_pwd);
                    str[i] = reg_name;
                    add_account(str,temp);
                    system("pause");
                    break;
				}
				else
				{
					printf("\n\t\t����ĳ���Ϊ%d������������\n",strlen(reg_pwd));
				}
			}
			break;
		}
		else
		{
			printf("\n\t\t�û����ĳ���Ϊ%d������������\n\n",strlen(reg_name));
		}
	}
	fclose(fp);
}

//�ж��Ƿ�ע��
int judge()
{
    FILE *fp = fopen("account.data","r");
    int n;
    int i,j,k;
    char ch;
    char temp[20];
    char **names;
    fgets(temp,10,fp);

    n = atoi(temp);
    names = (char**)malloc(sizeof(char*)*n);
    for(i = 0;i < n;i++)
    {
        j = k = 0;
        names[i] = (char*)malloc(sizeof(char)*20);
        fgets(temp,20,fp);
        ch = temp[0];
        while(ch != '#')
        {
            ch = temp[j++];
            names[i][j] = ch;
        }
        names[i][j] = '\0';
        if(strcmp(names[0],"\0")==0)
        {
            printf("\n\n\t\t����δע�ᣬ����ע�ᣡ\n\n");
            return 0;
        }
        else
        {
            return 1;
        }
    }
    fclose(fp);

}

//�û���¼
int dl()
{
	FILE *fp = fopen("account.data","r+");
    int n;
    int i,j,k;
    char ch;
    char temp[20];
    char **names,**password;
    if(fp == NULL)
    {
        printf("���ļ�ʧ�ܣ�");
        return 0;
    }
	system("pause");
	system("cls");

	printf("\n\n\t\t\t��ӭʹ������ũҩ��¼ϵͳ\n\n");
    fgets(temp,10,fp);

    n = atoi(temp);
    names = (char**)malloc(sizeof(char*)*n);
    password = (char**)malloc(sizeof(char*)*n);
    for(i = 0;i < n;i++)
    {
        j = k = 0;
        names[i] = (char*)malloc(sizeof(char)*20);
        password[i] = (char*)malloc(sizeof(char)*20);
        fgets(temp,20,fp);
        ch = temp[0];
        while(ch != '#')
        {
            ch = temp[j];
            names[i][j++] = ch;
        }
        names[i][j-1] = '\0';
        while(ch != '\n')
        {
            ch = temp[j + k];
            password[i][k++] = ch;
        }
        password[i][k-1] = '\0';
    }
    fclose(fp);
	//���ε�¼��֤
	for(i=1;i<=3;i++)
	{
		printf("\t\t�������û���:");
		scanf("%s",on_name);
		printf("\n\t\t��������  ��:");
		scanf("%s",on_pwd);
		for(j = 0;j < n;j++)
        {
            if(strcmp(names[j],on_name) == 0 && strcmp(password[j],on_pwd) == 0)
            {
                printf("\n\n\t\t��¼�ɹ�����ӭʹ������ũҩϵͳ\n\n");
                strcpy(account,on_name);
                strcat(account,".data");
                system("pause");
                return 1;
            }
        }
        printf("\n\n\t\t��¼ʧ�ܣ������µ�¼��������%d�λ���\n\n",3-i);

	}
	return 0;

}

int check(char *reg_name)
{
    FILE *fp = fopen("account.data","r");
    int n;
    int i,j = 0;
    char ch;
    char temp[20];
    char **names;
    if(fp == NULL)
    {
        printf("���ļ�ʧ�ܣ�");
        return;
    }
    fgets(temp,10,fp);

    n = atoi(temp);
    names = (char**)malloc(sizeof(char*)*n);
    for(i = 0;i < n;i++)
    {
        names[i] = (char*)malloc(sizeof(char)*20);
        fgets(temp,20,fp);
        ch = temp[0];
        j = 0;
        while(ch != '#')
        {
            ch = temp[j];
            names[i][j++] = ch;
        }
        j--;
        names[i][j] = '\0';
        //printf("�û���%s\n",names[i]);
    }
    for(i = 0;i < n;i++)
    {
        if(strcmp(reg_name,names[i]) == 0)
            return 1;
    }
    fclose(fp);
    return 0;
}

void add_account(char** str,char* n)
{
    int num = atoi(n) + 1;
    int i;
    FILE *fp = fopen("account.data","w");
    if(fp == NULL)
    {
        printf("���ļ�ʧ��\n");
        return;
    }
    n = itoa(num,n,10);
    fputs(n,fp);
    fputs("\n",fp);
    for(i = 0;i < num;i ++)
    {
        fputs(str[i],fp);
        if(i == num - 2)
            fputs("\n",fp);
    }
    fclose(fp);

}

#endif // LOGIN_H_INCLUDED
