#include <iostream>
#include "NodeField.h"

using namespace std;

int main() {
    // NodeField field(25, 25); // Uncomment to generate an empty field
    // field.addObstacles(50);   // Uncomment to add obstacles

    NodeField field("field.txt"); // Load field from file
    if (!field.findPath(0, 1, 40, 3, true)) {
        cout << "No path found" << endl;
    }
    return 0;
}
