#include "Loki/AbstractFactory.h"
#include "ColumnEngine/IColumn.h"
#include <map>

using namespace Loki;

typedef AbstractFactory
<
    LOKI_TYPELIST_1(IColumn)
>
AbstractColumnFactory;


class Factory 
{
public:
    Factory();

    AbstractColumnFactory* GetWidgetFactory(const std::string& key );

    ~Factory();

private:
    std::map<std::string, AbstractColumnFactory*> factory;
};