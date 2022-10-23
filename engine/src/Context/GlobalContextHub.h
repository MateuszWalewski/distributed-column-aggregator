#pragma once
#include <memory>
#include <string>
#include <tuple>

#include "ColumnEngine/ColumnFactory.h"
#include "Networking/RPCManager.h"

#include "ParameterController/ParameterControllerHub.h"

#define CTX() GlobalContextHub::Instance()
using SuperFactory = std::tuple<std::shared_ptr<ColumnFactory<int>>, std::shared_ptr<ColumnFactory<double>>,
                                std::shared_ptr<ColumnFactory<float>>>;

class GlobalContextHub
{
private:
    GlobalContextHub();
    // TODO: Decouple GlobalContext from concrete RPCManager class. Inverse the dependency!
    std::shared_ptr<RPCManager> mRPCManager;
    SuperFactory factory;

public:
    static GlobalContextHub& Instance();

    RPCManager& GetRPCManager();

    template <typename T>
    inline std::shared_ptr<ColumnFactory<T>>& GetColumnFactory()
    {
        return std::get<std::shared_ptr<ColumnFactory<T>>>( factory );
    }
};