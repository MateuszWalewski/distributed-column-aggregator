import sys
import pytest
sys.path.insert(1, '/home/guest1/engine/')

from initDB import IntColumn

@pytest.fixture(scope="module")
def start_up():
    a = IntColumn()
    a.LoadData("data1.csv")
    yield a

@pytest.fixture(scope="module")
def tear_down():
    a = None


def test_db(start_up):
    a = start_up
    assert a.Sum() == 5082342.0
