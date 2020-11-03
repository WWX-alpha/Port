/**************************
** 文件名:学生成绩管理系统
** 创建人:吴玮坚
** 日 期:2020.10.27
** 修改人:吴玮坚
** 日 期:2020.11.03
** 描 述:管理学生成绩的程序
** 版 本:V3.0
*************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 30

/**********************************
** 函数名:Readscore
** 输 入: score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub
** score[][MAX_LEN]---记录成绩的数组
** ID[]---记录ID的数组
** name[][MAX_LEN]---记录姓名的二维数组
** n---学生数量
** sub---学科数量
** 输 出: void
** 功能描述:通过键盘输入学生的ID，姓名和成绩，并且排除无关变量（超限或者非法字符）
** 全局变量:score[][MAX_LEN], ID[], name[][], n, sub
** 调用模块:无
** 作 者:吴玮坚
** 日 期:2020.10.27
** 修 改:吴玮坚
** 日 期:2020.11.03
** 版本：V5.0
************************************/
void Readscore(int score[][MAX_LEN], int ID[], char name[][MAX_LEN], int n, int sub)
{
    int i, j, judge1, judge2;

    for(i=0; i<n; i++)
    {
        //通过循环去除非法字符和超限数据
        while(1)
        {
            judge2 = 0;

            printf("input No.%d ID:", i+1);
            judge1 = scanf("%d", &ID[i]);
            printf("input the student's name:");
            scanf("%s", name[i]);
            fflush(stdin);
            printf("input score:");
            for(j=0; j<sub; j++)
            {
                judge2 += scanf("%d", &score[i][j]);
                if(score[i][j]<=100 && score[i][j]>=0)
                {
                    judge2++;
                }
            }


            if(judge1==1 && ID[i]<=n && ID[i]>=0 && judge2 == 2*sub)
            {
                break;
            }

            else
            {
                printf("wrong input!\nPlease input a number from 1 to %d for ID!\n", n);
                printf("Please enter the score from 1 to 100 for score!\n");
                fflush(stdin);
            }
        }
    }
}

/**********************************
** 函数名:SubjectAverage
** 输 入: score[][MAX_LEN], n, sub
** score[][MAX_LEN]---记录成绩的数组
** n---学生数量
** sub---学科数量
** 输 出: void
** 功能描述:对于每一个学科，先打印总分的值，然后计算平均分并保留两位小数
** 全局变量:score[][MAX_LEN], n, sub
** 调用模块:无
** 作 者:吴玮坚
** 日 期:2020.10.27
** 修 改:吴玮坚
** 日 期:2020.11.03
** 版本：V2.0
************************************/
void SubjectAverage(int score[][MAX_LEN], int n, int sub)
{
    float aver,sum=0;
    int i, j;
    for(j=0; j<sub; j++)
    {
        aver = 0;
        sum = 0;
        for(i=0; i<n; i++)
        {
            sum += score[i][j];
        }
        aver = (float) (sum / n);
        printf("In subject%d:\n",j+1);
        printf("Total score = %.0f\n", sum);
        printf("Average score = %.2f\n", aver);
    }

}

/**********************************
** 函数名:StudentAverage
** 输 入: score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub
** score[][MAX_LEN]---记录成绩的数组
** ID[]---记录ID的数组
** name[][MAX_LEN]---记录姓名的二维数组
** n---学生数量
** sub---学科数量
** 输 出: void
** 功能描述:对于每一个学生，先打印总分的值，然后计算平均分并保留两位小数
** 全局变量:score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub
** 调用模块:无
** 作 者:吴玮坚
** 日 期:2020.10.27
** 修 改:吴玮坚
** 日 期:2020.11.03
** 版本：V2.0
************************************/
void StudentAverage(int score[][MAX_LEN], int ID[], char name[][MAX_LEN], int n, int sub)
{
    float aver,sum=0;
    int i, j;
    for(i=0; i<n; i++)
    {
        aver = 0;
        sum = 0;
        for(j=0; j<sub; j++)
        {
            sum += score[i][j];
        }
        aver = (float) (sum / n);
        printf("For student ID = %d named %s:\n", ID[i], name[i]);
        printf("Total score = %.0f\n", sum);
        printf("Average score = %.2f\n", aver);
    }

}

