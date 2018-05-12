#include "IGuestOS.hpp"

void IGuestOS::installApp(const std::string &appName)
{
    auto iter = m_appMap.find(appName);
    if (iter != m_appMap.cend())
    {
        throw std::runtime_error("Application " + appName + " already installed");
    }
    auto res = m_appMap.insert(std::make_pair(appName,
                                              installAppImpl(appName)));
    if (!res.second)
    {
        uninstallAppImpl(appName);
        throw std::runtime_error("Error during " + appName + " installation");
    }
    std::cout << "Application " << appName << " installed successfully" << std::endl;
}

void IGuestOS::uninstallApp(const std::string &appName)
{
    auto iter = m_appMap.find(appName);
    if (iter == m_appMap.cend())
    {
        std::cout << "Application " << appName << " not installed" << std::endl;
    }
    else
    {
        uninstallAppImpl(appName);
        m_appMap.erase(appName);
        std::cout << "Application " << appName << " uninstalled successfully" << std::endl;
    }
}

void IGuestOS::execApp(const std::string &appName)
{
    auto iter = m_appMap.find(appName);
    if (iter == m_appMap.cend())
    {
        throw std::runtime_error("Application " + appName + " not installed");
    }
    (iter->second)->exec();
}
