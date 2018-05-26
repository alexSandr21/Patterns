#ifndef ESXIHYPERVISOR_HPP
#define ESXIHYPERVISOR_HPP

#include "IHypervisor.hpp"

class ESXiHypervisor : public IHypervisor
{
public:
    explicit ESXiHypervisor(IProgressObserver* observer);
private:
    ESXiHypervisor(const ESXiHypervisor&) = delete;
    ESXiHypervisor(ESXiHypervisor&&) = delete;
    ESXiHypervisor & operator = (const ESXiHypervisor&) = delete;
    ESXiHypervisor & operator = (ESXiHypervisor&&) = delete;

    friend class ESXiFactory;

    std::unique_ptr<IVirtualMachine> createVMImpl(const HardwareParams& params, const std::string& name) override;
    void removeVMImpl(const std::string& name) override;
    std::unique_ptr<IVirtualMachine> cloneVMImpl(const std::string& orig_name, const std::string& clone_name) override;

};

#endif // ESXIHYPERVISOR_HPP
