#include "HyperVHypervisor.hpp"
#include "HyperVVirtualMachine.hpp"

HyperVHypervisor::HyperVHypervisor(IProgressObserver *observer)
    : IHypervisor(observer)
{
    std::cout << "HyperVHypervisor created" << std::endl;
}

std::unique_ptr<IVirtualMachine> HyperVHypervisor::createVMImpl(const HardwareParams &params, const std::string &name)
{
    std::cout << "HyperVHypervisor start VM creation..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }

    m_progressObserver->endProgress();
    std::cout << "HyperVHypervisor end VM creation" << std::endl;

    return std::unique_ptr<IVirtualMachine>(new HyperVVirtualMachine(m_progressObserver,
                                                                     params,
                                                                     name));
}

void HyperVHypervisor::removeVMImpl(const std::string &name)
{
    std::cout << "HyperVHypervisor start VM removing..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }

    m_progressObserver->endProgress();
    std::cout << "HyperVHypervisor end VM removing" << std::endl;
}

std::unique_ptr<IVirtualMachine> HyperVHypervisor::cloneVMImpl(const std::string &orig_name, const std::string &clone_name)
{
    std::cout << "HyperVHypervisor start VM cloning..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }

    m_progressObserver->endProgress();
    std::cout << "HyperVHypervisor end VM cloning" << std::endl;

    return getVM(orig_name)->clone();
}
