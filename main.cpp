#define CTEST_MAIN
#include "geometry.cpp"
#include "ctest.h"

int main()
{
    std::string file_name = "geoms.txt";//need to enter full link to file

    std::vector<Geometry> geoms = Read_File( file_name );
    
    
    for (const auto& geometry : geoms) 
    {
        std::cout << "Type: " << geometry.type << std::endl;
        if (geometry.type == "polygon" || geometry.type == "triangle") 
        {
            std::cout << "Coordinates:" << std::endl;
            for (const auto& point : geometry.polygon.points) 
                std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
        } 
        else if (geometry.type == "circle") 
        {
            std::cout << "Center: (" << geometry.circle.center.x << ", " << geometry.circle.center.y << ")" << std::endl;
            std::cout << "Radius: " << geometry.circle.radius << std::endl;
        }
        if (geometry.type == "polygon" || geometry.type == "triangle") 
        {
            std::cout << std::endl;
            std::cout << Perimeter(geometry.polygon.points) << std::endl;
            std::cout << Area(geometry.polygon.points) << std::endl;
        }
    }

    if( Is_Polygon_Polygon_Intersecting(geoms[0].polygon, geoms[1].polygon) )
        std::cout << geoms[0].type << " intersects with " << geoms[1].type << "\n\n";
    else
        std::cout << geoms[0].type << " not intersects with " << geoms[1].type << "\n\n";
    
    if( Is_Circle_Polygon_Intersecting(geoms[2].circle, geoms[0].polygon) )
        std::cout << geoms[2].type << " intersects with " << geoms[0].type << "\n\n";
    else
        std::cout << geoms[2].type << " not intersects with " << geoms[0].type << "\n\n";



    return 0;
}

CTEST(geometry_suite, geometry_test)
{
    std::string result;
    std::string expected;
    ASSERT_STR(expected.c_str(), result.c_str());
}