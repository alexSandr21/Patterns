#ifndef TESTAPPLICATION_HPP
#define TESTAPPLICATION_HPP

#include "IApplication.hpp"

class TestApplication : public IApplication
{
public:
    TestApplication(ProgressObserver* observer, const std::string& name)
        : IApplication(observer, name) {}

    void install() override;
    void uninstall() override;
    void exec() override;
};

#endif // TESTAPPLICATION_HPP
