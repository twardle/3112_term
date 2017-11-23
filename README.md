# Term project for ITCS 3112 - Evolution Simulator #
---
## Contributors ##
* Candace Allison
* [Tyler Wardle](https://github.com/twardle)
---
## Note: ##

To compile class only C++ file: 
`g++ -c <file>.cpp`

To link 2 classes together
* For testing purposes
* Assume one class uses the other as a variable
* Assume the class using the other contains a main method
* To do this, be sure to compile each class separately 

`g++ -o Class1 class1.o class2.o`

`To iterate through the creature array:`
	`for(it = cList.begin(); it != cList.end(); it++){`
		`Creature val = *it;`
		`std::cout << val.getAge() << std::endl;`
	`}`
