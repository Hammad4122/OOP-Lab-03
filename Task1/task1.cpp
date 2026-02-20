#include <iostream>
#include <string>

class Result {
private:
    int rollNo;
    std::string name;
    int marks[3];
public:
    // Parameterized constructor
    Result(int r, std::string n, int* m);
    // Default constructor
    Result();
    // Destructor
    ~Result();
    // Input function
    void input(int r, std::string n, int* m);
    // Getter functions
    int getRollNo();
    std::string getName();
    int getMarks(int subject);
    // Calculation functions
    int total();
    float avg();
};

// ------------------------------------------------------------
//          Function Definitions Outside the Class 
// ------------------------------------------------------------

// Constructor
// Default constructor
Result::Result() : rollNo(0), name(""), marks{0, 0, 0} {}
// Parameterized constructor
Result::Result(int r, std::string n, int* m) {
    rollNo = r;
    name = n;
    for (int i = 0; i < 3; i++) {
        marks[i] = *m++;
    }
}
// Destructor
Result::~Result() {
    std::cout << "\nResult object destroyed for student "<<name << std::endl;
}

// Input function
void Result::input(int r, std::string n, int* m) {
    rollNo = r;
    name = n;
    for (int i = 0; i < 3; i++) {
        marks[i] = *m++;
    }
}
// Getter for roll number
int Result::getRollNo() {
    return rollNo;
}
// Getter for name
std::string Result::getName() {
    return name;
}
// Getter for marks of a subject
int Result::getMarks(int subject) {
    if (subject >= 0 && subject < 3)
        return marks[subject];
    return -1; // invalid index
}
// Calculate total marks
int Result::total() {
    int total = 0;
    for (int i = 0; i < 3; i++) {
        total += marks[i];
    }
    return total;
}
// Calculate average marks
float Result::avg() {
    return total() / 3.0;
}
// -------------------------------------------------------
//                      Main Function
// -------------------------------------------------------
int main() {
    int marks1[3] = {83, 89, 85};
    int marks2[3];
    std::string student_name = "";
    int student2_rollNo = 0;
    Result student1(47, "Hammad", marks1);
    Result student2;
    // Output with hardcoded values
    std::cout<<"Output with hardcoded values";
    std::cout<<"\nHardcoded Student Info: ";
    std::cout << "\nRoll No: " << student1.getRollNo();
    std::cout << "\nName: " << student1.getName();
    std::cout << "\nSubject 1 Marks: " << student1.getMarks(0);
    std::cout << "\nSubject 2 Marks: " << student1.getMarks(1);
    std::cout << "\nSubject 3 Marks: " << student1.getMarks(2);
    std::cout << "\nTotal Marks: " << student1.total();
    std::cout << "\nAverage Marks: " << student1.avg();

    // Taking Input from user 
    while (true){
        std::cout<<"\n\nEnter your roll number: ";
        std::cin>>student2_rollNo;
        if (student2_rollNo < 0){
            std::cout<<"\nInvalid Roll Number\nEnter again.";
        }
        else {
            break;
        }
    }


    std::cout<<"\nEnter your name: ";
    std::cin.ignore();
    std::getline(std::cin,student_name);
    std::cout<<"Enter subject marks...";
    for (int i = 0; i < 3; i++){
        while(true){
            std::cout<<"\nEnter subject "<<i + 1<<" marks: ";
            std::cin>>marks2[i];
            if (marks2[i] > 0 && marks2[i] < 100){
                break;
            }
            else {
                std::cout<<"\nInvalid marks. Enter marks again.";
            }
        }
    }

    student2.input(student2_rollNo,student_name,marks2);

    std::cout << "\nDefault Student Details:" << std::endl;
    std::cout << "Roll No: " << student2.getRollNo() << std::endl;
    std::cout << "Name: " << student2.getName() << std::endl;
    std::cout << "Subject 1 Marks: " << student2.getMarks(0) << std::endl;
    std::cout << "Subject 2 Marks: " << student2.getMarks(1) << std::endl;
    std::cout << "Subject 3 Marks: " << student2.getMarks(2) << std::endl;
    std::cout << "Total Marks: " << student2.total() << std::endl;
    std::cout << "Average Marks: " << student2.avg() << std::endl;
    return 0;
}
