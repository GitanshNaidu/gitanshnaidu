#include <stdio.h>
#include <stdlib.h>
typedef struct student{
    int rollno;
    char name[20];
    struct subject{
        int subjectcode;
        char subjectname[20];
        int marks;
        }sub [3];
        int total;
        float percentage;
}student;
void create()
{

    student *s;
    FILE *fp;
    int n,i,j;
    printf("Number of students : ");
    scanf("%d",&n);

    s = (student*)calloc(n, sizeof(student));
    fp = fopen("students.txt","w");

    for(i=0;i<n;i++)
    {
        s[i].total=0;
        s[i].percentage=0;
        printf("Enter Roll Number : ");
        scanf("%d",&s[i]);
        fflush(stdin);
        printf("Enter First Name : ");
        scanf("%s",s[i].name);
        for(j=0;j<3;j++)
        {
            printf("Enter Marks For Subject %d : ",j+1);
            scanf("%d",&s[i].sub[j].marks);
            s[i].total += s[i].sub[j].marks;
        }
        s[i].percentage = s[i].total / 3.0;
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
}
void display(){
    int j;
    student s1;
    FILE *fp;
    fp = fopen("students.txt","r");
    while(fread(&s1,sizeof(student),1,fp))
    {
        printf("\n%-5d%-20s",s1.rollno,s1.name);
        for(j=0;j<3;j++)
        {
            printf("%4d",s1.sub[j].marks);
        }
        printf("%5d-%7.2f",s1.total,s1.percentage);
    }
    fclose(fp);
}
void add()
{
    student *s;
    FILE *fp;
    int n,i,j;
    printf("Number of students : ");
    scanf("%d",&n);

    s = (student*)calloc(n, sizeof(student));
    fp = fopen("students.txt","a ");

    for(i=0;i<n;i++)
    {
        s[i].total=0;
        s[i].percentage=0;
        printf("Enter Roll Number : ");
        scanf("%d",&s[i]);
        fflush(stdin);
        printf("Enter First Name : ");
        scanf("%s",s[i].name);
        for(j=0;j<3;j++)
        {
            printf("\nEnter Marks For Subject %d : ",j+1);
            scanf("%d",&s[i].sub[j].marks);
            s[i].total += s[i].sub[j].marks;
        }
        s[i].percentage = s[i].total / 3.0;
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
}
void search()
{
    int j , rollno;
    student s1;
    FILE *fp;
    fp = fopen("students.txt","r");
    printf("Enter Roll Number to Search : ");
    scanf("%d",&rollno);
    while(fread(&s1,sizeof(student),1,fp))
    {
        if(s1.rollno == rollno)
        {
            printf("\n%-5d%-20s",s1.rollno,s1.name);
            for(j=0;j<3;j++)
            {
            printf("%4d",s1.sub[j].marks);
            }
            printf("%5d-%7.2f",s1.total,s1.percentage);
        }
    }
    fclose(fp);
}
int main()
{
    int choice;
    do{
        printf("\n1.CREATE");
        printf("\n2.DISPLAY");
        printf("\n3.ADD");
        printf("\n4.SEARCH");
        printf("\n0.EXIT");

        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            add();
            break;

        case 4:
            search();
            break;
        }
    }
    while(choice!=0);


    return 0;
}
