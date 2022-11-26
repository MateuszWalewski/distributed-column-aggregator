#include "ColumnNodeEngine/IColumnNode.h"
#include "Loki/AbstractFactory.h"
#include <map>

using namespace Loki;

typedef AbstractFactory<LOKI_TYPELIST_1( IColumnNode )> AbstractColumnFactory;

class FactoryNode
{
public:
    FactoryNode();

    AbstractColumnFactory* GetWidgetFactory( const std::string& key );

    ~FactoryNode();

private:
    std::map<std::string, AbstractColumnFactory*> factory;
};