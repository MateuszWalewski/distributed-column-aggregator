cmake_minimum_required(VERSION 3.0.0)

add_library(
    Loki
    STATIC
    AbstractFactory.h
    EmptyType.h
    HierarchyGenerators.h
    NullType.h
    Sequence.h
    Typelist.h
    TypelistMacros.h
    TypeManip.h
    TypeTraits.h
    Singleton.h
    Loki.cpp
    )


