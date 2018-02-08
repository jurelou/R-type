//
// Created by louis on 10/01/18.
//

#include <math.h>
#include "Vertex.hpp"

Vertex::Vertex(float x, float y)
        : x(x), y(y)
{}


Vertex::Vertex(const float *v)
        : x(v[0]), y(v[1])
{}


Vertex::Vertex(const Vertex &v)
        : x(v.x), y(v.y)
{}

void		Vertex::set(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vertex&	Vertex::operator+=(const Vertex& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

Vertex&	Vertex::operator-=(const Vertex& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

Vertex&	 Vertex::operator*=(float s)
{
    x *= s;
    y *= s;
    return *this;
}

Vertex&	 Vertex::operator/=(float s)
{
    x /= s;
    y /= s;
    return *this;
}

Vertex	 Vertex::operator+(const Vertex& v) const
{ return Vertex(x + v.x,  y + v.y); }

Vertex	 Vertex::operator-(const Vertex& v) const
{ return Vertex(x - v.x, y - v.y); }

Vertex	 Vertex::operator-(void) const
{ return Vertex(-x, -y); }

Vertex	 Vertex::operator*(float s) const
{ return Vertex(x * s, y * s); }

Vertex	 Vertex::operator/(float s) const
{ return Vertex(x / s, y / s); }

bool		 Vertex::operator==(const Vertex& v) const
{ return ((x == v.x) && (y == v.y)); }

bool		Vertex::operator!=(const Vertex& v) const
{
    return ((x != v.x) ||
            (y != v.y));
}


float		Vertex::length() const
{ return sqrt(lengthSquared()); }

float		 Vertex::lengthSquared() const
{ return x * x + y * y; }

void		 Vertex::normalize()
{
    float len = length();
    if (len > 0)
    {
        x /= len;
        y /= len;
    }
}

float   Vertex::distance(Vertex& end)
{
    float xa = x;
    float ya = y;
    float xb = end.x;
    float yb = end.y;
    return (sqrt(pow(xb- xa, 2) + pow(yb- ya, 2)));

}

Vertex&	Vertex::operator=(const Vertex& v)
{
    set(v.x, v.y);
    return *this;
}

std::ostream&  operator<<(std::ostream& stream, const Vertex& v)
{
    stream << "{x:" << v.x << "; y:" << v.y << "}";
    return stream;
}