/**********************************
** 函数名:PrintScoreAndID
** 输 入: score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub
** score[][MAX_LEN]---记录成绩的数组
** ID[]---记录ID的数组
** name[][MAX_LEN]---记录姓名的二维数组
** n---学生数量
** sub---学科数量
** 输 出: void
** 功能描述:直接打印学生的ID、姓名和成绩
** 全局变量:score[][MAX_LEN], ID[], name[][], n, sub
** 调用模块:无
** 作 者:吴玮坚
** 日 期:2020.10.27
** 修 改:吴玮坚
** 日 期:2020.11.03
** 版本：V3.0
************************************/
void PrintScoreAndID(int score[][MAX_LEN], int ID[], char name[][MAX_LEN], int n, int sub)
{
    int i, j;
    float aver,sum=0;

    for(i=0; i<n; i++)
    {
        sum = 0;
        aver = 0;
        printf("%d: %s  ", ID[i], name[i]);
        for(j=0; j<sub; j++)
        {
            printf("%d  ", score[i][j]);
            sum += score[i][j];
        }
        printf("\n");

        aver = (float) (sum / n);
        printf("Total score = %.0f\n", sum);
        printf("Average score = %.2f\n", aver);
    }
    printf("\n");
}

/**********************************
** 函数名:Statistics
** 输 入: score[][MAX_LEN], n, sub
** score[][MAX_LEN]---记录成绩的数组
** n---学生数量
** sub---学科数量
** 输 出: void
** 功能描述:逐一判断成绩属于哪个等级、计数，然后计算比例
** 全局变量:score[][MAX_LEN], ID[], n, sub
** 调用模块:无
** 作 者:吴玮坚
** 日 期:2020.10.27
** 修 改:吴玮坚
** 日 期:2020.11.03
** 版本：V2.0
************************************/
void Statistics(int score[][MAX_LEN], int n, int sub)
{
    int i, j;
    float group[MAX_LEN][5] = {0};

    //计数
    for(j=0; j<sub; j++)
    {
        for(i=0; i<n; i++)
        {
            if(score[i][j] >= 90)
            {
                group[j][0]++;
            }
            else if(score[i][j]<90 && score[i][j]>=80)
            {
                group[j][1]++;
            }
            else if(score[i][j]<80 && score[i][j]>=70)
            {
                group[j][2]++;
            }
            else if(score[i][j]<70 && score[i][j]>=60)
            {
                group[j][3]++;
            }
            else
            {
                group[j][4]++;
            }
        }

    //打印
    printf("In the subject%d:\n", j+1);
    printf("There is %.0f students in GradeA, making up for %.2f\n", group[j][0], (float)(group[j][0]/n));
    printf("There is %.0f students in GradeB, making up for %.2f\n", group[j][1], (float)(group[j][1]/n));
    printf("There is %.0f students in GradeC, making up for %.2f\n", group[j][2], (float)(group[j][2]/n));
    printf("There is %.0f students in GradeD, making up for %.2f\n", group[j][3], (float)(group[j][3]/n));
    printf("There is %.0f students didn't pass the exam, making up for %.2f\n", group[j][4], (float)(group[j][4]/n));
    }
}

