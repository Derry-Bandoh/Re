#include <iostream>
#include <string>
using namespace std;

// Constants for maximum students and tests
const int MAX_STUDENTS = 10;
const int MAX_TESTS = 5;

// Arrays to store data
string studentNames[MAX_STUDENTS];
int testScores[MAX_STUDENTS][MAX_TESTS] = {0};
double averageScores[MAX_STUDENTS] = {0};
char finalGrades[MAX_STUDENTS] = {' '};

// Function prototypes
void addStudent();
void inputScores();
void calculateAverages();
void assignGrades();
void displayResults();
void showMenu();

int main() {
    int choice;
    bool exitProgram = false;

    // Main menu loop
    while (!exitProgram) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                inputScores();
                break;
            case 3:
                calculateAverages();
                break;
            case 4:
                assignGrades();
                break;
            case 5:
                displayResults();
                break;
            case 6:
                exitProgram = true;
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void showMenu() {
    cout << "\n=== Class Grading System Menu ===" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Input Test Scores" << endl;
    cout << "3. Calculate Averages" << endl;
    cout << "4. Assign Grades" << endl;
    cout << "5. Display Results" << endl;
    cout << "6. Exit" << endl;
}

void addStudent() {
    static int studentCount = 0;

    if (studentCount >= MAX_STUDENTS) {
        cout << "Maximum number of students reached!" << endl;
        return;
    }

    cout << "Enter student name: ";
    cin.ignore(); // Clear previous input
    getline(cin, studentNames[studentCount]);
    studentCount++;
    cout << "Student added successfully!" << endl;
}

void inputScores() {
    string name;
    cout << "Enter the name of the student to input scores: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (studentNames[i] == name) {
            found = true;
            for (int j = 0; j < MAX_TESTS; j++) {
                int score;
                cout << "Enter score for Test " << j + 1 << ": ";
                cin >> score;

                // Validate score
                while (score < 0 || score > 100) {
                    cout << "Invalid score! Please enter a score between 0 and 100: ";
                    cin >> score;
                }
                testScores[i][j] = score;
            }
            cout << "Scores entered successfully!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student not found!" << endl;
    }
}

void calculateAverages() {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (!studentNames[i].empty()) {
            double sum = 0;
            for (int j = 0; j < MAX_TESTS; j++) {
                sum += testScores[i][j];
            }
            averageScores[i] = sum / MAX_TESTS;
        }
    }
    cout << "Averages calculated successfully!" << endl;
}

void assignGrades() {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (!studentNames[i].empty()) {
            if (averageScores[i] >= 90) {
                finalGrades[i] = 'A';
            } else if (averageScores[i] >= 80) {
                finalGrades[i] = 'B';
            } else if (averageScores[i] >= 70) {
                finalGrades[i] = 'C';
            } else if (averageScores[i] >= 60) {
                finalGrades[i] = 'D';
            } else {
                finalGrades[i] = 'F';
            }
        }
    }
    cout << "Grades assigned successfully!" << endl;
}

void displayResults() {
    cout << "\n=== Student Results ===" << endl;
    cout << "Name\tAverage Score\tFinal Grade" << endl;

    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (!studentNames[i].empty()) {
            cout << studentNames[i] << "\t" << averageScores[i] << "\t\t" << finalGrades[i] << endl;
        }
    }
}