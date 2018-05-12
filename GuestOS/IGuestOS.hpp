#ifndef IGUESTOS_HPP
#define IGUESTOS_HPP

#include <map>
#include <memory>
#include <iostream>
#include "IApplication.hpp"

enum GuestOS
{
    Linux,
    Windows
};

class IGuestOS
{
public:
    explicit IGuestOS() {}
    explicit IGuestOS(ProgressObserver* observer)
        : m_progressObserver(observer) {}
    virtual ~IGuestOS() {}

    virtual void install() = 0;
    virtual void uninstall() = 0;
    void installApp(const std::string& appName);
    void uninstallApp(const std::string& appName);
    void execApp(const std::string& appName);

protected:
    ProgressObserver* m_progressObserver;
    std::map<std::string, std::unique_ptr<IApplication>> m_appMap;

private:
    virtual std::unique_ptr<IApplication> installAppImpl(const std::string& appName) = 0;
    virtual void uninstallAppImpl(const std::string& appName) = 0;
};

#endif // IGUESTOS_HPP