/**********************************
** 函数名:PrintSort
** 输 入: score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub, (*compare)(int a,int b)
** score[][MAX_LEN]---记录成绩的数组
** ID[]---记录ID的数组
** name[][MAX_LEN]---记录姓名的二维数组
** n---学生数量
** sub---学科数量
** (*compare)(int a,int b)---比较的函数指针
** 输 出: void
** 功能描述:在不改变原始数组的情况下，给数组按score总和升序或者降序排列，并且打印出来
** 全局变量:score[][MAX_LEN], ID[], name[][], n, sub
** 调用模块:无
** 作 者:吴玮坚
** 日 期:2020.10.27
** 修 改:吴玮坚
** 日 期:2020.11.03
** 版本：V3.0
************************************/
void PrintSort(int score[][MAX_LEN], int ID[], char name[][MAX_LEN], int n, int sub, int (*compare)(int a,int b))
{
    int i, j, k, temp, tempscore[n], newID[n], sum;
    char tempname[n][MAX_LEN], tempstr[MAX_LEN];

    //复制
    for(i=0; i<n; i++)
    {
        sum = 0;
        for(j=0; j<sub; j++)
        {
            sum += score[i][j];
        }
        tempscore[i] = sum;
        newID[i] = ID[i];
        strcpy(tempname[i],name[i]);
    }

    //排序
    for(i=0; i<n; i++)
    {
        k = i;
        for(j=i+1; j<n; j++)
        {
            if((*compare)(tempscore[j], tempscore[k]))
            {
                k = j;
            }
        }
        if(k != i)
        {
            temp = tempscore[k];
            tempscore[k] = tempscore[i];
            tempscore[i] = temp;
            temp = newID[k];
            newID[k] = newID[i];
            newID[i] = temp;
            strcpy(tempstr, tempname[k]);
            strcpy(tempname[k], tempname[i]);
            strcpy(tempname[i], tempstr);
        }
    }

    //打印
    for(i=0; i<n; i++)
    {
        printf("No.%d ID = %d named %s\n", i+1, newID[i], tempname[i]);
    }
}

//两个指针
int Ascent (int a, int b)
{
    return a < b;
}

int Descent (int a, int b)
{
    return a > b;
}

/**********************************
** 函数名:FindScoreWithName
** 输 入: score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub
** score[][MAX_LEN]---记录成绩的数组
** ID[]---记录ID的数组
** name[][MAX_LEN]---记录姓名的二维数组
** n---学生数量
** sub---学科数量
** 输 出: void
** 功能描述:键盘输入学生的姓名，并找到他对应的成绩和排名，同时排除不存在的姓名
** 全局变量:score[][MAX_LEN], ID[], name[][], n, sub
** 调用模块:Descent
** 作 者:吴玮坚
** 日 期:2020.10.30
** 修 改:吴玮坚
** 日 期:2020.11.03
** 版本：V2.0
************************************/
void FindScoreWithName(int score[][MAX_LEN], int ID[],char name[][MAX_LEN], int n, int sub)
{

    int i, j, k, sum, judge = 0, tempscore1[n], newID[n], temp;
    char name1[MAX_LEN], tempname[n][MAX_LEN], tempstr[MAX_LEN];

    do
    {
        printf("please input the name:");
        i = scanf("%s",name1);

        //查找
        for(i=0; i<n; i++)
        {
            if(strcmp(name1, name[i]) == 0)
            {
                printf("The score of the student (ID=%d) named %s is ", ID[i], name[i]);
                for(j=0; j<sub; j++)
                {
                    printf("%d  ", score[i][j]);
                }
                printf("\n");
                judge = 1;
                break;
            }
        }
        if(judge != 1)
        {
            printf("The student named %s isn't found. Please check your input!\n", name1);
        }
    }while(judge != 1);

    //排序成绩
    for(i=0; i<n; i++)
    {
        sum = 0;
        for(j=0; j<sub; j++)
        {
            sum += score[i][j];
        }
        tempscore1[i] = sum;
        newID[i] = ID[i];
        strcpy(tempname[i],name[i]);
    }

    //排序
    for(i=0; i<n; i++)
    {
        k = i;
        for(j=i+1; j<n; j++)
        {
            if(Descent(tempscore1[j], tempscore1[k]))
            {
                k = j;
            }
        }
        if(k != i)
        {
            temp = tempscore1[k];
            tempscore1[k] = tempscore1[i];
            tempscore1[i] = temp;
            temp = newID[k];
            newID[k] = newID[i];
            newID[i] = temp;
            strcpy(tempstr, tempname[k]);
            strcpy(tempname[k], tempname[i]);
            strcpy(tempname[i], tempstr);
        }
    }
    for(i=0; i<n; i++)
    {
        if(strcmp(name1,tempname[i]) == 0)
        {
            break;
        }
    }
    printf("Rank No.%d\n", i+1);
}

