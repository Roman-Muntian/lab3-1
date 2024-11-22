#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Rhombus {
private:
    double side;        // Сторона ромба
    double diagonal1;   // Перша діагональ
    double diagonal2;   // Друга діагональ
    string color;       // Колір

public:
    // Конструктор за замовчуванням
    Rhombus() : side(1.0), diagonal1(1.0), diagonal2(1.0), color("Red") {}

    // Конструктор із параметрами
    Rhombus(double s, double d1, double d2, string c) {
        setSide(s);
        setDiagonals(d1, d2);
        setColor(c);
    }

    // Функції встановлення
    void setSide(double s) {
        if (s > 0) {
            side = s;
        }
        else {
            cout << "Error: Invalid side value\n";
        }
    }

    void setDiagonals(double d1, double d2) {
        if (d1 > 0 && d2 > 0) {
            diagonal1 = d1;
            diagonal2 = d2;
        }
        else {
            cout << "Error: Invalid diagonal values\n";
        }
    }

    void setColor(const string& c) {
        if (!c.empty()) {
            color = c;
        }
        else {
            cout << "Error: Invalid color value\n";
        }
    }

    // Функції отримання
    double getSide() const { return side; }
    double getDiagonal1() const { return diagonal1; }
    double getDiagonal2() const { return diagonal2; }
    string getColor() const { return color; }

    // Функція обчислення площі
    double area() const {
        return (diagonal1 * diagonal2) / 2.0;
    }

    // Функція обчислення периметру
    double perimeter() const {
        return 4 * side;
    }

    // Функція друку інформації
    void printInfo() const {
        cout << "Rhombus:\n"
            << "  Side: " << side << "\n"
            << "  Diagonal 1: " << diagonal1 << "\n"
            << "  Diagonal 2: " << diagonal2 << "\n"
            << "  Color: " << color << "\n"
            << "  Area: " << area() << "\n"
            << "  Perimeter: " << perimeter() << "\n";
    }
};

int main() {
    // Тестування класу
    Rhombus r1; // Створення об'єкта за замовчуванням
    r1.printInfo();

    Rhombus r2(5.0, 6.0, 8.0, "Blue"); // Створення об'єкта з параметрами
    r2.printInfo();

    // Тестування функцій встановлення
    Rhombus r3;
    r3.setSide(4.5);
    r3.setDiagonals(7.0, 9.0);
    r3.setColor("Green");
    r3.printInfo();

    // Тестування перевірки некоректних даних
    r3.setSide(-1.0);   // Некоректне значення сторони
    r3.setDiagonals(-2.0, 3.0); // Некоректні діагоналі
    r3.setColor(""); // Некоректний колір
    r3.printInfo();

    return 0;
}
