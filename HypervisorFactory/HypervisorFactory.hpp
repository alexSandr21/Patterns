#ifndef HYPERVISORFACTORY_HPP
#define HYPERVISORFACTORY_HPP

#include "IHypervisor.hpp"

class HypervisorFactory
{
public:
    static HypervisorFactory* getFactory();
    IHypervisor* getHypervisor(HypervisorType hyperType, ProgressObserver* observer);
private:
    explicit HypervisorFactory(){}
    HypervisorFactory(const HypervisorFactory&) = delete;
    HypervisorFactory(HypervisorFactory&&) = delete;
    HypervisorFactory & operator = (const HypervisorFactory&) = delete;
    HypervisorFactory & operator = (HypervisorFactory&&) = delete;

    std::map<HypervisorType, std::unique_ptr<IHypervisor>> m_hypervisorMap;
};

#endif // HYPERVISORFACTORY_HPP
