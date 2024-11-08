#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SIGN {
private:
    string lastName;
    string firstName;
    string zodiacSign;
    int birthDate[3];

public:
    SIGN() : lastName(""), firstName(""), zodiacSign("") 
    {
        birthDate[0] = birthDate[1] = birthDate[2] = 0;
    }

    string getLastName() const 
    {
        return lastName;
    }

    string getFirstName() const 
    {
        return firstName;
    }

    string getZodiacSign() const 
    {
        return zodiacSign;
    }

    const int* getBirthDate() const 
    {
        return birthDate;
    }

    friend istream& operator>>(istream& in, SIGN& sign) 
    {
        cout << "Введите фамилию: ";
        in >> sign.lastName;
        cout << "Введите имя: ";
        in >> sign.firstName;
        cout << "Введите знак зодиака: ";
        in >> sign.zodiacSign;
        cout << "Введите день рождения (день месяц год): ";
        in >> sign.birthDate[0] >> sign.birthDate[1] >> sign.birthDate[2];
        return in;
    }

    friend ostream& operator<<(ostream& out, const SIGN& sign) 
    {
        out << "Фамилия: " << sign.lastName
            << ", Имя: " << sign.firstName
            << ", Знак зодиака: " << sign.zodiacSign
            << ", Дата рождения: " << sign.birthDate[0] << " "
            << sign.birthDate[1] << " " << sign.birthDate[2];
        return out;
    }

    bool operator<(const SIGN& other) const 
    {
        if (birthDate[2] != other.birthDate[2])
            return birthDate[2] < other.birthDate[2];
        if (birthDate[1] != other.birthDate[1])
            return birthDate[1] < other.birthDate[1];
        return birthDate[0] < other.birthDate[0];
    }
};

void sortSigns(vector<SIGN>& signs)
{
    for (size_t i = 0; i < signs.size() - 1; ++i) 
    {
        for (size_t j = 0; j < signs.size() - i - 1; ++j) 
        {
            if (signs[j] < signs[j + 1]) 
            {
                swap(signs[j], signs[j + 1]);
            }
        }
    }
}

int main() 
{
    vector<SIGN> signs;
    int n;
    cout << "Введите количество записей: ";
    cin >> n;
    signs.resize(n);
    
    for (int i = 0; i < n; ++i) 
    {
        cin >> signs[i];
    }

    sortSigns(signs);

    cout << "Отсортированные записи: " << endl;
    for (const auto& sign : signs) 
    {
        cout << sign << endl;
    }

    string searchLastName;
    cout << "Введите фамилию для поиска: ";
    cin >> searchLastName;
    for (const auto& sign : signs) 
    {
        if (sign.getLastName() == searchLastName) 
        {
            cout << sign << endl;
        }
    }

    return 0;
}