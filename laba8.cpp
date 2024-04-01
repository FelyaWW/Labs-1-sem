#include <iostream>
#include <conio.h>
#include <windows.h>
#include <limits>
#ifdef max
#undef max
#endif

using namespace std;

void SetConsoleToUTF8() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}
void ClearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void getDayOfWeek(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }

    int h = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    if (h==0) cout<<"Понедельник";
    else if (h==1) cout<<"Вторник";
    else if (h==2) cout<<"Среда";
    else if (h==3) cout<<"Четверг";
    else if (h==4) cout<<"Пятница";
    else if (h==5) cout<<"Суббота";
    else if (h==6) cout<<"Воскресенье";

}
void hours(int hours1, int hours2, int minutes1, int minutes2, int seconds1, int seconds2){
    int seconds,minutes,hours;
    seconds = (seconds1 + seconds2)%60;
    minutes = (minutes1 + minutes2 + (seconds1 + seconds2)/60)%60;
    hours = (hours1 + hours2 + (minutes1 + minutes2 + (seconds1 + seconds2)/60)/60)%24;
    printf("Сумма времени: %02d:%02d:%02d \n",hours,minutes,seconds);

    int totalseconds1 = hours1*3600 + minutes1*60 + seconds1;
    int totalseconds2 = hours2*3600 + minutes2*60 + seconds2;
    int result = totalseconds1 - totalseconds2;
    if (result<0){
        result = (3600 * 24 + result)%(3600*24);
    }
    hours = (result/3600);
    minutes = (result%3600)/60;
    seconds = (result%3600)%60;
    printf("Разница времени: %02d:%02d:%02d \n",hours,minutes,seconds);


}

void datasum(int d, int month, int year, int days) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) daysInMonth[1]=29;
    else daysInMonth[1]=28;
    for (int i = 0; i < days; i++) {
        d++;
        if (d > daysInMonth[month - 1]) {
            d = 1;
            month++;
            if (month > 12) {

                month = 1;
                year++;
                if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) daysInMonth[1]=29;
                else daysInMonth[1]=28;
            }
        }
    }
    printf("Сумма дат: %02d.%02d.%04d ", d, month, year);
    getDayOfWeek(year,month,d);
    cout<<endl;




}
void datamin(int d, int month, int year, int days) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) daysInMonth[1]=29;
    else daysInMonth[1]=28;
    for (int i = 0; i < days && year>1; i++){
        d--;
        if (d==0){
            month !=1 ? d = daysInMonth[month - 2]: d = 31;
            month--;
            if (month==0){
                month = 12;
                year--;
                if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) daysInMonth[1]=29;
                else daysInMonth[1]=28;
                if (year==0){

                    year = 1;
                }


            }
        }
    }
    printf("Разница дат: %02d.%02d.%04d ", d, month, year);
    getDayOfWeek(year,month,d);
    cout<<endl;

}
int getDaysInMonth(int year, int month) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        return 29;
    }

    return daysInMonth[month - 1]; // Вернуть количество дней в указанном месяце
}

