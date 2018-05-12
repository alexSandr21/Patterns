#include "SCVMMVirtualMachine.hpp"
#include "GuestOSFactory.hpp"

SCVMMVirtualMachine::SCVMMVirtualMachine(ProgressObserver *observer, const HardwareParams &params, const std::string &name)
    : IVirtualMachine(observer, params, name)
{
    std::cout << "SCVMMVirtualMachine created" << std::endl;
}

std::unique_ptr<IVirtualMachine> SCVMMVirtualMachine::clone()
{
    std::cout << "SCVMMVirtualMachine cloned" << std::endl;
    return std::unique_ptr<IVirtualMachine>(new SCVMMVirtualMachine(*this));
}

void SCVMMVirtualMachine::installOS(GuestOS guestOs)
{
    m_guestOS.reset();
    m_guestOS = GuestOSFactory::getFactory()->getGuestOS(guestOs, m_progressObserver);
    m_osType = guestOs;
    m_guestOS->install();
}

void SCVMMVirtualMachine::uninstallOS()
{
    checkIsOSInstalled();
    m_guestOS->uninstall();
}

void SCVMMVirtualMachine::installApp(const std::string &appName)
{
    checkIsOSInstalled();
    m_guestOS->installApp(appName);
}

void SCVMMVirtualMachine::uninstallApp(const std::string &appName)
{
    checkIsOSInstalled();
    m_guestOS->uninstallApp(appName);
}

void SCVMMVirtualMachine::execApp(const std::string &appName)
{
    checkIsOSInstalled();
    m_guestOS->execApp(appName);
}

SCVMMVirtualMachine::SCVMMVirtualMachine(const SCVMMVirtualMachine &copy)
    : IVirtualMachine()
{
    this->m_progressObserver = copy.m_progressObserver;
    this->m_hardwareParams = copy.m_hardwareParams;
    this->m_name = copy.m_name;
    if (copy.m_guestOS.get())
    {
        this->installOS(copy.m_osType);
    }
}

SCVMMVirtualMachine & SCVMMVirtualMachine::operator =(const SCVMMVirtualMachine &copy)
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
