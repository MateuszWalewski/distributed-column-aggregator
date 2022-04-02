import sys
import pytest
sys.path.insert(1, '/home/guest1/engine/')

from initDB import DoubleColumn

@pytest.fixture(scope="module")
def start_up():
    a = DoubleColumn()
    a.LoadData("/home/guest1/engine/src/data2.csv")
    print("we entered start_up")
    yield a


def test_sum_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.Sum)

    #assert result == 43.11


def doAll():
    a = DoubleColumn()
    a.LoadData("/home/guest1/engine/src/data2.csv")
    a.Sum()

def test_sum_bench_2(benchmark):
    benchmark(doAll)
