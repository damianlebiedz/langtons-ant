#ifndef ANT_H
#define ANT_H

enum Direction { NORTH, EAST, SOUTH, WEST };

class Ant {
public:
    Ant(int startX, int startY);
    void turnRight();
    void turnLeft();
    void moveForward();
    void draw(sf::RenderWindow& window) const;
    int getX() const;
    int getY() const;
    Direction getDirection() const;

private:
    int x, y;
    Direction dir;
};

#endif //ANT_H