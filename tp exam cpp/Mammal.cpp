//
// Created by jeann on 02/12/2025.
//

#include "Mammal.h"


Mammal::Mammal(string name,
               string color,
               string diet,
               string habitat,
               string sounds,
               bool isPet,
               int age,
               double weight,
               double height,
               string furColor)
    : Animal(name, color, diet, habitat, sounds, isPet, age, weight, height),
    furColor(furColor)
    {
}

string Mammal::getFurColor() const {
    return furColor;
}

void Mammal::setFurColor(const string& newfurcolor) {
    furColor = newfurcolor;
}

void Mammal::printInfo()const {
    cout<< "Animal of type Mammal: " << endl;
    cout<<"Name : " << getName() << endl;
    cout << "Color : " << getColor() << endl;
    cout << "Fur Color : " << getFurColor() << endl;
    cout << "Diet : " << getDiet() << endl;
    cout << "Habitat : " << getHabitat() << endl;
    cout << "Age : " << getAge() << "'s old" << endl;
    cout << "This animal is" << (getIsPet() ? "" : "not") << endl;
    cout << "Weight : " << getWeight()<< " kg" << endl;
    cout << "Height : " << getHeight()<< " cm" << endl;
    cout << endl;

}

