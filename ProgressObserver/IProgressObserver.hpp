#ifndef IPROGRESSOBSERVER_HPP
#define IPROGRESSOBSERVER_HPP

#include <iostream>
#include <thread>

const int UPDATE_PROGRESS_TIMEOUT = 100;
const int MAX_PERCENT = 100;

class IProgressObserver
{
public:
    virtual ~IProgressObserver() {}
    virtual void setStep(const size_t step) = 0;
    virtual void updateProgress() = 0;
    virtual void endProgress() = 0;
};

#endif // IPROGRESSOBSERVER_HPP
