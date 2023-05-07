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


def test_sum_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.Sum)
    assert result == 5082226.839999925


def test_count_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.Count)
    assert result == 1015823


def test_momentI_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentI)
    assert round(result, 11) == 5.00306336832


def test_momentII_bench_1(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentII)
    assert round(result, 10) == 33.3645618221




# def test_stddev_bench_1(benchmark, start_up):
#     a = start_up
#     result = benchmark(a.Stddev)
#     assert result == 2.8868541630547506

