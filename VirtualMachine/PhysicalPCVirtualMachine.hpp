#ifndef PHYSICALPCVIRTUALMACHINE_HPP
#define PHYSICALPCVIRTUALMACHINE_HPP


#include "IVirtualMachine.hpp"

class PhysicalPCVirtualMachine : public IVirtualMachine
{
public:
    PhysicalPCVirtualMachine(ProgressObserver* observer, const HardwareParams& params, const std::string& name);
    std::unique_ptr<IVirtualMachine> clone() override;
    void installOS(GuestOS guestOs) override;
    void uninstallOS() override;
    void installApp(const std::string& appName) override;
    void uninstallApp(const std::string& appName) override;
    void execApp(const std::string& appName) override;

private:
    PhysicalPCVirtualMachine(const PhysicalPCVirtualMachine& copy);
    PhysicalPCVirtualMachine & operator = (const PhysicalPCVirtualMachine& copy);
};

#endif // PHYSICALPCVIRTUALMACHINE_HPP
