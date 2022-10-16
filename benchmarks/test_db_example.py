import sys
import pytest
sys.path.insert(1, '/home/guest1/engine/')

from initDB import IntColumn

@pytest.fixture(scope="module")
def start_up():
    a = IntColumn()
    a.LoadData("/home/guest1/engine/src/data1.csv")
    yield a

def testSum(start_up):
    a = start_up
    assert a.Sum() == 80

def testSum2(start_up):
    a = start_up
    assert a.Sum() == 80
