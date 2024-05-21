import sys
import pytest
from pytest import approx
sys.path.insert(1, '/home/guest1/engine/')

from initDB import DoubleColumn

@pytest.fixture(scope="module")
def start_up():
    a = DoubleColumn()
    a.LoadData("data4.csv")
    print("we entered start_up")
    yield a

@pytest.fixture(scope="module")
def tear_down():
    a = None


def test_sum_double_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.Sum)
    assert result == approx(5082226.839999964, rel=1e-11)  # vs. postgres


def test_count_double_column(start_up):
    a = start_up
    result = a.Count() # O(1) complexity
    assert result == 1015823


def test_momentI_double_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentI)
    assert result == approx(5.003063368322995, rel=1e-11) # vs. postgres


def test_momentII_double_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentII)
    assert result == approx(33.364561822090515, rel=1e-11) # vs. postgres


def test_stddev_double_column(benchmark, start_up):
    a = start_up
    result = benchmark(a.Stddev)
    assert result == approx(2.88685416305477, rel=1e-11) # vs. postgres

