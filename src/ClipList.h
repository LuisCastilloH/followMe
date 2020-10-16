/*
 *     @file ClipList.h
 *
 *     @author Luis Castillo
 */

#ifndef CLIPLIST_H
#define CLIPLIST_H

#include <iostream>

#include "Clip.h"

/*
    ClipList class. Data structure which holds the list of clips.
*/

class ClipList {
    public:
        ClipList(); // default constructor
        /*
         *  Adds a clip to the list, appending it to the end.
         */
        void addClip(Clip *c);
        /*
         *  Returns the position of a clip with the given name if exists
         */
        Clip *exists(std::string);
        /*
         *  Gets stored head pointer
         *  @return pointer to Clip list
         */
        Clip *getHead();
        /*
         *  Displays list of clips
         */
        void display();
        /*
         *  Executes the chosen action, depending if floating point numbers
         *  were given (deterministic) or not (random)
         */
        void executeAction();
        void executeAction(float, float);

    private:
        Clip *head; // pointer to the list head
        int length; // length of the list
};

#endif // CLIPLIST_H
