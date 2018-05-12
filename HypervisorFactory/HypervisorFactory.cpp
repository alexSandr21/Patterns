#include "HypervisorFactory.hpp"
#include "HyperVHypervisor.hpp"
#include "ESXiHypervisor.hpp"
#include "SCVMMHypervisor.hpp"
#include "PhysicalPCHypervisor.hpp"

HypervisorFactory *HypervisorFactory::getFactory()
{
    static std::unique_ptr<HypervisorFactory> factory;
    if (!factory.get())
    {
        factory.reset(new HypervisorFactory());
    }
    return factory.get();
}

IHypervisor *HypervisorFactory::getHypervisor(HypervisorType hyperType,  ProgressObserver* observer)
{
    IHypervisor* retHyper = nullptr;

    auto iter = m_hypervisorMap.find(hyperType);
    if (iter != m_hypervisorMap.cend())
    {
        retHyper = (iter->second).get();
    }
    else
    {
        std::unique_ptr<IHypervisor> hyperPtr;
        switch (hyperType)
        {
        case HypervisorType::HyperV:
            hyperPtr.reset(new HyperVHypervisor(observer));
            break;
        case HypervisorType::ESXi:
            hyperPtr.reset(new ESXiHypervisor(observer));
            break;
        case HypervisorType::SCVMM:
            hyperPtr.reset(new SCVMMHypervisor(observer));
            break;
        case HypervisorType::PhysicalPC:
            hyperPtr.reset(new PhysicalPCHypervisor(observer));
            break;
        default:
            throw std::runtime_error("Invalid hypervisor type");
        }

        retHyper = hyperPtr.get();
        auto res = m_hypervisorMap.insert(std::make_pair(hyperType,
                                                         std::move(hyperPtr)));
        if (!res.second)
        {
            throw std::runtime_error("Error during hypervisor creation");
        }
    }

    return retHyper;
}
