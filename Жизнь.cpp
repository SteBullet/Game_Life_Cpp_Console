#include <iostream>

using namespace std;

int NeighborsInf(int h, int l, int i, int j, bool** a) //Для бесконечного поля
//Планировка матрицы:
//922223
//811114
//811114
//811114
//766665
{
    if (i > 1 && i < h && j > 1 && j < l)
        return a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];//Группа 1
    if (i == 1 && j > 1 && j < l)
        return a[h][j - 1] + a[h][j] + a[h][j + 1] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];//Группа 2
    if (i == 1 && j == l)
        return a[h][j - 1] + a[h][j] + a[h][1] + a[i][j - 1] + a[i][1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][1];//Группа 3
    if (i > 1 && i < h && j == l)
        return a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][1] + a[i][j - 1] + a[i][1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][1];//Группа 4
    if (i == h && j == l)
        return a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][1] + a[i][j - 1] + a[i][1] + a[1][j - 1] + a[1][j] + a[1][1];//Группа 5
    if (i == h && j > 1 && j < l)
        return a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] + a[i][j + 1] + a[1][j - 1] + a[1][j] + a[1][j + 1];//Группа 6
    if (i == h && j == 1)
        return a[i - 1][l] + a[i - 1][j] + a[i - 1][j + 1] + a[i][l] + a[i][j + 1] + a[1][l] + a[1][j] + a[1][j + 1];//Группа 7
    if (i > 1 && i < h && j == 1)
        return a[i - 1][l] + a[i - 1][j] + a[i - 1][j + 1] + a[i][l] + a[i][j + 1] + a[i + 1][l] + a[i + 1][j] + a[i + 1][j + 1];//Группа 8
    if (i == 1 && j == 1)
        return a[h][l] + a[h][j] + a[h][j + 1] + a[i][l] + a[i][j + 1] + a[i + 1][l] + a[i + 1][j] + a[i + 1][j + 1];//Группа 9
}

int NeighborsClose(int h, int l, int i, int j, bool** a) //Для ограниченного поля
{
    return a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
}

void GenerationInf(int h, int l, bool** a, bool** b) //Для бесконечного поля
{
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= l; j++)
            if (a[i][j] == 0)
            {
                if (NeighborsInf(h, l, i, j, a) == 3)
                    b[i][j] = 1;
            }
            else
                if (NeighborsInf(h, l, i, j, a) == 2 || NeighborsInf(h, l, i, j, a) == 3)
                    b[i][j] = 1;
                else
                    b[i][j] = 0;
}

void GenerationClose(int h, int l, bool** a, bool** b) //Для ограниченного поля
{
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= l; j++)
            if (a[i][j] == 0)
            {
                if (NeighborsClose(h, l, i, j, a) == 3)
                    b[i][j] = 1;
            }
            else
                if (NeighborsClose(h, l, i, j, a) == 2 || NeighborsClose(h, l, i, j, a) == 3)
                    b[i][j] = 1;
                else
                    b[i][j] = 0;
}

void Transfer(int h, int l, bool** a, bool** b)
{
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= l; j++)
        {
            a[i][j] = b[i][j];
            b[i][j] = 0;
        }
}

void PrintBin(int h, int l, bool** a) //Вывод 0 и 1
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            cout.width(2);
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}

void PrintSmile(int h, int l, bool** a) //Вывод смайликами
{
    char z;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            if (a[i][j])
                z = 1;
            else
                z = 150;
            cout.width(2);
            cout << z;
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}

int main()
{
    setlocale(0, "");
    int l, h, c, d = 2;
    bool s, in;
    cout << "Введите размеры игрового поля (сначала количество строк, затем столбцов): ";
    cin >> h >> l;
    bool** a;
    bool** b;
    a = new bool* [h + 2];
    b = new bool* [h + 2];
    for (int i = 0; i < h + 2; i++)
    {
        a[i] = new bool[l + 2];
        b[i] = new bool[l + 2];
    }
    cout << "Выберите настройки поля (1 - бесконечное, 0 - ограниченное): ";
    cin >> in;
    s = 0;
    //cout << "Выберите настройки вывода (1 - цифрами, 0 - смайликами): ";
    //cin >> s;
    cout << "Как вы хотите ввести первое поколение? 1 - построчно, 0 - задать координаты живых клеток: ";
    cin >> c;
    if (c == 1)
    {
        cout << "Введите первое поколение построчно (1 - жизнь, 0 - ее отсутствие)" << endl;
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= l; j++)
                cin >> a[i][j];
        for (int i = 0; i < h + 2; i++)
        {
            a[i][0] = 0;
            a[i][l + 1] = 0;
        }
        for (int i = 0; i < l + 2; i++)
        {
            a[0][i] = 0;
            a[h + 1][i] = 0;
        }
        cout << "Первое поколение:" << endl;
        if (s)
            PrintBin(h, l, a);
        else
            PrintSmile(h, l, a);
    }
    else
    {
        cout << "Введите координаты живых клеток (сначала строка, затем столбец; по одной клетке в строке; 0 0 - конец ввода; повторный ввод одной и той же клетки убивает ее):" << endl;
        for (int i = 0; i < h + 2; i++)
            for (int j = 0; j < l + 2; j++)
                a[i][j] = 0;
        while (c != 0 || d != 0)
        {
            cin >> c >> d;
            a[c][d] = !a[c][d];
        }
        cout << "Первое поколение:" << endl;
        if (s)
            PrintBin(h, l, a);
        else
            PrintSmile(h, l, a);
    }
    for (int i = 0; i < h + 2; i++)
        for (int j = 0; j < l + 2; j++)
            b[i][j] = 0;
    cout << "Введите количество поколений: ";
    cin >> c;
    for (d = 1; d <= c; d++)
    {
        if (in)
            GenerationInf(h, l, a, b);
        else
            GenerationClose(h, l, a, b);
        Transfer(h, l, a, b);
        cout << "Поколение " << d + 1 << endl;
        if (s)
            PrintBin(h, l, a);
        else
            PrintSmile(h, l, a);
    }
    for (int i = 0; i < h + 2; i++)
    {
        delete[]a[i];
        delete[]b[i];
    }
    delete[]a;
    delete[]b;
    return 0;
}