#include "SCVMMFactory.hpp"
#include "SCVMMHypervisor.hpp"

std::unique_ptr<IHypervisor> SCVMMFactory::getHypervisor(IProgressObserver* observer)
{
    return std::unique_ptr<IHypervisor>(new SCVMMHypervisor(observer));
}
