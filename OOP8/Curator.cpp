//
// Created by zamazan4ik on 21.09.16.
//

#include "Curator.hpp"
#include "Express.hpp"

void Curator::iCanModify(Express& express)
{
    express.turboSpeed_ = 42;
}
