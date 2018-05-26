#include "PhysicalPCFactory.hpp"
#include "PhysicalPCHypervisor.hpp"

std::unique_ptr<IHypervisor> PhysicalPCFactory::getHypervisor(IProgressObserver* observer)
{
    return std::unique_ptr<IHypervisor>(new PhysicalPCHypervisor(observer));
}
