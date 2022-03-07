// Student Management System - V1.0
// Language - C
// IDE - Xcode
// Created by Venn Jiang on 2022/3/4.

#include "head.h"

/*菜单*/
void Menu(void){
    printf("\n*********************************************************\n");
    printf("*\t\tWelcome to Student Management System V1.0\t\t*\n");
    printf("*\t\t\tUse Keyboard to Select a Function\t\t\t*\n");
    printf("*********************************************************\n");
    printf("*\t\t\t1. Enter Student Info\t\t\t\t\t\t*\n");
    printf("*\t\t\t2. Print Student Info\t\t\t\t\t\t*\n");
    printf("*\t\t\t3. Save Student Info to File\t\t\t\t*\n");
    printf("*\t\t\t4. Read Student Info from File\t\t\t\t*\n");
    printf("*\t\t\t5. Count the Number of the Students\t\t\t*\n");
    printf("*\t\t\t6. Search for Student Info\t\t\t\t\t*\n");
    printf("*\t\t\t7. Modify Student Info\t\t\t\t\t\t*\n");
    printf("*\t\t\t8. Delete Student Info\t\t\t\t\t\t*\n");
    printf("*\t\t\t0. Exit the System\t\t\t\t\t\t\t*\n");
    printf("*********************************************************\n");
}

/*录入学生信息*/
void InputStudent(void){
    stuNode *new = (stuNode*)malloc(sizeof(stuNode));       //创建新结点，并为其分配空间
    new -> next = NULL;         //指针指向下一个结点
    
    /*录入学生信息*/
    printf("input name: ");
    scanf("%s", new -> stu.name);
    printf("input gender: ");
    scanf("%s", (new -> stu.gender));
    printf("input age: ");
    scanf("%d", &(new -> stu.age));
    printf("input ID: ");
    scanf("%d", &(new -> stu.idNumber));
    printf("input score: ");
    scanf("%d", &(new -> stu.score));
    
    /*在尾部进行插入*/
    stuNode *p = head;
    if (head == NULL){
        head = new;
    } else {
        while (p -> next != NULL){
            p = p -> next;
        }
        p -> next = new;
    }

    printf("Data Entry Complete.\n\n");
}

/*输出学生信息*/
void PrintStudent(void){
    stuNode *p = head;
    if (p == NULL){
        printf("ERROR! Library is currently empty, try again after entering data.\n");
    } else {
        printf("*********************************************************\n");
        printf("*\t\tWelcome to Student Management System V1.0\t\t*\n");
        printf("*********************************************************\n");
        printf("*\tID\t*\tNAME\t*\tGENDER\t*\tAGE\t*\tSCORE\t\t*\n");
        printf("*********************************************************\n");
        
        while (p != NULL){
            printf("*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t\t\t*\n",
                   p -> stu.idNumber,
                   p -> stu.name,
                   p -> stu.gender,
                   p -> stu.age,
                   p -> stu.score);
            printf("*********************************************************\n");
            p = p -> next;
        }
    }
}

/*写入学生信息到文件*/
void SaveStudent(void){
    FILE *file;
    file = fopen(".\\stuInfo.dat", "w");
    
    if (file == NULL){
        printf("Failed to open file, try again later.\n");
        return;
    }
    
    /*写入数据*/
    stuNode *p = head;
    while (p != NULL){
        fprintf(file, "*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t\t\t*\n",
                p -> stu.idNumber,
                p -> stu.name,
                p -> stu.gender,
                p -> stu.age,
                p -> stu.score);
        p = p -> next;
    }
    fclose(file);           //关闭文件
    printf("Data saved.\n");
}

/*从文件读取学生信息*/
void ReadStudent(void){
    system("clear");
    FILE *file;
    file = fopen(".\\stuInfo.dat", "r");
    
    /*若文件为空*/
    if (file == NULL){
        printf("No data saved yet, create a save file then try again.\n");
        return;
    }
    
    stuNode *p = (stuNode*)malloc(sizeof(stuNode));
    p -> next = NULL;
    head = p;
    
    /*逐字符读取文本*/
    char a[200];
    int i = 0;
    while (fscanf(file, "%s", a) != EOF){
        //字符不为‘*‘且非空时
        if (strcmp(a, "*")){
            switch (i){
                case 0:
                    p -> stu.idNumber = atoi(a);
                    break;
                case 1:
                    strcpy(p -> stu.name, a);
                    break;
                case 2:
                    strcpy(p -> stu.gender, a);
                    break;
                case 3:
                    p -> stu.age = atoi(a);
                    break;
                case 4:
                    p -> stu.score = atoi(a);
                    break;
                default:{
                    stuNode *new = (stuNode*)malloc(sizeof(stuNode));
                    new -> next = NULL;
                    p -> next = new;
                    p = new;
                    p -> stu.idNumber = atoi(a);
                    i = 0;
                    break;
                }
            }
            i++;
        }
    }
    PrintStudent();         //输出读取的结果
}

/*统计学生人数*/
void CountStudent(void){
    int count = 0;
    
    /*遍历链表并记数*/
    stuNode *p = head;
    while (p){
        count++;
        p = p -> next;
    }
    printf("The total amount of the students is %d", count);
}

