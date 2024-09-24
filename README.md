# Cpp-OOP-Project

This project was developed as part of a workshop for Object-Oriented Programming in C++ and demonstrates key object-oriented principles and practices. The project is divided into three parts, each building on the previous work and continuing to enhance and evolve the system.

The goal of this project is to simulate real-world scenarios where development teams continue working on and improving code that was originally written by other developers.


## Part 1: Gas Stations (Initial Architecture Design)

In the first part of the project, our task was to design the architecture of an organization, and we chose to model a gas station. Our focus was on building the foundational structure of the system, applying object-oriented principles like inheritance and encapsulation. We created a modular and flexible architecture that includes key entities such as vehicles, pumps, employees, customers, and refineries.

After establishing the core design, we handed over the project to a different group, who continued and completed the implementation of the final C++ project. This simulated a real-world scenario where one team sets up the architecture, and another team finalizes the development.



## Part 2: NBA Management System (Continuation and Improvement)

In the second part of the project, we were given a skeletal architecture designed by another group, which modeled an NBA management system. Our task was to continue their work by improving the architecture and implementing all the functions they had outlined in their initial design. We made slight adjustments to the architecture to enhance the system’s efficiency and modularity, ensuring that the final implementation aligned with their original concept while optimizing the code structure.


## Part 3: Continuation and Enhancements

In Part 3, we built on the work from Part 2, adding significant improvements to the system. One of the enhancements was the implementation of a linked list using templates. We used this custom linked list to replace the static array of team owners from Part 2, allowing for more dynamic and efficient management of data.

Additionally, we transitioned from using  `char*`  to the  `std::string`  object from the  `<string>`  library, which improved memory management and reduced potential errors. Following this, we replaced all remaining arrays in the system with lists, ensuring that the data handling throughout the project was consistent and dynamic.

Finally, we implemented three key design patterns to make the system more modular and flexible:

-   **Decorator**: We added the ability to assign specific titles to players, along with the year they received them (e.g., "MVP 2022"). This allowed for dynamic enhancement of player objects without modifying their base class.
-   **Abstract Factory**: We organized the creation of objects that inherit from the  `Person`  class (such as players, referees, and team owners) through the use of an abstract factory, simplifying and standardizing object creation.
-   **Singleton**: Ensured that only one instance of the league exists throughout the system, maintaining control over global access to the league.


# Contact

For any questions or support, please contact:

 **Shachar Zeharia** - shacharz2000@gmail.com
 
 **Maxim Feldman** - maxim95@windowslive.com


