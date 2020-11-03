/**************************
** �ļ���:ѧ���ɼ�����ϵͳ
** ������:�����
** �� ��:2020.10.27
** �޸���:�����
** �� ��:2020.11.03
** �� ��:����ѧ���ɼ��ĳ���
** �� ��:V3.0
*************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 30

/**********************************
** ������:Readscore
** �� ��: score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub
** score[][MAX_LEN]---��¼�ɼ�������
** ID[]---��¼ID������
** name[][MAX_LEN]---��¼�����Ķ�ά����
** n---ѧ������
** sub---ѧ������
** �� ��: void
** ��������:ͨ����������ѧ����ID�������ͳɼ��������ų��޹ر��������޻��߷Ƿ��ַ���
** ȫ�ֱ���:score[][MAX_LEN], ID[], name[][], n, sub
** ����ģ��:��
** �� ��:�����
** �� ��:2020.10.27
** �� ��:�����
** �� ��:2020.11.03
** �汾��V5.0
************************************/
void Readscore(int score[][MAX_LEN], int ID[], char name[][MAX_LEN], int n, int sub)
{
    int i, j, judge1, judge2;

    for(i=0; i<n; i++)
    {
        //ͨ��ѭ��ȥ���Ƿ��ַ��ͳ�������
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
** ������:SubjectAverage
** �� ��: score[][MAX_LEN], n, sub
** score[][MAX_LEN]---��¼�ɼ�������
** n---ѧ������
** sub---ѧ������
** �� ��: void
** ��������:����ÿһ��ѧ�ƣ��ȴ�ӡ�ֵܷ�ֵ��Ȼ�����ƽ���ֲ�������λС��
** ȫ�ֱ���:score[][MAX_LEN], n, sub
** ����ģ��:��
** �� ��:�����
** �� ��:2020.10.27
** �� ��:�����
** �� ��:2020.11.03
** �汾��V2.0
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
** ������:StudentAverage
** �� ��: score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub
** score[][MAX_LEN]---��¼�ɼ�������
** ID[]---��¼ID������
** name[][MAX_LEN]---��¼�����Ķ�ά����
** n---ѧ������
** sub---ѧ������
** �� ��: void
** ��������:����ÿһ��ѧ�����ȴ�ӡ�ֵܷ�ֵ��Ȼ�����ƽ���ֲ�������λС��
** ȫ�ֱ���:score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub
** ����ģ��:��
** �� ��:�����
** �� ��:2020.10.27
** �� ��:�����
** �� ��:2020.11.03
** �汾��V2.0
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
** ������:PrintScoreAndID
** �� ��: score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub
** score[][MAX_LEN]---��¼�ɼ�������
** ID[]---��¼ID������
** name[][MAX_LEN]---��¼�����Ķ�ά����
** n---ѧ������
** sub---ѧ������
** �� ��: void
** ��������:ֱ�Ӵ�ӡѧ����ID�������ͳɼ�
** ȫ�ֱ���:score[][MAX_LEN], ID[], name[][], n, sub
** ����ģ��:��
** �� ��:�����
** �� ��:2020.10.27
** �� ��:�����
** �� ��:2020.11.03
** �汾��V3.0
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
** ������:Statistics
** �� ��: score[][MAX_LEN], n, sub
** score[][MAX_LEN]---��¼�ɼ�������
** n---ѧ������
** sub---ѧ������
** �� ��: void
** ��������:��һ�жϳɼ������ĸ��ȼ���������Ȼ��������
** ȫ�ֱ���:score[][MAX_LEN], ID[], n, sub
** ����ģ��:��
** �� ��:�����
** �� ��:2020.10.27
** �� ��:�����
** �� ��:2020.11.03
** �汾��V2.0
************************************/
void Statistics(int score[][MAX_LEN], int n, int sub)
{
    int i, j;
    float group[MAX_LEN][5] = {0};

    //����
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

    //��ӡ
    printf("In the subject%d:\n", j+1);
    printf("There is %.0f students in GradeA, making up for %.2f\n", group[j][0], (float)(group[j][0]/n));
    printf("There is %.0f students in GradeB, making up for %.2f\n", group[j][1], (float)(group[j][1]/n));
    printf("There is %.0f students in GradeC, making up for %.2f\n", group[j][2], (float)(group[j][2]/n));
    printf("There is %.0f students in GradeD, making up for %.2f\n", group[j][3], (float)(group[j][3]/n));
    printf("There is %.0f students didn't pass the exam, making up for %.2f\n", group[j][4], (float)(group[j][4]/n));
    }
}

/**********************************
** ������:PrintSort
** �� ��: score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub, (*compare)(int a,int b)
** score[][MAX_LEN]---��¼�ɼ�������
** ID[]---��¼ID������
** name[][MAX_LEN]---��¼�����Ķ�ά����
** n---ѧ������
** sub---ѧ������
** (*compare)(int a,int b)---�Ƚϵĺ���ָ��
** �� ��: void
** ��������:�ڲ��ı�ԭʼ���������£������鰴score�ܺ�������߽������У����Ҵ�ӡ����
** ȫ�ֱ���:score[][MAX_LEN], ID[], name[][], n, sub
** ����ģ��:��
** �� ��:�����
** �� ��:2020.10.27
** �� ��:�����
** �� ��:2020.11.03
** �汾��V3.0
************************************/
void PrintSort(int score[][MAX_LEN], int ID[], char name[][MAX_LEN], int n, int sub, int (*compare)(int a,int b))
{
    int i, j, k, temp, tempscore[n], newID[n], sum;
    char tempname[n][MAX_LEN], tempstr[MAX_LEN];

    //����
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

    //����
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

    //��ӡ
    for(i=0; i<n; i++)
    {
        printf("No.%d ID = %d named %s\n", i+1, newID[i], tempname[i]);
    }
}

//����ָ��
int Ascent (int a, int b)
{
    return a < b;
}

int Descent (int a, int b)
{
    return a > b;
}

/**********************************
** ������:FindScoreWithName
** �� ��: score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub
** score[][MAX_LEN]---��¼�ɼ�������
** ID[]---��¼ID������
** name[][MAX_LEN]---��¼�����Ķ�ά����
** n---ѧ������
** sub---ѧ������
** �� ��: void
** ��������:��������ѧ�������������ҵ�����Ӧ�ĳɼ���������ͬʱ�ų������ڵ�����
** ȫ�ֱ���:score[][MAX_LEN], ID[], name[][], n, sub
** ����ģ��:Descent
** �� ��:�����
** �� ��:2020.10.30
** �� ��:�����
** �� ��:2020.11.03
** �汾��V2.0
************************************/
void FindScoreWithName(int score[][MAX_LEN], int ID[],char name[][MAX_LEN], int n, int sub)
{

    int i, j, k, sum, judge = 0, tempscore1[n], newID[n], temp;
    char name1[MAX_LEN], tempname[n][MAX_LEN], tempstr[MAX_LEN];

    do
    {
        printf("please input the name:");
        i = scanf("%s",name1);

        //����
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

    //����ɼ�
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

    //����
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
** ������:FindScoreWithID
** �� ��: score[][MAX_LEN], ID[],name[][MAX_LEN], n, sub
** score[][MAX_LEN]---��¼�ɼ�������
** ID[]---��¼ID������
** name[][MAX_LEN]---��¼�����Ķ�ά����
** n---ѧ������
** sub---ѧ������
** �� ��: void
** ��������:��������ѧ����ID�����ҵ�����Ӧ���������ɼ���������ͬʱ�ų����޵�ID�ͷǷ��ַ�
** ȫ�ֱ���:score[][MAX_LEN], ID[], name[][], n, sub
** ����ģ��:Descent
** �� ��:�����
** �� ��:2020.10.27
** �� ��:�����
** �� ��:2020.11.03
** �汾��V4.0
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

    //����
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
    //�ų��Ƿ�����
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

    //����ɼ�
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

    //����
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
** ������:PrintScoreOrdered
** �� ��: score[][MAX_LEN], ID[], name[][], n, sub
** score[][MAX_LEN]---��¼�ɼ�������
** ID[]---��¼ID������
** name[][MAX_LEN]---��¼�����Ķ�ά����
** n---ѧ������
** sub---ѧ������
** �� ��: void
** ��������:�ڲ��ı�ԭʼ���������£������鰴ID�������У����Ҵ�ӡ
** ȫ�ֱ���:score[][MAX_LEN], ID[], name[][], n, sub
** ����ģ��:��
** �� ��:�����
** �� ��:2020.10.27
** �� ��:�����
** �� ��:2020.11.03
** �汾��V4.0
************************************/
void PrintScoreOrdered(int score[][MAX_LEN], int ID[], char name[][MAX_LEN], int n, int sub)
{
    int i, j, l, k, temp, tempscore[n][MAX_LEN], newID[n], tempsubsc[MAX_LEN];
    char tempname[n][MAX_LEN], tempstr[MAX_LEN];

    //����
    for(i=0; i<n; i++)
    {
        for(j=0; j<sub; j++)
        {
            tempscore[i][j] = score[i][j];
        }
        newID[i] = ID[i];
        strcpy(tempname[i],name[i]);
    }

    //����
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

    //��ӡ
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
** ������:PrintNameOrdered
** �� ��: score[][MAX_LEN], ID[], name[][MAX_LEN], n, sub
** score[][MAX_LEN]---��¼�ɼ�������
** ID[]---��¼ID������]
** name[][MAX_LEN]---��¼�����Ķ�ά����
** n---ѧ������
** sub---ѧ������
** �� ��: void
** ��������:�ڲ��ı�ԭʼ���������£������鰴�����������У����Ҵ�ӡ
** ȫ�ֱ���:score[][MAX_LEN], ID[], n, sub
** ����ģ��:��
** �� ��:�����
** �� ��:2020.10.27
** �� ��:�����FindScoreWithID
** �� ��:2020.11.03
** �汾��V2.0
************************************/
void PrintNameOrdered(int score[][MAX_LEN], int ID[], char name[][MAX_LEN], int n, int sub)
{
    int i, j, l, k, temp, tempscore[n][MAX_LEN], newID[n], tempsubsc[MAX_LEN];
    char tempname[n][MAX_LEN], tempstr[MAX_LEN];

    //����
    for(i=0; i<n; i++)
    {
        for(j=0; j<sub; j++)
        {
            tempscore[i][j] = score[i][j];
        }
        newID[i] = ID[i];
        strcpy(tempname[i],name[i]);
    }

    //����
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

    //��ӡ
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
** ������:Inputlist
** �� ��: void
** �� ��: void
** ��������:��ӡ�б�
** ȫ�ֱ���:��
** ����ģ��:��
** �� ��:�����
** �� ��:2020.10.27
** �� ��:�����
** �� ��:2020.11.03
** �汾��V3.0
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
** ������:GetDecision
** �� ��: void
** �� ��: input
** input---�û������ѡ��
** ��������:����ѡ�����ų������ַ��ͷǷ��ַ�
** ȫ�ֱ���:input
** ����ģ��:Inputlist
** �� ��:�����
** �� ��:2020.10.27
** �� ��:�����
** �� ��:2020.12.03
** �汾��V3.0
************************************/
int GetDecision()
{
    int i, input;

    //��ӡ�б�
    Inputlist();

    //ȥ���Ƿ�����
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
** ������:Usedecision
** �� ��: decision, score[][MAX_LEN], ID[],name[][MAX_LEN], n, sub, judge
** score[][MAX_LEN]---��¼�ɼ�������
** ID[]---��¼ID������
** name[][MAX_LEN]---��¼�����Ķ�ά����
** n---ѧ������
** sub---ѧ������
** judge---�ж��Ƿ�����Ѿ�����ĳɼ���ID����
** �� ��: judge
** judge---�ж��Ƿ�����Ѿ�����ĳɼ���ID����
** judgeΪ0��û�п��õ�����
** judge��Ϊ0���п��õ�����
** ��������:�ж��Ѿ������ѡ�񣬲��������ֶ�Ӧ�ĺ��������û���Ѿ����ڵ��������ʾ�û�����
** ȫ�ֱ���:decision, score[][MAX_LEN], ID[], n, judge, name[][], sub
** ����ģ��:Readscore PrintScoreAndID Average PrintSort PrintScoreOrdered FindScoreWithID Statistics
** �� ��:�����
** �� ��:2020.10.27
** �� ��:�����
** �� ��:2020.11.03
** �汾��V3.0
************************************/
int Usedecision(int decision, int score[][MAX_LEN], int ID[], char name[][MAX_LEN], int n, int sub, int judge)
{
    if(decision != 0)
    {
        if(decision == 1)
        {
            printf("\n");
            Readscore(score, ID, name, n, sub);

            //��ʾ�Ѿ���������
            judge++;
        }

        //��û�������κ����������²��ܵ���2-11
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
** ������:Check
** �� ��:ID[], n�� judge
** ID[]---��¼ID������
** n---ѧ������
** judge---�ж��Ƿ�����Ѿ�����ĳɼ���ID����
** �� ��: judge
** judge---�ж��Ƿ�����Ѿ�����ĳɼ���ID����
** ��������:�ж��ǲ�����n֮�����е�ID���ж�Ӧ��score�����ȱ�پʹ�ӡ�Ǹ�ID���ˣ�Ҫ���û��������������ɼ�
** ȫ�ֱ���:ID[], n�� judge
** ����ģ��:��
** �� ��:�����
** �� ��:2020.10.28
** �� ��:�����
** �� ��:2020.10.28
** �汾��V4.0
************************************/
int Check(int ID[], int n, int judge)
{
    int i, j, judge1, judge2=0;

    //���
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

    //�д�������
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

    //��ʾ�û�����ѧ������
    printf("input total number of students:");
    scanf("%d", &number);

    printf("input total number of subjects:");
    scanf("%d", &sub);

    int score[number][MAX_LEN], ID[number];
    char name[number][MAX_LEN];

    //ѭ��ִ��
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
