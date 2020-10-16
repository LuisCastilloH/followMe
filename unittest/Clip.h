/*
 *     @file Clip.h
 *
 *     @author Luis Castillo
 */

#ifndef CLIP_H
#define CLIP_H

#include <iostream>

/*
    Clip class. Data structure which holds the information of every clip.
*/

class Clip {
    public:
        Clip(); // default constructor
        // parameterized constructor
        Clip(const std::string, const int, const float, const float,
             const std::string, const std::string);
        /*
         * Attribute getters
         */
        const std::string getName();
        const std::string getAction1();
        const std::string getAction2();
        const int getTicksToPlay();
        /*
         * Chooses the following action to execute
         */
        const int chooseAction();
        const int chooseAction(const float&, const float&);
        /*
         * link connectors
         */
        Clip *next;
        Clip *previous;

    private:
        std::string name; // name of the clip
        int ticksToPlay; // times to reproduce clip
        float chance1; // chances to execute action 1
        float chance2; // chances to execute action 2
        std::string action1;
        std::string action2;
};

#endif // CLIPLIST_H

