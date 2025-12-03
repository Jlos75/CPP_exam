//
// Created by jeann on 02/12/2025.
//

#include "Bird.h"


Bird::Bird(string name,
           string color,
           string diet,
           string habitat,
           string sounds,
           bool isPet,
           int age,
           double weight,
           double height,
           double wingspan)
    : Animal(name, color, diet, habitat, sounds, isPet, age, weight, height),
    wingspan(wingspan)
{
}

double Bird::getWingspan() const {
    return wingspan;
}

void Bird::setWingspan(double newWingspan) {
    wingspan = newWingspan;
}

void Bird::printInfo()const {
    cout<< "Animal of type Bird: " << endl;
    cout<<"Name : " << getName() << endl;
    cout << "Color : " << getColor() << endl;
    cout << "Wingspan : " << getWingspan() << endl;
    cout << "Diet : " << getDiet() << endl;
    cout << "Habitat : " << getHabitat() << endl;
    cout << "Age : " << getAge() << "'s old" << endl;
    cout << "This animal is" << (getIsPet() ? "" : "not") << endl;
    cout << "Weight : " << getWeight()<< " kg" << endl;
    cout << "Height : " << getHeight()<< " cm" << endl;
    cout << endl;

}

