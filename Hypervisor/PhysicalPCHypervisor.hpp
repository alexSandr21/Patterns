#ifndef PHYSICALPCHYPERVISOR_HPP
#define PHYSICALPCHYPERVISOR_HPP


#include "IHypervisor.hpp"

class PhysicalPCHypervisor : public IHypervisor
{
private:
    explicit PhysicalPCHypervisor(ProgressObserver* observer);
    PhysicalPCHypervisor(const PhysicalPCHypervisor&) = delete;
    PhysicalPCHypervisor(PhysicalPCHypervisor&&) = delete;
    PhysicalPCHypervisor & operator = (const PhysicalPCHypervisor&) = delete;
    PhysicalPCHypervisor & operator = (PhysicalPCHypervisor&&) = delete;

    friend class HypervisorFactory;

    std::unique_ptr<IVirtualMachine> createVMImpl(const HardwareParams& params, const std::string& name) override;
    void removeVMImpl(const std::string& name) override;
    std::unique_ptr<IVirtualMachine> cloneVMImpl(const std::string& orig_name, const std::string& clone_name) override;

};

#endif // PHYSICALPCHYPERVISOR_HPP
