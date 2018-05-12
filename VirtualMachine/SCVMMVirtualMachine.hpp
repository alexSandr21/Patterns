#ifndef SCVMMVIRTUALMACHINE_HPP
#define SCVMMVIRTUALMACHINE_HPP

#include "IVirtualMachine.hpp"

class SCVMMVirtualMachine : public IVirtualMachine
{
public:
    SCVMMVirtualMachine(ProgressObserver* observer, const HardwareParams& params, const std::string& name);
    std::unique_ptr<IVirtualMachine> clone() override;
    void installOS(GuestOS guestOs) override;
    void uninstallOS() override;
    void installApp(const std::string& appName) override;
    void uninstallApp(const std::string& appName) override;
    void execApp(const std::string& appName) override;

private:
    SCVMMVirtualMachine(const SCVMMVirtualMachine& copy);
    SCVMMVirtualMachine & operator = (const SCVMMVirtualMachine& copy);
};

#endif // SCVMMVIRTUALMACHINE_HPP
