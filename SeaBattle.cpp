/*    
 *    Задача № 32 (SeaBattle)
 *    Кравцов Олег, статистика 2
 *    Файл основної програми 
 */  


#include "SeaBattle.h"

enum ConsoleColor
{
    Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
    LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

int random_int(int a, int b)
{
    return rand() % (b - a) + a;
}

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int** Field::create_cells(int rows, int cols)
{
    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];

        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = 0;
        }
    }

    return arr;
}

Field::Field()
{
    rows = 10;
    cols = 10;
    cells = create_cells(rows, cols);
    x_pos = random_int(0, rows);
    y_pos = random_int(0, cols);
    cells[x_pos][y_pos] = 1;
}

int Field::getRows()
{
    return rows;
}

int Field::getCols()
{
    return cols;
}

int Field::get_x_pos()
{
    return x_pos;
}

int Field::get_y_pos()
{
    return y_pos;
}

int Field::get_cell(int x, int y)
{
    return cells[x][y];
}

void Field::set_cell(int x, int y, int value)
{
    cells[x][y] = value;
}


void Field::set_field()
{
    int rows, cols, x, y;
    cout << "Rows = ";
    cin >> rows;
    cout << "Cols = ";
    cin >> cols;
    cout << "Vertical pos of ship x = ";
    cin >> x;
    cout << "Horisontal pos of ship y = ";
    cin >> y;

    while ((x < 0 || x >= rows) && (y < 0 || y >= cols))
    {
        cout << "Incorrect data, try again";
        cout << "Vertical pos of ship x = ";
        cin >> x;
        cout << "Horisontal pos of ship y = ";
        cin >> y;
    }

    this->rows = rows;
    this->cols = cols;
    cells = create_cells(rows, cols);
    cells[x - 1][y - 1] = 1;
    x_pos = x - 1;
    y_pos = y - 1;
}

void Field::set_field(int rows, int cols)
{
    if (rows < 0)
        rows = random_int(7, 100);
    if (cols < 0)
        cols = random_int(7, 100);
    this->rows = rows;
    this->cols = cols;
    cells = create_cells(rows, cols);
}

void Field::set_ship(int x, int y)
{
    if (x < 0 || x >= rows)
        x = random_int(0, rows - 1);
    if (y < 0 || y >= cols)
        y = random_int(0, cols - 1);
    cells[x_pos][y_pos] = 0;
    cells[x][y] = 1;
    x_pos = x;
    y_pos = y;
}

void Field::print_field()
{
    cout << "\n";
    SetColor(14, 0);
    cout << "\t\t\t    ";
    for (int i = 1;i <= cols;++i)
        cout << i << "  ";
    cout << "\n";
    cout << "\t\t\t   ";
    for (int i = 0;i <= cols * 3;++i)
        cout << "_";
    cout << "\n";
    for (int i = 0;i < rows;++i)
    {
        cout << "\t\t\t";
        for (int j = 0;j < cols;++j)
        {
            if (j == 0 && i < 9) cout << " " << i + 1 << "|";
            else if (j == 0 && i >= 9) cout << i + 1 << "|";
            if (cells[i][j] == 0)
            {
                SetColor(10, 0);
                cout << " * ";
            }
            else if (cells[i][j] == 1)
            {
                SetColor(7, 0);
                cout << " # ";
            }
            else if (cells[i][j] == 2)
            {
                SetColor(12, 0);
                cout << " X ";
            }
            SetColor(14, 0);
        }
        cout << "\n";
    }
}

bool Field::isShot(int x, int y)
{
    if (cells[x][y] == 1) return true;
    else cells[x][y] = 2; return false;
}

int Field::distance_l1(int x, int y)
{
    return abs(x_pos - x) + abs(y_pos - y);
}

bool Field::possible_to_shoot(int x, int y)
{
    if (x < 0 || x > getRows())
        return false;
    else if (y < 0 || y > getCols())
        return false;
    else if (cells[x][y] == 2)
        return false;
    return true;
}

Field::~Field()
{
    //dtor
}


Player::Player()
{
    field = new Field();
    field->set_field();
    enemy_field = new Field();
    enemy_field->set_field(field->getRows(), field->getCols());
}

Player::Player(int rows, int cols)
{
    field = new Field();
    field->set_field(rows, cols);
    int x_pos = random_int(0, field->getRows());
    int y_pos = random_int(0, field->getCols());
    field->set_ship(x_pos, y_pos);
    enemy_field = new Field();
    enemy_field->set_field(rows, cols);
}

bool Player::moveShip(int x, int y)
{
    int x_pos = field->get_x_pos();
    int y_pos = field->get_y_pos();
    if (abs(x_pos - x) > 1 || abs(y_pos - y) > 1)
    {
        return false;
    }
    else if (x < 0 || x >= field->getRows() || y < 0 || y >= field->getCols())
    {
        return false;
    }
    else if (field->get_cell(x, y) == 2)
    {
        return false;
    }
    field->set_ship(x, y);
    return true;
}

