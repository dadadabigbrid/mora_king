#include <stdio.h>
#include <stdlib.h>
#include"define.h"

#include "stdio.h"
#include "string.h"
#include "windows.h"

//�������
char reg_name[30]="",reg_pwd[10]="";
char on_name[30],on_pwd[10];

void regist();
int judge();
void dl();

int main()//����ũҩע���½ϵͳ
{
	//�������
	int id;
	while(1)
	{
		system("pause");
		system("cls");
		//�������
		printf("\n\n\t\t\t����ũҩ����ϵͳ\n\n");

		printf("\t\t\t1:ע��\n");
		printf("\t\t\t2:��¼\n");
		printf("\t\t\t0:�˳�\n\n");

		//���빦�ܱ��
		printf("\t\t��ѡ���ܱ�ţ�");
		scanf("%d",&id);

		//�ж�
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
				printf("\n\t\t������Ĺ��ܱ���������������룡\n");
		}

	}

}
//�û�ע��ϵͳ
void regist()
{
	//����
	system("pause");
	system("cls");

	printf("\n\n\t\t\t��ӭʹ������ũҩע��ϵͳ\n\n");
	while(1)
	{
		//�����û���
		printf("\t\t�������û���[���ܴ���10���ַ�]��");
		scanf("%s",reg_name);

		//�ж��û���
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
}

//�ж��Ƿ�ע��
int judge()
{
	if(strcmp(reg_name,"")==0&&strcmp(reg_pwd,"")==0)
	{
		printf("\n\n\t\t����δע�ᣬ����ע�ᣡ\n\n");
		return 0;
	}
	else
	{
		return 1;
	}
}

//�û���¼
void dl()
{
	int i;
	system("pause");
	system("cls");

	printf("\n\n\t\t\t��ӭʹ������ũҩ��¼ϵͳ\n\n");
	//���ε�¼��֤
	for(i=1;i<=3;i++)
	{
		printf("\t\t�������û���:");
		scanf("%s",on_name);
		printf("\n\t\t��������  ��:");
		scanf("%s",on_pwd);
		if(strcmp(reg_name,on_name)==0&&strcmp(reg_pwd,on_pwd)==0)
		{
			printf("\n\n\t\t��¼�ɹ�����ӭʹ������ũҩϵͳ\n\n");
			break;
		}
		else
		{
			printf("\n\n\t\t��¼ʧ�ܣ������µ�¼��������%d�λ���\n\n",3-i);
		}

	}

}
