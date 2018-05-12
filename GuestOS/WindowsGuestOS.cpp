#include "WindowsGuestOS.hpp"
#include "TestApplication.hpp"

WindowsGuestOS::WindowsGuestOS(const WindowsGuestOS &copy)
    : IGuestOS()
{
    this->m_progressObserver = copy.m_progressObserver;
    for (auto iter = copy.m_appMap.cbegin(); iter != copy.m_appMap.cend(); ++iter)
    {
        this->installApp(iter->first);
    }
}

WindowsGuestOS & WindowsGuestOS::operator =(const WindowsGuestOS &copy)
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

void WindowsGuestOS::install()
{
    std::cout << "WindowsGuestOS installation started..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }
    m_progressObserver->endProgress();
    std::cout << "WindowsGuestOS installation finished" << std::endl;
}

void WindowsGuestOS::uninstall()
{
    std::cout << "WindowsGuestOS uninstallation started..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }
    m_progressObserver->endProgress();
    std::cout << "WindowsGuestOS uninstallation finished" << std::endl;
}

std::unique_ptr<IApplication> WindowsGuestOS::installAppImpl(const std::string &appName)
{
    std::unique_ptr<IApplication> app(new TestApplication(m_progressObserver, appName));
    app->install();
    return std::move(app);
}

void WindowsGuestOS::uninstallAppImpl(const std::string &appName)
{
    auto iter = m_appMap.find(appName);
    (iter->second)->uninstall();
}
