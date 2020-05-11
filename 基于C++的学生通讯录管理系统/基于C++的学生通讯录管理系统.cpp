#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
using namespace std;
struct record
{
	char name[20];   //姓名
	char phone[12];   //电话
	char adress[50];   //地址
	char postcode[8];   //邮政编码
	char e_mail[20];   //电子邮件。
	char qq[10];    //QQ号
    char wechat[30];   //微信号 
}student[100];     //假设最大数为100.
//定义全局变量num，表示已经输入的人数 。
int num;     //这里使用数组解决通讯录的问题，实际上使用链表更好。
int menu_select()
{
	 char s[80];
	 int a;/*定义整形变量*/
	 system("cls");
	 printf("\t\t\t\t\t*********欢迎进入通讯录管理界面*********\n");
	 printf("\t\t\t\t\t      |      0. 输入记录         |\n");
	 printf("\t\t\t\t\t      |      1. 显示记录         |\n");
	 printf("\t\t\t\t\t      |      2. 按姓名查找       |\n");
	 printf("\t\t\t\t\t      |      3. 按电话号码查找   |\n");
	 printf("\t\t\t\t\t      |      4. 插入记录         |\n");
	 printf("\t\t\t\t\t      |      5. 按姓名排序       |\n");
	 printf("\t\t\t\t\t      |      6. 删除记录         |\n");
	 printf("\t\t\t\t\t      |      7. 退出界面         |\n");
	 printf("\t\t\t\t\t     ******************************\n\n");
	do{
			printf("Enter you choice(0~7):");
		    scanf("%s",s);
		    a=atoi(s);
	 }
    while (a<0 || a>7);
    return a;
}
int adduser()
{
	 printf("\t\t\t\t    **************** 请输入用户信息 ****************\n");
	 printf("\t\t\t\t\t输入姓名:");
	 scanf("%s",student[num].name);
	 printf("\t\t\t\t\t输入电话号码:");
	 scanf("%s",student[num].phone);
	 printf("\t\t\t\t\t输入地址:");
	 scanf("%s",student[num].adress);
	 printf("\t\t\t\t\t输入邮编:");
	 scanf("%s",student[num].postcode);
	 printf("\t\t\t\t\t输入e-mail:");
	 scanf("%s",student[num].e_mail);
	 printf("\t\t\t\t\tQQ:");
	 scanf("%s",student[num].qq);
     printf("\t\t\t\t\t输入微信：");
	 scanf("%s",student[num].wechat);
	 num++;
	 printf("\t\t\t\t\t是否继续添加?(Y/N):\n");
	 if(getch()=='y' || getch()=='Y')
	     adduser();
	 return(0);
}
void list()
{
	 int i;
	 system("cls");
	 if(num!=0)
	 {
	  printf("\t\t\t\t     *************** 以下为通讯录所有信息************\n");
	  for (i=0;i<num;i++)
	  {
	    printf("\t\t\t\t姓名：%s",student[i].name);
		cout<<endl;
		printf("\t\t\t\t电话：%s",student[i].phone);
		cout<<endl;
		printf("\t\t\t\t地址：%s",student[i].adress);
		cout<<endl;
		printf("\t\t\t\t邮编：%s",student[i].postcode);
		cout<<endl;
		printf("\t\t\t\te-mail：%s",student[i].e_mail);
		cout<<endl;
		printf("\t\t\t\tQQ：%s",student[i].qq);
		cout<<endl;
		printf("\t\t\t\t微信：%s",student[i].wechat);
		cout<<endl;
	   if(i+1<num)
	   {
		system("pause");
	   }
	  }
	  printf("\t\t\t\t*******************************************************\n");
	 }
	 else
	  printf("\t\t\t\t\t  ********通讯录中无任何纪录********\n");
	  printf("按任意键返回主菜单：");
	  getch();    //这里是无回显的输入字符，你输入的字符不会显示在屏幕上。
	  return;
}
int searchbyname()
{
	 int mark=0;
	 int i;
	 printf("\t\t\t\t***************** 按姓名查找 *******************\n");
	 char name[20];
	 printf("\t\t\t请输入姓名:");
	 scanf("%s",name);
	 for(i=0;i<num;i++)
	 {
		  if (strcmp(student[i].name,name)==0)
		   {
			printf("\t\t\t\t************* 以下是您查找的用户信息 ***********\n");
			printf("\t\t\t\t姓名： %s",student[i].name);
			cout<<endl;
			printf("\t\t\t\t电话： %s",student[i].phone);
			cout<<endl;
			printf("\t\t\t\t地址： %s",student[i].adress);
			cout<<endl;
			printf("\t\t\t\te-mail：%s",student[i].e_mail);
			cout<<endl;
			printf("\t\t\t\t邮编：%s",student[i].postcode);
			cout<<endl;
			printf("\t\t\t\tQQ：%s",student[i].qq);
			cout<<endl;
			printf("\t\t\t\t微信：%s",student[i].wechat);
			cout<<endl;
			printf("\t\t\t\t\t\t\t\t\t************************************************\n");
			mark++;
		   if((i+1)<num)
		   {
			   printf("\t\t\t\t是否继续查找相同名字的用户信息：(y/n)\n");
			   if(getch()=='y' || getch()=='Y')
			   {
					 continue;
			   }
			   else
					 return(0);
		   }
		   else
		   {
			   printf("按任意键返回主菜单:");
			   getch();
			   return(0);
		   }
		  }
	 }
	 if(mark == 0)
	 {
		  printf("\t\t\t\t没有相同姓名的用户纪录\n");
		  printf("按任意键返回主菜单:");
		  getch();
		  return(0);
	 }
	 return 0;
}
int searchbyphone()
{
	int mark=0;
	int i;
	printf("\t\t\t\t****************** 按电话查找 ******************\n");
	char phone[10];
	printf("\t\t\t\t请输入电话号码:");
	scanf("%s",phone);
	for(i=0;i<num;i++)
	{
	 if (strcmp(student[i].phone,phone)==0)
	 {
	  printf("\t\t\t\t************** 以下是您查找的用户信息 **********\n");
	  printf("\t\t\t\t姓名： %s",student[i].name);
	  cout<<endl;
	  printf("\t\t\t\t电话： %s",student[i].phone);
	  cout<<endl;
	  printf("\t\t\t\t地址： %s",student[i].adress);
	  cout<<endl;
	  printf("\t\t\t\te-mail：%s",student[i].e_mail);
	  cout<<endl;
	  printf("\t\t\t\t邮编：%s",student[i].postcode);
	  cout<<endl; 
	  printf("\t\t\t\tQQ：%s",student[i].qq);
	  cout<<endl;
	  printf("\t\t\t\t微信：%s",student[i].wechat);
	  cout<<endl;
	  printf("\t\t\t\t************************************************\n");
	  printf("按任意键返回主菜单:");
	  mark++;
	  getch();
	  return(0);
	 }
	}
	if (mark==0)
	{
	 printf("\t\t\t\t没有改用户的信息\n");
	 printf("按任意键返回主菜单:");
	 getch();
	 return(0);
	}
	return(0);
}
void deletebyphone()
{
	int i,j;
	int deletemark=0;
	char phone[20];
	 cout<<endl;
	 printf("\t\t\t\t请输入要删除用户电话号码:");
	 scanf("%s",phone);
	 if(num==0)
	 {
	  printf("\t\t\t\t对不起，文件中无任何纪录\n");
	  printf("按任意键返回主菜单:");
	  getch();
	 return;
	 }
	 for (i=0;i<num;i++)
	 {    if (strcmp(student[i].phone,phone)==0)
		  {
			  printf("\t\t\t\t以下是您要删除的用户纪录：\n");
			  printf("\t\t\t\t姓名： %s",student[i].name);
			  cout<<endl;
			  printf("\t\t\t\t电话： %s",student[i].phone);
			  cout<<endl;
			  printf("\t\t\t\t地址： %s",student[i].adress);
			  cout<<endl;
			  printf("\t\t\t\te-mail：%s",student[i].e_mail);
			  cout<<endl;
			  printf("\t\t\t\t邮编：%s",student[i].postcode);
			  cout<<endl;
			  printf("\t\t\t\tQQ：%s",student[i].qq);
			  cout<<endl;
			  printf("\t\t\t\t微信：%s",student[i].wechat);
              cout<<endl;
			  printf("\t\t\t\t是否删除?(y/n)");
			  if (getch()=='y' || getch()=='Y')
			  {    for (j=i;j<num-1;j++)
				        student[j]=student[j+1];
                   num--;
				   deletemark++;
				   printf("\t\t\t\t删除成功\n");
				   printf("\t\t\t\t是否继续删除?(y/n)");
				   if (getch()=='y' || getch()=='Y')
				        deletebyphone();
				   return;
			  }
			  else
			  return;
		  }
		 continue;
	 }
	 if (deletemark==0)
	 {
		  printf("\t\t\t\t没有该用户的纪录\n");
		  printf("\t\t\t\t是否继续删除?(y/n)");
		  if(getch()=='y' || getch()=='Y')
		        deletebyphone();
		  return;
     }
	 return;
}
void deletebyname()
{
	int a=0;
	int findmark=0;
	int j;
	int deletemark=0;
	int i;
	char name[20];
	cout<<endl;
	printf("请输入要删除用户姓名：");
	scanf("%s",name);
	for (i=a;i<num;i++)
	{
	 if(strcmp(student[i].name,name)==0)
	 {
	  printf("\t\t\t\t以下是您要删除的用户纪录：\n");
	  findmark++;
	  printf("\t\t\t\t________________________________\n");
	  printf("\t\t\t\t姓名： %s",student[i].name);
	  cout<<endl;
	  printf("\t\t\t\t电话： %s",student[i].phone);
	  cout<<endl;
	  printf("\t\t\t\t地址： %s",student[i].adress);
	  cout<<endl;
	  printf("\t\t\t\te-mail：%s",student[i].e_mail);
	  cout<<endl;
	  printf("\t\t\t\t邮编：%s",student[i].postcode); 
	  cout<<endl; 
	  printf("\t\t\t\tQQ：%s",student[i].qq);
	  cout<<endl;
	  printf("\t\t\t\t微信：%s",student[i].wechat);
	  cout<<endl;
	  printf("\t\t\t\t________________________________\n");
	  cout<<endl;
	  printf("\t\t\t\t是否删除?(y/n)");
	  if (getch()=='y' || getch() == 'Y')
	  {
	  for(j=i;j<num-1;j++)
	   student[j]=student[j+1];
	  num--;
	  deletemark++;
	  printf("\t\t\t\t删除成功\n");
	  if((i+1)<num)
	  {
	   printf("\t\t\t\t是否继续删除相同姓名的用户信息?(y/n)");
	   if (getch()=='y')
	   {
		a=i;
	   continue;
	   }
	  }
	   printf("\t\t\t\t是否继续删除?(y/n)");
	  if (getch()=='y')
	   deletebyname();
	  return;
	  }
	  if((i+1)<num)
	  {
	   printf("\t\t\t\t是否继续删除相同姓名的用户信息?(y/n)");
	   if (getch()=='y' || getch() == 'Y')
	   {a=i;
	    continue;}
	  }
	 }
	else
	continue;
	}
	if ((deletemark==0)&&(findmark==0))
	{
	 printf("\t\t\t\t没有该用户的纪录\n");
	 printf("\t\t\t\t是否继续删除?(y/n)");
	 if(getch()=='y' || getch() == 'Y')
	   deletebyphone();
	 return;
	}
	else if (findmark!=0)
	{
	 printf("\t\t\t\t没有重名信息\n");
	 printf("\t\t\t\t没有该用户的纪录\n");
	 printf("\t\t\t\t是否继续删除?(y/n)");
	 if(getch()=='y' || getch() == 'Y')
	  deletebyphone();
	 return;
	 }
	}
