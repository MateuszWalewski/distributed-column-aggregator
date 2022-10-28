import sys
import pytest
sys.path.insert(1, '/home/guest1/engine/')

from initDB import FloatColumn

@pytest.fixture(scope="module")
def start_up():
    a = FloatColumn()
    a.LoadData("/home/guest1/engine/src/data3.csv")
    print("we entered start_up")
    yield a

@pytest.fixture(scope="module")
def tear_down():
    a = None



def test_sum_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.Sum)
    assert round(result, 5) == 43.39077

