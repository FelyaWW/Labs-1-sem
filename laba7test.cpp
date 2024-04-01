#include <iostream>
#include <windows.h>

using namespace std;
bool isPalindrome(const char* str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void SetConsoleToUTF8() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

int main() {
    SetConsoleToUTF8();
    const int maxLength = 70;
    char input[maxLength + 1]; // +1 для учета завершающего нулевого символа строки
    while(1) {
        cout << "Введите строку (до 70 символов): ";
        cin.getline(input, sizeof(input));

        int maxPalindromeStart = 0;
        int maxPalindromeLength = 0;

        int length = 0;
        while (input[length] != '\0' && length < maxLength) {
            length++;
        }

        for (int start = 0; start < length; ++start) {
            for (int end = start; end < length; ++end) {
                int currentLength = end - start + 1;
                if (currentLength > maxPalindromeLength && isPalindrome(input, start, end)) {
                    maxPalindromeStart = start;
                    maxPalindromeLength = currentLength;
                }
            }
        }

        // Вывод самого длинного палиндрома
        cout << "Самый длинный палиндром: ";
        for (int i = maxPalindromeStart; i < maxPalindromeStart + maxPalindromeLength; ++i) {
            cout << input[i];
        }
        cout << endl << "Длинна палиндрома: " << (maxPalindromeLength)<< endl;
        system("pause");
        system("cls");
    }

    system("pause");

    return 0;
}