/**********************************
** 函数名:FindScoreWithID
** 输 入: score[][MAX_LEN], ID[],name[][MAX_LEN], n, sub
** score[][MAX_LEN]---记录成绩的数组
** ID[]---记录ID的数组
** name[][MAX_LEN]---记录姓名的二维数组
** n---学生数量
** sub---学科数量
** 输 出: void
** 功能描述:键盘输入学生的ID，并找到他对应的姓名、成绩、排名，同时排除超限的ID和非法字符
** 全局变量:score[][MAX_LEN], ID[], name[][], n, sub
** 调用模块:Descent
** 作 者:吴玮坚
** 日 期:2020.10.27
** 修 改:吴玮坚
** 日 期:2020.11.03
** 版本：V4.0
************************************/
void FindScoreWithID(int score[][MAX_LEN], int ID[],char name[][MAX_LEN], int n, int sub)
{
    int i, j, k, l,  temp, tempscore[n][MAX_LEN], newID[n], ID1, tempsubsc[MAX_LEN], sum, tempscore1[n];
    char tempname[n][MAX_LEN], tempstr[MAX_LEN];

    for(i=0; i<n; i++)
    {
        for(j=0; j<sub; j++)
        {
            tempscore[i][j] = score[i][j];
        }
        newID[i] = ID[i];
        strcpy(tempname[i],name[i]);
    }

    //排序
    for(i=0; i<n; i++)
    {
        k = i;
        for(j=i+1; j<n; j++)
        {
            if(Ascent(newID[j], newID[k]))
            {
                k = j;
            }
        }
        if(k != i)
        {
            for(l=0; l<sub; l++)
            {
                tempsubsc[l] = tempscore[k][l];
                tempscore[k][l] = tempscore[i][l];
                tempscore[i][l] = tempsubsc[l];
            }
            temp = newID[k];
            newID[k] = newID[i];
            newID[i] = temp;
            strcpy(tempstr, tempname[k]);
            strcpy(tempname[k], tempname[i]);
            strcpy(tempname[i], tempstr);
        }
    }

    int mid, low = 0, high = n-1;
    //排除非法输入
    while(1)
    {
        printf("please input the ID:");
        i = scanf("%d",&ID1);
        if(i==1 && ID1<=n && ID1 > 0)
        {
            break;
        }
        else
        {
            printf("wrong input!\nPlease input a number from 1 to %d\n", n);
            fflush(stdin);
        }
    }

    while(1)
    {
        mid = (low + high)/2;
        if(ID1==newID[mid])
        {
            printf("The score of the student (ID=%d) named  %s is ", ID1,tempname[ID1-1]);
                for(j=0; j<sub; j++)
                {
                    printf("%d  ", tempscore[ID1-1][j]);
                }
                printf("\n");
            break;
        }
        else if(ID1>newID[mid])
        {
            low=mid+1;
        }
        else if(ID1<newID[mid])
        {
            high=mid-1;
        }
    }

    //排序成绩
    for(i=0; i<n; i++)
    {
        sum = 0;
        for(j=0; j<sub; j++)
        {
            sum += score[i][j];
        }
        tempscore1[i] = sum;
        newID[i] = ID[i];
        strcpy(tempname[i],name[i]);
    }

    //排序
    for(i=0; i<n; i++)
    {
        k = i;
        for(j=i+1; j<n; j++)
        {
            if(Descent(tempscore1[j], tempscore1[k]))
            {
                k = j;
            }
        }
        if(k != i)
        {
            temp = tempscore1[k];
            tempscore1[k] = tempscore1[i];
            tempscore1[i] = temp;
            temp = newID[k];
            newID[k] = newID[i];
            newID[i] = temp;
            strcpy(tempstr, tempname[k]);
            strcpy(tempname[k], tempname[i]);
            strcpy(tempname[i], tempstr);
        }
    }
    for(i=0; i<n; i++)
    {
        if(newID[i] == ID1)
        {
            break;
        }
    }
    printf("Rank No.%d\n", i+1);
}

