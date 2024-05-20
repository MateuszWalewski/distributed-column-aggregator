import sys
import pytest
sys.path.insert(1, '/home/guest1/engine/')

from initDB import FloatColumn

@pytest.fixture(scope="module")
def start_up():
    a = FloatColumn()
    yield a


@pytest.fixture(scope="module")
def tear_down():
    a = None

def test_add_element_to_float_column(start_up):
    a = start_up
    a.AddElement(1, 12.34)
    a.AddElement(1, 5.564)
    a.AddElement(1, 8.1)
    result = a.Sum()
    assert round(result, 5) == 26.004


