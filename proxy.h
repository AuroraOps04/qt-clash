#include <string>
#include <vector>

void curl_callback(const char *data, size_t size, size_t n, void *res);

void httpget(const std::string &url, std::string &output);

class Proxy {
public:
  Proxy(std::string type, std::string name, bool udp, bool alive);
  bool alive;
  bool udp;
  std::string type;
  std::string name;
  long delay;
};
std::vector<Proxy> getproxies();
