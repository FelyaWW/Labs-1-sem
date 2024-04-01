#include <conio.h>
#include <random>
#include <iostream>
#include <windows.h>
#include <random>
#include <cmath>
#include <iomanip>

using namespace std;

void SetConsoleToUTF8() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

int RandomInt(int x) {
    random_device rd;
    mt19937 gen(rd());
    // Укажите диапазон случайных чисел с помощью std::uniform_int_distribution
    int lower_bound = 1;
    int upper_bound = x;
    uniform_int_distribution<int> distribution(lower_bound, upper_bound);

    // Генерация случайного числа в заданном диапазоне
    int random_number = distribution(gen);
    return random_number;

}

int main() {
    SetConsoleToUTF8();
    int wallsCount = 0, candyCount = 4, n = 10, m = 10, selectedCommand = 1;
    bool border = false, menu = true;
    bool alive1 = true, alive2 = true;
    char LastChar;
    while (1) {

        while (menu) {
            system("cls");
            cout << "1. Ввести количество строк " << (selectedCommand == 1 ? " <---" : "") << endl;
            cout << "2. Ввести количество столбцов " << (selectedCommand == 2 ? " <---" : "") << endl;
            cout << "3. Ввести количество стенок [0;5]" << (selectedCommand == 3 ? " <---" : "") << endl;
            cout << "4. Включить границы (1 - да, 0 - нет): " << border << (selectedCommand == 4 ? " <---" : "")
                 << endl;
            cout << "5. Закончить настройку " << (selectedCommand == 5 ? " <---" : "") << endl;
            cout << endl << endl;
            cout << "Количество строк: " << n << "   Количество столбцов: " << m << "     Количество стенок: "
                 << wallsCount << endl;
            int input = _getch();
            if (input == 224) {
                int arrowKey = _getch();
                if (arrowKey == 72) { // Up arrow key
                    selectedCommand = max(selectedCommand - 1, 1);
                } else if (arrowKey == 80) { // Down arrow key
                    selectedCommand = min(selectedCommand + 1, 5);
                }
            } else if (input >= '1' && input <= '5') {
                selectedCommand = input - '0';
            } else if (input == 13) { //enter
                if (selectedCommand == 1) {
                    system("cls");
                    cout << "Введите количество строк (от 4-х до 15): ";
                    cin >> n;
                    if (n < 4) {
                        cout << endl << "Вы ввели число меньше 4-х, количество строк будет равно 4." << endl;
                        system("pause");
                        n = 4;
                    } else if (n > 15) {
                        cout << endl << "Вы ввели число больше 15, количество строк будет равно 15." << endl;
                        system("pause");
                        n = 15;
                    }
                } else if (selectedCommand == 2) {
                    system("cls");
                    cout << "Введите количество столбцов (от 4-х до 15): ";
                    cin >> m;
                    if (m < 4) {
                        cout << endl << "Вы ввели число меньше 4-х, количество столбцов будет равно 4." << endl;
                        system("pause");
                        m = 4;
                    } else if (m > 15) {
                        cout << endl << "Вы ввели число больше 15, количество стролбцов будет равно 15." << endl;
                        system("pause");
                        m = 15;
                    }
                } else if (selectedCommand == 3) {
                    system("cls");
                    cout << "Введите количество стенок (от 0 до 5): ";
                    cin >> wallsCount;
                    if (wallsCount > 5) {
                        cout << endl << "Вы ввели количество стенок больше 5, это количество будет равно 5" << endl;
                        system("pause");
                        wallsCount = 5;
                    } else if (wallsCount < 0) {
                        cout << endl << "Вы ввели количество стенок меньше 0, это количество будет равно 0" << endl;
                        system("pause");
                        wallsCount = 0;
                    }

                } else if (selectedCommand == 4) border = not(border);
                else if (selectedCommand == 5) menu = false;
            }
        }
        unsigned char Field[n + 2][m + 2];
        const char space = 32, wall = 47, wall_user = 35, head1 = 79, tail1 = 111, head2 = 48, tail2 = 34, candy = 42;
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < m + 2; j++) {
                if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
                    Field[i][j] = wall;
                } else {
                    Field[i][j] = space;
                }
            }
        }

        bool menu2 = true;
        int CurrentN = RandomInt(n), CurrentM = RandomInt(m), input, Snake1N, Snake1M;
        (Field[CurrentN][CurrentM] = head1);
        while (menu2) {
            system("cls");
            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < m + 2; j++) {
                    cout << setw(2) << Field[i][j] << ' ';
                }
                cout << endl;
            }
            cout
                    << "esc - Случайная позиция головы первой змейки, enter - установка головы первой змейки в текущую позицию "
                    << endl;
            char CurrentChar = space;
            input = _getch();

            if (input == 224) {
                int arrowKey = _getch();
                if (arrowKey == 72) { // Вверх
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentN = max(CurrentN - 1, 1);
                    (Field[CurrentN][CurrentM] = head1);

                } else if (arrowKey == 80) { // Вниз
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentN = min(CurrentN + 1, n);
                    (Field[CurrentN][CurrentM] = head1);

                } else if (arrowKey == 75) { // Влево
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentM = max(CurrentM - 1, 1);
                    (Field[CurrentN][CurrentM] = head1);

                } else if (arrowKey == 77) { // Вправо
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentM = min(CurrentM + 1, m);
                    (Field[CurrentN][CurrentM] = head1);

                }

            } else if (input == 13) {
                menu2 = false;
            } else if (input == 27) {       // esc
                Field[CurrentN][CurrentM] = ' ';
                CurrentN = RandomInt(n);
                CurrentM = RandomInt(m);
                Field[CurrentN][CurrentM] = head1;
                menu2 = false;
            }


        }
        Snake1N = CurrentN;
        Snake1M = CurrentM;

        bool menu3 = true;

        CurrentN = RandomInt(n), CurrentM = RandomInt(m);
        while (CurrentN == Snake1N && CurrentM == Snake1M) CurrentN = RandomInt(n), CurrentM = RandomInt(m);
        (Field[CurrentN][CurrentM] = head2);
        char CurrentChar = space;
        while (menu3) {
            system("cls");
            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < m + 2; j++) {
                    cout << setw(2) << Field[i][j] << ' ';
                }
                cout << endl;
            }
            cout
                    << "esc - Случайная позиция головы второй змейки, enter - установка головы второй змейки в текущую позицию "
                    << endl;

            input = _getch();
            if (input == 224) {
                int arrowKey = _getch();
                if (arrowKey == 72) { // Вверх
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentN = max(CurrentN - 1, 1);
                    CurrentChar = Field[CurrentN][CurrentM];
                    (Field[CurrentN][CurrentM] = head2);

                } else if (arrowKey == 80) { // Вниз
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentN = min(CurrentN + 1, n);
                    CurrentChar = Field[CurrentN][CurrentM];
                    (Field[CurrentN][CurrentM] = head2);
                } else if (arrowKey == 75) { // Влево
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentM = max(CurrentM - 1, 1);
                    CurrentChar = Field[CurrentN][CurrentM];
                    (Field[CurrentN][CurrentM] = head2);
                } else if (arrowKey == 77) { // Вправо
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentM = min(CurrentM + 1, m);
                    CurrentChar = Field[CurrentN][CurrentM];
                    (Field[CurrentN][CurrentM] = head2);
                }
            }
            else if (input == 13) {
                if (CurrentChar ==' ') menu3 = false;
                else cout<<"Нельзя установить в это место. "<<endl,system("pause");


            } else if (input == 27) {       // esc
                Field[CurrentN][CurrentM] = CurrentChar;
                while (CurrentN == Snake1N && CurrentM == Snake1M) CurrentN = RandomInt(n), CurrentM = RandomInt(m);
                Field[CurrentN][CurrentM] = head2;
                CurrentChar = ' ';
                menu3 = false;
            }
        }
        int Snake2N = CurrentN;
        int Snake2M = CurrentM;

        bool menu4 = true;
        int CurWalls = 0;
        CurrentN = RandomInt(n), CurrentM = RandomInt(m);
        while (Field[CurrentN][CurrentM] != ' ') CurrentN = RandomInt(n), CurrentM = RandomInt(m);
        wallsCount > 0 ? (Field[CurrentN][CurrentM] = wall_user) : Field[CurrentN][CurrentM] = ' ';

        while (menu4) {
            if (CurWalls == wallsCount) break;
            system("cls");
            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < m + 2; j++) {
                    cout << setw(2) << Field[i][j] << ' ';
                }
                cout << endl;
            }
            cout << "esc - Поставить случайно оставшиеся стенки, enter - установка стенки в текущую позицию " << endl;
            input = _getch();

            if (input == 224) {
                int arrowKey = _getch();
                if (arrowKey == 72) { // Вверх
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentN = max(CurrentN - 1, 1);
                    CurrentChar = Field[CurrentN][CurrentM];
                    (Field[CurrentN][CurrentM] = wall_user);

                } else if (arrowKey == 80) { // Вниз
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentN = min(CurrentN + 1, n);
                    CurrentChar = Field[CurrentN][CurrentM];
                    (Field[CurrentN][CurrentM] = wall_user);
                } else if (arrowKey == 75) { // Влево
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentM = max(CurrentM - 1, 1);
                    CurrentChar = Field[CurrentN][CurrentM];
                    (Field[CurrentN][CurrentM] = wall_user);
                } else if (arrowKey == 77) { // Вправо
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentM = min(CurrentM + 1, m);
                    CurrentChar = Field[CurrentN][CurrentM];
                    (Field[CurrentN][CurrentM] = wall_user);
                }
            } else if (input == 13) {
                if (CurrentChar ==' ') {
                    (Field[CurrentN][CurrentM] = wall_user);
                    if (CurWalls < wallsCount) {
                        CurWalls += 1;
                        if (CurWalls == wallsCount) break;
                        while (Field[CurrentN][CurrentM] != ' ') {
                            CurrentN = RandomInt(n), CurrentM = RandomInt(m);

                        }
                        Field[CurrentN][CurrentM]= wall_user;
                    }
                }
                else {
                    cout<<"Нельзя установить в это место. "<<endl;
                    system("pause");
                }
            } else if (input == 27) {       // esc
                Field[CurrentN][CurrentM] = CurrentChar;
                while (CurWalls < wallsCount) {
                    do {
                        CurrentN = RandomInt(n), CurrentM = RandomInt(m);
                    } while (Field[CurrentN][CurrentM] != ' ');
                    Field[CurrentN][CurrentM] = wall_user;
                    CurrentChar = ' ';
                    CurWalls += 1;
                }
            }
        }

        system("cls");
        bool menu5 = true;
        int CurCandy = 0;
        CurrentN = RandomInt(n), CurrentM = RandomInt(m);
        while (Field[CurrentN][CurrentM] != ' ') CurrentN = RandomInt(n), CurrentM = RandomInt(m);
        Field[CurrentN][CurrentM] = candy;

        while (menu5) {
            if (CurCandy == candyCount) break;
            system("cls");
            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < m + 2; j++) {
                    cout << setw(2) << Field[i][j] << ' ';
                }
                cout << endl;
            }
            cout << "esc - Поставить случайно оставшуюся еду, enter - установка еды в текущую позицию " << endl;
            input = _getch();

            if (input == 224) {
                int arrowKey = _getch();
                if (arrowKey == 72) { // Вверх
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentN = max(CurrentN - 1, 1);
                    CurrentChar = Field[CurrentN][CurrentM];
                    (Field[CurrentN][CurrentM] = candy);

                } else if (arrowKey == 80) { // Вниз
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentN = min(CurrentN + 1, n);
                    CurrentChar = Field[CurrentN][CurrentM];
                    (Field[CurrentN][CurrentM] = candy);
                } else if (arrowKey == 75) { // Влево
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentM = max(CurrentM - 1, 1);
                    CurrentChar = Field[CurrentN][CurrentM];
                    (Field[CurrentN][CurrentM] = candy);
                } else if (arrowKey == 77) { // Вправо
                    Field[CurrentN][CurrentM] = CurrentChar;
                    CurrentM = min(CurrentM + 1, m);
                    CurrentChar = Field[CurrentN][CurrentM];
                    (Field[CurrentN][CurrentM] = candy);
                }

            } else if (input == 13) {
                if (CurrentChar ==' ') {
                    (Field[CurrentN][CurrentM] = candy);
                    if (CurCandy < candyCount) {
                        CurCandy += 1;
                        if (CurCandy == candyCount) break;
                        while (Field[CurrentN][CurrentM] != ' ') {
                            CurrentN = RandomInt(n), CurrentM = RandomInt(m);

                        }
                        Field[CurrentN][CurrentM]= candy;
                    }
                }
                else {
                    cout<<"Нельзя установить в это место. "<<endl;
                    system("pause");
                }


            } else if (input == 27) {       // esc
                Field[CurrentN][CurrentM] = CurrentChar;
                while (CurCandy < candyCount) {
                    do {
                        CurrentN = RandomInt(n), CurrentM = RandomInt(m);
                    } while (Field[CurrentN][CurrentM] != ' ');
                    Field[CurrentN][CurrentM] = candy;
                    CurrentChar = ' ';
                    CurCandy += 1;
                }

            }

        }
        const int maxTailLength = 400; // максимальная длина хвоста (вы можете выбрать свое значение)
        int tailLength1 = 0;
        int tailLength2 = 0;
        int MasTail1[maxTailLength][2];
        int MasTail2[maxTailLength][2];
        for (int i = 1; i<maxTailLength; i++){
            for (int j = 0; j<2; j++){
                MasTail1[i][j] = 0;
                MasTail2[i][j] = 0;
            }
        }
        int N = 0, M = 1, long1 = 0, long2 = 0;
        MasTail1[0][N] = Snake1N; MasTail1[0][M] = Snake1M;


        bool game1 = true;
        int score1 = 0, score2 = 0;
        while (game1){
            system("cls");
            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < m + 2; j++) {
                    cout << setw(2) << Field[i][j] << ' ';
                }
                cout << endl;
            }
            cout<<"wasd - Движение первого игрока, Стрелки - Движение второго игрока."<<endl;
            cout<<"Статус первого игрока: " << (alive1 )<< "     Счет первого игрока: "<< score1<<endl;
            cout<<"Статус второго игрока: " << (alive2 )<< "     Счет второго игрока: "<< score2<<endl;

            input = _getch();
            if (input == 224) {
                int arrowKey = _getch();
                if(alive1) {
                    if (arrowKey == 72) { // Вверх
                        if (Field[Snake1N - 1][Snake1M] == head2 || Field[Snake1N - 1][Snake1M] == wall_user ||
                            Field[Snake1N - 1][Snake1M] == tail1 || Field[Snake1N - 1][Snake1M] == tail2 || Field[Snake1N - 1][Snake1M] == '/') {
                            alive1 = false;
                        }
                        else if (Field[max(Snake1N - 1, 1)][Snake1M] == ' ') {

                            //MasTail1[long1][N] = 0; MasTail1[long1][M] = 0;     //long1 = 0
                            for (int i = 1; MasTail1[i][N]!=0; i++){        //
                                for (int j = 0; j<2; j++){
                                    MasTail1[i][j] = MasTail1[i-1][j];
                                }
                                Field[MasTail1[i][N]][MasTail1[i][M]] = tail1;
                            }

                            MasTail1[0][N] = Snake1N; MasTail1[0][M] = Snake1M;
                            Snake1N = max(Snake1N - 1, 1);
                            (Field[Snake1N][Snake1M] = head1);
                            Field[MasTail1[long1][N]][MasTail1[long1][M]] = ' ';
                            for (int i = 0; i<5; i++){
                                for (int j = 0; j<2; j++){
                                    cout<<MasTail1[i][j]<< ' ';
                                }
                                cout<< endl;

                            }
                            system("pause");

                        }
                        else if (Field[max(Snake1N - 1, 1)][Snake1M] == '*'){
                            for (int i = 1; MasTail1[i][N]!=0 || MasTail1[i+1][N]!=0; i++){        //
                                for (int j = 0; j<2; j++){
                                    MasTail1[i][j] = MasTail1[i-1][j];
                                }
                                Field[MasTail1[i][N]][MasTail1[i][M]] = tail1;
                            }
                            ++long1;
                            Snake1N = max(Snake1N - 1, 1);
                            (Field[Snake1N][Snake1M] = head1);
                            MasTail1[0][N] = Snake1N; MasTail1[0][M] = Snake1M;

                        }

                    } else if (arrowKey == 80) { // Вниз
                        if (Field[Snake1N + 1][Snake1M] == head2 || Field[Snake1N + 1][Snake1M] == wall_user ||
                            Field[Snake1N + 1][Snake1M] == tail1 || Field[Snake1N + 1][Snake1M] == tail2 || Field[Snake1N + 1][Snake1M] == '/') {
                            alive1 = false;
                        }
                        Field[Snake1N][Snake1M] = ' ';
                        Snake1N = min(Snake1N + 1, n);
                        (Field[Snake1N][Snake1M] = head1);
                    } else if (arrowKey == 75) { // Влево
                        if (Field[Snake1N][Snake1M - 1] == head2 || Field[Snake1N][Snake1M - 1] == wall_user ||
                            Field[Snake1N][Snake1M - 1] == tail1 || Field[Snake1N][Snake1M - 1] == tail2 || Field[Snake1N][Snake1M - 1] == '/') {
                            alive1 = false;
                        }
                        Field[Snake1N][Snake1M] = ' ';
                        Snake1M = max(Snake1M - 1, 1);
                        (Field[Snake1N][Snake1M] = head1);
                    } else if (arrowKey == 77) { // Вправо
                        if (Field[Snake1N][Snake1M + 1] == head2 || Field[Snake1N][Snake1M + 1] == wall_user ||
                            Field[Snake1N][Snake1M + 1] == tail1 || Field[Snake1N][Snake1M + 1] == tail2 || Field[Snake1N][Snake1M + 1] == '/') {
                            alive1 = false;
                        }
                        Field[Snake1N][Snake1M] = ' ';
                        Snake1M = min(Snake1M + 1, m);
                        (Field[Snake1N][Snake1M] = head1);
                    }
                }
            }
            if (input == 'w'){
                if (Field[Snake2N - 1][Snake2M] == head1 || Field[Snake2N - 1][Snake2M] == wall_user ||
                    Field[Snake2N - 1][Snake2M] == tail1 || Field[Snake2N - 1][Snake2M] == tail2 || Field[Snake2N - 1][Snake2M] == '/') {
                    alive2 = false;
                }

            }
            else if(input == 's'){
                if (Field[Snake2N + 1][Snake2M] == head1 || Field[Snake2N + 1][Snake2M] == wall_user ||
                    Field[Snake2N + 1][Snake2M] == tail1 || Field[Snake2N + 1][Snake2M] == tail2 || Field[Snake2N + 1][Snake2M] == '/') {
                    alive2 = false;
                }

            }
            else if(input=='a'){
                if (Field[Snake2N][Snake2M - 1] == head1 || Field[Snake2N][Snake2M - 1] == wall_user ||
                    Field[Snake2N][Snake2M - 1] == tail1 || Field[Snake2N][Snake2M - 1] == tail2 || Field[Snake2N][Snake2M - 1] == '/') {
                    alive2 = false;
                }

            }
            else if(input=='d'){
                if (Field[Snake2N][Snake2M + 1] == head1 || Field[Snake2N][Snake2M + 1] == wall_user ||
                    Field[Snake2N][Snake2M + 1] == tail1 || Field[Snake2N][Snake2M + 1] == tail2 || Field[Snake2N][Snake2M + 1] == '/') {
                    alive2 = false;
                }

            }


        }

        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < m + 2; j++) {
                cout << setw(2) << Field[i][j] << ' ';
            }
            cout << endl;
        }
        system("pause");

    }
    system("cls");
    cout << "END" << endl;
    system("pause");

    return 0;

}