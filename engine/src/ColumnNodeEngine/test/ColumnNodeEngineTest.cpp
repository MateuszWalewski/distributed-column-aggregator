#include <ColumnNodeEngine/ColumnNodeImpl.h>
#include <any>
#include <gtest/gtest.h>

TEST( ColumEngineTests, SumTests )
{
    ColumnNodeImpl<int> col;

    col.AddElement( std::make_any<int>( 5 ) );
    col.AddElement( std::make_any<int>( 7 ) );
    col.AddElement( std::make_any<int>( 4 ) );

    EXPECT_EQ( std::any_cast<int>( col.Sum() ), 16 );
}

TEST( ColumEngineTests, CountTests )
{
    ColumnNodeImpl<int> col;

    col.AddElement( std::make_any<int>( 5 ) );
    col.AddElement( std::make_any<int>( 7 ) );
    col.AddElement( std::make_any<int>( 4 ) );
    col.AddElement( std::make_any<int>( 7 ) );
    col.AddElement( std::make_any<int>( 4 ) );

    EXPECT_EQ( std::any_cast<int>( col.Count() ), 5 );
}