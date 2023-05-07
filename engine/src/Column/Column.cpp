#include "Column.h"
#include "Traits.h"
#include <Factory/Factory.h>
#include <Loki/Singleton.h>

template class Column<double>;
template class Column<float>;
template class Column<int>;

template <typename T>
Column<T>::Column()
{
    auto& Instance = Loki::SingletonHolder<Factory>::Instance();
    auto gadgetFactory = Instance.GetWidgetFactory( TypeName<T>::name );

    columnEngine = gadgetFactory->template Create<IColumn>();
    columnEngine->CreateColumnOnNode();
}

template <typename T>
Column<T>::~Column()
{
    columnEngine->DeleteColumnOnNode();
    delete columnEngine;
}

template <typename T>
void Column<T>::Print()
{
    columnEngine->PrintColumnOnNode();
}

template <typename T>
void Column<T>::AddElement( const size_t nodeNumber, const T element )
{
    columnEngine->AddElement( nodeNumber, std::make_any<T>( element ) );
}

template <typename T>
void Column<T>::LoadData( const std::string& dataFilePath )
{
    columnEngine->LoadDataToNode( dataFilePath );
}

template <typename T>
T Column<T>::Sum()
{
    return std::any_cast<T>( columnEngine->Sum() );
}

template <typename T>
int Column<T>::Count()
{
    return columnEngine->Count();
}

template <typename T>
double Column<T>::MomentI()
{
    return columnEngine->MomentI();
}

template <typename T>
double Column<T>::MomentII()
{
    return columnEngine->MomentII();
}

template <typename T>
double Column<T>::Stddev()
{
    return columnEngine->Stddev();
}