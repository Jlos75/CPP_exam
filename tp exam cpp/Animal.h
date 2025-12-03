//
// Created by jeann on 02/12/2025.
//

#ifndef TP_EXAM_CPP_ANIMAL_H
#define TP_EXAM_CPP_ANIMAL_H
#include <string>
#include <iostream>

using namespace std;


class Animal {
private:
    string name;
    string color;
    string diet;
    string habitat;
    string sounds;
    bool isPet;
    int age;
    double weight;
    double height;
public:
    Animal();
    Animal(string name,
           string color,
           string diet,
           string habitat,
           string sounds,
           bool isPet,
           int age,
           double weight,
           double height);


    virtual void printInfo() const;
    void make_sound();

    //Getters
    string getName() const;
    string getColor() const;
    string getDiet() const;
    string getHabitat() const;
    string getSounds() const;
    bool getIsPet() const;
    int getAge() const;
    double getWeight() const;
    double getHeight() const;

    //Setters
    void setName(const string& name);
    void setColor(const string& color);
    void setDiet(const string& diet);
    void setHabitat(const string& habitat);
    void setSounds(const string& sounds);
    void setIsPet(bool isPet);
    void setAge(int age);
    void setWeight(double weight);
    void setHeight(double height);
};

#endif //TP_EXAM_CPP_ANIMAL_H