/**********************************
** 函数名:PrintScoreOrdered
** 输 入: score[][MAX_LEN], ID[], name[][], n, sub
** score[][MAX_LEN]---记录成绩的数组
** ID[]---记录ID的数组
** name[][MAX_LEN]---记录姓名的二维数组
** n---学生数量
** sub---学科数量
** 输 出: void
** 功能描述:在不改变原始数组的情况下，将数组按ID升序排列，并且打印
** 全局变量:score[][MAX_LEN], ID[], name[][], n, sub
** 调用模块:无
** 作 者:吴玮坚
** 日 期:2020.10.27
** 修 改:吴玮坚
** 日 期:2020.11.03
** 版本：V4.0
************************************/
void PrintScoreOrdered(int score[][MAX_LEN], int ID[], char name[][MAX_LEN], int n, int sub)
{
    int i, j, l, k, temp, tempscore[n][MAX_LEN], newID[n], tempsubsc[MAX_LEN];
    char tempname[n][MAX_LEN], tempstr[MAX_LEN];

    //复制
    for(i=0; i<n; i++)
    {
        for(j=0; j<sub; j++)
        {
            tempscore[i][j] = score[i][j];
        }
        newID[i] = ID[i];
        strcpy(tempname[i],name[i]);
    }

    //排序
    for(i=0; i<n; i++)
    {
        k = i;
        for(j=i+1; j<n; j++)
        {
            if(Ascent(newID[j], newID[k]))
            {
                k = j;
            }
        }
        if(k != i)
        {
            for(l=0; l<sub; l++)
            {
                tempsubsc[l] = tempscore[k][l];
                tempscore[k][l] = tempscore[i][l];
                tempscore[i][l] = tempsubsc[l];
            }
            temp = newID[k];
            newID[k] = newID[i];
            newID[i] = temp;
            strcpy(tempstr, tempname[k]);
            strcpy(tempname[k], tempname[i]);
            strcpy(tempname[i], tempstr);
        }
    }

    //打印
    for(i=0; i<n; i++)
    {
        printf("No.%d ID = %d named %s score =  ", i+1, newID[i], tempname[i]);
        for(j=0; j<sub; j++)
            {
                printf("%d  ", tempscore[i][j]);
            }
        printf("\n");
    }
}

