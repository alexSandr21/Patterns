#ifndef IHYPERVISORFACTORY_HPP
#define IHYPERVISORFACTORY_HPP

#include "IHypervisor.hpp"


class IHypervisorFactory
{
public:
    virtual ~IHypervisorFactory() {}
    virtual std::unique_ptr<IHypervisor> getHypervisor(IProgressObserver* observer) = 0;
};

#endif // IHYPERVISORFACTORY_HPP
