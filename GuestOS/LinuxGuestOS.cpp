#include "LinuxGuestOS.hpp"
#include "TestApplication.hpp"

LinuxGuestOS::LinuxGuestOS(const LinuxGuestOS &copy)
    : IGuestOS()
{
    this->m_progressObserver = copy.m_progressObserver;
    for (auto iter = copy.m_appMap.cbegin(); iter != copy.m_appMap.cend(); ++iter)
    {
        this->installApp(iter->first);
    }
}

LinuxGuestOS & LinuxGuestOS::operator =(const LinuxGuestOS &copy)
{
    if (this != &copy)
    {
        this->m_progressObserver = copy.m_progressObserver;
        for (auto iter = copy.m_appMap.cbegin(); iter != copy.m_appMap.cend(); ++iter)
        {
            this->installApp(iter->first);
        }
    }
    return *this;
}

void LinuxGuestOS::install()
{
    std::cout << "LinuxGuestOS installation started..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }
    m_progressObserver->endProgress();
    std::cout << "LinuxGuestOS installation finished" << std::endl;
}

void LinuxGuestOS::uninstall()
{
    std::cout << "LinuxGuestOS uninstallation started..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }
    m_progressObserver->endProgress();
    std::cout << "LinuxGuestOS uninstallation finished" << std::endl;
}

std::unique_ptr<IApplication> LinuxGuestOS::installAppImpl(const std::string &appName)
{
    std::unique_ptr<IApplication> app(new TestApplication(m_progressObserver, appName));
    app->install();
    return std::move(app);
}

void LinuxGuestOS::uninstallAppImpl(const std::string &appName)
{
    auto iter = m_appMap.find(appName);
    (iter->second)->uninstall();
}
