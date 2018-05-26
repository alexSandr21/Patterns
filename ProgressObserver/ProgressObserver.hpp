#ifndef PROGRESSOBSERVER_HPP
#define PROGRESSOBSERVER_HPP

#include "IProgressObserver.hpp"

class ProgressObserver : public IProgressObserver
{
public:
    explicit ProgressObserver(const size_t step = 5)
        : m_step(step),
          m_total(0) {}

    void setStep(const size_t step) override;
    void updateProgress() override;
    void endProgress() override;

private:
    size_t m_step;
    size_t m_total;
};

#endif // PROGRESSOBSERVER_HPP