/**********************************
** 函数名:PrintNameOrdered
** 输 入: score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub
** score[][MAX_LEN]---记录成绩的数组
** ID[]---记录ID的数组]
** name[][MAX_LEN]---记录姓名的二维数组
** n---学生数量
** sub---学科数量
** 输 出: void
** 功能描述:在不改变原始数组的情况下，将数组按姓名升序排列，并且打印
** 全局变量:score[][MAX_LEN], ID[], n, sub
** 调用模块:无
** 作 者:吴玮坚
** 日 期:2020.10.27
** 修 改:吴玮坚FindScoreWithID
** 日 期:2020.11.03
** 版本：V2.0
************************************/
void PrintNameOrdered(int score[][MAX_LEN], int ID[], char name[][MAX_LEN], int n, int sub)
{
    int i, j, l, k, temp, tempscore[n][MAX_LEN], newID[n], tempsubsc[MAX_LEN];
    char tempname[n][MAX_LEN], tempstr[MAX_LEN];

    //复制
    for(i=0; i<n; i++)
    {
        for(j=0; j<sub; j++)
        {
            tempscore[i][j] = score[i][j];
        }
        newID[i] = ID[i];
        strcpy(tempname[i],name[i]);
    }

    //排序
    for(i=0; i<n; i++)
    {
        k = i;
        for(j=i+1; j<n; j++)
        {
            if(strcmp(name[j], name[k])<0)
            {
                k = j;
            }
        }
        if(k != i)
        {
            for(l=0; l<sub; l++)
            {
                tempsubsc[l] = tempscore[k][l];
                tempscore[k][l] = tempscore[i][l];
                tempscore[i][l] = tempsubsc[l];
            }
            temp = newID[k];
            newID[k] = newID[i];
            newID[i] = temp;
            strcpy(tempstr, tempname[k]);
            strcpy(tempname[k], tempname[i]);
            strcpy(tempname[i], tempstr);
        }
    }

    //打印
    for(i=0; i<n; i++)
    {
        printf("No.%d ID = %d named %s score =  ", i+1, newID[i], tempname[i]);
        for(j=0; j<sub; j++)
            {
                printf("%d  ", tempscore[i][j]);
            }
        printf("\n");
    }
}

/**********************************
** 函数名:Inputlist
** 输 入: void
** 输 出: void
** 功能描述:打印列表
** 全局变量:无
** 调用模块:无
** 作 者:吴玮坚
** 日 期:2020.10.27
** 修 改:吴玮坚
** 日 期:2020.11.03
** 版本：V3.0
************************************/
void Inputlist()
{
    printf("\n1 .Input record\n");
    printf("2 .List record\n");
    printf("3 .Calculate total and average score of every course\n");
    printf("4 .Calculate total and average score of every student\n");
    printf("5 .Sort in descending order by total score of every student\n");
    printf("6 .Sort in ascending order by total score of every student\n");
    printf("7 .Sort in ascending order by studentID\n");
    printf("8 .Sort in ascending order by name\n");
    printf("9 .Search by StudentID\n");
    printf("10 .Search by name\n");
    printf("11.Statistic analysis for every course\n");
    printf("0 .Exit\n\n");
    printf("Please enter your choice:");
}

/**********************************
** 函数名:GetDecision
** 输 入: void
** 输 出: input
** input---用户输入的选择
** 功能描述:输入选择并且排除超限字符和非法字符
** 全局变量:input
** 调用模块:Inputlist
** 作 者:吴玮坚
** 日 期:2020.10.27
** 修 改:吴玮坚
** 日 期:2020.12.03
** 版本：V3.0
************************************/
int GetDecision()
{
    int i, input;

    //打印列表
    Inputlist();

    //去除非法输入
    while(1)
    {
        i = scanf("%d",&input);
        if(i==1 && input<=11 && input>=0)
        {
            break;
        }
        else
        {
            printf("wrong input!\nPlease input a number in the list!\n");
            fflush(stdin);
        }
    }
    return input;
}

