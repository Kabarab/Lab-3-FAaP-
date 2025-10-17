#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <sstream>

using namespace std;

string vivod(long double number, int n) {
    stringstream ss;
    ss << setprecision(20) << number;
    string vivod_str = ss.str();

    if (vivod_str.length() >= n) {
        return vivod_str.substr(0, n);
    }

    while (vivod_str.length() < n) {
        vivod_str += ' ';
    }

    return vivod_str;
}


double get_double_value()
{
    double value;
    while (!(cin >> value))
    {
        cout << "Некорректное значение. Пожалуйста, введите число." << endl;
        cout << "Введите значение снова: " << endl;

        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return value;
}
int get_int_value()
{
    int value;
    while (!(cin >> value))
    {
        cout << "Некорректное значение." << endl;
        cout << "Значение должно быть целым числом." << endl;
        cout << "Введите значение снова:" << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return value;
}


int main() {
    long double a, b, h, sx, yx;
    int n;
    cout << "Введите верхний предел n: ";
    n = get_int_value();
    cout << "Enter the value of a: ";
    a = get_double_value();
    cout << "Enter the value of b: ";
    b = get_double_value();
    cout << "Enter the value of h: ";
    h = get_double_value();

    cout << "|       x      |     S(x)     |             Y(x)             |         Y(x)-S(x)            |" << endl;
    for (; a < b; a += h)
    {

        if (n > 0) {
            long double current = 1.0;
            sx = current;

            for (int k = 1; k < n; k++) {
                current = current * (-a * a) / ((2 * k - 1) * (2 * k));
                sx += current;
            }
        }
        else {
            sx = 0;
        }

        yx = cos(a);

        cout << "|     " << vivod(a, 7) << "  " << "|    " << vivod(sx, 7) << "   " << "|         " << vivod(yx, 12) << "         " << "|     " << vivod(fabs(yx - sx), 20) << "     |" << endl;
    }
    return 0;
}