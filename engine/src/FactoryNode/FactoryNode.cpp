#include "FactoryNode.h"
#include "constants.h"
#include <ColumnNodeEngine/ColumnNodeImpl.h>
#include <string>

typedef ConcreteFactory<AbstractColumnFactory, OpNewFactoryUnit, LOKI_TYPELIST_1( ColumnNodeImpl<int> )> IntColumnFactory;
typedef ConcreteFactory<AbstractColumnFactory, OpNewFactoryUnit, LOKI_TYPELIST_1( ColumnNodeImpl<double> )> DoubleColumnFactory;
typedef ConcreteFactory<AbstractColumnFactory, OpNewFactoryUnit, LOKI_TYPELIST_1( ColumnNodeImpl<float> )> FloatColumnFactory;

FactoryNode::FactoryNode()
{
    factory[INT_TYPE_GADGET] = new IntColumnFactory();
    factory[DOUBLE_TYPE_GADGET] = new DoubleColumnFactory();
    factory[FLOAT_TYPE_GADGET] = new FloatColumnFactory();
}

AbstractColumnFactory* FactoryNode::GetWidgetFactory( const std::string& key )
{
    return factory[key];
}

FactoryNode::~FactoryNode()
{
    for ( auto& x : factory )
    {
        delete x.second;
    }
}
