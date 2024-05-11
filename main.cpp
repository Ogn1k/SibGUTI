#define CTEST_MAIN
#include "geometry.cpp"
#include "ctest.h"

std::vector<Geometry> geoms;

// Circle
CTEST(geometryCircle_suite, type_test)
{
    std::string expected = "circle";
    ASSERT_STR(expected.c_str(), geoms[0].type.c_str());
}

CTEST(geometryCircle_suite, x_test)
{
    int expected = 25;
    ASSERT_EQUAL(expected, geoms[0].circle.center.x);
}

CTEST(geometryCircle_suite, y_test)
{
    int expected = 25;
    ASSERT_EQUAL(expected, geoms[0].circle.center.y);
}

CTEST(geometryCircle_suite, radius_test)
{
    int expected = 8;
    ASSERT_EQUAL(expected, geoms[0].circle.radius);
}

// Polygon
CTEST(geometryPolygon_suite, type_test)
{
    std::string expected = "polygon";
    ASSERT_STR(expected.c_str(), geoms[1].type.c_str());
}

CTEST(geometryPolygon_suite, x1_test)
{
    int expected = 10;
    ASSERT_EQUAL(expected, geoms[1].polygon.points[0].x);
}

CTEST(geometryPolygon_suite, y1_test)
{
    int expected = 43;
    ASSERT_EQUAL(expected, geoms[1].polygon.points[0].y);
}

CTEST(geometryPolygon_suite, x2_test)
{
    int expected = 43;
    ASSERT_EQUAL(expected, geoms[1].polygon.points[1].x);
}

// Triangle
CTEST(geometryTriangle_suite, type_test)
{
    std::string expected = "triangle";
    ASSERT_STR(expected.c_str(), geoms[2].type.c_str());
}

CTEST(geometryTriangle_suite, x1_test)
{
    int expected = 28;
    ASSERT_EQUAL(expected, geoms[2].polygon.points[0].x);
}

CTEST(geometryTriangle_suite, y1_test)
{
    int expected = 32;
    ASSERT_EQUAL(expected, geoms[2].polygon.points[0].y);
}

CTEST(geometryTriangle_suite, x2_test)
{
    int expected = 43;
    ASSERT_EQUAL(expected, geoms[2].polygon.points[1].x);
}

// Intersections
CTEST(geomytryIntersection_suite, circleXpolygon)
{
    ASSERT_FALSE(Is_Circle_Polygon_Intersecting(geoms[0].circle, geoms[1].polygon));
}

CTEST(geomytryIntersection_suite, circleXcircle)
{
    ASSERT_TRUE(Is_Circle_Circle_Intersecting(geoms[0].circle, geoms[3].circle));
}

CTEST(geomytryIntersection_suite, polygonXtriangle)
{
    ASSERT_TRUE(Is_Polygon_Polygon_Intersecting(geoms[1].polygon, geoms[2].polygon));
}

int main(int argc, const char** argv)
{
    std::string file_name = "output\\geoms.txt";//need to enter full link to file

    geoms = Read_File( file_name );
    
    // output print stuff
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

    // intersection stuff
    if( Is_Circle_Polygon_Intersecting(geoms[0].circle, geoms[1].polygon) )
        std::cout << geoms[0].type << " intersects with " << geoms[1].type << "\n\n";
    else
        std::cout << geoms[0].type << " not intersects with " << geoms[1].type << "\n\n";
    
    if( Is_Polygon_Polygon_Intersecting(geoms[1].polygon, geoms[2].polygon) )
        std::cout << geoms[1].type << " intersects with " << geoms[2].type << "\n\n";
    else
        std::cout << geoms[1].type << " not intersects with " << geoms[2].type << "\n\n";

    if( Is_Circle_Circle_Intersecting(geoms[0].circle, geoms[3].circle) )
        std::cout << geoms[0].type << " intersects with " << geoms[3].type << "\n\n";
    else
        std::cout << geoms[0].type << " not intersects with " << geoms[3].type << "\n\n";


    // testing stuff

    return ctest_main(argc, argv);
}

