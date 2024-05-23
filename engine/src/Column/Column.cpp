#include "Column.h"
#include "Traits.h"
#include <Factory/Factory.h>
#include <Loki/Singleton.h>

template class Column<double>;
template class Column<float>;
template class Column<int>;

template <typename T>
Column<T>::Column() {
    auto& Instance = Loki::SingletonHolder<Factory>::Instance();
    auto gadgetFactory = Instance.GetWidgetFactory(TypeName<T>::name);

    _columnEngine.reset(gadgetFactory->template Create<IColumn>());
    _columnEngine->CreateColumnOnNode();
}

template <typename T>
Column<T>::~Column() {
    _columnEngine->DeleteColumnOnNode();
}
template <typename T>
Column<T>::Column(const Column&) {
} // Needed by the Boost.Python

template <typename T>
void Column<T>::Print() {
    _columnEngine->PrintColumnOnNode();
}

template <typename T>
void Column<T>::AddElement(const size_t nodeNumber, const T element) {
    _columnEngine->AddElement(nodeNumber, std::make_any<T>(element));
}

template <typename T>
T Column<T>::GetElement(size_t index) {
    return std::any_cast<T>(_columnEngine->GetElement(index));
}

template <typename T>
void Column<T>::LoadData(const std::string& dataFilePath) {
    _columnEngine->LoadDataToNode(dataFilePath);
}

template <typename T>
double Column<T>::Sum() {
    return _columnEngine->Sum();
}

template <typename T>
size_t Column<T>::Count() {
    return _columnEngine->Count();
}

template <typename T>
size_t Column<T>::Fetch() {
    return _columnEngine->Fetch();
}

template <typename T>
double Column<T>::MomentI() {
    return _columnEngine->MomentI();
}

template <typename T>
double Column<T>::MomentII() {
    return _columnEngine->MomentII();
}

template <typename T>
double Column<T>::Stddev() {
    return _columnEngine->Stddev();
}
