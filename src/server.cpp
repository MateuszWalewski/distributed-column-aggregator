#include <iostream>
// #include "Networking/SessionHandler.h"
#include "Context/GlobalContext.h"
#include "Aggregations/SimpleAggs.h"

void foo() { std::cout << "foo was called!" << std::endl; }

void bad(int x) {
    if (x == 5) {
        throw std::runtime_error("x == 5. I really don't like 5.");
    }
}

int main() {
    // SessionHandler session(std::make_shared<rpc::server>("0.0.0.0", 5555));
    GlobalContext::Instance(false).GetSessionHandler().GetNode()->bind("foo", &foo);
    GlobalContext::Instance(false).GetSessionHandler().GetNode()->bind("AllocateAndAggregate", &calcs::AllocateAndAggregate);
    GlobalContext::Instance(false).GetSessionHandler().GetNode()->bind("add", [](int a, int b) { return a + b; });
    GlobalContext::Instance(false).GetSessionHandler().GetNode()->run();

    // TODO: make RPCMethodsBinder singleton class which makes all this stuff in a ctr and call it here
    // session.GetNode()->bind("foo", &foo);
    // session.GetNode()->bind("AllocateAndAggregate", &calcs::AllocateAndAggregate);

    // session.GetNode()->bind("add", [](int a, int b) { return a + b; });

    // Run the server loop.
    // session.GetNode()->run();

    return 0;
}
