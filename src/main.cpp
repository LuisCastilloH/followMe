/*
 *     @file main.cpp
 *
 *     @author Luis Castillo
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "ClipList.h"


/*     Plays the clips stored in the list containing all
 *          the data needed
 *
 *     @param ClipList list of clips
 *     @param int number of ticks to play
 *     @param vector<float> list of points
 *     @see ClipList.h and Clip.h
 */

void play (ClipList *clips, int master_ticks, const std::vector<float> &points);

// Prints usage
void showUsage(std::string name);

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    ClipList *clips = new ClipList(); // creation of list to store clips
    std::string keyword = "";
    std::string name, act1, act2, line;
    int ticks, master_ticks;
    float prob1, prob2, point;
    std::vector<float> points;

    // print usage if requested
    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "-h" || arg == "--help") {
            showUsage(argv[0]);
            return 0;
        }
    }

    // loop to read input data from console
    while(keyword != "ticks") {
        std::cin >> keyword;
        if (keyword == "clip") {
            std::cin >> name >> ticks >> prob1 >> prob2 >> act1 >> act2;
            // new clip added to the list
            Clip *temp = new Clip(name, ticks, prob1, prob2, act1, act2);
            clips->addClip(temp);
        }
        else if(keyword == "ticks") {
            // trigger to start the playlist
            std::cin >> master_ticks;
            // optional list of floating point numbers (stored in a vector)
            std::getline(std::cin, line);
            if (!line.empty()) {
                std::istringstream stream (line);
                while (stream >> point) {
                    points.push_back(point);
                }
            }
        }
        else {
            std::cout << "Incorrect input. Exit program." << std::endl;
            return 0;
        }
    }

    play(clips, master_ticks, points);
    delete clips;
    return 0;
}

void play(ClipList *clips, int master_ticks, const std::vector<float> &points) {
    int cont = 0;
    int local_cont = 0;
    Clip *ptr;
    // loop to play the clips
    while (cont < master_ticks) {
        ptr = clips->getHead();
        // if not floating points provided, random behavior
        if (points.empty()) {
            // loop to play the ticks (according to the ticks to play given)
            while (local_cont < ptr->getTicksToPlay()) {
                std::cout << ptr->getName() << std::endl;
                local_cont++;
                cont++;
                if(cont > master_ticks)
                    return;
            }
            // method to execute the next action
            clips->executeAction();
            local_cont = 0;
        }
        // if floating points provided, deterministic behavior
        else {
            std::cout << ptr->getName() << std::endl;
            clips->executeAction(points[cont*2], points[cont*2+1]);
            cont++;
        }
    }
    delete ptr;
}

void showUsage(std::string name) {
        std::cout << "Usage: " << name << "  [OPTIONS]" << "\n"
		<< "\t-h, --help    Displays this help and exists\n"
        << "Play (print) a list of clips for an amount of ticks given.\n"
        << "Input format: \n"
        << "\tclip <name> <ticks to play> <follow chance1> <follow chance2> "
        << "<action1> <action2> \n"
        << "\t...\n"
        << "\tticks <ticks to play> <...optional list of floating point numbers>\n"
        << std::endl;
}
