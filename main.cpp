#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>


constexpr int8_t MaxSize = 5;
constexpr int8_t MaxAllowedValue = 17;
using OpsVec = std::vector< std::vector<int8_t> >;


#ifdef DEBUG
void printOpsVec( const OpsVec& vec  )
{
    for( auto x : vec  )
    {
        for( auto y : x )
        {
            std::cout << (int32_t)y << "\t";
        }
        std::cout << std::endl;
    }
}
#endif

template< uint16_t ArraySize >
int64_t listmax( const OpsVec& vec )
{
    #ifdef DEBUG
    printOpsVec( vec );
    #endif

    using ArrType = std::array<int8_t, ArraySize>;

    #ifdef DEBUG
    auto printArr = []( const ArrType& a )
    {
        for( auto s : a ) {
            std::cout << (int32_t)s << "\t";
        }
        std::cout << std::endl;
    };
    #endif

    ArrType arr{};
    int64_t rv = 0;

    auto isvalidindex = []( int8_t val ) {
        return (val > 0) && (val <= ArraySize);  // input indexes are 1-based
    };

    for( auto x : vec )
    {
        // validate the input
        if( (x.size() != 3) || (x[0] > x[1]) || !isvalidindex(x[0]) || !isvalidindex(x[1]) ) {
            throw std::runtime_error( "Invalid input" );
        }

        for( int i = x[0]-1; i <= x[1]-1; ++i )
        {
            arr[i] = std::clamp( static_cast<int8_t>(arr[i] + x[2]), arr[i], MaxAllowedValue );
            if( arr[i] > rv )
                rv = arr[i];
        }

        #ifdef DEBUG
        printArr( arr );
        #endif
    }

    return rv;
}



int main( int /*argc*/, char** /*argv*/ )
{
    try {
        const OpsVec v{ {1,2,10}, {2,4,5}, {3,5,12} };
        const auto result = listmax<MaxSize>( v );
        std::cout << "Max value is " << result << std::endl;
    }
    catch( const std::exception& e ) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