int main() {
    SetConsoleToUTF8();
    int hours1 = 0, hours2 = 0, minutes1 = 0, minutes2 = 0, seconds1 = 0, seconds2 = 0;
    int day1 = 1, month1 = 1, year1 = 1000, days = 0;
    char week[20];
    int selectedCommand = 1;
    while (1) {
        system("cls");
        printf("1. Первое Время: %02d:%02d:%02d %s  \n", hours1, minutes1, seconds1,
               (selectedCommand == 1) ? " <---" : "");
        printf("2. Второе Время: %02d:%02d:%02d %s \n", hours2, minutes2, seconds2,
               (selectedCommand == 2) ? " <---" : "");
        printf("3. Дата: %02d.%02d.%04d ", day1, month1, year1); getDayOfWeek(year1,month1,day1); cout<<((selectedCommand == 3) ? " <---" : "")<<endl;
        printf("4. Количество дней: %d %s\n", days, (selectedCommand == 4) ? " <---" : "");
        cout << endl;
        hours(hours1, hours2 , minutes1 , minutes2 , seconds1 , seconds2);
        cout << endl;
        datasum(day1,month1,year1,days);
        datamin(day1,month1,year1,days);
        int input = _getch();

        if (input == 224) {
            int arrowKey = _getch();
            if (arrowKey == 72) { // Up arrow key
                selectedCommand = max(selectedCommand - 1, 1);

            } else if (arrowKey == 80) { // Down arrow key
                selectedCommand = min(selectedCommand + 1, 4);

            }
        } else if (input >= '1' && input <= '4') {
            selectedCommand = input - '0';
        } else if (input == 13) {
            if (selectedCommand == 1) {
                system("cls");
                cout << "Введите Количество Часов: ";
                cin >> hours1;
                ClearInputBuffer();
                if (hours1 >= 24) {
                    cout << endl << "Вы превысили лимит в 24 часа, часы будут равняться 23." << endl;

                    system("pause");
                    hours1 = 23;
                } else if (hours1 < 0) {
                    cout << endl << "Нужно ввести целое положительное число, часы будут равняться 0." << endl;
                    system("pause");
                    hours1 = 0;
                }

                system("cls");
                cout << "Введите Количество Минут: ";
                cin >> minutes1;
                ClearInputBuffer();
                if (minutes1 >= 60) {
                    cout << endl << "Вы превысили лимит в 60 минут, минуты будут равняться 59." << endl;
                    system("pause");
                    minutes1 = 59;
                } else if (minutes1 < 0) {
                    cout << endl << "Нужно ввести целое положительное число, минуты будут равняться 0." << endl;
                    system("pause");

                    minutes1 = 0;
                }

                system("cls");
                cout << "Введите Количество Секунд: ";
                cin >> seconds1;
                ClearInputBuffer();
                if (seconds1 >= 60) {
                    cout << endl << "Вы превысили лимит в 60 секунд, секунды будут равняться 59." << endl;
                    system("pause");

                    seconds1 = 59;
                } else if (seconds1 < 0) {
                    cout << endl << "Нужно ввести целое положительное число, секунды будут равняться 0." << endl;
                    system("pause");

                    seconds1 = 0;
                }
            }
            if (selectedCommand == 2) {
                system("cls");
                cout << "Введите Количество Часов: ";
                cin >> hours2;
                ClearInputBuffer();
                if (hours2 >= 24) {
                    cout << endl << "Вы превысили лимит в 24 часа, часы будут равняться 23." << endl;
                    system("pause");

                    hours2 = 23;
                } else if (hours2 < 0) {
                    cout << endl << "Нужно ввести целое положительное число, часы будут равняться 0." << endl;
                    system("pause");

                    hours2 = 0;
                }

                system("cls");
                cout << "Введите количество Минут: ";
                cin >> minutes2;
                ClearInputBuffer();
                if (minutes2 >= 60) {
                    cout << endl << "Вы превысили лимит в 60 минут, минуты будут равняться 59." << endl;
                    system("pause");

                    minutes2 = 59;
                } else if (minutes2 < 0) {
                    cout << endl << "Нужно ввести целое положительное число, минуты будут равняться 0." << endl;
                    system("pause");

                    minutes2 = 0;
                }

                system("cls");
                cout << "Введите Количество Секунд: ";
                cin >> seconds2;
                ClearInputBuffer();
                if (seconds2 >= 60) {
                    cout << endl << "Вы превысили лимит в 60 секунд, секунды будут равняться 59." << endl;
                    system("pause");

                    seconds2 = 59;
                } else if (seconds2 < 0) {
                    cout << endl << "Нужно ввести целое положительное число, секунды будут равняться 0." << endl;
                    system("pause");

                    seconds2 = 0;
                }
            }
            if (selectedCommand == 3) {
                system("cls");
                cout << "Введите год: ";
                cin >> year1;
                ClearInputBuffer();
                if (year1 > 9000) {
                    cout << "Вы превысили лимит в 9001, год будет равняться 9000. " << endl;
                    system("pause");

                    year1 = 9000;

                } else if (year1 <= 1000) {
                    cout << "Вы вышли из ограничения в 1000 лет, год будет равен 1000" << endl;
                    system("pause");

                    year1 = 1000;
                }

                system("cls");
                cout << "Введите месяц: ";
                cin >> month1;
                ClearInputBuffer();
                if (month1 > 12) {
                    cout << "Вы превысили лимит в 13, месяц будет равняться 12. " << endl;
                    system("pause");

                    month1 = 12;

                } else if (month1 <= 0) {
                    cout << "Вы ввели не натуральное число, месяц будет равен 01." << endl;
                    system("pause");

                    month1 = 1;
                }

                system("cls");
                cout << "Введите день: ";
                cin >> day1;
                ClearInputBuffer();
                if (day1 > getDaysInMonth(year1, month1)) {
                    cout << "Вы превысили лимит, день будет равняться максимальному числу в месяце. " << endl;
                    system("pause");

                    day1 = getDaysInMonth(year1, month1);
                } else if (day1 <= 0) {
                    cout << "Вы ввели не натуральное число, день будет равняться 01. " << endl;
                    system("pause");

                    day1 = 1;
                }

            }
            if (selectedCommand == 4) {
                system("cls");
                cout << "Введите количество дней: ";
                cin >> days;
                ClearInputBuffer();
                if (days <= 0) {
                    cout << "Вы ввели не натуральное число, количество дней будет равняться 1" << endl;
                    system("pause");

                    days = 1;
                } else if (days > 999) {
                    cout << "Вы превысили лимит в 1000, количество дней будет равняться 999" << endl;
                    system("pause");

                    days = 999;
                }
            }

        } else if (input == 27) {
            exit(0); // Выход по клавише Escape
        }
    }
}