#ifndef __BEHAVIOUR_H_
#define __BEHAVIOUR_H_

#include <memory>

class Level;

class Behaviour {
public:
    Behaviour(int priority);

    virtual bool execute(Level &level, unsigned int dt) = 0;
    virtual bool operator<(const Behaviour &other) const;
protected:
    int priority;
};

class BehaviourCompare {
public:
    bool operator()(std::shared_ptr<Behaviour> a, std::shared_ptr<Behaviour> b)
    { return a && b && *a < *b; }
};

#endif // __BEHAVIOUR_H_
