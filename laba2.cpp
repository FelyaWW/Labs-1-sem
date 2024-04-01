#include <iostream>
#include <windows.h>
#include <limits>
#include <conio.h>
#include <cstdint>

using namespace std;

// Функция для установки кодировки консоли на UTF-8
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


    while (true) {
        system("cls");

        cout << "1. Ввести первое число" << endl;
        cout << "2. Ввести второе число" << endl;
        cout << "3. Сумма" << endl;
        cout << "4. Умножение" << endl;
        cout << "F: " << F << " S: " << S << endl;

        if (choice == 3) {
            result = static_cast<int64_t>(F) + static_cast<int64_t>(S);
            cout << "Ответ: " << result << endl;
        } else if (choice == 4) {

            result = static_cast<int64_t>(F) * static_cast<int64_t>(S);
            cout << "Ответ: " << result << endl;

        }

        if (1) {
            cout << "Ваш выбор: ";

            int input = _getch();  // Считываем клавишу без ожидания Enter

            if (input == '1' || input == '2' || input == '3' || input == '4') {
                choice = input - '0';  // Преобразуем символ в число
            } else {
                cout << "Я не понимаю твой ввод. Попробуй еще раз! ";
                system("Pause");
                _getch();  // Ожидаем любую клавишу
                continue;
            }

            if (choice == 1) {
                system("cls");
                cout << "Введите первое число F: ";
                cin >> F;
                if (F == 2147483647) {
                    cout << "Число превысило лимит в 2147483647, F будет равен 2147483647 "; system("Pause");
                }
                else if  (F == -2147483648) {
                    cout << "Число превысило лимит в -2147483648, F будет равен -2147483648 "; system("Pause");
                }
                ClearInputBuffer();

            } else if (choice == 2) {
                system("cls");
                cout << "Введите второе число S: ";
                cin >> S;
                if (S == 2147483647) {
                    cout << "Число превысило лимит в 2147483647, S будет равен 2147483647 ";
                    system("Pause");
                }
                else if  (S == -2147483648) {
                    cout << "Число превысило лимит в -2147483648, S будет равен -2147483648 "; system("Pause");
                }
                ClearInputBuffer();

            }
        }
        }


    return 0;
}
