#include "ProgressObserver.hpp"
#include <string>

const int MAX_PERCENT = 100;

void ProgressObserver::setStep(const size_t step)
{
    m_step = step;
}

void ProgressObserver::updateProgress()
{
    m_total += m_step;
    std::cout << "\r" << (m_total > MAX_PERCENT ? "100" : std::to_string(m_total)) << "%" << std::flush;
}

void ProgressObserver::endProgress()
{
    while(m_total < MAX_PERCENT)
    {
        updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT/10));
    }
    m_total = 0;
    std::cout << std::endl;
}
