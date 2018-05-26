#include "HyperVVirtualMachine.hpp"
#include "GuestOSFactory.hpp"

HyperVVirtualMachine::HyperVVirtualMachine(IProgressObserver *observer, const HardwareParams &params, const std::string &name)
    : IVirtualMachine(observer, params, name)
{
    std::cout << "HyperVVirtualMachine created" << std::endl;
}

std::unique_ptr<IVirtualMachine> HyperVVirtualMachine::clone()
{
    std::cout << "HyperVVirtualMachine cloned" << std::endl;
    return std::unique_ptr<IVirtualMachine>(new HyperVVirtualMachine(*this));
}

void HyperVVirtualMachine::installOS(GuestOS guestOs)
{
    m_guestOS.reset();
    m_guestOS = GuestOSFactory::getFactory().getGuestOS(guestOs, m_progressObserver);
    m_osType = guestOs;
    m_guestOS->install();
}

void HyperVVirtualMachine::uninstallOS()
{
    checkIsOSInstalled();
    m_guestOS->uninstall();
}

void HyperVVirtualMachine::installApp(const std::string &appName)
{
    checkIsOSInstalled();
    m_guestOS->installApp(appName);
}

void HyperVVirtualMachine::uninstallApp(const std::string &appName)
{
    checkIsOSInstalled();
    m_guestOS->uninstallApp(appName);
}

void HyperVVirtualMachine::execApp(const std::string &appName)
{
    checkIsOSInstalled();
    m_guestOS->execApp(appName);
}

HyperVVirtualMachine::HyperVVirtualMachine(const HyperVVirtualMachine &copy)
    : IVirtualMachine ()
{
    this->m_progressObserver = copy.m_progressObserver;
    this->m_hardwareParams = copy.m_hardwareParams;
    this->m_name = copy.m_name;
    if (copy.m_guestOS.get())
    {
        this->installOS(copy.m_osType);
    }
}

HyperVVirtualMachine & HyperVVirtualMachine::operator =(const HyperVVirtualMachine &copy)
{
    if (this != &copy)
    {
        this->m_progressObserver = copy.m_progressObserver;
        this->m_hardwareParams = copy.m_hardwareParams;
        this->m_name = copy.m_name;
        if (copy.m_guestOS.get())
        {
            this->installOS(copy.m_osType);
        }
    }
    return *this;
}

