#include <iostream>
#include "../include/algebra/PrecisionDouble.h"
#include "../include/geometry/Point3D.h"
#include "../include/geometry/Vector3D.h"


int main()
{
    std::cout << "Hello World!\n" << std::endl;
    PrecisionDouble test(1, 5);
    std::cout << test.ToString() << std::endl;

    Vector3D direction(1, 2, 3);
    Point3D origin(3, 2, 1);
    Point3D destination = origin - direction;

}