/**********************************
** 函数名:Usedecision
** 输 入: decision, score[][MAX_LEN], ID[],name[][MAX_LEN], n, sub, judge
** score[][MAX_LEN]---记录成绩的数组
** ID[]---记录ID的数组
** name[][MAX_LEN]---记录姓名的二维数组
** n---学生数量
** sub---学科数量
** judge---判断是否存在已经输入的成绩、ID数组
** 输 出: judge
** judge---判断是否存在已经输入的成绩、ID数组
** judge为0：没有可用的数组
** judge不为0：有可用的数组
** 功能描述:判断已经输入的选择，并调用数字对应的函数，如果没有已经存在的数组就提示用户输入
** 全局变量:decision, score[][MAX_LEN], ID[], n, judge, name[][], sub
** 调用模块:Readscore PrintScoreAndID Average PrintSort PrintScoreOrdered FindScoreWithID Statistics
** 作 者:吴玮坚
** 日 期:2020.10.27
** 修 改:吴玮坚
** 日 期:2020.11.03
** 版本：V3.0
************************************/
int Usedecision(int decision, int score[][MAX_LEN], int ID[], char name[][MAX_LEN], int n, int sub, int judge)
{
    if(decision != 0)
    {
        if(decision == 1)
        {
            printf("\n");
            Readscore(score, ID, name, n, sub);

            //表示已经有数组了
            judge++;
        }

        //在没有输入任何数组的情况下不能调用2-11
        else if(judge != 0)
        {
            if(decision == 2)
            {
                printf("\n");
                PrintScoreAndID(score, ID, name, n, sub);
            }
            else if(decision == 3)
            {
                printf("\n");
                SubjectAverage(score, n, sub);
            }
            else if(decision == 4)
            {
                printf("\n");
                StudentAverage(score, ID, name, n, sub);
            }
            else if(decision == 5)
            {
                printf("\n");
                PrintSort(score, ID, name, n, sub, Descent);
            }
            else if(decision == 6)
            {
                printf("\n");
                PrintSort(score, ID, name, n, sub, Ascent);
            }
            else if(decision == 7)
            {
                printf("\n");
                PrintScoreOrdered(score, ID, name, n, sub);
            }
            else if(decision == 8)
            {
                printf("\n");
                PrintNameOrdered(score, ID, name, n, sub);
            }
            else if(decision == 9)
            {
                printf("\n");
                FindScoreWithID(score, ID, name, n, sub);
            }
            else if(decision ==10)
            {
                printf("\n");
                FindScoreWithName(score, ID, name, n, sub);
            }
            else if(decision == 11)
            {
                printf("\n");
                Statistics(score, n, sub);
            }
        }
        else
        {
            printf("\nYou should input a sort of score first!\n");
        }
    }
    return judge;
}

/**********************************
** 函数名:Check
** 输 入:ID[], n， judge
** ID[]---记录ID的数组
** n---学生数量
** judge---判断是否存在已经输入的成绩、ID数组
** 输 出: judge
** judge---判断是否存在已经输入的成绩、ID数组
** 功能描述:判断是不是在n之内所有的ID都有对应的score，如果缺少就打印那个ID少了，要求用户重新输入整个成绩
** 全局变量:ID[], n， judge
** 调用模块:无
** 作 者:吴玮坚
** 日 期:2020.10.28
** 修 改:吴玮坚
** 日 期:2020.10.28
** 版本：V4.0
************************************/
int Check(int ID[], int n, int judge)
{
    int i, j, judge1, judge2=0;

    //检查
    for(i=1; i<=n; i++)
    {
        judge1 = 0;
        for(j=0; j<n; j++)
        {
            if(i == ID[j])
            {
                judge1++;
                break;
            }
        }
        if(judge1 == 0 && judge !=0)
        {
            printf("ID = %d isn't included!\n", i);
            judge2++;
        }
    }

    //有错误输入
    if(judge2 != 0 && judge !=0)
    {
        printf("Please check your list and enter the score again!\n");
        judge = 0;
    }
    return judge;
}

int main()
{
    printf("Number:200320725\nsubject No.7 project No.1\n");
    printf("\nWelcome to students' score management system V3.0!\n\n");

    int number, sub, decision, judge=0;

    //提示用户输入学生数量
    printf("input total number of students:");
    scanf("%d", &number);

    printf("input total number of subjects:");
    scanf("%d", &sub);

    int score[number][MAX_LEN], ID[number];
    char name[number][MAX_LEN];

    //循环执行
    while(1)
    {
        decision = GetDecision();
        judge = Usedecision(decision, score, ID, name, number, sub, judge);
        judge = Check(ID, number, judge);
        if(decision == 0)
        {
            break;
        }
    }

    printf("\nThanks for your usage!\n");

    return 0;
}
