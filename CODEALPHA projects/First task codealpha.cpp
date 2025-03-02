//CGPA CALCULATOR PROGRAM 

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    float totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < n; i++) {
        string name;
        int credits;
        float grade;

        cout << "Enter Your course name, credits, and grade: ";
        cin >> name >> credits >> grade;

        totalGradePoints += (grade * credits);
        totalCredits += credits;
    }

    float CGPA = totalCredits == 0 ? 0 : totalGradePoints / totalCredits;
    cout << "YOUR CGPA IS : " << CGPA << endl;

    return 0;
}
