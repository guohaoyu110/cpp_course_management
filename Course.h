#ifndef CMSYS_COURSE_H
#define CMSYS_COURSE_H
#include<string>
using namespace std;
//课程类，存储和处理课程信息
class Course{
public:
    //无参数构造函数
    Course();
    Course(const string& cName, )
    
    int id;//课程ID
    string name;//课程名称
    static int currentID;

}
