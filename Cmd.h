#ifndef CMSYS_CMD_H
#define CMSYS_CMD_H

// 类的定义放在.h文件中，而类的实现放在cpp文件中
// ifndef is if not defined，是宏定义的一种；

//#ifndef x //先测试x是否被宏定义过
//#define x
//程序段1 //如果x没有被宏定义过，定义x，并编译程序段 1
//#else
//程序段2 //如果x已经定义过了则编译程序段2的语句，“忽视”程序段 1
//#endif//终止if


//支持的命令

enum CourseCmd
{
    //打印命令帮助信息
    Cmd_PrintHelp=0,
    //打印课程信息
    Cmd_PrintCourse = 1,
    //打印课程数量
    Cmd_PrintCourseNum = 2,
    //打印最长的课程名称
    Cmd_PrintLongName = 3,
    //删除最后一个课程
    Cmd_RemoveLastCourse = 4,
    //退出程序
    Cmd_Exit = 5, 
};

#endif //CMSYS_CMD_H