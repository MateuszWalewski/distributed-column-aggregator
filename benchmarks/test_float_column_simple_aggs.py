import sys
import pytest
from pytest import approx
sys.path.insert(1, '/home/guest1/engine/')

from initDB import FloatColumn

@pytest.fixture(scope="module")
def start_up():
    a = FloatColumn()
    a.LoadData("data4.csv")
    print("we entered start_up")
    yield a

@pytest.fixture(scope="module")
def tear_down():
    a = None


def test_sum_float_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.Sum)
    assert result == approx(5082198, rel=1e4) # vs. postgres


def test_count_float_column(start_up):
    a = start_up
    result = a.Count() # O(1) complexity
    assert result == 1015823

def test_min_float_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.Min)
    assert result == 0.0

def test_max_float_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.Max)
    assert result == 10.0

def test_momentI_float_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentI)
    assert result == approx(5.003063368314448, rel=1e-11) # vs. postgres


def test_momentII_float_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentII)
    assert result == approx(33.36456173224293, rel=1e-8) # vs. postgres


def test_stddev_float_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.Stddev)
    assert result == approx(2.8868541621375936, rel=1e-8) # vs. postgres
