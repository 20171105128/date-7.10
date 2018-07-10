//
//  main.c
//  date 7.10
//
//  Created by TAO on 18/7/10.
//  Copyright © 2018年 TAO. All rights reserved.
//

/*#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}*/

#include<stdio.h>
int main()
{
    int num;//学号
    char name[10];//姓名
    char sec[5];//性别
    int bri;//出生日期
    char class1[15];//班级
    char phonenum[15];//电话号码
    char bt[100];//
    int judge[5];//五个评委
    int max;//最高分
    int min;//最低分
    int score;//5个评委分数总和
    int score1;//分数总和减去最高分与最低分
    int aver;//平均成绩
    int i;
    FILE *fp;
    FILE *fp1;
    score=0;
    
    fp=fopen("student1.csv","r");//只读，打开一个名为student.csv的文件
    if(fp==NULL)
    {
        printf("The file is empty");
        return -1;//当文件为空，输出The file is empty,退出程序，终止进程
    }
    else
    {
        fscanf(fp1,"%*[^\n]%*c");//跳过第一行
        while(!feof(fp1))//当文件不是文件尾时，执行后续代码
  
        {
            
        fscanf(fp,"%s",bt);
        fscanf(fp,"%d,",&num);
        fscanf(fp,"%[^,],",name);
        fscanf(fp,"%[^,],",sec);
        fscanf(fp,"%d,",&bri);
        fscanf(fp,"%[^,],",class1);
        fscanf(fp,"%[^,],",phonenum);
        for(i=0;i<5;i++)
            
        {
            fscanf(fp,"%d,",&judge[i]);
            
        }
        fclose(fp);
    }
    max=judge[0];
    min=judge[1];
    for(i=0;i<5;i++)
    {
        if(judge[i]>max)
            max=judge[i];
    }
    
    for(i=0;i<5;i++)
    {
        if(judge[i]<min)
            min=judge[i];
    }
    
    for(i=0;i<5;i++)
    {
        score=judge[i]+score;
    }
    
    score=score-min-max;
    aver=score/3;
    
    fp1=fopen("student2.csv","w");
    fprintf(fp1,"%s\n",bt);
    printf("%s\n",bt);
    fprintf(fp1,"%d,",num);
    printf("%d,",num);
    fprintf(fp1,"%s,",name);
    printf("%s,",name);
    fprintf(fp1,"%s,",sec);
    printf("%s,",sec);
    fprintf(fp1,"%d,",bri);
    printf("%d,",bri);
    fprintf(fp1,"%s,",class1);
    printf("%s,",class1);
    fprintf(fp1,"%s,",phonenum);
    printf("%s,",phonenum);
    
    for(i=0;i<5;i++)
    {
        fprintf(fp1,"%d,",judge[i]);
        printf("%d,",judge[i]);
    }
    
    fprintf(fp1,"%d",aver);
    printf("%d",aver);
    fprintf(fp1,"\n");
    printf("\n");
    fclose(fp1);
    return 0;
    }
}
