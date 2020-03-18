// #include <iostream>
// #include <numeric>
// #include <vector>


auto main() -> int {
  using std::cin;
  using std::cout;
 
  int a, b;
  cin >> a >> b;
 
  std::vector<int> skill;
  for(int i = 0; i < b; i++) {
    int n;
    cin >> n;
    skill.push_back(n);
  }
 
  int sum = std::accumulate(skill.begin(), skill.end(), 0);
 
  if(sum < a) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
 
  return 0;
}
  
