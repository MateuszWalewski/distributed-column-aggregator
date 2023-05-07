import sys
import pytest
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


def test_sum_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.Sum)
    assert result == 40


def test_count_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.Count)
    assert result == 9


def test_momentI_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentI)
    assert result == 4


# def test_stddev_bench_1(benchmark, start_up):
#     a = start_up
#     result = benchmark(a.Stddev)
#     assert result == 2.6034165586355515
