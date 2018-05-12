#include "PhysicalPCHypervisor.hpp"
#include "PhysicalPCVirtualMachine.hpp"

PhysicalPCHypervisor::PhysicalPCHypervisor(ProgressObserver *observer)
    : IHypervisor(observer)
{
    std::cout << "PhysicalPCHypervisor created" << std::endl;
}

std::unique_ptr<IVirtualMachine> PhysicalPCHypervisor::createVMImpl(const HardwareParams &params, const std::string &name)
{
    std::cout << "PhysicalPCHypervisor start VM creation..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }

    m_progressObserver->endProgress();
    std::cout << "PhysicalPCHypervisor end VM creation" << std::endl;

    return std::unique_ptr<IVirtualMachine>(new PhysicalPCVirtualMachine(m_progressObserver,
                                                                     params,
                                                                     name));
}

void PhysicalPCHypervisor::removeVMImpl(const std::string &name)
{
    std::cout << "PhysicalPCHypervisor start VM removing..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }

    m_progressObserver->endProgress();
    std::cout << "PhysicalPCHypervisor end VM removing" << std::endl;
}

std::unique_ptr<IVirtualMachine> PhysicalPCHypervisor::cloneVMImpl(const std::string &orig_name, const std::string &clone_name)
{
    std::cout << "PhysicalPCHypervisor start VM cloning..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }

    m_progressObserver->endProgress();
    std::cout << "PhysicalPCHypervisor end VM cloning" << std::endl;

    return getVM(orig_name)->clone();
}

