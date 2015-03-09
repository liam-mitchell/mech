#ifndef __BEHAVIOUR_H_
#define __BEHAVIOUR_H_

#include <memory>

class Level;

class Behaviour {
public:
    virtual bool execute(Level &level, unsigned int dt) = 0;
    virtual bool operator<(const Behaviour &other) const;
private:
    int priority;
};

class BehaviourCompare {
    bool operator()(std::unique_ptr<Behaviour> a, std::unique_ptr<Behaviour> b)
    { return a && b && *a < *b; }
};

#endif // __BEHAVIOUR_H_
