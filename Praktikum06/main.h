#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include <algorithm>

class Dinosaur{
private:
    double weight;
    double maxWeight;
    std::string race;
    bool alive = true;
    bool planteater;
    int ageRate;
    int breedSuccessRate;
    int dinosaurAge = 0;
    std::string deadReason{"wounds by a carnivore"};
public:
    Dinosaur(double maxWeight, const std::string& race, int ageRate, int breedSuccessRate, bool planteater);
    Dinosaur(const Dinosaur& dinosaur);
    /**
     * @brief returns true if the dinosaur died
     */
    bool age();
    virtual bool breed();
    int getAgeRate() const;
    int getBreedSuccessRate() const;
    int getAge() const;
    double getWeight() const;
    double getMaxWeight() const;
    std::string getRace() const;
    void setDeadReason(const std:: string& reason);
    void died();
    bool isAlive() const ;
};


class Herbivoren : public Dinosaur{
    int hideSuccessRate;
public:
    bool hide() const;
    Herbivoren(const Herbivoren& herbivore);
    Herbivoren(int hideSuccessRate, double maxWeight, const std::string &race, int ageRate, int breedSuccessRate);
};

class Carnivore : public Dinosaur {
public:
    bool hunt(std::vector<Herbivoren>& planteaters);
    Carnivore(double maxWeight, const std::string &race, int ageRate, int breedSuccessRate);
    Carnivore(const Carnivore& carnivore);

};


class Park {
private:
    const int maxPopulation = 100;
    std::vector<Herbivoren> planteaters;
    std::vector<Carnivore> cannibals;
public:
    explicit Park(int maxPopulation);
    void passingTime();
    int getPopulation() const;
    int getMaxPopulation() const;

    void printPopulation() const ;
};

#endif // MAIN_H
