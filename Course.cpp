#include<iostream>
#include "Course.h"
using namespace std;

//Course类成员函数

//初始化静态成员，默认第一个课程ID为1
int Course::currentId = 1;

//课程类的构造函数

Course::Course(){
    //将currentId当前值赋值给id，再将currentID自增
    id=currentId++;

    //默认课程名称为空字符串
    name="";
}
// protected:
//     //课程id
//     int id;
//     //课程名称
//     string name;
//     //设置静态变量来生成唯一的ID值
//     static int currentId;
// };  

//课程类拷贝构造函数
Course::Course(const Course& course){
    id = course.GetId();
    name=course.GetName();
}

//打印课程信息
void Course::PrintInfo() const{
    cout<<"Course"<<id<<" : "<<name<<endl;
}

//友元函数：读取输入创建新的课程
void read(istream &is, Course &item){
    is>>item.name;
}

//友元函数：操作符<<重载函数，当cout<<输出课程信息时使用
ostream &operator<<(ostream &os, const Course& course)
{
    os<<"Course: "<<course.id<<" : "<<course.name;
    return os;
}

//ProjectCourse 类成员函数
//打印课程信息
void ProjectCourse::PrintInfo()const{
    cout<<"ProjectCourse: "<<id<<" : "<<name <<" : "<<tag<<endl;
}

//JudgeCourse类成员函数
void JudgeCourse::PrintInfo() const{
    cout<<"JudgeCourse: "<< id<<" : "<< name<<" : "<<time<<endl;
}