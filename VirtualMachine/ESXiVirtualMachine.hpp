#ifndef ESXIVIRTUALMACHINE_HPP
#define ESXIVIRTUALMACHINE_HPP

#include "IVirtualMachine.hpp"

class ESXiVirtualMachine : public IVirtualMachine
{
public:
    ESXiVirtualMachine(IProgressObserver* observer, const HardwareParams& params, const std::string& name);
    std::unique_ptr<IVirtualMachine> clone() override;
    void installOS(GuestOS guestOs) override;
    void uninstallOS() override;
    void installApp(const std::string& appName) override;
    void uninstallApp(const std::string& appName) override;
    void execApp(const std::string& appName) override;

private:
    ESXiVirtualMachine(const ESXiVirtualMachine& copy);
    ESXiVirtualMachine & operator = (const ESXiVirtualMachine& copy);
};
#endif // ESXIVIRTUALMACHINE_HPP
