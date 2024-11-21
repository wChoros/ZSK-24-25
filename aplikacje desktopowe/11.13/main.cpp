#include <iostream>
#include <cmath>

class Punkt {
private:
    float x;
    float y;
public:
    // Konstruktor domyślny
    Punkt() : x(0), y(0) {}

    // Konstruktor główny
    Punkt(float x, float y) : x(x), y(y) {}

    // Konstruktor kopiujący
    Punkt(const Punkt& other) : x(other.x), y(other.y) {}

    // Gettery
    float getX() const { return x; }
    float getY() const { return y; }

    // Settery
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }

    // Funkcja obliczająca długość wektora
    float dlugoscWektora() const {
        return std::sqrt(x * x + y * y);
    }

    // Przeciążenie operatora +
    Punkt operator+(const Punkt& other) const {
        return Punkt(x + other.x, y + other.y);
    }

    // Przeciążenie operatora -
    Punkt operator-(const Punkt& other) const {
        return Punkt(x - other.x, y - other.y);
    }

    // Przeciążenie operatora * (iloczyn skalarny)
    float operator*(const Punkt& other) const {
        return x * other.x + y * other.y;
    }

    // Przeciążenie operatora przypisania =
    Punkt& operator=(const Punkt& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    // Przeciążenie operatora << dla cout
    friend std::ostream& operator<<(std::ostream& os, const Punkt& punkt) {
        os << "(" << punkt.x << ", " << punkt.y << ")";
        return os;
    }
};

class Wielokat {
private:
    Punkt* wierzcholki;
    int ileWierzcholkow;
public:
    // Konstruktor domyślny
    Wielokat() : wierzcholki(nullptr), ileWierzcholkow(0) {}

    // Konstruktor główny
    Wielokat(int ileWierzcholkow, const Punkt* wierzcholkiArray) : ileWierzcholkow(ileWierzcholkow) {
        if (ileWierzcholkow >= 3) {
            wierzcholki = new Punkt[ileWierzcholkow];
            for (int i = 0; i < ileWierzcholkow; ++i) {
                wierzcholki[i] = wierzcholkiArray[i];
            }
        } else {
            this->ileWierzcholkow = 0;
            wierzcholki = nullptr;
        }
    }

    // Konstruktor kopiujący
    Wielokat(const Wielokat& other) : ileWierzcholkow(other.ileWierzcholkow) {
        if (ileWierzcholkow > 0) {
            wierzcholki = new Punkt[ileWierzcholkow];
            for (int i = 0; i < ileWierzcholkow; ++i) {
                wierzcholki[i] = other.wierzcholki[i];
            }
        } else {
            wierzcholki = nullptr;
        }
    }

    // Destruktor
    ~Wielokat() {
        delete[] wierzcholki;
    }

    // Gettery
    int getIleWierzcholkow() const { return ileWierzcholkow; }

    Punkt getWierzcholek(int index) const {
        if (index >= 0 && index < ileWierzcholkow) {
            return wierzcholki[index];
        } else {
            std::cerr << "Błędny indeks wierzchołka!" << std::endl;
            return Punkt();
        }
    }

    // Settery
    void setWierzcholek(int index, const Punkt& punkt) {
        if (index >= 0 && index < ileWierzcholkow) {
            wierzcholki[index] = punkt;
        } else {
            std::cerr << "Błędny indeks wierzchołka!" << std::endl;
        }
    }

    // Funkcja obliczająca pole wielokąta (wzór Gaussa)
    float obliczPole() const {
        if (ileWierzcholkow < 3) return 0.0f;
        float pole = 0.0f;
        for (int i = 0; i < ileWierzcholkow; ++i) {
            float x1 = wierzcholki[i].getX();
            float y1 = w    ierzcholki[i].getY();
            float x2 = wierzcholki[(i + 1) % ileWierzcholkow].getX();
            float y2 = wierzcholki[(i + 1) % ileWierzcholkow].getY();
            pole += (x1 * y2 - x2 * y1);
        }
        return std::abs(pole) / 2.0f;
    }

    // Przeciążenie operatora przypisania =
    Wielokat& operator=(const Wielokat& other) {
        if (this != &other) {
            delete[] wierzcholki;
            ileWierzcholkow = other.ileWierzcholkow;
            if (ileWierzcholkow > 0) {
                wierzcholki = new Punkt[ileWierzcholkow];
                for (int i = 0; i < ileWierzcholkow; ++i) {
                    wierzcholki[i] = other.wierzcholki[i];
                }
            } else {
                wierzcholki = nullptr;
            }
        }
        return *this;
    }

    // Przeciążenie operatora << dla cout
    friend std::ostream& operator<<(std::ostream& os, const Wielokat& wielokat) {
        os << "Wielokąt o " << wielokat.ileWierzcholkow << " wierzchołkach: ";
        for (int i = 0; i < wielokat.ileWierzcholkow; ++i) {
            os << wielokat.wierzcholki[i] << " ";
        }
        return os;
    }
};

int main() {
    // Testowanie klasy Punkt
    Punkt p1; // Konstruktor domyślny
    Punkt p2(3.0f, 4.0f); // Konstruktor główny
    Punkt p3 = p2; // Konstruktor kopiujący

    // Wyświetlanie punktów
    std::cout << "Punkt p1: " << p1 << std::endl;
    std::cout << "Punkt p2: " << p2 << std::endl;
    std::cout << "Punkt p3: " << p3 << std::endl;

    // Testowanie metod
    std::cout << "Długość wektora p2: " << p2.dlugoscWektora() << std::endl;

    // Przeciążone operatory
    Punkt suma = p2 + p3;
    Punkt roznica = p2 - p3;
    float iloczynSkalarny = p2 * p3;

    std::cout << "Suma p2 + p3: " << suma << std::endl;
    std::cout << "Różnica p2 - p3: " << roznica << std::endl;
    std::cout << "Iloczyn skalarny p2 * p3: " << iloczynSkalarny << std::endl;

    // Testowanie klasy Wielokat
    Punkt wierzcholki[] = {Punkt(0.0f, 0.0f), Punkt(4.0f, 0.0f), Punkt(4.0f, 3.0f)};
    Wielokat trojkat(3, wierzcholki);

    std::cout << trojkat << std::endl;
    std::cout << "Pole trójkąta: " << trojkat.obliczPole() << std::endl;

    // Zmiana wierzchołka
    trojkat.setWierzcholek(2, Punkt(4.0f, 4.0f));
    std::cout << "Po zmianie wierzchołka: " << trojkat << std::endl;
    std::cout << "Nowe pole trójkąta: " << trojkat.obliczPole() << std::endl;

    return 0;
}
