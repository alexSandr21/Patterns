#ifndef WINDOWSGUESTOS_HPP
#define WINDOWSGUESTOS_HPP

#include "IGuestOS.hpp"

class WindowsGuestOS : public IGuestOS
{
public:
    explicit WindowsGuestOS(ProgressObserver* observer)
        : IGuestOS(observer){}
    WindowsGuestOS(const WindowsGuestOS& copy);
    WindowsGuestOS & operator = (const WindowsGuestOS& copy);

    void install() override;
    void uninstall() override;

private:
    std::unique_ptr<IApplication> installAppImpl(const std::string& appName) override;
    void uninstallAppImpl(const std::string& appName) override;

};

#endif // WINDOWSGUESTOS_HPP
