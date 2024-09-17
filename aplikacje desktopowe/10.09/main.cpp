#include <iostream>
#include <cmath>
#include <utility>
#include <stdexcept>
#include <limits>

using namespace std;

/**
 * @brief Represents a point in 2D Cartesian coordinate space.
 *
 * This structure defines a point in two-dimensional space with x and y coordinates.
 */
struct Point {
    float x;
    float y;
};

/**
 * @brief Calculates the Euclidean distance between two points in 2D space.
 *
 * This function computes the straight-line (Euclidean) distance between two points, p1 and p2,
 * in two-dimensional Cartesian coordinates.
 *
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The Euclidean distance between p1 and p2.
 */
float calculateDistance(const Point &p1, const Point &p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

/**
 * @brief Calculates the area of a triangle given its three vertices.
 *
 * This function computes the area of a triangle defined by three points (vertices) in 2D space.
 * It first checks if the three points can form a valid triangle using the triangle inequality theorem.
 * If they do not form a valid triangle, the function returns -1.0f.
 * If they form a valid triangle, the area is calculated using the shoelace formula.
 *
 * @param p1 The first vertex of the triangle.
 * @param p2 The second vertex of the triangle.
 * @param p3 The third vertex of the triangle.
 * @return The area of the triangle if valid; otherwise, returns -1.0f.
 */
float calculateTriangleArea(const Point &p1, const Point &p2, const Point &p3) {
    // Calculate the lengths of the sides
    float a = calculateDistance(p1, p2);
    float b = calculateDistance(p2, p3);
    float c = calculateDistance(p3, p1);

    // Sort the side lengths so that 'c' is the largest
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);

    // Check the triangle inequality theorem
    if (c >= a + b) {
        // The sides do not form a valid triangle
        return -1.0f;
    }

    // Calculate the area using the shoelace formula
    float area = 0.5f * abs(
                     p1.x * (p2.y - p3.y) +
                     p2.x * (p3.y - p1.y) +
                     p3.x * (p1.y - p2.y)
                 );

    return area;
}

/**
 * @brief Calculates the real roots of a quadratic equation of the form ax^2 + bx + c = 0.
 *
 * This function computes the real roots of a quadratic equation using the quadratic formula.
 * It returns a pair of doubles if the roots are real and indicates if the roots are complex.
 *
 * @param a Coefficient of x^2 (must not be zero).
 * @param b Coefficient of x.
 * @param c Constant term.
 * @return A pair containing a boolean and a pair of doubles:
 *         - The boolean is true if the roots are real, false if they are complex.
 *         - The pair of doubles contains the roots (undefined if roots are complex).
 * @throws invalid_argument if 'a' is zero.
 */
pair<bool, pair<double, double> > quadraticRoots(double a, double b, double c) {
    // Check if 'a' is zero (not a quadratic equation)
    if (abs(a) < numeric_limits<double>::epsilon()) {
        throw invalid_argument("'a' cannot be zero in a quadratic equation.");
    }

    // Calculate the discriminant (b^2 - 4ac)
    double discriminant = b * b - 4 * a * c;

    // Check if the discriminant is negative (complex roots)
    if (discriminant < 0) {
        // Roots are complex; return false with undefined roots
        return make_pair(false, make_pair(0.0, 0.0));
    } else {
        // Calculate the square root of the discriminant
        double sqrt_discriminant = sqrt(discriminant);

        // Calculate the two real roots using the quadratic formula
        double root1 = (-b + sqrt_discriminant) / (2 * a);
        double root2 = (-b - sqrt_discriminant) / (2 * a);

        // Return true indicating real roots along with the roots
        return make_pair(true, make_pair(root1, root2));
    }
}

int main() {
    cout << "calculateTriangleArea:" << endl;
    // Define the vertices of the triangle
    Point firstPoint = {0.0f, 0.0f};
    Point secondPoint = {0.0f, 5.0f};
    Point thirdPoint = {5.0f, 0.0f};

    // Calculate the area of the triangle
    float area = calculateTriangleArea(firstPoint, secondPoint, thirdPoint);

    if (area < 0.0f) {
        cout << "The points do not form a valid triangle." << endl;
    } else {
        cout << "The area of the triangle is: " << area << endl;
    }

    // Example usage of quadraticRoots function
    cout << endl << "quadraticRoots:" << endl << "Input a, b, c" << endl;
    double a, b, c;
    cin >> a >> b >> c;
    pair<bool, pair<double, double> > result = quadraticRoots(a, b, c);
    if (result.first) {
        cout << "The quadratic equation has roots: x1=" << result.second.first << ", x2=" << result.second.second <<
                endl;
    } else {
        cout << "The quadratic equation doesn't have real solutions." << endl;
    }
    return 0;
}
