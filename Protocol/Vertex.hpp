//
// Created by louis on 10/01/18.
//

#ifndef CPP_RTYPE_VERTEX_HPP
#define CPP_RTYPE_VERTEX_HPP

#include <iostream>
#include <math.h>

class Vertex
{
public:
    Vertex(float x = 0, float y = 0);
    Vertex(const float *v);
    Vertex(const Vertex &v);

    void	set(float x, float y);


    Vertex&   operator+=(const Vertex& v);
    Vertex&   operator-=(const Vertex& v);
    Vertex&   operator*=(float s);
    Vertex&   operator/=(float s);
    Vertex    operator+(const Vertex& v) const;
    Vertex	operator-(const Vertex& v) const;
    Vertex	operator*(float s) const;
    Vertex	operator/(float s) const;
    Vertex	operator-() const;
    bool	    operator==(const Vertex& v) const;
    bool	    operator!=(const Vertex& v) const;
    Vertex&     operator= (const Vertex& v);
    float	x;
    float	y;
public:
    float	length() const;
    float	lengthSquared() const;
    void    normalize();
    float   distance(Vertex& y);
};

std::ostream&  operator<<(std::ostream& stream, const Vertex& v);

#endif //CPP_RTYPE_VERTEX_HPP
