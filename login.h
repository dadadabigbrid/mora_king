#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include"define.h"
#include<stdlib.h>
#include<string.h>

/**
  *调用login()函数即可
  返回值0登录失败，1登录成功
*/

void regist();
int judge();
int dl();
int check(char* reg_pwd);
int login();
void add_account(char**str,char *n);

int login()
{
    //定义变量
	int id;
	//int j = 0;
	int j = 0;
	//int choice[3];
	//int enemy_choice[3];
	while(j == 0)
	{
		system("cls");
		//输出界面
		printf("\n\n\t\t\t王者农药管理系统\n\n");

		printf("\t\t\t1:注册\n");
		printf("\t\t\t2:登录\n");
		printf("\t\t\t0:退出\n\n");

		//输入功能编号
		printf("\t\t请选择功能编号：");
		setbuf(stdin, NULL);
		scanf("%d",&id);

		//判断
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
				printf("\n\t\t您输入的功能编号有误，请重新输入！\n");
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
//用户注册系统
void regist()
{
    FILE *fp = fopen("account.data","r");
    int n;
    int i;
    char **str;
    char temp[5];

    if(fp == NULL)
    {
        printf("打开文件失败！\n");
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
	//清屏
	system("pause");
	system("cls");

	printf("\n\n\t\t\t欢迎使用王者农药注册系统\n\n");
	while(1)
	{
		//输入用户名
		printf("\t\t请输入用户名[不能大于10个字符]：");
		scanf("%s",reg_name);

		if(check(reg_name))
		{
		    printf("\n\t\t该用户名已被注册，请重新输入\n\n");
		    continue;
		}


		//判断用户名
		//TODO:判断是否有特殊字符
		if(strlen(reg_name)<=10)
		{
			while(1)
			{
				//输入密码
				printf("\n\t\t请输入密码[密码长度为八位]：");
				scanf("%s",reg_pwd);

				//判断密码
				if(strlen(reg_pwd)==8)
				{
                    printf("\n\n\t\t注册成功，您的用户名是%s,密码是%s\n\n",reg_name,reg_pwd);
                    strcat(reg_name,"#");
                    strcat(reg_name,reg_pwd);
                    str[i] = reg_name;
                    add_account(str,temp);
                    system("pause");
                    break;
				}
				else
				{
					printf("\n\t\t密码的长度为%d，请重新输入\n",strlen(reg_pwd));
				}
			}
			break;
		}
		else
		{
			printf("\n\t\t用户名的长度为%d，请重新输入\n\n",strlen(reg_name));
		}
	}
	fclose(fp);
}

//判断是否注册
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
            printf("\n\n\t\t您尚未注册，请先注册！\n\n");
            return 0;
        }
        else
        {
            return 1;
        }
    }
    fclose(fp);

}

//用户登录
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
        printf("打开文件失败！");
        return 0;
    }
	system("pause");
	system("cls");

	printf("\n\n\t\t\t欢迎使用王者农药登录系统\n\n");
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
	//三次登录验证
	for(i=1;i<=3;i++)
	{
		printf("\t\t请输入用户名:");
		scanf("%s",on_name);
		printf("\n\t\t请输入密  码:");
		scanf("%s",on_pwd);
		for(j = 0;j < n;j++)
        {
            if(strcmp(names[j],on_name) == 0 && strcmp(password[j],on_pwd) == 0)
            {
                printf("\n\n\t\t登录成功，欢迎使用王者农药系统\n\n");
                strcpy(account,on_name);
                strcat(account,".data");
                system("pause");
                return 1;
            }
        }
        printf("\n\n\t\t登录失败，请重新登录，您还有%d次机会\n\n",3-i);

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
        printf("打开文件失败！");
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
        //printf("用户名%s\n",names[i]);
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
        printf("打开文件失败\n");
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
