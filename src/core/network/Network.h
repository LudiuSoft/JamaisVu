//
// Created by chemicalchems on 29/03/16.
//

#ifndef JAMAISVU_NETWORK_H
#define JAMAISVU_NETWORK_H

#include <iostream>
#include "Generation.h"

class Network {
public:
    Network(Generation);
    Generation currentGeneration; // Necessary, otherwise it'd use the default constructor (Unnecessary performance waste)
};                                // Pat, make an empty constructor. The default constructor could be used
                                  // it only allocates memory for the object, plus an object isn't a pointer.
                                  // You can't assign a pointer to an object, neither can you dereference nullptr,
                                  // since it's a void* pointer. Best option would be this one or instantiating the
                                  // object in the constructor for Network and call an empty constructor.
                                  // Talk to me this afternoon, I'll explain if you don't understand.

#endif //JAMAISVU_NETWORK_H
