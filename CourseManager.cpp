#include <stdexcept>
#include <iostream>

#include "CourseManager.h"

using namespace std;

//构造函数，参数为课程vector
CourseManager::CourseManager(const vector<Course> &course){
    for(auto curs = course.begin();curs!=course.end();++curs)
    {
        courseList.push_back(*curs);
    }
}
//添加课程函数（参数为课程名称）

void CourseManager::AddCourse(const string& courseName)
{
    Course course(courseName);
    courseList.push_back(course);
}

//添加课程函数（参数为课程对象）
void CourseManager::AddCourse(const Course &course)
{
    courseList.push_back(course);
}

//删除最后一个课程
void CourseManager::RemoveLast(){
    try{
        //如果课程非空，则删除最后一门课程
        if (!courseList.empty())
        {
            courseList.pop_back();
            cout<<"Deleted successfully!"<<endl;
        }
        else{
            //课程为空，则抛异常，该异常将被catch捕捉
            throw runtime_error("Deleted error, there is no course");
        }
    }
    catch(runtime_error err)
    {
        cout<<err.what()<<endl;
    }
}