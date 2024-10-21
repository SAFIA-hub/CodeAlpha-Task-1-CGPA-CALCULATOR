#include <iostream>
#include <string>
#include <vector>

using namespace std;
// calculating the cgpa of a student : 
// Getting the grade's values according to the given grades by the user :
float getGradeValue(const string &note) {
    if (note == "A" || note == "A+") return 4.0;
    if (note == "A-") return 3.7;
    if (note == "B+") return 3.3;
    if (note == "B") return 3.0;
    if (note == "B-") return 2.7;
    if (note == "C+") return 2.3;
    if (note == "C") return 2.0;
    if (note == "C-") return 1.7;
    if (note == "D+") return 1.3;
    if (note == "D") return 1.0;
    if (note == "D-") return 0.7;
    if (note == "F") return 0.0;
    return 0.0; // Default case for invalid grades
}
 // A function that calculates the gpa of a semester  by dividing the total of the number of courses and the total of the credits of :
float calculateSemesterGPA(int courseCount) {
    float totalPoints = 0;
    float totalCredits = 0;
    vector<string> grades(courseCount);
    vector<int> credits(courseCount);

    for (int i = 0; i < courseCount; i++) {
        cout << "Enter grade for course " << (i + 1) << ": "<< endl ;
        cin >> grades[i];
        cout << "Enter credits for course " << (i + 1) << ": " << endl;
        cin >> credits[i];

        totalPoints += getGradeValue(grades[i]) * credits[i];
        totalCredits += credits[i];
    }

    return (totalCredits > 0) ? totalPoints / totalCredits : 0.0;
}

int main() {
    int semesters;
    cout << "Please input the number of semesters: ";
    cin >> semesters;

    float cumulativeGPA = 0;

    for (int i = 0; i < semesters; i++) {
        int courses;
        cout << "Enter the number of courses for semester " << (i + 1) << ": ";
        cin >> courses;
        // summing all the grades of each semester
        cumulativeGPA += calculateSemesterGPA(courses);

    }
    // dividing the cumulative gpa by the number of the semesters to get the cgpa 
    float cgpa = cumulativeGPA / semesters;
    cout << "Your CGPA after " << semesters << " semester(s) is: " << cgpa << endl;

    return 0;
}