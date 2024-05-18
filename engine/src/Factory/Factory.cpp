#include "Factory.h"
#include "constants.h"
#include <ColumnEngine/ColumnImpl.h>
#include <string>

typedef ConcreteFactory<AbstractColumnFactory, OpNewFactoryUnit, LOKI_TYPELIST_1( ColumnImpl<int> )> IntColumnFactory;
typedef ConcreteFactory<AbstractColumnFactory, OpNewFactoryUnit, LOKI_TYPELIST_1( ColumnImpl<double> )> DoubleColumnFactory;
typedef ConcreteFactory<AbstractColumnFactory, OpNewFactoryUnit, LOKI_TYPELIST_1( ColumnImpl<float> )> FloatColumnFactory;

Factory::Factory()
{
    factory[INT_TYPE_GADGET] = std::make_unique<IntColumnFactory>();
    factory[DOUBLE_TYPE_GADGET] = std::make_unique<DoubleColumnFactory>();
    factory[FLOAT_TYPE_GADGET] = std::make_unique<FloatColumnFactory>();
}

AbstractColumnFactory* Factory::GetWidgetFactory( const std::string& key )
{
    return factory[key].get();
}
