
#ifndef TA_19_DOUBLEMAJORSTUDENT_H
#define TA_19_DOUBLEMAJORSTUDENT_H
#includ "Student"
#include <iostream>
#include <string>
#include <vector>
#include <map>

class DoubleMajorStudent: public Student{
private:
    std::string major2;
public:
    DoubleMajorStudent() : Person() {}
    DoubleMajorStudent(const std::string& studentId, std::string first, std::string last , double workHours,std::string major2,
                       std::vector<std::string> passedCourses, std::map<std::string, double> currentSemesterCourses, std::string major2);

};


#endif
