#include "ProgressObserver.hpp"
#include "HyperVFactory.hpp"
#include "ESXiFactory.hpp"
#include "PhysicalPCFactory.hpp"
#include "SCVMMFactory.hpp"

void printDel()
{
    std::cout << "-----------------------------------------" << std::endl;
}

int main(int argc, char *argv[])
{
    try
    {
        std::unique_ptr<IProgressObserver> progress(new ProgressObserver());

        std::list<std::unique_ptr<IHypervisorFactory>> hypervisorFactories;
        hypervisorFactories.emplace_back(std::unique_ptr<IHypervisorFactory>(new HyperVFactory()));
        hypervisorFactories.emplace_back(std::unique_ptr<IHypervisorFactory>(new PhysicalPCFactory()));
        hypervisorFactories.emplace_back(std::unique_ptr<IHypervisorFactory>(new ESXiFactory()));
        hypervisorFactories.emplace_back(std::unique_ptr<IHypervisorFactory>(new SCVMMFactory()));

        std::list<std::unique_ptr<IHypervisor>> hypervisorVec;
        for (const auto & factory : hypervisorFactories)
        {
            printDel();
            hypervisorVec.emplace_back(factory->getHypervisor(progress.get()));
        }

        printDel();

        HardwareParams params{1, 1, 1, NIC::Bridge};

        for (const auto& hyper : hypervisorVec)
        {
            hyper->createVM(params, "vm1");
            hyper->createVM(params, "vm2");
            printDel();
        }

        printDel();

        for (const auto& hyper : hypervisorVec)
        {
            hyper->cloneVM("vm1", "vm1_clone");
            hyper->cloneVM("vm2", "vm2_clone");
            printDel();
        }

        printDel();

        for (const auto& hyper : hypervisorVec)
        {

            for (const auto vm : hyper->getAllVMs())
            {
                vm->installOS(GuestOS::Windows);
                printDel();
            }
            printDel();
        }
        for (const auto& hyper : hypervisorVec)
        {

            for (const auto vm : hyper->getAllVMs())
            {
                vm->installApp("TestApp");
                printDel();
                vm->execApp("TestApp");
                printDel();
                vm->uninstallApp("TestApp");
                printDel();
            }
            printDel();
        }
        for (const auto& hyper : hypervisorVec)
        {
            hyper->removeVM("vm1");
            hyper->removeVM("vm2");
            printDel();
        }
        for (const auto& hyper : hypervisorVec)
        {
            hyper->removeVM("vm1_clone");
            hyper->removeVM("vm2_clone");
            printDel();
        }

    }
    catch(const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
