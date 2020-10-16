# Follow me

Follow me is a simulation of a set of musical clips. Clips start playing when they are triggered. Clips can also have Follow Actions , which allow creating groups of clips that can trigger each other. 

A clip can have one or two Follow Actions that define what happens after a clip has been playing for a set amount of time. Every Follow Action has an associated Chance value that controls the likelihood of each of the two Follow Actions occurring.

This project was based in the problem provided by the ableton company.
## Installation

The project comes ready to execute (application and testing) but you have the option to compile the source code and testing configuration again. 

For the source code you need to locate in the src/ folder and use the make command.

```bash
make
```

For the testing configuration you need to locate in the unittest folder and execute the following commands.

```bash
mkdir build
cmake -S . -B build/
make -C build/
```

## Usage

Application (you need to be located in the src/ folder)
```bash
./followMe
```
In the application you have the option -h to get help.

Once the application is running you need to provide valid inputs. The inputs are of two types.

First, you need to provide all the clips to be played. It creates a named clip with a set of properties. (The name of the clip has to be a word without spaces.)

```bash
clip <name> <ticks to play> <follow chance1> <follow chance 2> <action1> <action2>
```

Second, you need the ticks command, which runs the program a certain number of ticks.
If the optional list of floating point numbers is provided the output is made deterministic, otherwise the output is random (taking into account the chances of every action)

```bash
ticks <ticks to play> <...optional list of floating point numbers>
```

Testing (you need to be located in the unittest/build/ folder)
```bash
./unitTest
```

## Design

This project was designed and approached using a double linked list to store the different clips. 
The mentioned data structure provides the attributes and methods needed to solve the whole problem.

## Authors

* **Luis Castillo**
