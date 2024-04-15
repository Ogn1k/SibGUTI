#include "fileIn.cpp"
#include <cmath>

bool onSegment( const Point& p, const Point& q, const Point& r ) 
{
    if ( q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y) )
        return true;
    return false;
}

int orientation(const Point& p, const Point& q, const Point& r) 
{
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // коллинеарны
    return (val > 0) ? 1 : 2; // по часовой или против часовой стрелки
}

bool doIntersect( const Point& p1, const Point& q1, const Point& p2, const Point& q2 ) 
{
    // четыре ориентации троек точек, образованных отрезками
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // Общий случай
    if ( o1 != o2 && o3 != o4 )
        return true;

    // Особые случаи
    // p1, q1 и p2 коллинеарны и p2 лежит на отрезке p1q1
    if ( o1 == 0 && onSegment(p1, p2, q1) ) return true;

    // p1, q1 и q2 коллинеарны и q2 лежит на отрезке p1q1
    if ( o2 == 0 && onSegment(p1, q2, q1) ) return true;

    // p2, q2 и p1 коллинеарны и p1 лежит на отрезке p2q2
    if ( o3 == 0 && onSegment(p2, p1, q2) ) return true;

     // p2, q2 и q1 коллинеарны и q1 лежит на отрезке p2q2
    if ( o4 == 0 && onSegment(p2, q1, q2) ) return true;

    return false; // Нет пересечения
}

double distance( const Point& p1, const Point& p2 ) 
{
    return sqrt( pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) );
}

double Perimeter( const std::vector<Point>& points ) 
{
    double perimeter = 0;

    for ( size_t i = 0; i < points.size() - 1; ++i ) 
        perimeter += distance( points[i], points[i + 1] );
    
    perimeter += distance( points.back(), points.front() );
    return perimeter;
}

double Area( const std::vector<Point>& points )
{
    double area = 0;
    size_t num_points = points.size();

    for( size_t i = 0; i < num_points; i++ )
    {
        const Point& cur_point = points[i];
        const Point& next_point = points[(i+1) % num_points];
        area += cur_point.x * next_point.y - next_point.x * cur_point.y;
    }

    return std::abs(area) / 2;

}

bool Is_Circle_Polygon_Intersecting( const Circle& circle, const Polygon& polygon ) 
{
    for ( size_t i = 0; i < polygon.points.size(); ++i ) 
    {
        Point p1 = polygon.points[i];
        Point p2 = polygon.points[(i + 1) % polygon.points.size()];
        
        double d = abs((p2.y - p1.y) * circle.center.x - (p2.x - p1.x) * circle.center.y + p2.x * p1.y - p2.y * p1.x) / distance(p1, p2);
        
        if ( d < circle.radius )
            return true;
    }
    
    for ( const auto& vertex : polygon.points ) 
    {
        if ( distance(circle.center, vertex) < circle.radius )
            return true;
    }
    
    return false;
}

bool Is_Circle_Circle_Intersecting( const Circle& circle1, const Circle& circle2 ) 
{
    double d = distance( circle1.center, circle2.center );
    return d < circle1.radius + circle2.radius;
}

bool Is_Polygon_Polygon_Intersecting( const Polygon& polygon1, const Polygon& polygon2 ) 
{
    for ( size_t i = 0; i < polygon1.points.size(); ++i ) 
    {
        Point p1 = polygon1.points[i];
        Point p2 = polygon1.points[(i + 1) % polygon1.points.size()];
        
        for ( size_t j = 0; j < polygon2.points.size(); ++j ) 
        {
            Point q1 = polygon2.points[j];
            Point q2 = polygon2.points[(j + 1) % polygon2.points.size()];
            
            // Проверяем пересечение отрезков
            if ( doIntersect(p1, p2, q1, q2) )
                return true;
        }
    }
    
    return false;
}

