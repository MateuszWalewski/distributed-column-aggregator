import sys
import pytest
sys.path.insert(1, '/home/guest1/engine/')

from initDB import IntColumn

@pytest.fixture(scope="module")
def start_up():
    a = IntColumn()
    a.LoadData("/home/guest1/engine/src/data1.csv")
    print("we entered start_up")
    yield a

@pytest.fixture(scope="module")
def tear_down():
    a = None


def test_sum_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.Sum)
    assert result == 40

