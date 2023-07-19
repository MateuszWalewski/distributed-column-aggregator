from results_fetch_data_from_nodes import results
import sys
import pytest
sys.path.insert(1, '/home/guest1/engine/')


from initDB import DoubleColumn

@pytest.fixture(scope="module")
def start_up():
    a = DoubleColumn()
    a.LoadData("data3.csv")

    print("we entered start_up")
    yield a

@pytest.fixture(scope="module")
def tear_down():
    a = None


def test_fetch_data(benchmark, start_up):
    a = start_up
    a.Print()
    size = benchmark(a.Fetch)
    data = []
    for i in range(size):
        data.append(a.GetElement(i))

    assert len(data) == len(results)
    assert all([a == b for a, b in zip(data, results)])

