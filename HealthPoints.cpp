#include "HealthPoints.h"



HealthPoints HealthPoints::operator+(int health_add) 
{
    return (*this += health_add);
}
//------------------------------------------------------------------
HealthPoints HealthPoints::operator-(int health_remove) 
{
    return (*this -= health_remove);
}
//------------------------------------------------------------------
HealthPoints HealthPoints::operator+=(int add)
{
    this->health_points += add;
    return *this;
}
//------------------------------------------------------------------
HealthPoints HealthPoints::operator-= (int remove)
{
    this->health_points -= remove;
    return *this;
}
//------------------------------------------------------------------
HealthPoints operator+(int add, HealthPoints& obj)
{
    return obj += add;
}
//------------------------------------------------------------------
bool HealthPoints::operator== (const HealthPoints& other) const
{
    return(this->health_points == other.health_points);
}
//------------------------------------------------------------------
bool HealthPoints::operator>= (const HealthPoints& other) const
{
    return (this->health_points >= other.health_points);
}
//------------------------------------------------------------------
bool HealthPoints::operator<= (const HealthPoints& other) const
{
    return (this->health_points <= other.health_points);
}
//------------------------------------------------------------------
bool HealthPoints::operator!= (const HealthPoints& other) const
{
    return (this->health_points != other.health_points);
}
//------------------------------------------------------------------
bool HealthPoints::operator> (const HealthPoints& other) const
{
    return (this->health_points > other.health_points);
}
//------------------------------------------------------------------
bool HealthPoints::operator< (const HealthPoints& other) const
{
    return (this->health_points < other.health_points);
}