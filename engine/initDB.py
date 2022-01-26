import os
import sys
sys.path.append('/usr/local/lib')

from interpreter import ConnectToNodes
from interpreter import DoubleColumn
from interpreter import IntColumn

ConnectToNodes(os.environ['CONN_CONF'])

