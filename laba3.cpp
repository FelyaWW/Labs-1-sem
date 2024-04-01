#include <iostream>
#include <windows.h>
#include <limits>
#include <cstdint>
#include <conio.h>
#include <cmath>
#include <iomanip>

using namespace std;

void SetConsoleToUTF8() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

void ClearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    SetConsoleToUTF8();

    int F = 0, S = 0;
    int64_t result = 0;
    int choice = 0;
    int maxChoice = 8; // Максимальный номер команды
    int selectedCommand = 1; // Выбранная команда
    int ans = 0;
    bool fNumberEntered = false, sNumberEntered = false;

    while (true) {
        system("cls");

        cout << "1. Ввести первое число" << (selectedCommand == 1 ? " <---" : "") << endl;
        cout << "2. Ввести второе число" << (selectedCommand == 2 ? " <---" : "") << endl;
        cout << "3. Сумма F и S" << (selectedCommand == 3 ? " <---" : "") << endl;
        cout << "4. Разница F и S" << (selectedCommand == 4 ? " <---" : "") << endl;
        cout << "5. Умножение F и S" << (selectedCommand == 5 ? " <---" : "") << endl;
        cout << "6. Деление F на S" << (selectedCommand == 6 ? " <---" : "") << endl;
        cout << "7. Возведение F в степень S" << (selectedCommand == 7 ? " <---" : "") << endl;
        cout << "9. Выход" << (selectedCommand == 8 ? " <---" : "") << endl;
        cout<<endl<<endl;
        cout << "F: " << F << " S: " << S << endl;

        if (choice == 3 && fNumberEntered && sNumberEntered) {
            result = static_cast<int64_t>(F) + static_cast<int64_t>(S);
            cout << "Ответ: " << result << endl;
        } else if (choice == 4 && fNumberEntered && sNumberEntered) {
            result = static_cast<int64_t>(F) - static_cast<int64_t>(S);
            cout << "Ответ: " << result << endl;
        }
        else if (choice == 5 && fNumberEntered && sNumberEntered) {
            result = static_cast<int64_t>(F) * static_cast<int64_t>(S);
            cout << "Ответ: " << result << endl;
        }
        else if (choice == 6 && fNumberEntered && sNumberEntered) {
            if (S!=0){
                result = static_cast<int64_t>(F) / static_cast<int64_t>(S);
                cout << "Ответ: " << result << endl;
            }
            else{
                cout << "Нельзя делить на ноль."<<endl;
            }
        }
        else if (choice == 7 && fNumberEntered && sNumberEntered) {
            long double result7 = pow(F, S);
            if (S < 0) {
                if (result7 == 0.0) {
                    cout << "Ответ: 0" << endl;
                } else {
                    cout << "Ответ: " << fixed << setprecision(25) << result7 << endl;
                }
            } else if (result7!= INFINITY){
                cout << fixed << setprecision(0);
                cout << "Ответ: " << result7 << endl;
            }
            else {
                cout << "Числа слишком большие. Попробуйте другую комбинацию." << endl;
            }


        }

        int input = _getch();
        if (input == 224) {
            int arrowKey = _getch();
            if (arrowKey == 72) { // Up arrow key
                selectedCommand = max(selectedCommand - 1, 1);
                choice = selectedCommand;
            } else if (arrowKey == 80) { // Down arrow key
                selectedCommand = min(selectedCommand + 1, maxChoice);
                choice = selectedCommand;
            }
        } else if (input >= '1' && input <= '7') {
            selectedCommand = input - '0';
            choice = selectedCommand;

        } else if (input == '9') {
            selectedCommand = input - '0';
            choice = selectedCommand;
            selectedCommand = selectedCommand-1;
        }
        else if (input == 27) { // Escape key
            exit(0); // Выход по клавише Escape
        } else if (input == 13) { // Enter key
            if (selectedCommand == 1) {
                system("cls");
                cout << "Введите первое число F: ";
                cin >> F;
                fNumberEntered = true;
                if (F==2147483647){
                    cout<<endl<< "Вы превысили лимит в 2147483648, F будет равен 2147483647"<<endl;
                    system("pause");
                }
                else if (F==-2147483648){
                    cout<<endl<< "Вы превысили лимит в -2147483648, F будет равен -2147483648"<<endl;
                    system("pause");
                }
                ClearInputBuffer();
            } else if (selectedCommand == 2) {
                system("cls");
                cout << "Введите второе число S: ";
                cin >> S;
                sNumberEntered = true;
                if (S==2147483647){
                    cout<<endl<< "Вы превысили лимит в 2147483648, S будет равен 2147483647"<<endl;
                    system("pause");
                }
                else if (S==-2147483648){
                    cout<<endl<< "Вы превысили лимит в -2147483648, S будет равен -2147483648"<<endl;
                    system("pause");
                }
                ClearInputBuffer();
            } else if (selectedCommand == 8) {
                exit(0); // Выход по клавише Enter
            }
        }
    }

    return 0;
}
