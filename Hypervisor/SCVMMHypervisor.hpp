#ifndef SCVMMHYPERVISOR_HPP
#define SCVMMHYPERVISOR_HPP

#include "IHypervisor.hpp"

class SCVMMHypervisor : public IHypervisor
{
private:
    explicit SCVMMHypervisor(ProgressObserver* observer);
    SCVMMHypervisor(const SCVMMHypervisor&) = delete;
    SCVMMHypervisor(SCVMMHypervisor&&) = delete;
    SCVMMHypervisor & operator = (const SCVMMHypervisor&) = delete;
    SCVMMHypervisor & operator = (SCVMMHypervisor&&) = delete;

    friend class HypervisorFactory;

    std::unique_ptr<IVirtualMachine> createVMImpl(const HardwareParams& params, const std::string& name) override;
    void removeVMImpl(const std::string& name) override;
    std::unique_ptr<IVirtualMachine> cloneVMImpl(const std::string& orig_name, const std::string& clone_name) override;

};

#endif // SCVMMHYPERVISOR_HPP
