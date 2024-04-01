#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

void SetConsoleToUTF8() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

int main() {
    SetConsoleToUTF8();
    int n = 0, m = 0;
    int CurrentN = 0, CurrentM = 0, input, robotN = 1, robotM = 1;
    char CurrentChar;
    int lastN = 0, lastM = 0;

    while (n == 0 || m == 0) {
        cout << "Введите n в промежутке [3;15]:" << endl;
        cin >> n;
        if (n < 3) n = 3;
        else if (n > 15) n = 15;
        system("cls");
        cout << "Введите m в промежутке [3;15]:" << endl;
        cin >> m;
        if (m < 3) m = 3;
        else if (m > 15) m = 15;
    }
    char array[n][m];
    int walls[n][m];
    int way[n][m];


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 0 && i < n - 1 && j > 0 && j < m - 1) {
                array[i][j] = ' ';
                walls[i][j] = ' ';
            } else {
                array[i][j] = '#';
                walls[i][j] = '#';
            }

            way[i][j] = 0;
        }
    }
    array[robotN][robotM] = 48;
    array[CurrentN][CurrentM] = 'X';

    while (true) {
        system("cls");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << setw(2) << array[i][j] << ' ';
            }
            cout << endl;
        }
        cout << "1 - '#'" << endl << "2 - ' '" << endl << "3 - '0' (Робот)" << endl << "4 - Вывод пути" << endl;

        input = _getch();

        if (input == 224) {
            int arrowKey = _getch();
            if (arrowKey == 72) { // Вверх
                array[CurrentN][CurrentM] = CurrentChar;
                CurrentN = max(CurrentN - 1, 0);
                CurrentChar = array[CurrentN][CurrentM];
            }
            else if (arrowKey == 80) { // Вниз
                array[CurrentN][CurrentM] = CurrentChar;
                CurrentN = min(CurrentN + 1, n - 1);
                CurrentChar = array[CurrentN][CurrentM];
            }
            else if (arrowKey == 75) { // Влево
                array[CurrentN][CurrentM] = CurrentChar;
                CurrentM = max(CurrentM - 1, 0);
                CurrentChar = array[CurrentN][CurrentM];
            }
            else if (arrowKey == 77) { // Вправо
                array[CurrentN][CurrentM] = CurrentChar;
                CurrentM = min(CurrentM + 1, m - 1);
                CurrentChar = array[CurrentN][CurrentM];
            }
        }
        else if (input == 49) { // 1
            CurrentChar = '#';
            array[CurrentN][CurrentM] = CurrentChar;
            walls[CurrentN][CurrentM] = '#'; // Стена
        }
        else if (input == 50) { // 2
            CurrentChar = ' ';
            array[CurrentN][CurrentM] = CurrentChar;
            walls[CurrentN][CurrentM] = CurrentChar;

        }
        else if (input == 51) { // 3
            CurrentChar = '0'; // Робот 0
            array[CurrentN][CurrentM] = CurrentChar;
            walls[CurrentN][CurrentM] = CurrentChar;
            array[robotN][robotM] = ' ';
            walls[robotN][robotM] = ' ';
            robotN = CurrentN;
            robotM = CurrentM;
        }
        else if (input == 27) { // Выход при нажатии клавиши Esc
            break;
        }
        else if (input == 52) { // 4
            array[CurrentN][CurrentM] = CurrentChar;
            char ans[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i][j] = array[i][j];
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i][j] = array[i][j];
                    way[i][j] = array[i][j]+100; // Копирование значений из array в way
                    if (way[i][j]==148) way[i][j]=0;
                    if (i == 0 || (i + 1) == n || j == 0 || (j + 1) == m) {
                        way[i][j] = walls[i][j]+100;
                    }
                    if (way[i][j] == 'X'+100) {

                        way[i][j] = CurrentChar+100;

                    }
                }
            }


            for (int k = 0; k < 250; k++) {
                for (int i = 0; i < n + 2; i++) {
                    for (int j = 0; j < m + 2; j++) {
                        if (way[i][j] == k) {
                            if ((array[i + 1][j] == ' ') && way[i + 1][j] > k) way[i + 1][j] = k + 1;
                            if ((array[i - 1][j] == ' ') && way[i - 1][j] > k) way[i - 1][j] = k + 1;
                            if ((array[i][j + 1] == ' ') && way[i][j + 1] > k) way[i][j + 1] = k + 1;
                            if ((array[i][j - 1] == ' ') && way[i][j - 1] > k) way[i][j - 1] = k + 1;
                        }
                    }
                }
            }
            int minWay = 1000, exi = 0, exj = 0;
            bool flag = false;
            for (int i = 0; i<n;i++){
                for (int j = 0; j<m; j++){
                    if ((i == 0 || i == n-1 || j == 0 || j == m-1) && way[i][j]<132) {
                        flag = true;
                        if (way[i][j]<minWay){
                            minWay = way[i][j];
                            exi = i;
                            exj = j;
                        }

                    }
                }
            }
            if (flag){
                ans[exi][exj] = '*';

                for (int i = exi; i>0; i--){
                    for (int j = exj; j>0; j--){
                        if (way[i+1][j] == way[i][j]-1){
                            ans[i+1][j] = '*';

                        }
                        else if (way[i-1][j] == way[i][j]-1) {
                            ans[i-1][j] = '*';
                        }
                        else if (way[i][j+1] == way[i][j]-1) {
                            ans[i][j+1] = '*';
                        }
                        else {
                            ans[i][j-1] = '*';
                        }
                    }
                }
                int i = exi; int j = exj;
                for(int l = 0; way[i][j]!=0;l++){

                    if (way[i+1][j] == way[i][j]-1){
                        ans[i+1][j] = '*';
                        ++i;

                    }
                    else if (way[i-1][j] == way[i][j]-1) {
                        ans[i-1][j] = '*';
                        --i;
                    }
                    else if (way[i][j+1] == way[i][j]-1) {
                        ans[i][j+1] = '*';
                        ++j;
                    }
                    else {
                        ans[i][j-1] = '*';
                        j--;
                    }
                }

            }
        // Выводим результат
        ans[robotM][robotN] = '0';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << setw(2) << ans[i][j] << ' ';

            }
            cout << endl;
        }
        if (flag == false) cout<<"Нет пути"<<endl;
        else cout<<"Длинна пути: "<<minWay<<endl;
        system("pause");
    }

    (array[lastN][lastM] = '#');
    (array[CurrentN][CurrentM] = 'X');
}

system("pause");
return 0;
}