int dele()
{
	char choic;
	 printf("\t\t\t\t1-按电话号码删除 2-按姓名删除\n");
	 printf("\t\t\t\t请选择：");
	 choic=getch();
	switch (choic)
	{case '1':deletebyphone();break;
	 case '2':deletebyname();break;}
	 return(0);
}
int sortbyname()   //按姓名进行排序
{
	 int i,j;
	 struct record tmp;
	 for (i=1;i<num;i++)
	 {
	 if(strcmp(student[i].name,student[i-1].name)<0)
	 {
	  tmp=student[i];
	  j=i-1;
	  do
	  {student[j+1]=student[j];
	   j--;
	  }while ((strcmp(tmp.name,student[j].name)<0&&j>=0));
	  student[j+1]=tmp;}
	 }
	 cout<<endl;
	 printf("\t\t\t\t排序成功,是否显示?(y/n)");
	 if (getch()=='y')
	  list();
	 return(0);
}
int main()
{system("color 75");
    printf("\t\t                  ***************************************************\n");
    printf("\t\t                                 \n");
    printf("\t\t                       ★★★★★★欢迎使用通讯录系统 ★★★★★★\n");
    printf("\t\t                                 \n");
    printf("\t\t                             ###########制作人###########\n");
    printf("\t\t                                 \n");
    printf("\t\t                                  罗志伟 肖丽萍 刘蝶\n");
    printf("\t\t                                 \n");
    printf("\t\t                         江西理工大学信息工程学院通信工程162班");
    printf("\t\t                                 \n");
    printf("\t\t                                 \n");
    printf("\t\t                                 \n");
    printf("\t\t                                 \n");
    printf("                                                  按任意键进入主菜单:");
getch();
int selectnum;
    while(1)
    {
    	selectnum = menu_select();
    	switch(selectnum)
    	{
case 0:
			{adduser();
			 break;}
case 1:
			{list();
             break;}
case 2:
			{searchbyname();
             break;}
case 3:
			{searchbyphone();
             break;}
case 4:
			{adduser();//这里插入，应该能指定位置，不过意义不大，所以和添加记录一样了。
             break;}
case 5:
			{sortbyname();
             break;}
case 6:
			{dele();
             break;}
case 7:
			{printf("BYE BYE!\n");
			 system("pause");
			 getchar();
             exit(0);}
    	}
    }
    getchar();
    return 0;
}
