#include "SCVMMHypervisor.hpp"
#include "SCVMMVirtualMachine.hpp"

SCVMMHypervisor::SCVMMHypervisor(IProgressObserver *observer)
    : IHypervisor(observer)
{
    std::cout << "SCVMMHypervisor created" << std::endl;
}

std::unique_ptr<IVirtualMachine> SCVMMHypervisor::createVMImpl(const HardwareParams &params, const std::string &name)
{
    std::cout << "SCVMMHypervisor start VM creation..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }

    m_progressObserver->endProgress();
    std::cout << "SCVMMHypervisor end VM creation" << std::endl;

    return std::unique_ptr<IVirtualMachine>(new SCVMMVirtualMachine(m_progressObserver,
                                                                     params,
                                                                     name));
}

void SCVMMHypervisor::removeVMImpl(const std::string &name)
{
    std::cout << "SCVMMHypervisor start VM removing..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }

    m_progressObserver->endProgress();
    std::cout << "SCVMMHypervisor end VM removing" << std::endl;
}

std::unique_ptr<IVirtualMachine> SCVMMHypervisor::cloneVMImpl(const std::string &orig_name, const std::string &clone_name)
{
    std::cout << "SCVMMHypervisor start VM cloning..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        m_progressObserver->updateProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PROGRESS_TIMEOUT));
    }

    m_progressObserver->endProgress();
    std::cout << "SCVMMHypervisor end VM cloning" << std::endl;

    return getVM(orig_name)->clone();
}
