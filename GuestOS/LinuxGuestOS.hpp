#ifndef LINUXGUESTOS_HPP
#define LINUXGUESTOS_HPP

#include "IGuestOS.hpp"

class LinuxGuestOS : public IGuestOS
{
public:
    explicit LinuxGuestOS(ProgressObserver* observer)
        : IGuestOS(observer){}
    LinuxGuestOS(const LinuxGuestOS& copy);
    LinuxGuestOS & operator = (const LinuxGuestOS& copy);

    void install() override;
    void uninstall() override;

private:
    std::unique_ptr<IApplication> installAppImpl(const std::string& appName) override;
    void uninstallAppImpl(const std::string& appName) override;

};

#endif // LINUXGUESTOS_HPP
