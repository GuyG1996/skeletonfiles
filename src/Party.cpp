#include "Party.h"

//contructor
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
}

//destructor
Party::~Party() 
{
    if(mJoinPolicy) delete mJoinPolicy;
};

//copy contructor
Party::Party(const Party& other)
{
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    //mJoinPolicy = ??
    mState = other.mState;
};

//copy assignment operator
Party& Party::operator=(const Party &other)
{
    if(this != &other)
    {
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;  
        this->mJoinPolicy = other.mJoinPolicy;
        delete mJoinPolicy;
        mState = other.mState;
    }
    return *this;
};

//move contructor
Party::Party(Party&& other)
{
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy = other.mJoinPolicy;
    other.mJoinPolicy = nullptr;
    mState = other.mState;
};

State Party::getState() const
{

    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    // TODO: implement this method
}
