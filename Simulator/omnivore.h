/*
 * Omnivore.h
 *
 *  Created on: Nov 6, 2017
 *      Author: Tyler
*/

#ifndef OMNIVORE_H_
#define OMNIVORE_H_

#include "creature.h"
#include "herbivore.h"

class Omnivore : public Creature {
private:
    bool herding = false;
public:
    Omnivore(){}
    Omnivore(Creature & creature){}
    bool hunt(Creature & prey){
        float currHealth = prey.getHealth();
        if(prey.getPredatorResist() > 1)
            prey.updateHealth(prey.getPredatorResist() - 2);
        else
            prey.setHealth(0);

        if(currHealth < prey.getHealth())
            prey.setHealth(currHealth);

        if(prey.getHealth() <= 0)
            return true;
        else
            return false;
    };

    bool hunt(Herbivore prey){
        float currHealth = prey.getHealth();
        if(prey.getHerding()){
            if(prey.getPredatorResist() + 0.5 > 1)
                prey.updateHealth(prey.getPredatorResist() - 1.5);
            else
                prey.setHealth(0);

            if(currHealth < prey.getHealth())
                prey.setHealth(currHealth);

            if(prey.getHealth() <= 0)
                return true;
            else
                return false;
        }
        else if(prey.getPredatorResist() > 1)
            prey.updateHealth(prey.getPredatorResist() - 2);
        else
            prey.setHealth(0);

        if(currHealth < prey.getHealth())
            prey.setHealth(currHealth);

        if(prey.getHealth() <= 0)
            return true;
        else
            return false;

        return false;
    };

    bool hunt(Omnivore prey){
        float currHealth = prey.getHealth();
        if(prey.getHerding()){
            if(prey.getPredatorResist() + 0.5 > 1)
                prey.updateHealth(prey.getPredatorResist() - 1.5);
            else
                prey.setHealth(0);

            if(currHealth < prey.getHealth())
                prey.setHealth(currHealth);

            if(prey.getHealth() <= 0)
                return true;
            else
                return false;
        }
        else if(prey.getPredatorResist() > 1)
            prey.updateHealth(prey.getPredatorResist() - 2);
        else
            prey.setHealth(0);

        if(currHealth < prey.getHealth())
            prey.setHealth(currHealth);

        if(prey.getHealth() <= 0)
            return true;
        else
            return false;

        return false;
    };

    void herd(){
            if(herdTendency > .5)
                herding = true;
        };

        bool getHerding(){
            return herding;
        };
};

#endif /* OMNIVORE_H_ */
