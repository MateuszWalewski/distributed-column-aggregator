import os
import sys
sys.path.append('/usr/local/lib')

from interpreter import LoadConnectionDetails
from interpreter import DoubleColumn
from interpreter import IntColumn

LoadConnectionDetails(os.environ['CONN_CONF'])

