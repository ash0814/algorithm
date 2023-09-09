#include <iostream>
#include <queue>

using namespace std;

void print_q(queue<int> qu)
{
  queue<int> tmp = qu;
  while (!tmp.empty())
  {
    cout << tmp.front() << " ";
    tmp.pop();
  }
  cout << endl;
}

int bridge_sum(queue<int> bridge)
{
  queue<int> tmp = bridge;
  int sum = 0;
  while (!tmp.empty())
  {
    sum += tmp.front();
    tmp.pop();
  }

  return sum;
}

int main()
{
  int n, w, L;
  queue<int> trucks;

  cin >> n >> w >> L;
  while (n--)
  {
    int truck_weight;
    cin >> truck_weight;
    trucks.push(truck_weight);
  }

  int time = 0;
  queue<int> bridge;

  while (w--)
    bridge.push(0);

  while (1)
  {
    if (trucks.size() <= 0 && bridge_sum(bridge) <= 0)
      break;
    bridge.pop();
    if (bridge_sum(bridge) + trucks.front() <= L && trucks.size() > 0)
    {
      bridge.push(trucks.front());
      trucks.pop();
    }
    else
    {
      bridge.push(0);
    }
    time++;
  }

  cout << time << endl;
  return 0;
}