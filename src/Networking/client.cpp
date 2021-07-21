#include <iostream>
#include "rpc/client.h"

int main() {
    rpc::client client("127.0.0.1", 5555);
    rpc::client client2("127.0.0.1", 5556);
    auto result = client.call("add", 2, 3).as<int>();
    client2.call("foo");
    std::cout << "The result is: " << result << std::endl;
    return 0;
}
