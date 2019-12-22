#ifndef CMSYS_COURSE_H
#define CMSYS_COURSE_H
#include<string>
using namespace std;

// #ifndef起到的效果是防止一个源文件两次包含同一个头文件，而不是防止两个源文件包含同一个头文件。
//类的定义放在.h文件中，而类的实现放在cpp文件中
//课程类，存储和处理课程信息

//假如你有一个C源文件，它包含了多个头文件，比如头文件A和头文件B，而头文件B又包含了头文件A，则最终的效果是，该源文件包含了两次头文件A。
//如果你在头文件A里定义了结构体或者类类型（这是最常见的情况），那么问题来了，编译时会报大量的重复定义错误。
//例如要编写头文件test.h，在头文件开头写上两行：
//#ifndef _TEST_H
//#define _TEST_H //一般是文件名的大写
//头文件结尾写上一行：
//#endif
//这样一个工程文件里同时包含两个test.h时，就不会出现重定义的错误了。

class Course{
    
    //友元函数：读取输入创建新的课程
    friend void read(istream &inputStream, Course &course);

public:
    //无参数构造函数
    Course();
    //课程类构造函数：根据课程名称创建课程对象
    Course(const string& cName):Course() {
        name = cName;
    };

    
    //拷贝构造函数是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象。
    //通过使用另一个同类型的对象来初始化新创建的对象。复制对象把它作为参数传递给函数。复制对象，并从函数返回这个对象。
    //classname (const classname &obj) {
    // 构造函数的主体}
    
    //课程类拷贝构造函数
    Course(const Course& course);

    //打印课程信息
    virtual void PrintInfo() const;
    
    //const修饰成员函数：在成员函数后面加const，const修饰指针所指向的对象，也就是说保证调用这个const成员函数的对象在函数内不会被改变。
    
    //返回课程名称
    inline string GetName() const {return name;}; 
    
    //内联函数的作用？ 
    // -- 内联函数有些鸡肋，不是太大作用。
    // 以inline修饰的函数叫做内联函数，编译时C++编译器会调用内联函数的地方展开，没有函数压栈的开销，内联函数提升程序允许的效率。

    //设置课程名称
    inline void SetName(const string& newName){
        name = newName;
    };

    //返回课程ID
    inline const int GetId() const { return id;};

    //操作符<<重载函数, 当cout<<输出课程信息是使用
    friend ostream& operator <<(ostream& out, const Course& course);
    //友元函数：在C++中友元函数允许在类外面访问该类中的任何成员，就像成员函数一样，友元函数用关键字friend说明。 

protected:
    //课程id
    int id;
    //课程名称
    string name;
    //设置静态变量来生成唯一的ID值
    static int currentId;
};  


//课程分为基础课，项目课，评估课等三种不同的类型
//基础课为基础Course类，而项目课和评估课都继承基础课
//项目课，比基础课增加了标签
class ProjectCourse: public Course{
public:
    //设置标签
    inline void SetTag(const string& newTag){
        tag=newTag; 
    };
    //返回标签
    inline string GetTag() const { return tag; };

    //打印课程信息
    virtual void PrintInfo() const override;

private:
    string tag;
};

//评估课：比基础课增加了时间限制
class JudgeCourse: public Course{
public:
    //设置限时
    inline void SetTime(int newTime){ time=newTime;};

    //返回限时
    inline int GetTime(){return time;};
    
    //打印课程信息
    virtual void PrintInfo() const override;
private:
    int time;

};
#endif //CMSYS_COURSE_H
