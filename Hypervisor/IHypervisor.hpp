#ifndef IHYPERVISOR_HPP
#define IHYPERVISOR_HPP

#include <map>
#include <vector>
#include <memory>
#include "IVirtualMachine.hpp"
#include "ProgressObserver.hpp"

enum HypervisorType
{
    HyperV,
    ESXi,
    SCVMM,
    PhysicalPC
};

class IHypervisor
{
public:
    explicit IHypervisor(ProgressObserver* observer)
        : m_progressObserver(observer) {}
    virtual ~IHypervisor(){}
    IVirtualMachine* createVM(const HardwareParams& params, const std::string& name);
    void removeVM(const std::string& name);
    IVirtualMachine* cloneVM(const std::string& orig_name, const std::string& clone_name);
    IVirtualMachine* getVM(const std::string& name);
    std::vector<IVirtualMachine*> getAllVMs();

protected:
    ProgressObserver* m_progressObserver;
    std::map<std::string, std::unique_ptr<IVirtualMachine>> m_vmMap;

private:
    virtual std::unique_ptr<IVirtualMachine> createVMImpl(const HardwareParams& params, const std::string& name) = 0;
    virtual void removeVMImpl(const std::string& name) = 0;
    virtual std::unique_ptr<IVirtualMachine> cloneVMImpl(const std::string& orig_name, const std::string& clone_name) = 0;

};

#endif // IHYPERVISOR_HPP
