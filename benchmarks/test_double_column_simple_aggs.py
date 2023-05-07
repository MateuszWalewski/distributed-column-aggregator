import sys
import pytest
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


def test_sum(benchmark, start_up):
    a = start_up
    result = benchmark(a.Sum)
    assert round(result,2) == 5082226.84


def test_count(benchmark, start_up):
    a = start_up
    result = benchmark(a.Count)
    assert result == 1015823


def test_momentI(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentI)
    assert round(result, 11) == 5.00306336832


def test_momentII(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentII)
    assert round(result, 10) == 33.3645618221


def test_stddev(benchmark, start_up):
    a = start_up
    result = benchmark(a.Stddev)
    assert round(result, 5) == 2.88685

