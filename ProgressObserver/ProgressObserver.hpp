#ifndef PROGRESSOBSERVER_HPP
#define PROGRESSOBSERVER_HPP

#include <iostream>
#include <thread>

const int UPDATE_PROGRESS_TIMEOUT = 100;

class ProgressObserver
{
public:
    explicit ProgressObserver(const size_t step = 5)
        : m_step(step),
          m_total(0) {}

    void setStep(const size_t step);
    void updateProgress();
    void endProgress();

private:
    size_t m_step;
    size_t m_total;
};

#endif // PROGRESSOBSERVER_HPP
