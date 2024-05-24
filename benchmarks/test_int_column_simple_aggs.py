import sys
import pytest
from pytest import approx
sys.path.insert(1, '/home/guest1/engine/')

from initDB import IntColumn

@pytest.fixture(scope="module")
def start_up():
    a = IntColumn()
    a.LoadData("data1.csv")
    print("we entered start_up")
    yield a

@pytest.fixture(scope="module")
def tear_down():
    a = None


def test_sum_int_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.Sum)
    assert result == 5082342 # vs. postgres


def test_count_int_column(start_up):
    a = start_up
    result = a.Count() # O(1) complexity
    assert result == 1015823


def test_min_int_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.Min)
    assert result == 0

def test_max_int_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.Max)
    assert result == 10

def test_momentI_int_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentI)
    assert result == approx(5.0031767345295391, rel=1e-11) # vs. postgres

def test_momentII_int_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentII)
    assert result== approx(35.0343967403770145, rel=1e-11) # vs. postgres


def test_stddev_int_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.Stddev)
    assert result == approx(3.1626933380051605, rel=1e-11) # vs. postgres
