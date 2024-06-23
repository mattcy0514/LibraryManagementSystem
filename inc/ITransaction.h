#ifndef ITRANSACTION_H_
#define ITRANSACTION_H_
class ITransaction {
    public:
    virtual void execute() = 0;
};
#endif