#pragma once
#include <string>

/*
Used to white-listing the user-defined names of services in Docker,
while processing the TCP/IP connection details.
Should resemble the container names in configuration .yml files.
*/
const std::string HUB_NAME = "hub";
const std::string NODE_NAME = "node";

const std::string NUMBER_OF_NODES = "NumberOfNodes";
const std::string RPC_SERVER_PORT = "RpcServerPort";
const std::string TCP_SERVER_IP = "TcpServerIp";
const std::string TCP_SERVER_PORT = "TcpServerPort";

const std::string INT_TYPE_GADGET = "IntTypeGadget";
const std::string DOUBLE_TYPE_GADGET = "DoubleTypeGadget";
const std::string FLOAT_TYPE_GADGET = "FloatTypeGadget";

const std::string INT_TYPE = "IntTypeColumn_";
const std::string DOUBLE_TYPE = "DoubleTypeColumn_";
const std::string FLOAT_TYPE = "FloatTypeColumn_";
