#include "src/ColumnNodeEngine/ColumnNodeImpl.h"
#include "gtest/gtest.h"
#include <any>

TEST( Test1, Test1 )
{
    ColumnNodeImpl<int> col;

    col.AddElement( std::make_any<int>( 5 ) );
    col.AddElement( std::make_any<int>( 7 ) );
    col.AddElement( std::make_any<int>( 4 ) );

    EXPECT_EQ( std::any_cast<int>( col.Sum() ), 16 );
}