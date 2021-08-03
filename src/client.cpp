#include <iostream>
#include "Networking/SessionHandler.h"
#include "Aggregations/SimpleAggsDist.h"
#include <string>

int main() {
    SessionHandler session(std::make_shared<rpc::client>("127.0.0.1", 5555));
    int size = 6;
    int key = 4;
    std::string methodName = "add";
    auto result = session.GetHub()->call(methodName, size, key).as<int>();
    std::cout << "The result is: " << result << std::endl;

    auto result2 = calcs::AllocateAndAggregateDist(size, key);

    std::cout << "The result2 is: " << result2 << std::endl;
    return 0;
}
