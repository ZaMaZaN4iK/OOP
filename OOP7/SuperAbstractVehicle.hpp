//
// Created by zamazan4ik on 15.09.16.
//

#ifndef OOP3_SUPERABSTRACTVEHICLE_HPP
#define OOP3_SUPERABSTRACTVEHICLE_HPP


//I don't know what do you mean when we said "Research visibility of variables".
//So i think, that I should simply tell you about bla-bla-bla :-)

//Type of Inheritance, Before, After
//Public    Public -> Public    Protected -> Protected  Private -> inaccessible
//Protected    Public -> Protected    Protected -> Protected  Private -> inaccessible
//Private    Public -> Private    Protected -> Private  Private -> inaccessible
class SuperAbstractVehicle
{
protected:
    int someVariable = 0;
public:
    int someAnotherVariable = 42;
    virtual void toConsole() = 0;
};

#endif //OOP3_SUPERABSTRACTVEHICLE_HPP
