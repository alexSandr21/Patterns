#include "TestApplication.hpp"


void TestApplication::install()
{
    std::cout << "Installation " << m_name << " started..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }
    m_progressObserver->endProgress();
    std::cout << "Installation " << m_name << " finished" << std::endl;
}

void TestApplication::uninstall()
{
    std::cout << "Uninstallation " << m_name << " started..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }
    m_progressObserver->endProgress();
    std::cout << "Uninstallation " << m_name << " finished" << std::endl;
}

void TestApplication::exec()
{
    std::cout << "Start " << m_name << " execution..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }
    m_progressObserver->endProgress();
    std::cout << "Execution " << m_name << " finished" << std::endl;
}
