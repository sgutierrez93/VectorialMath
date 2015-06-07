#include <iostream>
#include "MMVector.h"

using std::cout;
using std::endl;

/*
 * 
 */
int main(int argc, char** argv){
    MMVector u(1, 2, 3), v(4, 5, 6);
    MMVector w = u.productoCruz(v);
    cout << "W(" << w.x() << ", " << w.y() << ", " << w.z() << ")";
    
    return 0;
}

