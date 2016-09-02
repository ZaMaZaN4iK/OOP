#include <iostream>
#include <vector>

#include "Auto.hpp"
#include "Express.hpp"
#include "Train.hpp"
#include "Vehicle.hpp"
#include "Carriage.hpp"

// I decided that using e.g. XML or JSON  is stupid solution here
// because the main idea of the lesson is hierarchy of classes.
// And for parsing XML or JSON (or smth else) i should use TinyXML.
// I wouldn't do that :)

int main()
{
    std::vector<Carriage> car({Carriage("1488", 322.0), Carriage("zamazan4ik", 228.0)});
    Auto automobile("BigBossCar", 100500.0, 4.2, 228.0, true, false);
    Express express("Azazin Kreet", 10000.0, 42.0, 500.0, true, car, true);
    return 0;
}