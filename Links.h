//
// Created by Samina Faheem on 6/15/2022.
//

#ifndef INC_22SU_PA03_LINKS_H
#define INC_22SU_PA03_LINKS_H

#include "DSString.h"
#include "DSVector.h"
#include "DSAdjacencyList.h"
#include "DSLinkedList.h"
#include "DSListNode.h"
#include "Paths.h"

class Links {
public:
    Links(DSString, DSString);

 private:
    DSAdjacencyList<DSString> lists;
    DSLinkedList<DSLinkedList<DSLinkedList<DSString>>> results;
    DSVector<Paths> paths;

    void readfile(DSString);
    void iterative_backtracking(DSString, DSString);
    void Outputfile(DSString);

};


#endif //INC_22SU_PA03_LINKS_H
