#ifndef SCVMMHYPERVISOR_HPP
#define SCVMMHYPERVISOR_HPP

#include "IHypervisor.hpp"

class SCVMMHypervisor : public IHypervisor
{
public:
    explicit SCVMMHypervisor(IProgressObserver* observer);
private:
    SCVMMHypervisor(const SCVMMHypervisor&) = delete;
    SCVMMHypervisor(SCVMMHypervisor&&) = delete;
    SCVMMHypervisor & operator = (const SCVMMHypervisor&) = delete;
    SCVMMHypervisor & operator = (SCVMMHypervisor&&) = delete;

    friend class SCVMMFactory;

    std::unique_ptr<IVirtualMachine> createVMImpl(const HardwareParams& params, const std::string& name) override;
    void removeVMImpl(const std::string& name) override;
    std::unique_ptr<IVirtualMachine> cloneVMImpl(const std::string& orig_name, const std::string& clone_name) override;

};

#endif // SCVMMHYPERVISOR_HPP
