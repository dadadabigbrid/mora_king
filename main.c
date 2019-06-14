#include <stdio.h>
#include <stdlib.h>
#include"define.h"
#include"fun.h"
#include"login.h"
#include"menu.h"
#include<string.h>
#include<windows.h>

<<<<<<< HEAD

int main()//����ũҩע���½ϵͳ
{
    /*int flag;
	flag = login();
	if(flag == 0)
        exit(0);*/
    functionMenu();
    functionChoice();//����ѡ��



=======
#include "stdio.h"
#include "string.h"
#include "windows.h"

//定义变量
char reg_name[30]="",reg_pwd[10]="";
char on_name[30],on_pwd[10];

void regist();
int judge();
void dl();

int main()//王者农药注册登陆系统
{
	//定义变量
	int id;
	while(1)
	{
		system("pause");
		system("cls");
		//输出界面
		printf("\n\n\t\t\t王者农药管理系统\n\n");

		printf("\t\t\t1:注册\n");
		printf("\t\t\t2:登录\n");
		printf("\t\t\t0:退出\n\n");

		//输入功能编号
		printf("\t\t请选择功能编号：");
		scanf("%d",&id);

		//判断
		switch(id)
		{
			case 1:regist();break;
			case 2:
				if(judge()==1)
				{
					dl();
				}
				break;
			case 0:exit(1);break;
			default:
				printf("\n\t\t您输入的功能编号有误，请重新输入！\n");
		}

	}

}
//用户注册系统
void regist()
{
	//清屏
	system("pause");
	system("cls");

	printf("\n\n\t\t\t欢迎使用王者农药注册系统\n\n");
	while(1)
	{
		//输入用户名
		printf("\t\t请输入用户名[不能大于10个字符]：");
		scanf("%s",reg_name);

		//判断用户名
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
}

//判断是否注册
int judge()
{
	if(strcmp(reg_name,"")==0&&strcmp(reg_pwd,"")==0)
	{
		printf("\n\n\t\t您尚未注册，请先注册！\n\n");
		return 0;
	}
	else
	{
		return 1;
	}
}

//用户登录
void dl()
{
	int i;
	system("pause");
	system("cls");

	printf("\n\n\t\t\t欢迎使用王者农药登录系统\n\n");
	//三次登录验证
	for(i=1;i<=3;i++)
	{
		printf("\t\t请输入用户名:");
		scanf("%s",on_name);
		printf("\n\t\t请输入密  码:");
		scanf("%s",on_pwd);
		if(strcmp(reg_name,on_name)==0&&strcmp(reg_pwd,on_pwd)==0)
		{
			printf("\n\n\t\t登录成功，欢迎使用王者农药系统\n\n");
			break;
		}
		else
		{
			printf("\n\n\t\t登录失败，请重新登录，您还有%d次机会\n\n",3-i);
		}

	}
>>>>>>> 03ab79548d0f17c2c8f79f494f856366172d406f

}
