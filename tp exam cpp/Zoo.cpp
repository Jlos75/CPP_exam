#include "Zoo.h"
#include "Animal.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <map>

#include "Bird.h"
#include "Knndouble.h"
#include "Knnstring.h"
#include "Mammal.h"
#include "Reptile.h"


int Zoo::MAX_CAPACITY = 100;

Zoo::Zoo(string name) : name(name) {
}


void Zoo::setName(const string& newName) {
    name = newName;
}

string Zoo::getName() const {
    return name;
}

// Fonction utilitaire pour convertir une string en minuscules
string toLower(const string& str) {
    string lower_str = str;
    // transform applique une fonction unaire (::tolower) à chaque élément de la plage
    transform(lower_str.begin(), lower_str.end(), lower_str.begin(),
                   // Utilisation de la version globale ::tolower pour éviter des problèmes de surcharge
                   [](unsigned char c){ return tolower(c); });
    return lower_str;
}

//trié ordre alphabetique _______________________
void Zoo::addAnimal(Animal* animal) {

    if (animals.size() >= MAX_CAPACITY) {
        cout << "ERREUR: Le Zoo " << name << " a atteint sa capacité maximale ("
             << MAX_CAPACITY << ")" << endl;
        return;
    }

    auto it = lower_bound(
        animals.begin(),
        animals.end(),
        animal,
        [](const Animal* a, const Animal* b) {
            return toLower(a->getName()) < toLower(b->getName());
        }
    );

    animals.insert(it, animal);

    cout << animal->getName() << " is added to Zoo " << name << "." << endl;
}

// Affichager les animaux en O(log(n))
void Zoo::listAnimals() const {
    cout << "\n List of Animals in Zoo " << name  << endl;
    if (animals.empty()) {
        cout << "The Zoo is empty." << endl;
        return;
    }

    for (const Animal* animal : animals) {
        // Appelle la méthode virtuelle printInfo()
        animal->printInfo(); 
    }
    cout << "end list" << endl;
}

int Zoo::searchAnimalByName(string name) const {
    // 1. Définir le critère de comparaison pour lower_bound
    // Il compare l'objet du vecteur (Animal*) avec la chaîne de caractères (name).
    auto comparison_criterion = [](const Animal* a, const string& searchName) {
        return a->getName() < searchName;
    };

    // 2. Utiliser lower_bound pour trouver le premier élément >= 'name'
    // 'it' sera un itérateur vers le potentiel emplacement de l'animal,
    // ou animals.end() si 'name' est plus grand que tous les noms.
    auto it = lower_bound(
        animals.begin(),
        animals.end(),
        name,
        comparison_criterion
    );

    // 3. Vérifier si l'élément trouvé est bien celui que l'on cherche
    if (it != animals.end() && (*it)->getName() == name) {
        // Si l'élément existe, calculer son indice
        // distance calcule la différence entre l'itérateur de début et 'it'.
        return distance(animals.begin(), it);
    }

    // 4. L'animal n'a pas été trouvé
    return -1;
}

void Zoo::removeAnimalByName(string name) {
    int index = searchAnimalByName(name);

    if (index != -1) {
        // 1. Obtenir l'itérateur de l'élément à supprimer
        auto it = animals.begin() + index;
        delete *it;
        animals.erase(it);

        cout << "L'animal '" << name << "' was removed from Zoo." << endl;
    } else {
        cout << "ERREUR: L'animal '" << name << "' isn't found Zoo." << endl;
    }
}

double Zoo::averageAgForType(string type) const {
    int totalAge = 0;
    int count = 0;

    for (const Animal* animal : animals) {
        string actualType = typeid(*animal).name();

        if (actualType.find(type) != string::npos) {
            totalAge += animal->getAge();
            count++;
        }
    }

    if (count == 0) {
        cout << "Aucun animal de type '" << type << "' trouvé." << endl;
        return 0.0;
    }
    // moyenne
    return static_cast<double>(totalAge) / count;
}

void Zoo::predictTypeWithKNN(const Animal& unknownAnimal, int k, string informationType) const {
    if (informationType == "numerical"){
        KNNDouble knn(k);
        vector<pair<double, double>> trainData;
        vector<string> labels;
        for (const Animal* animal : animals) {
            trainData.push_back({animal->getWeight(), animal->getHeight()});
            if (dynamic_cast<const Mammal*>(animal)) {
                labels.push_back("Mammal");
            } else if (dynamic_cast<const Bird*>(animal)) {
                labels.push_back("Bird");
            } else if (dynamic_cast<const Reptile*>(animal)) {
                labels.push_back("Reptile");
            } else {
                labels.push_back("Unknown");
            }
        }

        pair<double, double> target = {unknownAnimal.getWeight(), unknownAnimal.getHeight()};
        vector<int> neighbors = knn.findNearestNeighbors(trainData, target);

        map<string, int> typeCount;
        for (int idx : neighbors) {
            typeCount[labels[idx]]++;
        }
        string predictedType;
        int maxCount = 0;
        for (const auto& pair : typeCount) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
                predictedType = pair.first;
            }
        }

        cout << "Predicted Type (Numerical) : " << predictedType << endl;
    } else if (informationType == "categorical") {
        KNNString knn(k);
        vector<vector<string>> trainData;
        vector<string> labels;

        for (const Animal* animal : animals) {
            trainData.push_back({animal->getColor(), animal->getDiet(), animal->getHabitat(), animal->getSounds()});
            if (dynamic_cast<const Mammal*>(animal)) {
                labels.push_back("Mammal");
            } else if (dynamic_cast<const Bird*>(animal)) {
                labels.push_back("Bird");
            } else if (dynamic_cast<const Reptile*>(animal)) {
                labels.push_back("Reptile");
            } else {
                labels.push_back("Unknown");
            }
        }

        vector<string> target = {unknownAnimal.getColor(), unknownAnimal.getDiet(), unknownAnimal.getHabitat(), unknownAnimal.getSounds()};
        vector<int> neighbors = knn.findNearestNeighbors(trainData, target);
        map<string, int> typeCount;
        for (int idx : neighbors) {
            typeCount[labels[idx]]++;
        }

        string predictedType;
        int maxCount = 0;
        for (const auto& pair : typeCount) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
                predictedType = pair.first;
            }
        }
        cout << "Predicted Type (Categorical): " << predictedType << endl;
    }
}