QT += core
QT -= gui

CONFIG += c++11

TARGET = Patterns
CONFIG += console
CONFIG -= app_bundle


INCLUDEPATH += Hypervisor\
    HypervisorFactory\
    VirtualMachine\
    ProgressObserver\
    GuestOS\
    Application\
    GuestOSFactory

TEMPLATE = app

SOURCES += main.cpp \
    Hypervisor/IHypervisor.cpp \
    Hypervisor/HyperVHypervisor.cpp \
    Hypervisor/ESXiHypervisor.cpp \
    Hypervisor/SCVMMHypervisor.cpp \
    Hypervisor/PhysicalPCHypervisor.cpp \
    ProgressObserver/ProgressObserver.cpp \
    VirtualMachine/ESXiVirtualMachine.cpp \
    VirtualMachine/SCVMMVirtualMachine.cpp \
    VirtualMachine/PhysicalPCVirtualMachine.cpp \
    VirtualMachine/HyperVVirtualMachine.cpp \
    GuestOSFactory/GuestOSFactory.cpp \
    GuestOS/IGuestOS.cpp \
    GuestOS/LinuxGuestOS.cpp \
    GuestOS/WindowsGuestOS.cpp \
    Application/TestApplication.cpp \
    HypervisorFactory/HyperVFactory.cpp \
    HypervisorFactory/ESXiFactory.cpp \
    HypervisorFactory/SCVMMFactory.cpp \
    HypervisorFactory/PhysicalPCFactory.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    Hypervisor/IHypervisor.hpp \
    Hypervisor/ESXiHypervisor.hpp \
    Hypervisor/HyperVHypervisor.hpp \
    Hypervisor/SCVMMHypervisor.hpp \
    Hypervisor/PhysicalPCHypervisor.hpp \
    VirtualMachine/IVirtualMachine.hpp \
    VirtualMachine/ESXiVirtualMachine.hpp \
    VirtualMachine/SCVMMVirtualMachine.hpp \
    VirtualMachine/PhysicalPCVirtualMachine.hpp \
    VirtualMachine/HyperVVirtualMachine.hpp \
    GuestOSFactory/GuestOSFactory.hpp \
    GuestOS/IGuestOS.hpp \
    GuestOS/LinuxGuestOS.hpp \
    GuestOS/WindowsGuestOS.hpp \
    Application/IApplication.hpp \
    Application/TestApplication.hpp \
    ProgressObserver/ProgressObserver.hpp \
    ProgressObserver/IProgressObserver.hpp \
    HypervisorFactory/IHypervisorFactory.hpp \
    HypervisorFactory/HyperVFactory.hpp \
    HypervisorFactory/ESXiFactory.hpp \
    HypervisorFactory/SCVMMFactory.hpp \
    HypervisorFactory/PhysicalPCFactory.hpp





