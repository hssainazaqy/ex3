#include "HealthPoints.h"





HealthPoints::HealthPoints(int _health_points)
        :m_health_points(_health_points), m_max_health_points(_health_points){

    if(m_health_points <= 0){
        throw HealthPoints::InvalidArgument();
    }
}


HealthPoints& HealthPoints::operator+=(int add)
{
    m_health_points += add;
    if(m_health_points < 0){
        m_health_points = 0;
    }
    if(m_health_points > m_max_health_points){
        m_health_points = m_max_health_points;
    }
    return *this;
}


HealthPoints& HealthPoints::operator-= (int remove)
{
    m_health_points -= remove;
    if(m_health_points < 0){
        m_health_points = 0;
    }
    if(m_health_points > m_max_health_points) {
        m_health_points = m_max_health_points;
    }
    return *this;
}


HealthPoints& HealthPoints::operator+(int health_add)
{
    return (*this += health_add);
}

HealthPoints& operator+(int add, HealthPoints& obj)
{
    return obj += add;
}
HealthPoints& HealthPoints::operator-(int health_remove)
{
    return (*this -= health_remove);
}
bool HealthPoints::operator== (const HealthPoints& other) const
{
    return(m_health_points == other.m_health_points);
}
bool HealthPoints::operator>= (const HealthPoints& other) const
{
    return (m_health_points >= other.m_health_points);
}
bool HealthPoints::operator<= (const HealthPoints& other) const
{
    return (m_health_points <= other.m_health_points);
}
bool HealthPoints::operator!= (const HealthPoints& other) const
{
    return (m_health_points != other.m_health_points);
}
bool HealthPoints::operator> (const HealthPoints& other) const
{
    return (m_health_points > other.m_health_points);
}
bool HealthPoints::operator< (const HealthPoints& other) const
{
    return (m_health_points < other.m_health_points);
}







bool operator==(const HealthPoints& obj, int compare)
{
    return(obj.m_health_points == compare);
}
bool operator==(int compare, const HealthPoints& obj)
{
    return (obj == compare);
}

bool operator!= (const HealthPoints& obj, int compare)
{
    return(obj.m_health_points != compare);
}
bool operator!= (int compare, const HealthPoints& obj)
{
    return(obj != compare);
}

bool operator>= (const HealthPoints& obj, int compare)
{
    return(obj.m_health_points >= compare);
}
bool operator>= (int compare, const HealthPoints& obj)
{
    return(obj <= compare);
}

bool operator<= (const HealthPoints& obj, int compare)
{
    return(obj.m_health_points <= compare);
}
bool operator<= (int compare, const HealthPoints& obj)
{
    return(obj >= compare);
}

bool operator> (const HealthPoints& obj, int compare)
{
    return(obj.m_health_points > compare);
}
bool operator> (int compare, const HealthPoints& obj)
{
    return(obj < compare);
}

bool operator< (const HealthPoints& obj, int compare)
{
    return(obj.m_health_points < compare);
}
bool operator< (int compare, const HealthPoints& obj)
{
    return(obj > compare);
}

ostream& operator<<(ostream& os, const HealthPoints& obj) {
    return os << obj.m_health_points << "(" << obj.m_max_health_points << ")";
}