#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void pole(char poler[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << poler[i][j];
            cout << "|";
        }
        cout << endl;
        cout << " -----" << endl;
    }
}
char winnerIs(char poler[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (poler[i][0] == poler[i][1] && poler[i][1] == poler[i][2] && poler[i][0] != ' ')
            return poler[i][0];
    }
    for (int j = 0; j < 3; j++)
    {
        if (poler[0][j] == poler[1][j] && poler[1][j] == poler[2][j] && poler[0][j] != ' ')
            return poler[0][j];
    }
    if (poler[0][0] == poler[1][1] && poler[1][1] == poler[2][2] && poler[0][0] != ' ')
        return poler[0][0];
    if (poler[0][2] == poler[1][1] && poler[1][1] == poler[2][0] && poler[0][2] != ' ')
        return poler[0][2];
    else
        return ' ';
}
bool isFull(char poler[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (poler[i][j] == ' ')
                return false;
            else true;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int row, col;
    char poler[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '}, {' ', ' ', ' '}};
    char player1 = 'X';
    char player2 = '0';
    while (true) {
        pole(poler);
        cout << player1 << " походи: ";
        cin >> row >> col;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && poler[row][col] == ' ')
        {
            poler[row][col] = player1;
        }
        else {
            cout << "выбери другую клеточку";
            continue;
        }
        char winner = winnerIs(poler);
        if (winner != ' ')
        {
            pole(poler);
            cout << winner << " выиграл";
            break;
        }
        if (isFull(poler))
        {
            cout << "игра закончилась ничьей";
            break;
        }
        player1 = (player1 == 'X') ? '0' : 'X';
    }
}







//1рисунок матрицы, 2чек кто победил, 3проверка заполнения поля
//1)сначала проходим по всем ячейкам массива, чтоб вывести. выводим х или 0. добавление разделялки
//2)чекаем победителя: проходимся по строчкам, нужным для победы и ретерн того, кто победил, потом также со столбиками, потом также с диагоналями, если победителя нет, то ниче не выводим
//3)проверка заполнения: проверяем если есть пустая клеточка, то ретерен фолс, элс тру

//row это строчка, col столбик