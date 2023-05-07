import sys
import pytest
sys.path.insert(1, '/home/guest1/engine/')

from initDB import FloatColumn

@pytest.fixture(scope="module")
def start_up():
    a = FloatColumn()
    a.LoadData("data3.csv")
    print("we entered start_up")
    yield a

@pytest.fixture(scope="module")
def tear_down():
    a = None



def test_sum_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.Sum)
    assert round(result, 5) == 43.39077


def test_count_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.Count)
    assert result == 9


def test_momentI_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentI)
    assert round(result, 4) == 4.8212


def test_momentII_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentII)
    assert round(result, 4) == 28.7952




# def test_stddev_bench_1(benchmark, start_up):
#     a = start_up
#     result = benchmark(a.Stddev)
#     assert result == 2.4990429927703106