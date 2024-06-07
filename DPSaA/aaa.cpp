#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct fcs {
    std::string forname;
    std::string name;
    std::string surname;
};

// Функция сравнения для сортировки
bool compare(const fcs &a, const fcs &b) {
    // if (a.name != b.name) {
    //     return a.surname < b.surname;
    // }
    if (a.name != b.name) {
        return a.name < b.name;
    }
    return a.forname < b.forname;
}

void bubbleSort(std::vector<fcs> &people) {
    bool swapped;
    for (size_t i = 0; i < people.size() - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < people.size() - i - 1; ++j) {
            if (!compare(people[j], people[j + 1])) {
                for (const auto &person : people) {
        std::cout << person.surname << " " << person.name << " " << person.forname << "\n" << std::endl;
    }
                std::swap(people[j], people[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    // Создаем вектор структур fcs
    setlocale(LC_ALL, "Russian");
    std::vector<fcs> people = {
        {"Федорушкин", "Станислав", "Алексеевич"},
        {"Федорушкин", "Алексей", "Дмитриевич"},
        {"Квашнев", "Егор", "Александрович"},
        {"Кривощеков", "Александр", "Александрович"}
    };

    // Сортируем вектор с использованием функции compare
    bubbleSort(people);

    // Выводим отсортированный вектор
    for (const auto &person : people) {
        std::cout << person.surname << " " << person.name << " " << person.forname << std::endl;
    }

    return 0;
}
