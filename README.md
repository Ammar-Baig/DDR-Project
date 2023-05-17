Doctors and Nurses Simulation Program
This repository contains a C++ program that simulates a scenario involving doctors and nurses in a hospital setting. The program aims to showcase the interaction and collaboration between doctors and nurses, highlighting their roles and responsibilities within a healthcare environment.

Program Structure
The code consists of three classes: Doctor, ListOfDoctors, and Nurse.

The Doctor class is an abstract class that serves as the base class for the specialized doctor classes, namely Male and Female. It defines virtual functions that represent common actions performed by doctors, such as getting fed, drinking, receiving compliments, and changing their mood. The specialized doctor classes inherit from the Doctor class and implement these functions based on their specific characteristics.

The ListOfDoctors class is a linked list implementation that manages a collection of doctors. It provides methods to insert new doctors into the list and delete doctors based on their position. This class enables dynamic management of doctors and facilitates easy addition or removal of doctors during program execution.

The Nurse class represents a nurse and encapsulates their actions and interactions with doctors. It has member functions such as feeding doctors, providing them with water, giving compliments, and checking their mood to determine if they can continue working. The nurse class interacts with the ListOfDoctors class to access and modify the list of doctors as necessary.

Program Execution
The program executes a simulation by creating instances of doctors and a nurse. It initializes the ListOfDoctors class to store the doctors and establishes the nurse's interactions with them. The simulation progresses in a sequential manner, with each iteration representing a turn for the nurse to perform tasks and observe the doctors' moods.

During each turn, the nurse starts by refreshing the doctors' states, ensuring they are hungry, sober, and without any received compliments. The nurse then proceeds to feed the doctors and provide them with drinks, based on their gender and specific needs. Additionally, the nurse may provide compliments to the doctors, depending on the simulation scenario.

After each interaction, the nurse checks the doctors' moods to determine if they are happy and willing to continue working. If all doctors are in a good mood, the simulation proceeds to the next turn; otherwise, it concludes, and the program displays the doctors' names who will not continue.

Purpose and Usage
This program serves as a demonstration of object-oriented programming principles and provides insight into the dynamic interactions between doctors and nurses. It can be used as a learning resource to understand class inheritance, linked list data structures, and program flow control in C++.

Feel free to explore, modify, and enhance this program to suit your specific needs. You can use it as a basis for further development, extend its functionalities, or integrate it into larger healthcare simulation projects.
