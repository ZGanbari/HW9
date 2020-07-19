#include "LeafMenu.h"

using namespace std;

LeafMenu::LeafMenu(std::string name, Menu* parent)
    : Menu{move(name), parent} {}

void LeafMenu:: showSubMenus() const {}

void LeafMenu::run() {
    setCurrentMenu(parent);

    if(name == "Show This Semester Courses"){

    }

    else if(name == "Take Course"){

    }

    else if(name == "Drop Course"){

    }

    else if(name == "Show Student Courses In Current Semester"){

    }

    else if(name == "Calculate Student Salary"){

    }

    else if(name == "Show Professor Courses In Current Semester"){

    }

    else if(name == "Submit Grade"){

    }

    else if(name == "Calculate Professor Salary"){

    }

    else if(name == "Add Professor"){

    }

    else if(name == "Show Professors"){

    }

    else if(name == "Add Student"){
        string ID;
        cout << "Enter student number: ";
        cin >> ID;
        string first;
        cout << "Enter First Name: ";
        cin >> first;
        string last;
        cout << "Enter Last Name: ";
        cin >> last;
        controller.addStudent(ID, first, last);
    }

    else if(name == "Show Students"){
showStudents();
    }

    else if(name == "Add Course"){
       string courseName;
       string profLast;
       string semester;
       vector<std::string> pre;
       int a;
        cout<<"Enter Course Name:";
        cin>>courseName;
        cout << "Enter Last Name Of Professor: ";
        cin>>profLast;
        cout<<"Enter Semester: ";
        cin>>semester;
        cout<<"Enter Num Of preCourses: ";
        cin>> a;
        for (int i = 0; i <a ; ++i) {
            cout<<"Enter Name Of preCourses: ";
            string name;
            cin>>name;
            pre.push_back(name);
        }
        controller.addCourse(courseName,profLast,semester,pre);
    }

    else if(name == "Show All Courses"){

    }

    else{
        throw invalid_argument("This Menu hase not been defined!!");
    }
}
void LeafMenu:: showStudents(){
    for(const auto& stu : controller.students){
        cout << stu.toString() << endl;
    }
}
