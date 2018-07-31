// C++ Implementation to find the line passing
// through two points
#include <iostream>
#include <cmath>

using namespace std;

// This pair is used to store the X and Y
// coordinate of a point respectively
#define pdd pair<double, double>

// structure to represent a co-ordinate
// point
struct Point {
  
  double x, y;
  Point()
  {
    x = y = 0;
  }
  Point( double a, double b )
  {
    x = a, y = b;
  }
};

// function to find the slope of a straight line
float slope( float x1, float y1, float x2, float y2 )
{
    return (y2 - y1) / (x2 - x1);
}

void crossPoints( double a, double b, double c, double r )
{
  double b2 = b*b;
  double A = 1. + a*a/b2;
  double B = (-2.*a*c)/b2;
  double C = (c*c)/b2 - r*r;

  double sRoot = sqrt( B*B-4.*A*C );
  double x1 = ( -B + sRoot )/(2.*A);
  double x2 = ( -B - sRoot )/(2.*A);
  double y1 = ( c - a*x1 )/b;
  double y2 = ( c - a*x2 )/b;
  
  cout << "x1 = " << x1 << ", x2 = " << x2 << "\n";
  cout << "y1 = " << y1 << ", y2 = " << y2 << "\n";
}

bool checkCollision( double a, double b, double c, 
                     double x, double y, double radius )
{
  bool flag = false;
  
  // Finding the distance of line from center.
  double dist = (abs(a * x + b * y + c)) / 
    sqrt(a * a + b * b);
  
  // Checking if the distance is less than, 
  // greater than or equal to radius.
  if( radius == dist ) {
    flag = true;
    cout << "Touch" << endl;
  }
  else if( radius > dist ) {
    cout << "Intersect" << endl;
    flag = true;
  }
  else
    cout << "Outside" << endl;
  return flag;
}

// Function to find the line given two points
Point lineFromPoints( Point P, Point Q, double r )
{
  double a = Q.y - P.y;
  double b = P.x - Q.x;
  double c = a*(P.x) + b*(P.y);
  
  if( b < 0 ) {
    cout << "The line passing through points P and Q is: "
         << a << "x " << b << "y = " << c << endl;
  }
  else {
    cout << "The line passing through points P and Q is: "
         << a << "x + " << b << "y = " << c << endl;
  }
  if( checkCollision( a, b, c, 0., 0., r ))
    crossPoints( a, b, c, r );

  return Point( 0., 0. );
}

// A utility function to find the distance between two points
double dist( Point p1, Point p2 )
{
  return sqrt(( p1.x - p2.x )*( p1.x - p2.x ) +
              ( p1.y - p2.y )*( p1.y - p2.y ));
}

// Driver code
int main()
{
  double x1 = 1.;
  double y1 = 1.;
  double x2 = 4.;
  double y2 = 1.;
  double r = 5.;
  cout << "Slope is: "
       << slope( x1, y1, x2, y2 ) << "\n";
  
  pdd P = make_pair( x1, y1 );
  pdd Q = make_pair( x2, y2 );
  Point x = lineFromPoints( P, Q, r );
  
  return 0;
}
