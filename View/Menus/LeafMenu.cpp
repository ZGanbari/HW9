#include "LeafMenu.h"

using namespace std;

LeafMenu::LeafMenu(std::string name, Menu *parent)
        : Menu{move(name), parent} {}

void LeafMenu::showSubMenus() const {}

void LeafMenu::run() {
    setCurrentMenu(parent);

    if (name == "Show This Semester Courses") {
        for (const auto &crs : controller.courses) {
            if (crs.semester == controller.currentSemester)
                cout << crs << endl;
        }
    } else if (name == "Take Course") {
        string id;
        cout << "Enter Student ID:";
        cin >> id;

        cout << "Enter Course Name:";
        string name;
        cin >> name;
        controller.takeCourse(id, name);
    } else if (name == "Drop Course") {
        string id;
        cout << "Enter Student ID:";
        cin >> id;

        cout << "Enter Course Name:";
        string name;
        cin >> name;
        controller.dropCourse(id, name);
    } else if (name == "Show Student Courses In Current Semester") {
        string id;
        cout << "Enter Student ID:";
        cin >> id;

        for (map<string, double>::const_iterator it = controller.findStudent(id).currentSemesterCourses.begin();
             it != controller.findStudent(id).currentSemesterCourses.end(); it++) {
            cout << it->first << endl;
        }

    } else if (name == "Calculate Student Salary") {
        string id;
        cout << "Enter Student ID:";
        cin >> id;
        cout << "Salary Of Student " << id << " = " << controller.findStudent(id).calculateSalary() << endl;

    } else if (name == "Show Professor Courses In Current Semester") {
        string lastName;
        cout << "Enter Professor Last Name:";
        cin >> lastName;

        for (const auto &crs:controller.courses) {
            if (crs.profLastName == lastName && crs.semester == controller.currentSemester)
                cout << crs.courseName << endl;
        }

    } else if (name == "Submit Grade") {

        cout << "Enter Course Name:";
        string name;
        cin >> name;
        string id;
        cout << "Enter Student ID:";
        cin >> id;
        double grade;
        cout << "Enter grade: ";
        cin >> grade;
        controller.findStudent(id).currentSemesterCourses.find(name)->second = grade;

    } else if (name == "Calculate Professor Salary") {
        string id;
        cout << "Enter Professor ID:";
        cin >> id;
        cout << "Salary Of Professor " << id << " = " << controller.findProf(id).calculateSalary() << endl;

    } else if (name == "Add Professor") {
        string ID;
        cout << "Enter professor id: ";
        cin >> ID;
        string first;
        cout << "Enter First Name: ";
        cin >> first;
        string last;
        cout << "Enter Last Name: ";
        cin >> last;
        string title;
        cout << "Enter Title: ";
        cin >> title;
        controller.addProfessor(ID, first, last, title);
    } else if (name == "Show Professors") {
        showProf();
    } else if (name == "Add Student") {
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
    } else if (name == "Show Students") {
        showStudents();
    } else if (name == "Add Course") {
        string courseName;
        string profLast;
        string semester;
        vector<std::string> pre;
        int a;
        cout << "Enter Course Name:";
        cin >> courseName;
        cout << "Enter Last Name Of Professor: ";
        cin >> profLast;
        cout << "Enter Semester: ";
        cin >> semester;
        cout << "Enter Num Of preCourses: ";
        cin >> a;
        for (int i = 0; i < a; ++i) {
            cout << "Enter Name Of preCourses: ";
            string name;
            cin >> name;
            pre.push_back(name);
        }
        controller.addCourse(courseName, profLast, semester, pre);
    } else if (name == "Show All Courses") {
        showCourse();
    } else {
        throw invalid_argument("This Menu hase not been defined!!");
    }
}

void LeafMenu::showStudents() {
    for (const auto &stu : controller.students) {
        cout << stu.toString() << endl;
    }
}

void LeafMenu::showProf() {
    for (const auto &pro : controller.professors) {
        cout << pro.toString() << endl;
    }
}

void LeafMenu::showCourse() {
    for (const auto &crs : controller.courses) {
        cout << crs.courseName << endl;
    }
}

