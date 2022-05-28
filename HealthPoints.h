#ifndef HEALTH_POINTS
#define HEALTH_POINTS


class HealthPoints
{
private:
    int health_points;
public:
    //constructor
    HealthPoints operator+ (int health_add);
    HealthPoints operator- (int health_remove);
    HealthPoints operator+= (int add);
    HealthPoints operator-= (int remove);
    bool operator== (const HealthPoints& other) const;
    bool operator>= (const HealthPoints& other) const;
    bool operator<= (const HealthPoints& other) const;
    bool operator!= (const HealthPoints& other) const;
    bool operator> (const HealthPoints& other) const;
    bool operator< (const HealthPoints& other) const;
    //print operator

    HealthPoints& operator= (const HealthPoints& heal1) = default;
    HealthPoints(const HealthPoints&) = default;
    ~HealthPoints() = default;
    
};

HealthPoints operator+(int add, const HealthPoints& obj);
#endif