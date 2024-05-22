#include "ColumnNode.h"
#include "Traits.h"
#include <FactoryNode/FactoryNode.h>
#include <Loki/Singleton.h>
#include <iostream>
#include <numeric>

template class ColumnNode<double>;
template class ColumnNode<float>;
template class ColumnNode<int>;

template <typename T>
ColumnNode<T>::ColumnNode(const std::string& colName) : _name(colName) {
    auto& Instance = Loki::SingletonHolder<FactoryNode>::Instance();
    auto gadgetFactory = Instance.GetWidgetFactory(TypeName<T>::name);
    _columnNodeEngine.reset(gadgetFactory->template Create<IColumnNode>());
    std::cout << _name << " created on node" << std::endl;
}

template <typename T>
ColumnNode<T>::~ColumnNode() {
    std::cout << _name << " destructed on node" << std::endl;
}

template <typename T>
void ColumnNode<T>::Print() {
    _columnNodeEngine->Print();
}

template <typename T>
void ColumnNode<T>::LoadData(const std::string& dataFilePath, const size_t begin, const size_t end) {
    _columnNodeEngine->LoadData(dataFilePath, begin, end);
}

template <typename T>
double ColumnNode<T>::Sum() {
    return _columnNodeEngine->Sum();
}

template <typename T>
double ColumnNode<T>::SumX2() {
    return _columnNodeEngine->SumX2();
}

template <typename T>
size_t ColumnNode<T>::Count() {
    return _columnNodeEngine->Count();
}

template <typename T>
void ColumnNode<T>::AddElement(const T element) {
    _columnNodeEngine->AddElement(std::make_any<T>(element));
}

template <typename T>
size_t ColumnNode<T>::Fetch() {
    return _columnNodeEngine->Fetch();
}
