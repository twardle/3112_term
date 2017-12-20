# Term project for ITCS 3112 - Evolution Simulator #
---
## Contributors ##
* Candace Allison
* [Tyler Wardle](https://github.com/twardle)
---
## About ##
This project was created as a term project for ITCS 3112 - Objected Oriented Programming. 

This project creates a randomly generated environment and a number of Creatures that initially exist within it. The program performs a user-set number of iterations and as it iterates, creatures interact with the environment an each other - changing their population (gaining/losing members of the population), breeding, or mutating.

Once all iterations have completed, the program generates a chart representing how the species populations have changed over the course of the iterations. Specifics for this data is available to the user in the form of a table. 

---
## Classes ##
### Environment ###
* Biome
* Water Supply
* Water Refill Speed
* Instance of Weather class

### Weather ###
* Seasons
* Seasonal Temperatures
* Changing of Seasons

### Creature ###
* Age
* Diseased or Not
* Health
* List of Traits
* Subclasses:
  * Carnivore
  * Herbivore
  * Omnivore
 
### Trait ###
* Water Need
* Breed Chance
* Herd Tendency
* Temperature Resistance
* Disease Resistance
* Predator Resistance
