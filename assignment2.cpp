#include <iostream>
#include <string>
using namespace std;

// Constants for maximum students and tests
const int MAX_STUDENTS = 10;
const int MAX_TESTS = 5;

// Arrays to store student data
string names[MAX_STUDENTS];       // Student names
int scores[MAX_STUDENTS][MAX_TESTS]; // Test scores for each student
double averages[MAX_STUDENTS];    // Average scores
char grades[MAX_STUDENTS];        // Final grades
int studentCount = 0;             // Number of students added

// Function to input student names and test scores
void inputScores() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Maximum number of students reached!" << endl;
        return;
    }

    cout << "Enter student name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, names[studentCount]); // Read the student's name

    cout << "Enter number of tests (max " << MAX_TESTS << "): ";
    int numTests;
    cin >> numTests;

    // Validate number of tests
    while (numTests < 1 || numTests > MAX_TESTS) {
        cout << "Invalid number of tests! Enter between 1 and " << MAX_TESTS << ": ";
        cin >> numTests;
    }

    // Input test scores
    for (int i = 0; i < numTests; i++) {
        cout << "Enter score for test " << (i + 1) << " (0-100): ";
        cin >> scores[studentCount][i];

        // Validate score
        while (scores[studentCount][i] < 0 || scores[studentCount][i] > 100) {
            cout << "Invalid score! Enter a number between 0 and 100: ";
            cin >> scores[studentCount][i];
        }
    }

    studentCount++; // Increment student count
    cout << "Student added successfully!" << endl;
}

// Function to calculate average scores
void calculateAverages() {
    for (int i = 0; i < studentCount; i++) {
        int sum = 0;
        int numTests = MAX_TESTS;

        // Calculate sum of scores
        for (int j = 0; j < numTests; j++) {
            sum += scores[i][j];
        }

        // Calculate average
        averages[i] = static_cast<double>(sum) / numTests;
    }

    cout << "Averages calculated successfully!" << endl;
}

// Function to assign final grades
void assignGrades() {
    for (int i = 0; i < studentCount; i++) {
        if (averages[i] >= 90) {
            grades[i] = 'A';
        } else if (averages[i] >= 80) {
            grades[i] = 'B';
        } else if (averages[i] >= 70) {
            grades[i] = 'C';
        } else if (averages[i] >= 60) {
            grades[i] = 'D';
        } else {
            grades[i] = 'F';
        }
    }

    cout << "Grades assigned successfully!" << endl;
}

// Function to display results
void displayResults() {
    if (studentCount == 0) {
        cout << "No students added yet!" << endl;
        return;
    }

    cout << "\nStudent Results:\n";
    cout << "--------------------------------\n";
    cout << "Name\t\tAverage\tGrade\n";
    cout << "--------------------------------\n";

    for (int i = 0; i < studentCount; i++) {
        cout << names[i] << "\t\t" << averages[i] << "\t" << grades[i] << endl;
    }
}

// Main function with menu
int main() {
    int choice;

    do {
        // Display menu
        cout << "\n--- Class Grading System ---\n";
        cout << "1. Add Student and Input Scores\n";
        cout << "2. Calculate Averages\n";
        cout << "3. Assign Grades\n";
        cout << "4. Display Results\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle user choice
        switch (choice) {
            case 1:
                inputScores();
                break;
            case 2:
                calculateAverages();
                break;
            case 3:
                assignGrades();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}