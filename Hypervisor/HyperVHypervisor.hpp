#ifndef HYPERVHYPERVISOR_HPP
#define HYPERVHYPERVISOR_HPP

#include "IHypervisor.hpp"


class HyperVHypervisor : public IHypervisor
{
private:
    explicit HyperVHypervisor(ProgressObserver* observer);
    HyperVHypervisor(const HyperVHypervisor&) = delete;
    HyperVHypervisor(HyperVHypervisor&&) = delete;
    HyperVHypervisor & operator = (const HyperVHypervisor&) = delete;
    HyperVHypervisor & operator = (HyperVHypervisor&&) = delete;

    friend class HypervisorFactory;

    std::unique_ptr<IVirtualMachine> createVMImpl(const HardwareParams& params, const std::string& name) override;
    void removeVMImpl(const std::string& name) override;
    std::unique_ptr<IVirtualMachine> cloneVMImpl(const std::string& orig_name, const std::string& clone_name) override;

};

#endif // HYPERVHYPERVISOR_HPP