/*查找学生信息*/
void FindStudent(void){
    int num;
    printf("input student ID Number: ");
    scanf("%d", &num);
    
    /*遍历链表（按值查找结点）*/
    stuNode *p = head;
    while (p){
        if (p -> stu.idNumber == num){
            printf("*********************************************************\n");
            printf("*\t\tWelcome to Student Management System V1.0\t\t*\n");
            printf("*********************************************************\n");
            printf("*\tID\t*\tNAME\t*\tGENDER\t*\tAGE\t*\tSCORE\t\t*\n");
            printf("*********************************************************\n");
            printf("*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t\t\t*\n",
                    p -> stu.idNumber,
                    p -> stu.name,
                    p -> stu.gender,
                    p -> stu.age,
                    p -> stu.score);
            printf("*********************************************************\n");
            return;
        } else {
            p = p -> next;
        }
    }
    printf("No match found, please check your input and try again!\n");     //查找失败提示错误信息
}

/*修改学生信息*/
void ModifyStudent(void){
    int num;
    printf("input student ID Number: ");
    scanf("%d", &num);
    
    /*遍历链表（按值查找结点）*/
    stuNode *p = head;
    while (p){
        if (p -> stu.idNumber == num){
            printf("*********************************************************\n");
            printf("*\t\tWelcome to Student Management System V1.0\t\t*\n");
            printf("*********************************************************\n");
            printf("*\tID\t*\tNAME\t*\tGENDER\t*\tAGE\t*\tSCORE\t\t*\n");
            printf("*********************************************************\n");
            printf("*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t\t\t*\n",
                    p -> stu.idNumber,
                    p -> stu.name,
                    p -> stu.gender,
                    p -> stu.age,
                    p -> stu.score);
            printf("*********************************************************\n");
            
            printf("input name: ");
            scanf("%s", p -> stu.name);
            printf("input gender: ");
            scanf("%s", (p -> stu.gender));
            printf("input age: ");
            scanf("%d", &(p -> stu.age));
            printf("input ID: ");
            scanf("%d", &(p -> stu.idNumber));
            printf("input score: ");
            scanf("%d", &(p -> stu.score));
            
            printf("Student Info modify success, please save it in time.\n");
            return;
        }
        p = p -> next;
    }
    printf("No match found, please check your input and try again!\n");     //查找失败提示错误信息
}

/*删除学生信息*/
void DeleteStudent(void){
    int num;
    printf("input student ID Number: ");
    scanf("%d", &num);
    
    stuNode *q = head, *p = head -> next;
    
    /*先检查头结点是否为目标结点*/
    if (head -> stu.idNumber == num){
        printf("*********************************************************\n");
        printf("*\t\tWelcome to Student Management System V1.0\t\t*\n");
        printf("*********************************************************\n");
        printf("*\tID\t*\tNAME\t*\tGENDER\t*\tAGE\t*\tSCORE\t\t*\n");
        printf("*********************************************************\n");
        printf("*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t\t\t*\n",
                p -> stu.idNumber,
                p -> stu.name,
                p -> stu.gender,
                p -> stu.age,
                p -> stu.score);
        printf("*********************************************************\n");
        
        /*直接用头结点的后继替换头结点*/
        head = head -> next;
        printf("Student Info Delete seccuss, please save it in time.\n");
        return;
    }
    
    /*若头结点不是目标结点，则开始遍历链表（按值查找结点）*/
    while (p){
        if (p -> stu.idNumber == num){
            printf("*********************************************************\n");
            printf("*\t\tWelcome to Student Management System V1.0\t\t*\n");
            printf("*********************************************************\n");
            printf("*\tID\t*\tNAME\t*\tGENDER\t*\tAGE\t*\tSCORE\t\t*\n");
            printf("*********************************************************\n");
            printf("*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t\t\t*\n",
                    p -> stu.idNumber,
                    p -> stu.name,
                    p -> stu.gender,
                    p -> stu.age,
                    p -> stu.score);
            printf("*********************************************************\n");
            
            /*前驱结点连接到后继结点，并释放空间*/
            q -> next = p -> next;
            free(p);
            printf("Student Info Delete seccuss, please save it in time.\n");
            return;
        }
        q = p;
        p = p -> next;
    }
    
    printf("No match found, please check your input and try again!\n");     //查找失败提示错误信息
}


/*主函数*/
int main(){
    while (true){
        Menu();     //打印菜单
        char a = getchar();
        switch (a){
            case '1':
                InputStudent();
                break;
            case '2':
                PrintStudent();
                break;
            case '3':
                SaveStudent();
                break;
            case '4':
                ReadStudent();
                break;
            case '5':
                CountStudent();
                break;
            case '6':
                FindStudent();
                break;
            case '7':
                ModifyStudent();
                break;
            case '8':
                DeleteStudent();
                break;
            case '0':
                return 0;
                break;
            default:
                printf("Wrong input, no such function found, check your input and try again.\n");
                system("clear");
                break;
        }
    }
    return 0;
}
