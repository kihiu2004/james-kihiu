#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void sortCube(int cube[3][3][3], int n) {
    vector<int> flat;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                flat.push_back(cube[i][j][k]);
            }
        }
    }

    //Sort the vector in ascending order
    sort(flat.begin(), flat.end());

    // put stored values in the cube
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cube[i][j][k] = flat[index++];
            }
        }
    }
}

int main() {
    int n = 2; 
    int cube[3][3][3] = {
        {{9, 2}, {5, 8}},
        {{1, 7}, {4, 3}}
    };

    sortCube(cube, n);

    cout << "Sorted Cube Elements:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << cube[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << "---" << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Sorter {
public:
    // Main function to merge two halves
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        // Merge back into arr in ascending order
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }
};

int main() {
    vector<int> data = {38, 27, 43, 3, 9, 82, 10};
    Sorter s;
    
    s.mergeSort(data, 0, data.size() - 1);

    cout << "Sorted array: ";
    for (int x : data) cout << x << " ";
    return 0;
}