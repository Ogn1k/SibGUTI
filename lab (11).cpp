#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>

struct Passenger
{
    std::string name;
    int bag_count;
    double total_weight;
};

void CreateFile( const std::string& file_name, int N )
{
    std::ofstream file( file_name );
    
    if( !file )
    {
        std::cerr << "file create error";
        return;
    }

    for( int i = 0; i < N; i++ )
    {
        Passenger passenger;

        std::cout << i+1 << ". fio, bags, weight: ";
        std::cin.ignore();
        //std::getline( std::cin, passenger.name );
        //scanf("%s%d%lf", passenger.name.data(), &passenger.bag_count, &passenger.total_weight);
        std::cin >> passenger.name >> passenger.bag_count >> passenger.total_weight;
        file << passenger.name << " " << passenger.bag_count << " " << passenger.total_weight << "\n";
    }

    file.close();
}

void DisplayFile( const std::string& file_name )
{
    std::ifstream file( file_name );
    std::string line;

    if( !file )
    {
        std::cerr << "open error";
        return;
    }
    
    while( std::getline( file, line ) )
        std::cout << line << "\n";

    file.close();
}

void AppendToFile( const std::string& file_name )
{
    std::ofstream file( file_name, std::ios::app );
    Passenger passenger;

    if( !file )
    {
        std::cerr << "open error";
        return;
    }

    std::cout << "fio, bags, weight: ";
    std::cin.ignore();
    //std::getline( std::cin, passenger.name );
    //std::cin >> passenger.bag_count >> passenger.total_weight;
    std::cin >> passenger.name >> passenger.bag_count >> passenger.total_weight;
    file << passenger.name << " " << passenger.bag_count << " " << passenger.total_weight << "\n";

    file.close();
}

void RemoveUnderweightPassengers( const std::string& file_name, double weight_limit = 10 )
{
    std::ifstream file_in( file_name );
    
    std::vector<Passenger> passengers;
    Passenger passenger;

    if( !file_in )
    {
        std::cerr << "open error";
        return;
    }
    
    while( file_in >> passenger.name >> passenger.bag_count >> passenger.total_weight )
        if( passenger.total_weight >= weight_limit )
            passengers.push_back( passenger );
            
    file_in.close();

    std::ofstream file_out( file_name ); 
    
    for( const auto& ipassenger : passengers )
        file_out << ipassenger.name << " " << ipassenger.bag_count << " " << ipassenger.total_weight << "\n";
    
    file_out.close();
}

void SetPassengerWeight( const std::string& file_name, const std::string& name, double new_weight )
{
    std::ifstream file_in( file_name );
    
    std::vector<Passenger> passengers;
    Passenger passenger;

    if( !file_in )
    {
        std::cerr << "open error";
        return;
    }
    
    while( file_in >> passenger.name >> passenger.bag_count >> passenger.total_weight )
    {
        if( passenger.name == name )
            passenger.total_weight = new_weight;
        passengers.push_back(passenger);
    }

    file_in.close();

    std::ofstream file_out( file_name );

    for( const auto& i : passengers )
        file_out << i.name << " " << i.bag_count << " " << i.total_weight << "\n";

    file_out.close();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string file_name = "passengers.txt";

    char choice;
    do
    {
        std::cout << "1.создать  файл из N записей;\n";
        std::cout << "2.просмотреть файл;\n";
        std::cout << "3.добавить в конец файла новую запись;\n";
        std::cout << "4.найти и удалить из файла записи о пассажирах, общий вес вещей  которых   меньше, чем 10 кг.\n";
        std::cout << "5.изменить вес вещей пассажира по заданной фамилии.\n";
        std::cout << "6.выход\n";
        std::cin >> choice;

        switch (choice) {
            case '1': 
                int N;
                std::cout << "N: ";
                std::cin >> N;
                CreateFile( file_name, N );
                break;
            case '2':
                DisplayFile( file_name );
                break;
            case '3':
                AppendToFile(file_name);
                break;
            case '4':
                RemoveUnderweightPassengers(file_name, 10);
                std::cout << "Done\n";
                break;
            case '5': 
            {
                std::string name;
                double new_weight;
                std::cout << "name && weight: ";
                std::cin >> name >> new_weight;
                SetPassengerWeight(file_name, name, new_weight);
                std::cout << "Done\n";
                break;
            }
            case '6':
                std::cout << "exit\n";
                break;
            default:
                std::cout << "wrong answer\n";
        }
    } while ( choice != '6' );

    return 0;
}