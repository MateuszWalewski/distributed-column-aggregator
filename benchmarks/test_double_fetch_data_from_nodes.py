import sys
import pytest
import pandas as pd
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


def test_fetch_data(start_up):
    a = start_up
    csv_file_path = "/home/guest1/engine/data/data4.csv"
    df = pd.read_csv(csv_file_path, header=None).squeeze()
    results = df.values.tolist()
    size = a.Fetch()
    data = []
    for i in range(size):
        data.append(a.GetElement(i))

    assert len(data) == len(results)
    assert all([a == b for a, b in zip(data, results)])

