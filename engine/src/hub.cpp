#include "python_bindings.h"
#include <ConfigurationManager/ConfigurationManager.h>
#include <Loki/Singleton.h>

int InitialiseHub() {
    auto& cMInstance = Loki::SingletonHolder<ConfigurationManager>::Instance();
    if (!cMInstance.LoadConnectionInfoOnHub()) {
        return 1;
    }
    return 0;
}
