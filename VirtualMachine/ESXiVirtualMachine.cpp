#include "ESXiVirtualMachine.hpp"

#include "GuestOSFactory.hpp"

ESXiVirtualMachine::ESXiVirtualMachine(IProgressObserver *observer, const HardwareParams &params, const std::string &name)
    : IVirtualMachine(observer, params, name)
{
    std::cout << "ESXiVirtualMachine created" << std::endl;
}

std::unique_ptr<IVirtualMachine> ESXiVirtualMachine::clone()
{
    std::cout << "ESXiVirtualMachine cloned" << std::endl;
    return std::unique_ptr<IVirtualMachine>(new ESXiVirtualMachine(*this));
}

void ESXiVirtualMachine::installOS(GuestOS guestOs)
{
    m_guestOS.reset();
    m_guestOS = GuestOSFactory::getFactory().getGuestOS(guestOs, m_progressObserver);
    m_osType = guestOs;
    m_guestOS->install();
}

void ESXiVirtualMachine::uninstallOS()
{
    checkIsOSInstalled();
    m_guestOS->uninstall();
}

void ESXiVirtualMachine::installApp(const std::string &appName)
{
    checkIsOSInstalled();
    m_guestOS->installApp(appName);
}

void ESXiVirtualMachine::uninstallApp(const std::string &appName)
{
    checkIsOSInstalled();
    m_guestOS->uninstallApp(appName);
}

void ESXiVirtualMachine::execApp(const std::string &appName)
{
    checkIsOSInstalled();
    m_guestOS->execApp(appName);
}

ESXiVirtualMachine::ESXiVirtualMachine(const ESXiVirtualMachine &copy)
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

ESXiVirtualMachine & ESXiVirtualMachine::operator =(const ESXiVirtualMachine &copy)
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
