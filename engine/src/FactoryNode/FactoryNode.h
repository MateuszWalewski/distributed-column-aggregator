#include "ColumnNodeEngine/IColumnNode.h"
#include <Loki/AbstractFactory.h>
#include <map>
#include <memory>

using namespace Loki;

typedef AbstractFactory<LOKI_TYPELIST_1(IColumnNode)> AbstractColumnFactory;

class FactoryNode {
public:
    FactoryNode();
    AbstractColumnFactory* GetWidgetFactory(const std::string& key);

private:
    std::map<std::string, std::unique_ptr<AbstractColumnFactory>> factory;
};
