

#include <cstdlib>
#include <iostream>

template <typename T>
void bubblsort(T data[], int n) {

    int i, j;
    T temp;

    for (i = 0; i < n - 1; i++) {

        for (j = 0; j < n - i - 1; j++) {

            if (data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

using namespace std;

int main() {
    int data[10];
    int i;
    cout << "Enter ten unsorted integers..." << endl;
    for (i = 0; i < 10; i++) {
        cout << "[" << i << "] = ";
        cin >> data[i];
    }
    cout << "Unsorted List = ";

    for (i = 0; i < 10; i++) {
        cout << data[i] << ", ";
    }
    cout << endl;

    cout << "Sorting..." << endl;

    bubblsort(data, 10);
    cout << "Sorted List = ";
    for (i = 0; i < 10; i++) {
        cout << data[i] << ", ";
    }

    cout << endl;

    float fData[10];
    
    cout << "Enter ten unsorted floats..." << endl;
    for (i = 0; i < 10; i++) {
        cout << "[" << i << "] = ";
        cin >> fData[i];
    }
    cout << "Unsorted List = ";

    for (i = 0; i < 10; i++) {
        cout << fData[i] << ", ";
    }
    cout << endl;

    cout << "Sorting..." << endl;

    bubblsort(fData, 10);
    cout << "Sorted List = ";
    for (i = 0; i < 10; i++) {
        cout << fData[i] << ", ";
    }

    char cData[10];

    cout << "Enter ten unsorted floats..." << endl;
    for (i = 0; i < 10; i++) {
        cout << "[" << i << "] = ";
        cin >> cData[i];
    }
    cout << "Unsorted List = ";

    for (i = 0; i < 10; i++) {
        cout << cData[i] << ", ";
    }
    cout << endl;

    cout << "Sorting..." << endl;

    bubblsort(cData, 10);
    cout << "Sorted List = ";
    for (i = 0; i < 10; i++) {
        cout << cData[i] << ", ";
    }


    return 0;
}
