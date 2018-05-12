#ifndef HYPERVVIRTUALMACHINE_HPP
#define HYPERVVIRTUALMACHINE_HPP


#include "IVirtualMachine.hpp"

class HyperVVirtualMachine : public IVirtualMachine
{
public:
    HyperVVirtualMachine(ProgressObserver* observer, const HardwareParams& params, const std::string& name);
    std::unique_ptr<IVirtualMachine> clone() override;
    void installOS(GuestOS guestOs) override;
    void uninstallOS() override;
    void installApp(const std::string& appName) override;
    void uninstallApp(const std::string& appName) override;
    void execApp(const std::string& appName) override;

private:
    HyperVVirtualMachine(const HyperVVirtualMachine& copy);
    HyperVVirtualMachine & operator = (const HyperVVirtualMachine& copy);
};

#endif // HYPERVVIRTUALMACHINE_HPP
