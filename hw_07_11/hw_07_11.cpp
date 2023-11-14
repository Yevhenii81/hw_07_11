#include <iostream>
#include <ctime>
using namespace std;

void printArray(int** arr, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void AddRow(int**& arr, int* rows, int columns, int index) {

    (*rows)++;

    int** newArr = new int* [*rows];

    for (int i = 0; i < index; ++i) {
        newArr[i] = new int[columns];
        for (int j = 0; j < columns; ++j) {
            newArr[i][j] = arr[i][j];
        }
    }

    
    newArr[index] = new int[columns] {}; 

    
    for (int i = index + 1; i < *rows; ++i) {
        newArr[i] = new int[columns];
        for (int j = 0; j < columns; ++j) {
            newArr[i][j] = arr[i - 1][j];
        }
    }

    
    for (int i = 0; i < *rows - 1; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = newArr;
}

void AddColumn(int**& arr, int rows, int* columns, int index) {
   
    (*columns)++;

   
    for (int i = 0; i < rows; ++i) {
        
        int* newRow = new int[*columns];
        int col = 0;

        for (int j = 0; j < *columns; ++j) {
            if (j == index) {
                newRow[j] = 0; 
            }
            else {
                newRow[j] = arr[i][col++];
            }
        }

        delete[] arr[i];

        arr[i] = newRow;
    }
}

int main() {

    srand(time(NULL));
    int rows = 4;
    int columns = 4;
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            array[i][j] = rand() % 9 + 1;
        }
    }

    cout << "source array:\n";
    printArray(array, rows, columns);
    
    int rowIndexToAdd = 2;
    AddRow(array, &rows, columns, rowIndexToAdd);

    cout << "\narray after adding rows:\n";
    printArray(array, rows, columns);

    
    //int colIndexToAdd = 2;
    AddColumn(array, rows, &columns, colIndexToAdd);

    cout << "\narray after adding columns:\n";
    printArray(array, rows, columns);

    
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

   
}