void Player::autoMove()
{
    int x, y, x1, x2, y1, y2;
    x = field->get_x_pos();
    y = field->get_y_pos();
    x1 = x + 1;
    x2 = x - 1;
    y1 = y + 1;
    y2 = y - 1;
    bool done = false;
    while (!done)
    {
        int option = random_int(1, 10);
        if (option == 1)
            done = moveShip(x, y);
        else if (option == 2)
            done = moveShip(x1, y);
        else if (option == 3)
            done = moveShip(x, y1);
        else if (option == 4)
            done = moveShip(x2, y);
        else if (option == 5)
            done = moveShip(x, y2);
        else if (option == 6)
            done = moveShip(x1, y1);
        else if (option == 7)
            done = moveShip(x2, y1);
        else if (option == 8)
            done = moveShip(x1, y2);
        else if (option == 9)
            done = moveShip(x2, y2);
    }
}

Player::~Player()
{
    //dtor
}

void play()
{
    bool finished = false;
    bool playerTurn = true;
    Player* human = new Player();
    Player* computer = new Player(human->field->getRows(), human->field->getCols());
    int option;
    bool smart;
    int dist1 = 0;
    int dist2 = random_int(2, computer->field->getRows() / 2);;
    int last_x = random_int(0, computer->field->getRows());
    int last_y = random_int(0, computer->field->getCols());
    cout << "Press 0 if you want to play with smart computer otherwise press smth else: ";
    cin >> option;
    if (option == 0) smart = true;
    else smart = false;

    while (!finished)
    {
        system("cls");
        SetColor(14, 0);
        cout << "Human field" << endl;
        cout << endl;
        human->field->print_field();
        cout << endl;
        cout << "Computer field" << endl;
        human->enemy_field->print_field();
        cout << endl;
        if (playerTurn)
        {
            int x, y;
            cout << "Current turn: human" << endl;
            cout << "Last distance from enemy ship: " << dist1 << endl;
            cout << "Move your ship, if you don't want to, just enter current position" << endl;
            cout << "x = ";
            cin >> x;
            cout << "y = ";
            cin >> y;
            bool done = human->moveShip(x - 1, y - 1);
            while (!done)
            {
                cout << "Impossible to move this way" << endl;
                cout << "x = ";
                cin >> x;
                cout << "y = ";
                cin >> y;
                done = human->moveShip(x - 1, y - 1);
            }
            system("cls");
            cout << "Human field" << endl;
            cout << endl;
            human->field->print_field();
            cout << endl;
            cout << "Computer field" << endl;
            human->enemy_field->print_field();
            cout << endl;
            cout << "Let's shoot!" << endl;
            cout << "x = ";
            cin >> x;
            cout << "y = ";
            cin >> y;
            bool possible = human->enemy_field->possible_to_shoot(x - 1, y - 1);
            if (possible)
            {
                if (computer->field->isShot(x - 1, y - 1))
                    break;
            }
            human->enemy_field->set_cell(x - 1, y - 1, 2);
            computer->field->set_cell(x - 1, y - 1, 2);
            dist1 = computer->field->distance_l1(x - 1, y - 1);
        }
        else
        {
            Sleep(1000);
            cout << "Current turn: computer" << endl;
            cout << "Last distance from enemy ship: " << dist2 << endl;
            computer->autoMove();
            cout << "Move done! I am shooting!" << endl;
            Sleep(5000);
            int x, y;
            if (smart)
            {
                int offset = random_int(0, dist2);
                int r = random_int(0, 10);
                int sign_x, sign_y;

                if (r > 5) sign_x = -1;
                else sign_x = 1;

                r = random_int(0, 10);

                if (r > 5) sign_y = -1;
                else sign_y = 1;

                x = last_x + offset * sign_x;
                y = last_y + (dist2 - offset) * sign_y;
                int i = 0;
                while (!computer->enemy_field->possible_to_shoot(x, y))
                {
                    if (i < 500)
                    {
                        offset = random_int(0, dist2);
                        r = random_int(0, 10);

                        if (r > 5) int sign_x = -1;
                        else int sign_x = 1;
                        r = random_int(0, 10);
                        if (r > 5) int sign_y = -1;
                        else int sign_y = 1;

                        x = last_x + offset * sign_x;
                        y = last_y + (dist2 - offset) * sign_y;
                    }
                    else
                    {
                        x = random_int(0, computer->field->getRows());
                        y = random_int(0, computer->field->getCols());
                    }
                    i += 1;
                }
                last_x = x;
                last_y = y;
            }
            else
            {
                x = random_int(0, computer->field->getRows());
                y = random_int(0, computer->field->getCols());

                while (!computer->enemy_field->possible_to_shoot(x, y))
                {
                    x = random_int(0, computer->field->getRows());
                    y = random_int(0, computer->field->getCols());
                }
            }

            if (human->field->isShot(x, y))
                break;

            computer->enemy_field->set_cell(x, y, 2);
            human->field->set_cell(x, y, 2);
            dist2 = human->field->distance_l1(x, y);
        }
        playerTurn = !playerTurn;
    }
    system("cls");
    if (playerTurn) cout << "Human won this game!";
    else cout << "Computer won this game";
}
