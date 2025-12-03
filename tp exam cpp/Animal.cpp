//
// Created by jeann on 02/12/2025.
//

#include "Animal.h"

#include <iostream>
using namespace std;

Animal::Animal()
    : name("Unknown"), color("None"), diet("None"), habitat("None"),
      sounds("Mute"), isPet(false), age(0), weight(0.0), height(0.0) {}

Animal::Animal(string name, string color, string diet, string habitat,
               string sounds, bool isPet, int age,double weight, double height):
    name(name),color(color),diet(diet),habitat(habitat),
    sounds(sounds),isPet( isPet),age( age){
}

void Animal::make_sound() {
    cout << name << " fait le son : " << sounds << endl;
}

//Getters
string Animal::getName() const {
    return name;
}

string Animal::getColor() const {
    return color;
}

string Animal::getDiet() const {
    return diet;
}

string Animal::getHabitat() const {
    return habitat;
}

string Animal::getSounds() const {
    return sounds;
}

bool Animal::getIsPet() const {
    return isPet;
}

int Animal::getAge() const {
    return age;
}

double Animal::getWeight() const {
    return weight;
}

double Animal::getHeight() const {
    return height;
}

//Setters
void Animal::setName(const string& newName) {
    name = newName;
}

void Animal::setColor(const string& newColor) {
    color = newColor;
}

void Animal::setDiet(const string& newDiet) {
    diet = newDiet;
}

void Animal::setHabitat(const string& newHabitat) {
    habitat = newHabitat;
}

void Animal::setSounds(const string& newSounds) {
    sounds = newSounds;
}

void Animal::setIsPet(bool newIsPet) {
    isPet = newIsPet;
}

void Animal::setAge(int newAge) {
    age = newAge;
}

void Animal::setWeight(double newWeight) {
    // Optionnel : ajouter une validation
    weight = newWeight;
}

void Animal::setHeight(double newHeight) {
    // Optionnel : ajouter une validation
    height = newHeight;
}

void Animal::printInfo() const {
    cout << "Animal of unknown type:" << endl;
    cout << "Name : " << name << endl;
    cout << "Color : " << color << endl;
    cout << "Diet : " << diet << endl;
    cout << "Habitat : " << habitat << endl;
    cout << "Age : " << age << "'s old" << endl;
    cout << "This animal is " << (getIsPet() ? "" : "not") << "a pt" << endl;
    cout << "Weight : " << weight << "kg" << endl;
    cout << "Height : " << getWeight() << "cm" << endl;
    cout << endl;

}