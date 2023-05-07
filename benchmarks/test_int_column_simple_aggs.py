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


def test_sum(benchmark, start_up):
    a = start_up
    result = benchmark(a.Sum)
    assert result == 40


def test_count(benchmark, start_up):
    a = start_up
    result = benchmark(a.Count)
    assert result == 9


def test_momentI(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentI)
    assert round(result, 11) == 4.44444444444

def test_momentII(benchmark, start_up):
    a = start_up
    result = benchmark(a.MomentII)
    assert round(result, 11) == 25.77777777778


def test_stddev(benchmark, start_up):
    a = start_up
    result = benchmark(a.Stddev)
    assert round(result,11) == 2.60341655864
