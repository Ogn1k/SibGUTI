#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

struct Point 
{
    double x;
    double y;
};

struct Circle 
{
    Point center;
    double radius;
};

struct Polygon 
{
    std::vector<Point> points;
};

struct Geometry 
{
    std::string type;
    Circle circle;
    Polygon polygon;
};

std::vector<Point> Parse_Coordinates(const std::string& text, const size_t line, bool &error) 
{
    std::vector<Point> points;
    std::stringstream ss(text);
    std::string pair;
    size_t line_num = 0;

    
    while (std::getline(ss, pair, ',')) 
    {
        line_num++;
        Point point;
        std::stringstream ss_pair(pair);

        if(!(ss_pair >> point.x >> point.y))
        {
            //проверка на правильность написания координат
            size_t column = text.find(pair) + 1;
            std::cerr << "error: line " << line << " column " << column+8 << " expected double" << std::endl;
            error = true;
        }

        //ss_pair >> point.x >> point.y;
        points.push_back(point);
    }

    

    return points;
}

bool isValidCircle(const std::string& line, size_t line_number) {
    std::istringstream iss(line);
    std::string word;
    iss >> word;
    if (word != "circle") {
        std::cerr << "Error at line " << line_number << ": expected 'circle'" << std::endl;
        return false;
    }
    char c;
    iss >> c;
    if (c != '(') {
        std::cerr << "Error at line " << line_number << ": expected '(' after circle" << std::endl;
        return false;
    }
    return true;
}

bool isValidPolygon(const std::string& line, size_t line_number) 
{
    // Ожидаемый формат: "polygon (x y, x y, x y..., x y)"
    std::regex pattern(R"(^polygon \((\d+\s\d+(,\s\d+\s\d+)*)\)$)");
    
    if (!std::regex_match(line, pattern)) {
        std::cout << "Ошибка: входные данные не соответствуют формату." << std::endl;
        return false;
    }

    size_t start_bracket_pos = line.find("(");
    size_t end_bracket_pos = line.find(")");
    if (start_bracket_pos == std::string::npos || end_bracket_pos == std::string::npos || start_bracket_pos > end_bracket_pos) {
        std::cerr << "Error at line " << line_number << ": expected '(' and ')' around polygon coordinates" << std::endl;
        return false;
    }
    return true;
}

std::vector<Geometry> Read_File(const std::string& file_name) 
{
    bool error = false;
    std::vector<Geometry> geometries;
    std::ifstream file( file_name );
    std::string line;
    size_t line_number = 0; 

    if ( !file.is_open() ) 
    {
        std::cerr << "Error opening file: " << file_name << std::endl;
        exit(EXIT_FAILURE);
    }

    while ( std::getline(file, line) ) 
    {
        line_number++;
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        Geometry geometry;
        geometry.type = type;

        if (type == "polygon" || type == "triangle")
        {
            if (!isValidPolygon(line, line_number)) {
                error = true;
            }

            

            std::string coordinatesText = line.substr(start + 1, end - start - 1);
            geometry.polygon.points = Parse_Coordinates(coordinatesText, line_number, error);
        }
        else if (type == "circle") 
        {
            char bracket1, bracket2, comma;
            Point center;
            double radius;

            //size_t open_bracket_count = std::count(line.begin(), line.end(), '(');
           // size_t close_bracket_count = std::count(line.begin(), line.end(), ')');

            if (!isValidCircle(line, line_number))
             {
                error = true;
            }

            if (!(iss >> bracket1 >> center.x >> center.y >> comma >> radius >> bracket2) || bracket1 != '(' || comma != ',' || bracket2 != ')' ) 
            {
                size_t column = line.find_first_of("1234567890.");
                std::cerr << "Error at line " << line_number << " column " << column << std::endl;
                error = true;
            }

            geometry.circle.center = center;
            geometry.circle.radius = radius;
            std::string rest_line;
            std::getline(iss, rest_line);

            if( !rest_line.empty())
            {
                std::cerr << "error: line " << line_number << " column " << line.size() << std::endl;
                error = true;
            }

            iss >> comma >> geometry.circle.center.x >> geometry.circle.center.y >> comma >> geometry.circle.radius;
        }
        else
        {
            std::cout << "error: " << type << ": expected 'CIRCLE' or 'POLYGON'" << std::endl;
            error = true;
        }

        if(!error)
            geometries.push_back(geometry);
    }
    
    file.close();
    if(error)
        return {};
    return geometries;
}