#ifndef HEALTH_POINTS
#define HEALTH_POINTS
#include <iostream>
using namespace std;



#define DEFAULT_MAX_HP 100

class HealthPoints
{

private:
    //fields: one saves the health points and one saves the max health points that an instance could have.
    int m_health_points;
    int m_max_health_points;
public:
    //exception:
    class InvalidArgument : public std::exception{};
    //constructor
    HealthPoints(int _health_points = DEFAULT_MAX_HP);
    //--------------------------------------------------------------------------
    //arithmetic operators:
    HealthPoints& operator+ (int health_add);
    HealthPoints& operator- (int health_remove);
    HealthPoints& operator+= (int add);
    HealthPoints& operator-= (int remove);
    //comparison operators:
    bool operator== (const HealthPoints& other) const;
    bool operator>= (const HealthPoints& other) const;
    bool operator<= (const HealthPoints& other) const;
    bool operator!= (const HealthPoints& other) const;
    bool operator> (const HealthPoints& other) const;
    bool operator< (const HealthPoints& other) const;

    //friend functions:
    friend ostream& operator<<(ostream& os, const HealthPoints& obj);
    friend HealthPoints& operator+(int add, HealthPoints& obj);
    friend bool operator==(const HealthPoints& obj, int compare);
    friend bool operator!= (const HealthPoints& obj, int compare);
    friend bool operator>= (const HealthPoints& obj, int compare);
    friend bool operator<= (const HealthPoints& obj, int compare);
    friend bool operator> (const HealthPoints& obj, int compare);
    friend bool operator< (const HealthPoints& obj, int compare);

    //default des, assi, cpy
    HealthPoints& operator= (const HealthPoints& heal1) = default;
    HealthPoints(const HealthPoints&) = default;
    ~HealthPoints() = default;

};


//inverse operators:
bool operator==(int compare, const HealthPoints& obj);
bool operator!= (int compare, const HealthPoints& obj);
bool operator>= (int compare, const HealthPoints& obj);
bool operator<= (int compare, const HealthPoints& obj);
bool operator> (int compare, const HealthPoints& obj);
bool operator< (int compare, const HealthPoints& obj);

#endif