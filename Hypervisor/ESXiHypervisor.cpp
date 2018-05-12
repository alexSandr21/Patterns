#include "ESXiHypervisor.hpp"
#include "ESXiVirtualMachine.hpp"

ESXiHypervisor::ESXiHypervisor(ProgressObserver *observer)
    : IHypervisor(observer)
{
    std::cout << "ESXiHypervisor created" << std::endl;
}

std::unique_ptr<IVirtualMachine> ESXiHypervisor::createVMImpl(const HardwareParams &params, const std::string &name)
{
    std::cout << "ESXiHypervisor start VM creation..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }

    m_progressObserver->endProgress();
    std::cout << "ESXiHypervisor end VM creation" << std::endl;

    return std::unique_ptr<IVirtualMachine>(new ESXiVirtualMachine(m_progressObserver,
                                                                     params,
                                                                     name));
}

void ESXiHypervisor::removeVMImpl(const std::string &name)
{
    std::cout << "ESXiHypervisor start VM removing..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }

    m_progressObserver->endProgress();
    std::cout << "ESXiHypervisor end VM removing" << std::endl;
}

std::unique_ptr<IVirtualMachine> ESXiHypervisor::cloneVMImpl(const std::string &orig_name, const std::string &clone_name)
{
    std::cout << "ESXiHypervisor start VM cloning..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }

    m_progressObserver->endProgress();
    std::cout << "ESXiHypervisor end VM cloning" << std::endl;

    return getVM(orig_name)->clone();
}
