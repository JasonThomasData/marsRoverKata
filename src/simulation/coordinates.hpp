#ifndef Coordinates_h 
#define Coordinates_h

struct Coordinates
{
    int fromTop;
    int fromLeft;

    bool isSame(Coordinates otherCoordinates)
    {
        if (fromTop == otherCoordinates.fromTop
            && fromLeft == otherCoordinates.fromLeft)
        {
            return true;
        }
        return false;
    }
};

#endif
