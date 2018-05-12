#include "PhysicalPCVirtualMachine.hpp"
#include "GuestOSFactory.hpp"

PhysicalPCVirtualMachine::PhysicalPCVirtualMachine(ProgressObserver *observer, const HardwareParams &params, const std::string &name)
    : IVirtualMachine(observer, params, name)
{
    std::cout << "PhysicalPCVirtualMachine created" << std::endl;
}

std::unique_ptr<IVirtualMachine> PhysicalPCVirtualMachine::clone()
{
    std::cout << "PhysicalPCVirtualMachine cloned" << std::endl;
    return std::unique_ptr<IVirtualMachine>(new PhysicalPCVirtualMachine(*this));
}

void PhysicalPCVirtualMachine::installOS(GuestOS guestOs)
{
    m_guestOS.reset();
    m_guestOS = GuestOSFactory::getFactory()->getGuestOS(guestOs, m_progressObserver);
    m_osType = guestOs;
    m_guestOS->install();
}

void PhysicalPCVirtualMachine::uninstallOS()
{
    checkIsOSInstalled();
    m_guestOS->uninstall();
}

void PhysicalPCVirtualMachine::installApp(const std::string &appName)
{
    checkIsOSInstalled();
    m_guestOS->installApp(appName);
}

void PhysicalPCVirtualMachine::uninstallApp(const std::string &appName)
{
    checkIsOSInstalled();
    m_guestOS->uninstallApp(appName);
}

void PhysicalPCVirtualMachine::execApp(const std::string &appName)
{
    checkIsOSInstalled();
    m_guestOS->execApp(appName);
}

PhysicalPCVirtualMachine::PhysicalPCVirtualMachine(const PhysicalPCVirtualMachine &copy)
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

PhysicalPCVirtualMachine & PhysicalPCVirtualMachine::operator =(const PhysicalPCVirtualMachine &copy)
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

