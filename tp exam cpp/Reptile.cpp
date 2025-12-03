//
// Created by jeann on 02/12/2025.
//

#include "Reptile.h"


Reptile::Reptile(string name,
               string color,
               string diet,
               string habitat,
               string sounds,
               bool isPet,
               int age,
               double weight,
               double height,
               string scalePattern)
    : Animal(name, color, diet, habitat, sounds, isPet, age, weight, height),
    scalePattern(scalePattern)
{
}

string Reptile::getScalePattern() const {
    return scalePattern;
}

void Reptile::setScalePattern(const string& newscalePattern) {
    scalePattern = newscalePattern;
}

void Reptile::printInfo() const{
    cout<< "Animal of type Reptile: " << endl;
    cout<<"Name : " << getName() << endl;
    cout << "Color : " << getColor() << endl;
    cout << "Scale Pattern : " << getScalePattern() << endl;
    cout << "Diet : " << getDiet() << endl;
    cout << "Habitat : " << getHabitat() << endl;
    cout << "Age : " << getAge() << "'s old" << endl;
    cout << "This animal is" << (getIsPet() ? "" : "not") << endl;
    cout << "Weight : " << getWeight()<< " kg" << endl;
    cout << "Height : " << getHeight()<< " cm" << endl;
    cout << endl;

}