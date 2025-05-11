#include <iostream>
using namespace std;

void ComparisonCountingSort(int A[], int n, int S[]) {
    int Count[n];
    
    // Initialize Count array to 0
    for (int i = 0; i < n; i++)
        Count[i] = 0;

    // Count comparisons
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] < A[j])
                Count[j]++;
            else
                Count[i]++;
        }
    }

    // Place elements in sorted positions
    for (int i = 0; i < n; i++)
        S[Count[i]] = A[i];
}

int main() {
    int A[] = {70, 30, 15, 60, 35, 81, 98, 14, 47};
    int n = sizeof(A) / sizeof(A[0]);
    int S[n];

    ComparisonCountingSort(A, n, S);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << endl;

    return 0;
}
