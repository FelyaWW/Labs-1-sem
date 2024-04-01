#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <limits>
using namespace std;

void SetConsoleToUTF8() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}
void ClearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void printMatrix(int n, int m, int matrix[20][20]) {
    int field_width = 1;
    int max_num = n * m;
    while (max_num >= 10) {
        max_num /= 10;
        field_width++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(field_width) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixClockWise(int n, int m) {
    if (n <= 0 || m <= 0) {
        cout << "Введите корректные размеры матрицы" << endl;
    } else {
        int matrix[20][20];

        int num = 1;
        int left = 0, right = m - 1, top = 0, bottom = n - 1;

        while (num <= n * m) {
            // Заполняем верхнюю строку
            if (top <= bottom) {
                for (int i = left; i <= right; i++) {
                    matrix[top][i] = num;
                    num++;
                }
                top++;
            }

            // Заполняем верхний столбец
            if (left <= right) {
                for (int i = top; i <= bottom; i++) {
                    matrix[i][right] = num;
                    num++;
                }
                right--;
            }

            // Заполняем нижнюю строку
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = num;
                    num++;
                }
                bottom--;
            }

            // Заполняем левый столбец
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num;
                    num++;
                }
                left++;
            }
        }

        printMatrix(n, m, matrix);
    }
}

void fillMatrixCounterClockwiseSpiral(int n, int m) {
    int matrix[20][20];

    if (n <= 0 || m <= 0) {
        cout << "Введите корректные размеры матрицы" << endl;
    } else {
        int num = 1;
        int left = 0, right = m - 1, top = 0, bottom = n - 1;

        while (num <= n * m) {
            for (int i = right; i >= left; i--) {
                matrix[top][i] = num;
                num++;
            }
            top++;

            if (num <= n * m) {
                for (int i = top; i <= bottom; i++) {
                    matrix[i][left] = num;
                    num++;
                }
                left++;
            }

            if (num <= n * m) {
                for (int i = left; i <= right; i++) {
                    matrix[bottom][i] = num;
                    num++;
                }
                bottom--;
            }

            if (num <= n * m) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][right] = num;
                    num++;
                }
                right--;
            }
        }

        printMatrix(n, m, matrix);
    }
}

void MatrixInnerClockwiseSpiral(int n, int m) {
    int matrix[20][20];

    if (n <= 0 || m <= 0) {
        cout << "Введите корректные размеры матрицы" << endl;
    } else {
        int num = n * m;
        int left = 0, right = m - 1, top = 0, bottom = n - 1;

        while (num >= 1) {
            for (int i = right; i >= left; i--) {
                matrix[top][i] = num;
                num--;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                matrix[i][left] = num;
                num--;
            }
            left++;

            if (top <= bottom) {
                for (int i = left; i <= right; i++) {
                    matrix[bottom][i] = num;
                    num--;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][right] = num;
                    num--;
                }
                right--;
            }
        }

        printMatrix(n, m, matrix);
    }
}

void matrixInnerCounterClockwiseSpiral(int n, int m) {
    int matrix[20][20];

    if (n <= 0 || m <= 0) {
        cout << "Введите корректные размеры матрицы" << endl;
    } else {
        int num = n * m;
        int left = 0, right = m - 1, top = 0, bottom = n - 1;

        while (num >= 1) {
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num;
                num--;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num;
                num--;
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = num;
                    num--;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num;
                    num--;
                }
                left++;
            }
        }

        printMatrix(n, m, matrix);
    }
}




int main() {
    SetConsoleToUTF8();

    int n = 0, m = 0;
    int selectedCommand = 1;
    int input = 0, choice = 0;
    while(1) {
        system("cls");
        cout << "1. Введите n" << (selectedCommand == 1 ? " <---" : "")<< endl;
        cout << "2. Введите m" << (selectedCommand == 2 ? " <---" : "")<< endl;
        cout << "3. Вывод спирали по часовой стрелки" << (selectedCommand == 3 ? " <---" : "")<< endl;
        cout << "4. Вывод спирали против часовой стрелки" << (selectedCommand == 4 ? " <---" : "")<< endl;
        cout << "5. Вывод спирали по часовой с центра стрелки" << (selectedCommand == 5 ? " <---" : "")<< endl;
        cout << "6. Вывод спирали против часовой с центра стрелки" << (selectedCommand == 6 ? " <---" : "")<< endl;
        cout << endl;
        cout << "n: " << n << " m: " << m << endl;

        if (selectedCommand == 3 ) {
            matrixClockWise(n,m);

        }
        else if (selectedCommand == 4){
            fillMatrixCounterClockwiseSpiral(n,m);
        }
        else if (selectedCommand == 5){
            MatrixInnerClockwiseSpiral(n,m);
        }
        else if (selectedCommand == 6){
            matrixInnerCounterClockwiseSpiral(n,m);
        }
        input = _getch();


        if (input == 224) {
            int arrowKey = _getch();
            if (arrowKey == 72) { // Up arrow key
                selectedCommand = max(selectedCommand - 1, 1);
                choice = selectedCommand;
            } else if (arrowKey == 80) { // Down arrow key
                selectedCommand = min(selectedCommand + 1, 6);
                choice = selectedCommand;
            }
        }
        else if (input >='1' && input <='6'){
            selectedCommand = input - '0';
            choice = selectedCommand;
        }
        else if (input == 13){
            if (choice == 1) {
                system("cls");
                cout << "Введите n: ";
                cin >> n;
                if (n > 20) {
                    cout << "Вы ввели число, превышающий лимит в 20, n будет равняться 20 " << endl;
                    n = 20;
                    ClearInputBuffer();
                    system("pause");
                } else if (n <= 0) {
                    cout << "n должен быть натуральным числом, n будет равняться 1" << endl;
                    n = 1;
                    ClearInputBuffer();
                    system("pause");
                }
            } else if (choice == 2) {
                system("cls");
                cout << "Введите m: ";
                cin >> m;
                if (m > 20) {
                    cout << "Вы ввели число, превышающий лимит в 20, m будет равняться 20 " << endl;
                    m = 20;
                    ClearInputBuffer();
                    system("pause");
                } else if (m <= 0) {
                    cout << "n должен быть натуральным числом, m будет равняться 1" << endl;
                    m = 1;
                    ClearInputBuffer();
                    system("pause");
                }
            }
        }



    }

    return 0;
}
