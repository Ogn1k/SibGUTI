#include <vector>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <unordered_set>

struct Objaga
{
    int roomNum;
    int roomS;
    std::string faculty;
    int residents;

    Objaga(int number, double roomArea, const std::string& fac, int numOfResidents) : 
        roomNum(number), roomS(roomArea), faculty(fac), residents(numOfResidents) {}
};

struct School
{
    int schoolNumber;
    int graduates;
    int enrolledInUniversity;
    double percentage;

    School(int number, int grads, int enrolled) : schoolNumber(number), graduates(grads), enrolledInUniversity(enrolled) 
    {
        percentage = (double)enrolledInUniversity / graduates * 100;
    }
};

int main()
{
    srand(time(NULL));
    //1
    {
        std::vector<School> schools = 
        {
        {1, 100, 80}, 
        {2, 120, 90},
        {3, 80, 60},
        {4, 150, 120}
        };

        std::sort(schools.begin(), schools.end(), [](const School& a, const School& b){ return a.percentage > b.percentage; });

        for (const auto& school : schools) 
            std::cout << "num " << school.schoolNumber << " grad " << school.graduates 
                << " proc " << school.percentage << "%" << std::endl;
    }
    //2
    {
        std::vector<Objaga> rooms = 
        {
            {101, 20.5, "IT", 3},
            {102, 18.0, "Phys", 2},
            {103, 22.5, "IT", 4},
            {104, 16.8, "Chem", 2},
            {105, 19.3, "Phys", 3},
            {106, 21.0, "IT", 2},
            {107, 17.6, "Chem", 2}
        };

        std::unordered_set<std::string> faculties;
        for (const auto& room : rooms) 
        {
            faculties.insert(room.faculty);
        }

        std::cout << faculties.size() << std::endl;

        // Вывод статистики по каждому факультету
        for (const auto& faculty : faculties) {
            int numRooms = 0, numResidents = 0;
            double totalArea = 0;
            for (const auto& room : rooms) {
                if (room.faculty == faculty) {
                    numRooms++;
                    numResidents += room.residents;
                    totalArea += room.roomS;
                }
            }
            double avgSPerRes = totalArea / numResidents;
            std::cout << "fac " << faculty << " numRooms " << numRooms << " numStudents " << numResidents
                    << " avgSPerRes " << avgSPerRes << std::endl;
        }
    }
    return 0;
}   