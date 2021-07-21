#include <iostream>
#include "Networking/SessionHandler.h"

int main() {
    SessionHandler session(std::make_shared<rpc::client>("127.0.0.1", 5555));
    auto result = session.GetHub()->call("add", 2, 3).as<int>();
    std::cout << "The result is: " << result << std::endl;
    return 0;
}
