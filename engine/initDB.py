import os
import sys
sys.path.append('/usr/local/lib')

from interpreter import LoadDependencies
from interpreter import DoubleColumn
from interpreter import FloatColumn
from interpreter import IntColumn

LoadDependencies(os.environ['CONN_CONF'])

