#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::endl;
using std::multimap;
using std::sort;
using std::string;
using std::unordered_multimap;
using std::vector;

// id, cc num, unix time

std::chrono::time_point<std::chrono::high_resolution_clock> TimeS()
{
  return std::chrono::high_resolution_clock::now();
};

void TimeC(std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::_V2::system_clock::duration> t2, std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::_V2::system_clock::duration> t1)
{
  cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms" << endl;
};

class Data
{
public:
  multimap<int, double> a;                                        // id : unix time
  multimap<int, double> b;                                        // id : cc num
  multimap<double, int> c;                                        // cc num : id
  int idc = 0;                                                    // brojač za id
  double tc = 0;                                                  // brojač za unix time
  bool tf = 0;                                                    // zastavica za uključenje clocka unutar metoda
  std::chrono::time_point<std::chrono::high_resolution_clock> t1; //
  std::chrono::time_point<std::chrono::high_resolution_clock> t2; // varijable za vrijeme
  bool searchCC(double cc)
  {
    t1 = TimeS();
    if (c.find(cc) != c.end())
      return 1;
    return 0;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  bool searchCC(vector<double> cc)
  {
    t1 = TimeS();
    for (int i = 0; i < cc.size(); i++)
    {
      if (c.find(cc[i]) == c.end())
        return 0;
    }
    return 1;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  bool searchID(int id)
  {
    t1 = TimeS();
    if (a.find(id) != a.end())
      return 1;
    return 0;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  bool searchID(vector<int> id)
  {
    t1 = TimeS();
    for (int i = 0; i < id.size(); i++)
    {
      if (a.find(id[i]) == a.end())
        return 0;
    }
    return 1;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  bool searchTime(double time)
  {
    t1 = TimeS();
    for (auto it = a.begin(); it != a.end(); it++)
    {
      if (it->second == time)
        return 1;
    }
    return 0;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  bool searchTime(vector<double> time)
  {
    t1 = TimeS();
    sort(time.begin(), time.end());
    int i = 0;
    for (auto it = a.begin(); it != a.end(); it++)
    {
      if (it->second == time[i])
      {
        i++;
        while (time[i] == time[i - 1])
        {
          i++;
        }
      }
      if (i >= time.size())
        return 1;
    }
    return 0;
    t2 = TimeS();
    TimeC(t2, t1);
  }
  double getMaxCC()
  {
    t1 = TimeS();
    double cc = (c.rbegin())->first;
    return cc;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  vector<double> getMaxCC(int n)
  {
    t1 = TimeS();
    vector<double> cc;
    int i = 0;
    for (auto it = c.rbegin(); i < n; it++)
    {
      cc.push_back(it->first);
      i++;
    }
    return cc;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  int getMaxID()
  {
    t1 = TimeS();
    int id = (a.rbegin())->first;
    return id;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  vector<int> getMaxID(int n)
  {
    t1 = TimeS();
    vector<int> id;
    int i = 0;
    for (auto it = a.rbegin(); i < n; it++)
    {
      id.push_back(it->first);
      i++;
    }
    return id;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  double getMaxTime()
  {
    t1 = TimeS();
    double time = (a.rbegin())->second;
    return time;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  vector<double> getMaxTime(int n)
  {
    t1 = TimeS();
    vector<double> time;
    int i = 0;
    for (auto it = a.rbegin(); i < n; it++)
    {
      time.push_back(it->second);
      i++;
    }
    return time;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  double getMinCC()
  {
    t1 = TimeS();
    double cc = (c.begin())->first;
    return cc;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  vector<double> getMinCC(int n)
  {
    t1 = TimeS();
    vector<double> cc;
    int i = 0;
    for (auto it = c.begin(); i < n; it++)
    {
      cc.push_back(it->first);
      i++;
    }
    return cc;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  int getMinID()
  {
    t1 = TimeS();
    int id = (a.begin())->first;
    return id;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  vector<int> getMinID(int n)
  {
    t1 = TimeS();
    vector<int> id;
    int i = 0;
    for (auto it = a.begin(); i < n; it++)
    {
      id.push_back(it->first);
      i++;
    }
    return id;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  double getMinTime()
  {
    t1 = TimeS();
    double time = (a.begin())->second;
    return time;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  vector<double> getMinTime(int n)
  {
    t1 = TimeS();
    vector<double> time;
    int i = 0;
    for (auto it = a.begin(); i < n; it++)
    {
      time.push_back(it->second);
      i++;
    }
    return time;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  void delID(int id)
  {
    t1 = TimeS();
    double ccnum;
    if (auto it = a.find(id); it != a.end())
      a.erase(it);
    if (auto it = b.find(id); it != b.end())
    {
      ccnum = it->second;
      b.erase(it);
    }
    for (auto it = c.find(ccnum); it->first == ccnum; it++)
    {
      if (it->second == id)
      {
        c.erase(it);
        break;
      }
    }
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  void delID(vector<int> id)
  {
    t1 = TimeS();
    for (int i = 0; i < id.size(); i++)
    {
      double ccnum;
      if (auto it = a.find(id[i]); it != a.end())
        a.erase(it);
      if (auto it = b.find(id[i]); it != b.end())
      {
        ccnum = it->second;
        b.erase(it);
      }
      for (auto it = c.find(ccnum); it->first == ccnum; it++)
      {
        if (it->second == id[i])
        {
          c.erase(it);
          break;
        }
      }
    }
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  void delCC(double cc)
  {
    t1 = TimeS();
    vector<int> id;
    for (auto it = c.find(cc); it->first == cc; it++)
    {
      id.push_back(it->second);
    }
    delID(id);
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  void delCC(vector<double> cc)
  {
    t1 = TimeS();
    vector<int> id;
    for (int i = 0; i < cc.size(); i++)
    {
      for (auto it = c.find(cc[i]); it->first == cc[i]; it++)
      {
        id.push_back(it->second);
      }
    }
    delID(id);
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  void delTime(double time)
  {
    t1 = TimeS();
    vector<int> id;
    for (auto it = a.begin(); it != a.end(); it++)
    {
      if (it->second == time)
      {
        id.push_back(it->first);
        break;
      }
    }
    delID(id);
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  void delTime(vector<double> time)
  {
    t1 = TimeS();
    int i = 0;
    vector<int> id;
    sort(time.begin(), time.end());
    for (auto it = a.begin(); it != a.end(); it++)
    {
      if (it->second == time[i])
      {
        id.push_back(it->first);
        i++;
        while (time[i] == time[i - 1])
        {
          if (i + 1 != time.size())
            i++;
          else
            break;
        }
        if (i >= time.size())
          break;
      }
    }
    delID(id);
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  void insertID(int id)
  {
    t1 = TimeS();
    if (id < idc)
      return;
    a.insert({id, 0});
    b.insert({id, 0});
    c.insert({0, id});
    if (id > idc)
      idc = id + 1;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  void insertID(vector<int> id)
  {
    t1 = TimeS();
    sort(id.begin(), id.end());
    if (id[0] < idc)
      return;
    for (int i = 0; i < id.size(); i++)
    {
      a.insert({id[i], 0});
      b.insert({id[i], 0});
      c.insert({0, id[i]});
      if (id[i] > idc)
        idc = id[i] + 1;
    }
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  void insertDataAuto(double time, double cc)
  {
    t1 = TimeS();
    if (time < tc)
      return;
    a.insert({idc, time});
    b.insert({idc, cc});
    c.insert({cc, idc});
    idc++;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  void insertData(int id, double time, double cc)
  {
    t1 = TimeS();
    if (id < idc)
      return;
    if (time < tc)
      return;
    a.insert({id, time});
    b.insert({id, cc});
    c.insert({cc, id});
    if (id > idc)
      idc = id + 1;
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  void insertDataAuto(vector<double> time, vector<double> cc)
  {
    t1 = TimeS();
    vector<double> time1 = time;
    sort(time1.begin(), time1.end());
    if (time1[0] < tc)
      return;
    for (int i = 0; i < time.size(); i++)
    {
      a.insert({idc, time[i]});
      b.insert({idc, cc[i]});
      c.insert({cc[i], idc});
      idc++;
    }
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  void insertData(vector<int> id, vector<double> time, vector<double> cc)
  {
    t1 = TimeS();
    vector<int> id1 = id;
    sort(id1.begin(), id1.end());
    if (id1[0] < idc)
      return;
    vector<double> time1 = time;
    sort(time1.begin(), time1.end());
    if (time1[0] < tc)
      return;
    for (int i = 0; i < id.size(); i++)
    {
      a.insert({id[i], time[i]});
      b.insert({id[i], cc[i]});
      c.insert({cc[i], id[i]});
      if (id[i] > idc)
        idc = id[i] + 1;
    }
    t2 = TimeS();
    if (tf)
      TimeC(t2, t1);
  }
  void info()
  {
    auto x = b.begin();
    for (auto i = a.begin(); i != a.end(); i++)
    {
      cout << std::setprecision(20) << i->first << " " << i->second << " " << x->second << endl;
      x++;
    }
  }
};

vector<string> read_line(const string &line)
{
  Data d;
  int qc = 0;
  string c;
  vector<string> r;
  string val;
  std::stringstream ss(line);
  while (getline(ss, val, ','))
  {
    if (val.starts_with('\"'))
      qc++;
    while ((val.ends_with('\"')) && (qc))
    {
      val = r.back() + ',' + val;
      if (r.back().starts_with('\"'))
        qc = 0;
      r.pop_back();
    }
    r.push_back(std::move(val));
  }
  return r;
}

void ispisi(vector<double> a)
{
  bool c = 1;
  for (auto it = a.begin(); it != a.end(); it++)
  {
    if (!c)
      cout << ", ";
    else
      c = 0;
    cout << *it;
  }
  cout << endl;
};

void ispisi(vector<int> a)
{
  bool c = 1;
  for (auto it = a.begin(); it != a.end(); it++)
  {
    if (!c)
      cout << ", ";
    else
      c = 0;
    cout << *it;
  }
  cout << endl;
};

int main()
{
  Data db;
  vector<string> l;
  unordered_multimap<int, string> mj;
  string data;
  std::chrono::time_point<std::chrono::high_resolution_clock> t1;
  std::chrono::time_point<std::chrono::high_resolution_clock> t2;
  int c = 0;
  int id;
  double time;
  double cc;
  std::fstream m;
  t1 = TimeS();
  m.open("fraudTest.csv", std::ios::in);
  while (getline(m, data))
  {
    if (c == 0)
    {
      c++;
      continue;
    }
    l = read_line(data);
    id = std::stoi(l[0]);
    time = std::stod(l[19]);
    cc = std::stod(l[2]);
    db.insertData(id, time, cc);
  }
  t2 = TimeS();
  cout << "Vrijeme popunjavanja: " << endl;
  TimeC(t2, t1);
  cout << "Vazeci:" << endl;
  t1 = TimeS();
  cout << db.searchCC(2291163933867244) << endl;
  cout << db.searchID(1) << endl;
  cout << db.searchTime(1371816865) << endl;
  cout << db.searchCC(vector<double>{2291163933867244, 3591919803438423, 3598215285024754}) << endl;
  cout << db.searchID(vector<int>{1, 3, 5, 2}) << endl;
  cout << db.searchTime(vector<double>{1371816893, 1371816873, 1371816865}) << endl;
  t2 = TimeS();
  TimeC(t2, t1);
  cout << "Nevazeci:" << endl;
  t1 = TimeS();
  cout << db.searchCC(1) << endl;
  cout << db.searchID(30000000) << endl;
  cout << db.searchTime(999999999999) << endl;
  cout << db.searchCC(vector<double>{2291163933867244, 3591919803438423, 1}) << endl;
  cout << db.searchID(vector<int>{1, 3, 300000000, 2}) << endl;
  cout << db.searchTime(vector<double>{1371816893, 1371816873, 999999999999}) << endl;
  t2 = TimeS();
  TimeC(t2, t1);
  cout << "Brisanje," << endl;
  t1 = TimeS();
  db.delCC(2291163933867244);
  db.delID(1);
  db.delTime(1371816865);
  db.delCC(vector<double>{2291163933867244, 3591919803438423, 3598215285024754});
  db.delID(vector<int>{1, 3, 5, 2});
  db.delTime(vector<double>{1371816893, 1371816873, 999999999999});
  t2 = TimeS();
  TimeC(t2, t1);
  cout << "Provjera:" << endl;
  cout << db.searchCC(2291163933867244) << endl;
  cout << db.searchID(1) << endl;
  cout << db.searchTime(1371816865) << endl;
  cout << db.searchCC(vector<double>{2291163933867244, 3591919803438423, 3598215285024754}) << endl;
  cout << db.searchID(vector<int>{1, 3, 5, 2}) << endl;
  cout << db.searchTime(vector<double>{1371816893, 1371816873, 1371816865}) << endl;
  cout << "Maksimalne vrijednosti:" << endl;
  t1 = TimeS();
  cout << db.getMaxCC() << endl;
  cout << db.getMaxID() << endl;
  cout << db.getMaxTime() << endl;
  ispisi(db.getMaxCC(5));
  ispisi(db.getMaxID(5));
  ispisi(db.getMaxTime(5));
  t2 = TimeS();
  TimeC(t2, t1);
  cout << "Minimalne vrijednosti:" << endl;
  t1 = TimeS();
  cout << db.getMinCC() << endl;
  cout << db.getMinID() << endl;
  cout << db.getMinTime() << endl;
  ispisi(db.getMinCC(5));
  ispisi(db.getMinID(5));
  ispisi(db.getMinTime(5));
  t2 = TimeS();
  TimeC(t2, t1);
}