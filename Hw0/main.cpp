#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>

#define PI 3.1415926
#define RAD (PI/180.0)

int main() {

    // Basic Example of cpp
    std::cout << "Example of cpp \n";
    float a = 1.0, b = 2.0;
    std::cout << a << std::endl;
    std::cout << a / b << std::endl;
    std::cout << std::sqrt(b) << std::endl;
    std::cout << std::acos(-1) << std::endl;
    std::cout << std::sin(30.0 / 180.0 * acos(-1)) << std::endl;

    // Example of vector
    std::cout << "Example of vector \n";
    // vector definition
    Eigen::Vector3f v(1.0f, 2.0f, 3.0f);
    Eigen::Vector3f w(1.0f, 0.0f, 0.0f);
    // vector output
    std::cout << "Example of output \n";
    std::cout << v << std::endl;
    // vector add
    std::cout << "Example of add \n";
    std::cout << v + w << std::endl;
    // vector scalar multiply
    std::cout << "Example of scalar multiply \n";
    std::cout << v * 3.0f << std::endl;
    std::cout << 2.0f * v << std::endl;

    // Example of matrix
    std::cout << "Example of matrix \n";
    // matrix definition
    Eigen::Matrix3f i, j;
    i << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;
    j << 2.0, 3.0, 1.0, 4.0, 6.0, 5.0, 9.0, 7.0, 8.0;
    // matrix output
    std::cout << "Example of output \n";
    std::cout << i << std::endl;
    // matrix add i + j
    Eigen::Matrix3f A;
    A = i + j;
    std::cout << "Example of matrix add \n";
    std::cout << A << std::endl;
    // matrix scalar multiply i * 2.0
    Eigen::Matrix3f B;
    B = i * 2.0;
    std::cout << "Example of scalar multiply \n";
    std::cout << B << std::endl;
    // matrix multiply i * j
    Eigen::Matrix3f C;
    C = i * j;
    std::cout << "Example of matrix multiply \n";
    std::cout << A << std::endl;
    // matrix multiply vector i * v
    Eigen::Vector3f D;
    D = i * v;
    std::cout << "Example of matrix multiply vector \n";
    std::cout << D << std::endl;


    /*
    * PA 0
    */
    
    // TO DO: Define point P
    Eigen::Vector3f P(2, 1, 1);
    // TO DO: Define rotation matrix M
    Eigen::Matrix3f M;
    float THETA = 45 * RAD;
    M << cos(THETA), -sin(THETA), 1, sin(THETA), cos(THETA), 2, 0, 0, 1;
    // TO DO: M * P
    P = M * P;
    std::cout << "The position of P after rotation is  \n";
    std::cout << P << std::endl;

    return 0;
}