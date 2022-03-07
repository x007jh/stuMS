
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

/*结构体定义 - 学生*/
typedef struct stu{
    char name[20];      //姓名
    int age;            //年龄
    char gender[20];         //性别
    int idNumber;       //学号
    int score;          //成绩
}Student;

/*单链表，用于存放学生信息*/
typedef struct stuNode{
    Student stu;
    struct stuNode *next;
}stuNode;

stuNode *head = NULL;       //初始化学生链表（创建头结点）


/*函数声明*/
void Menu(void);                //菜单
void InputStudent(void);        //录入学生信息
void PrintStudent(void);        //打印学生信息
void SaveStudent(void);         //保存学生信息到文件
void ReadStudent(void);         //读取学生信息
void CountStudent(void);        //统计学生人数
void FindStudent(void);         //查找学生信息
void ModifyStudent(void);       //修改学生信息
void DeleteStudent(void);       //删除学生信息
