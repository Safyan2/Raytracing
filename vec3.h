#ifndef VEC3_H
#define VEC3_H

/* program for peforming vector arithmetic operations such add 
adding, subtracting, multiplyng, dividing. also provides utility 
in the form of calculating length of a vector, dot product, 
and cross product */

#include <cmath>
#include <iostream>

/* same class for colours, offsets, locations, directions,etc. 
3 component vector. intialised by the elements of array 'e' 
which are scallar values */
which are scallar values */
class vec3 
{                                                          
public:
    double e[3];                                       // stores coordinates of vector

    vec3() : e{ 0,0,0 } {}                              
    vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {}
                                                        
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    double operator[](int x) const { return e[x]; }
    double& operator[](int x) { return e[x]; }

    vec3& operator+=(const vec3& v) 
    {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vec3& operator*=(double t) 
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3& operator/=(double t) 
    {
        return *this *= 1 / t;
    }
    // method that calculates the length of the vector
    double length() const 
    {
        return std::sqrt(length_squared());
    }
    // method calculating the squared length of vector
    double length_squared() const 
    {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }
};

//useful for geometric clarity in the code
using point3 = vec3;


// Utility Functions for vector operations

inline std::ostream& operator<<(std::ostream& out, const vec3& v) 
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) 
{
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) 
{
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) 
{
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) 
{
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) 
{
    return t * v;
}

inline vec3 operator/(vec3 v, double t) 
{
    return (1 / t) * v;
}

// function to calculate dot product of two vectors
inline double dot(const vec3& u, const vec3& v) 
{
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}

// function to calculate cross product of two vectors
inline vec3 cross(const vec3& u, const vec3& v) 
{
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// function to return unit vector in the direction of v
inline vec3 unit_vector(vec3 v) 
{
    return v / v.length();
}

#endif
