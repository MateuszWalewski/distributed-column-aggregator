#include "src/ColumnEngine/ColumnImpl.h"
#include "gtest/gtest.h"
#include <any>

TEST( Test1, Test1 )
{
    ColumnImpl<int> col;
}

int main( int argc, char** argv )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}