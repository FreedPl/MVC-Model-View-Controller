#include <iostream>
#include <string>


class Student {
private:
    std::string name;
    int rollNumber;

public:
    Student(const std::string& name, int rollNumber)
        : name(name), rollNumber(rollNumber) {}


    std::string getName() const {
        return name;
    }

    int getRollNumber() const {
        return rollNumber;
    }


    void setName(const std::string& newName) {
        name = newName;
    }

    void setRollNumber(int newRollNumber) {
        rollNumber = newRollNumber;
    }
};


class StudentView {
public:
    void printStudentDetails(const std::string& studentName, int studentRollNumber) const {
        std::cout << "Student: " << std::endl;
        std::cout << "Name: " << studentName << std::endl;
        std::cout << "Roll Number: " << studentRollNumber << std::endl;
    }
};


class StudentController {
private:
    Student& model;
    StudentView& view;

public:
    StudentController(Student& model, StudentView& view)
        : model(model), view(view) {}


    void setStudentName(const std::string& name) {
        model.setName(name);
    }

    void setStudentRollNumber(int rollNumber) {
        model.setRollNumber(rollNumber);
    }

    std::string getStudentName() const {
        return model.getName();
    }

    int getStudentRollNumber() const {
        return model.getRollNumber();
    }

    void updateView() const {
        view.printStudentDetails(model.getName(), model.getRollNumber());
    }
};

int main() {

    Student student("John Doe", 1);


    StudentView view;


    StudentController controller(student, view);


    controller.updateView();


    controller.setStudentName("Jane Doe");
    controller.setStudentRollNumber(2);


    controller.updateView();

    return 0;
}
