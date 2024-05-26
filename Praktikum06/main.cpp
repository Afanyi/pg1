
#include "main.h"




int main()
{
    char uselessInput;
    Park park{100};
    while (true) {
        park.printPopulation();
        park.passingTime();

        std::cin >> uselessInput;
    }
}
Dinosaur::Dinosaur(const Dinosaur& dinosaur): Dinosaur(dinosaur.maxWeight,dinosaur.race,dinosaur.ageRate,dinosaur.breedSuccessRate,dinosaur.planteater){

}

Dinosaur::Dinosaur( double maxWeight, const std::string& race, int ageRate, int breedSuccessRate, bool planteater):  maxWeight(maxWeight), race(race), ageRate(ageRate),breedSuccessRate(breedSuccessRate),planteater(planteater)
{
    srand (std::time(nullptr));
    if (planteater)
        weight = 0.05* maxWeight;
    else
        weight = 0.2 * maxWeight;
}


double Dinosaur::getWeight() const
{
    return weight;
}


double Dinosaur::getMaxWeight() const
{
    return maxWeight;
}

std::string Dinosaur::getRace() const
{
    return race;
}


bool Dinosaur::age()
{

    if(weight<= maxWeight) {
        weight = weight + weight* ageRate/100;
    }
    else {
        if ((rand()%99) < ageRate) {
            deadReason = "age";
            return true;
        }
    }
    if (weight > maxWeight)
        weight = maxWeight;
    dinosaurAge++;
    return false;
}



bool Dinosaur::breed()
{
    if (rand()%99 < breedSuccessRate) {
        return true;
    }
    return false;

}

void Dinosaur::setDeadReason(const std::string& reason) {
    deadReason = reason;

}

void Dinosaur::died() {
    alive = false;
}

bool Dinosaur::isAlive() const {
    return alive;
}

int Dinosaur::getAge() const {
    return dinosaurAge;
}

int Dinosaur::getBreedSuccessRate() const {
    return breedSuccessRate;
}

int Dinosaur::getAgeRate() const {
    return ageRate;
}


bool Herbivoren::hide() const
{
    if ((rand()%99) < hideSuccessRate) {
        return true;
    }
    return false;
}

Herbivoren::Herbivoren(int hideSuccessRate,  double maxWeight, const std::string &race, int ageRate, int breedSuccessRate) : Dinosaur(maxWeight, race, ageRate, breedSuccessRate, true),
                                                                                                                                      hideSuccessRate(hideSuccessRate)
{

}
Herbivoren::Herbivoren(const Herbivoren& herbivore): Dinosaur(herbivore.getMaxWeight(), herbivore.getRace(), herbivore.getAgeRate(), herbivore.getBreedSuccessRate(), true),
                                                     hideSuccessRate(herbivore.hideSuccessRate) {}


Carnivore::Carnivore(double maxWeight, const std::string &race, int ageRate, int breedSuccessRate) : Dinosaur(maxWeight, race, ageRate, breedSuccessRate, false)
{

}
Carnivore::Carnivore(const Carnivore& carnivore): Dinosaur(carnivore.getMaxWeight(), carnivore.getRace(), carnivore.getAgeRate(), carnivore.getBreedSuccessRate(), true)
                                                      {}

bool Carnivore::hunt(std::vector<Herbivoren>& planteaters)
{
    if (planteaters.empty())
        return false;

    bool down {true};
    for (int i=0; i <=1;i++ ){
        int n = rand() % planteaters.size();
        while (not planteaters[n].isAlive()){
            if (n==0)
                down = false;
            if (down)
                n = n-1;
            else
                n = n+1;
        }

        if (getWeight() > planteaters[n].getWeight() and not planteaters[n].hide() ) {
            planteaters[n].died();
            return true;
        }
    }
    Dinosaur::setDeadReason("starvation");
    return false;
}




int Park::getMaxPopulation() const
{
    return maxPopulation;
}





Park::Park(int maxPopulation) : maxPopulation(maxPopulation)
{
    planteaters.reserve(128);
    cannibals.reserve(128);
    double maxWeight = 30000;
    for (int i=0; i<4;i++)
        planteaters.emplace_back(0,maxWeight,"Brachiosaurus",20,10);
    maxWeight = 500;
    for (int i=0; i<10;i++)
        planteaters.emplace_back(0, maxWeight,"Parasaurolophus",75, 85);
    maxWeight = 500;
    for (int i=0; i<5;i++)
        cannibals.emplace_back(maxWeight,"Raptor",30,20);
    maxWeight = 8000;
    for (int i=0; i<2;i++)
        cannibals.emplace_back(maxWeight,"T-Rex",20,8);
}



void Park::printPopulation() const {
    for (const auto& e: cannibals) {
        if (e.isAlive())
            std::cout << e.getRace() << ":" << e.getWeight() << " of " << e.getMaxWeight() << " with age: " << e.getAge() << std::endl;
    }
    std::cout << "\r\n";

    for (const auto& e: planteaters) {
        if (e.isAlive())
            std::cout << e.getRace() << ":" << e.getWeight() << " of " << e.getMaxWeight() << " with age: "  << e.getAge() << std::endl;
    }
    std::cout << getPopulation() << std::endl;
}

void Park::passingTime() {
    for (auto& cannibal: cannibals) {
        if (cannibal.isAlive()) {
            if (not cannibal.hunt(planteaters) or cannibal.age()) {
                cannibal.died();
            } else {
                if (cannibal.breed() and getPopulation() < getMaxPopulation())
                    cannibals.emplace_back(cannibal);
            }

        }

    }
    for (auto& planteater: planteaters) {
        if (planteater.isAlive()) {
            if (planteater.age())
                planteater.died();
            else {
                if (planteater.breed() and getPopulation() < getMaxPopulation()) {
                    if (planteater.getRace() == "Parasaurolophus" and getPopulation() +2 < getMaxPopulation()) {
                        for (int n = 0; n < 3; n++)
                            planteaters.emplace_back(planteater);
                    } else {
                        planteaters.emplace_back(planteater);
                    }
                }
            }
        }
    }



}

int Park::getPopulation() const {
    int population = 0;
    for (auto const& e: cannibals){
        if (e.isAlive())
            population++;
    }
    for (auto const& e: planteaters){
        if (e.isAlive())
            population++;
    }
    return population;
}
