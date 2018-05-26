#include "IHypervisor.hpp"
#include <iostream>

IVirtualMachine* IHypervisor::createVM(const HardwareParams &params, const std::string &name)
{
    auto iter = m_vmMap.find(name);
    if (iter != m_vmMap.cend())
    {
        throw std::runtime_error("Name " + name + " is already exists");
    }
    auto res = m_vmMap.insert(std::make_pair(name,
                                             createVMImpl(params, name)));
    if (!res.second)
    {
        removeVMImpl(name);
        throw std::runtime_error("Error during crating VM " + name);
    }
    std::cout << "VM " << name << " created successfully" << std::endl;
    return (res.first->second).get();
}

void IHypervisor::removeVM(const std::string &name)
{
    auto res = m_vmMap.erase(name);
    if (!res)
    {
        std::cout << "VM " << name << " doesn't exists" << std::endl;
    }
    else
    {
        removeVMImpl(name);
        std::cout << "VM " << name << " removed successfully" << std::endl;
    }
}

IVirtualMachine* IHypervisor::cloneVM(const std::string &orig_name, const std::string &clone_name)
{
    auto iter_orig = m_vmMap.find(orig_name);
    if (iter_orig == m_vmMap.cend())
    {
        throw std::runtime_error("VM with name " + orig_name + " doesn't exists");
    }
    auto iter_clone = m_vmMap.find(clone_name);
    if (iter_clone != m_vmMap.cend())
    {
        throw std::runtime_error("Name " + clone_name + " is already exists");
    }

    auto clone = cloneVMImpl(orig_name, clone_name);
    clone->setName(clone_name);
    auto res = m_vmMap.insert(std::make_pair(clone_name,
                                             std::move(clone)));
    if (!res.second)
    {
        removeVMImpl(clone_name);
        throw std::runtime_error("Error during cloning VM " + orig_name);
    }
    std::cout << "VM " << orig_name << " cloned ot " << clone_name << " successfully" << std::endl;
    return (res.first->second).get();
}

IVirtualMachine* IHypervisor::getVM(const std::string &name)
{
    auto iter = m_vmMap.find(name);
    if (iter == m_vmMap.cend())
    {
        throw std::runtime_error("VM " + name + " doesn't exists");
    }
    return (iter->second).get();
}

std::list<IVirtualMachine *> IHypervisor::getAllVMs()
{
    std::list<IVirtualMachine *> ret;

    for (auto iter = m_vmMap.cbegin(); iter != m_vmMap.cend(); ++iter)
    {
        ret.emplace_back((iter->second).get());
    }
    return ret;
}
