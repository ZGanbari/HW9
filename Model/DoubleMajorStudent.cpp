
#include "DoubleMajorStudent.h"

DoubleMajorStudent::DoubleMajorStudent(const std::string &studentId, std::string first, std::string last,
                                       double workHours, std::vector<std::string> passedCourses,
                                       std::map<std::string, double> currentSemesterCourses, std::string major2)
        :Student(std::move(studentId),std::move(first),std::move(last),workHours,std::move(passedCourses),std::move(currentSemesterCourses))
{DoubleMajorStudent::major2=std::move(major2);}


double DoubleMajorStudent::calculateSalary() const {
    return getWorkHours()*6500;
}
