import sys
import pytest
sys.path.insert(1, '/home/guest1/engine/')

from initDB import DoubleColumn

@pytest.fixture(scope="module")
def start_up():
    a = DoubleColumn()
    yield a


@pytest.fixture(scope="module")
def tear_down():
    a = None


def test_sum_bench_1(benchmark, start_up):
    a = start_up
    a.AddElement(12.34)
    a.AddElement(5.564)
    a.AddElement(8.1)

    result = benchmark(a.Sum)
    assert result == 52.007999999999996


