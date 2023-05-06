#include "ColumnNode.h"
#include "Traits.h"
#include <FactoryNode/FactoryNode.h>
#include <Loki/Singleton.h>

#include <numeric>

template class ColumnNode<double>;
template class ColumnNode<float>;
template class ColumnNode<int>;

template <typename T>
ColumnNode<T>::ColumnNode( const std::string& colName ) : name( colName )
{
    auto& Instance = Loki::SingletonHolder<FactoryNode>::Instance();
    auto gadgetFactory = Instance.GetWidgetFactory( TypeName<T>::name );
    columnNodeEngine = gadgetFactory->template Create<IColumnNode>();
    std::cout << name << " created on node" << std::endl;
}

template <typename T>
ColumnNode<T>::~ColumnNode()
{
    delete columnNodeEngine;
    std::cout << name << " destructed on node" << std::endl;
}

template <typename T>
void ColumnNode<T>::Print()
{
    columnNodeEngine->Print();
}

template <typename T>
void ColumnNode<T>::LoadData( const std::string& dataFilePath, const size_t begin, const size_t end )
{
    columnNodeEngine->LoadData( dataFilePath, begin, end );
}

template <typename T>
T ColumnNode<T>::Sum()
{
    return std::any_cast<T>( columnNodeEngine->Sum() );
}

template <typename T>
int ColumnNode<T>::Count()
{
    return columnNodeEngine->Count();
}

template <typename T>
void ColumnNode<T>::AddElement( const T element )
{
    columnNodeEngine->AddElement( std::make_any<T>( element ) );
}