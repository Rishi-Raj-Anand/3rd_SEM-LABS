#include <iostream>
#include <string>

using namespace std;

// Base Class: Person
class Person {
protected:
    string name;
    int age;

public:
    Person(const string& name = "", int age = 0) : name(name), age(age) {}

    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    int getAge() const { return age; }
    void setAge(int age) { this->age = age; }

    virtual void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age;
    }
};

// 1. Single Inheritance: Employee inherits from Person
class Employee : public Person {
protected:
    int employeeId;

public:
    Employee(const string& name = "", int age = 0, int employeeId = 0)
        : Person(name, age), employeeId(employeeId) {}

    int getEmployeeId() const { return employeeId; }
    void setEmployeeId(int employeeId) { this->employeeId = employeeId; }

    void displayInfo() const override {
        Person::displayInfo();
        cout << ", Employee ID: " << employeeId;
    }
};

// 2. Multilevel Inheritance: Teacher inherits from Employee
class Teacher : public Employee {
protected:
    string subject;

public:
    Teacher(const string& name = "", int age = 0, int employeeId = 0, const string& subject = "")
        : Employee(name, age, employeeId), subject(subject) {}

    string getSubject() const { return subject; }
    void setSubject(const string& subject) { this->subject = subject; }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", Subject: " << subject;
    }
};

// 3. Hierarchical Inheritance: Student also inherits from Person
class Student : public Person {
protected:
    int studentId;

public:
    Student(const string& name = "", int age = 0, int studentId = 0)
        : Person(name, age), studentId(studentId) {}

    int getStudentId() const { return studentId; }
    void setStudentId(int studentId) { this->studentId = studentId; }

    void displayInfo() const override {
        Person::displayInfo();
        cout << ", Student ID: " << studentId;
    }
};

// Class for Multiple Inheritance
class Sportsperson {
protected:
    string sport;
    int yearsOfExperience;

public:
    Sportsperson(const string& sport = "", int yearsOfExperience = 0)
        : sport(sport), yearsOfExperience(yearsOfExperience) {}

    string getSport() const { return sport; }
    void setSport(const string& sport) { this->sport = sport; }

    int getYearsOfExperience() const { return yearsOfExperience; }
    void setYearsOfExperience(int yearsOfExperience) { this->yearsOfExperience = yearsOfExperience; }

    void displayInfo() const {
        cout << ", Sport: " << sport << ", Years of Experience: " << yearsOfExperience;
    }
};

// 4. Multiple Inheritance: StudentAthlete inherits from Student and Sportsperson
class StudentAthlete : public Student, public Sportsperson {
public:
    StudentAthlete(const string& name = "", int age = 0, int studentId = 0, 
                   const string& sport = "", int yearsOfExperience = 0)
        : Student(name, age, studentId), Sportsperson(sport, yearsOfExperience) {}

    void displayInfo() const override {
        Student::displayInfo();
        Sportsperson::displayInfo();
    }
};

// 5. Hybrid Inheritance: TeachingAssistant inherits from Employee and Student
class TeachingAssistant : public Employee, public Student {
protected:
    string assignedProfessor;

public:
    TeachingAssistant(const string& name = "", int age = 0, int employeeId = 0, int studentId = 0,
                      const string& assignedProfessor = "")
        : Employee(name, age, employeeId), Student(name, age, studentId), assignedProfessor(assignedProfessor) {}

    string getAssignedProfessor() const { return assignedProfessor; }
    void setAssignedProfessor(const string& assignedProfessor) { this->assignedProfessor = assignedProfessor; }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", Assigned Professor: " << assignedProfessor;
    }
};


// Function prototypes
void displayMenu();
void createAndDisplayEmployee();
void createAndDisplayTeacher();
void createAndDisplayStudent();
void createAndDisplayStudentAthlete();
void createAndDisplayTeachingAssistant();

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAndDisplayEmployee();         // Single Inheritance
                break;
            case 2:
                createAndDisplayTeacher();          // Multilevel Inheritance
                break;
            case 3:
                createAndDisplayStudent();          // Hierarchical Inheritance
                break;
            case 4:
                createAndDisplayStudentAthlete();   // Multiple Inheritance
                break;
            case 5:
                createAndDisplayTeachingAssistant(); // Hybrid Inheritance
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    cout << "\n=== Menu ===" << endl;
    cout << "1. Create and Display Employee (Single Inheritance)" << endl;
    cout << "2. Create and Display Teacher (Multilevel Inheritance)" << endl;
    cout << "3. Create and Display Student (Hierarchical Inheritance)" << endl;
    cout << "4. Create and Display Student Athlete (Multiple Inheritance)" << endl;
    cout << "5. Create and Display Teaching Assistant (Hybrid Inheritance)" << endl;
    cout << "0. Exit" << endl;
}

void createAndDisplayEmployee() {
    string name;
    int age, employeeId;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter employee ID: ";
    cin >> employeeId;

    Employee employee(name, age, employeeId);
    cout << "Employee Details: ";
    employee.displayInfo();
    cout << endl;
}

void createAndDisplayTeacher() {
    string name, subject;
    int age, employeeId;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter employee ID: ";
    cin >> employeeId;
    cout << "Enter subject: ";
    cin >> subject;

    Teacher teacher(name, age, employeeId, subject);
    cout << "Teacher Details: ";
    teacher.displayInfo();
    cout << endl;
}

void createAndDisplayStudent() {
    string name;
    int age, studentId;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter student ID: ";
    cin >> studentId;

    Student student(name, age, studentId);
    cout << "Student Details: ";
    student.displayInfo();
    cout << endl;
}

void createAndDisplayStudentAthlete() {
    string name, sport;
    int age, studentId, yearsOfExperience;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter student ID: ";
    cin >> studentId;
    cout << "Enter sport: ";
    cin >> sport;
    cout << "Enter years of experience: ";
    cin >> yearsOfExperience;

    StudentAthlete studentAthlete(name, age, studentId, sport, yearsOfExperience);
    cout << "Student Athlete Details: ";
    studentAthlete.displayInfo();
    cout << endl;
}

void createAndDisplayTeachingAssistant() {
    string name, assignedProfessor;
    int age, employeeId, studentId;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter employee ID: ";
    cin >> employeeId;
    cout << "Enter student ID: ";
    cin >> studentId;
    cout << "Enter assigned professor: ";
    cin >> assignedProfessor;

    TeachingAssistant teachingAssistant(name, age, employeeId, studentId, assignedProfessor);
    cout << "Teaching Assistant Details: ";
    teachingAssistant.displayInfo();
    cout << endl;
}
