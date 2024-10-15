#include "proxy.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
using json = nlohmann::json;

void write_callback(const char *data, size_t size, size_t n, void *res) {
  std::string *str = (std::string *)res;
  str->clear();
  str->resize(n);
  for (int i = 0; i < n; i++) {
    str->at(i) = (char)data[i];
  }
}

void httpget(const std::string &url, std::string &output) {
  std::string res;
  CURL *hd = curl_easy_init();
  curl_easy_setopt(hd, CURLOPT_URL, url.c_str());
  curl_easy_setopt(hd, CURLOPT_WRITEDATA, &output);
  curl_easy_setopt(hd, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_perform(hd);
  curl_easy_cleanup(hd);
}

Proxy::Proxy(std::string type, std::string name, bool udp, bool alive)
    : type(type), name(name), udp(udp), alive(alive) {}

std::vector<Proxy> getproxies() {
  std::vector<Proxy> v;
  std::string res;
  httpget("http://127.0.0.1:9090/proxies", res);
  json j = json::parse(res);
  json proxies = j["proxies"].template get<json>();
  for (auto item = proxies.begin(); item != proxies.end(); item++) {
    json tmpj = *item;
    Proxy p = {tmpj["type"].template get<std::string>(),
               tmpj["name"].template get<std::string>(),
               tmpj["udp"].template get<bool>(),
               tmpj["alive"].template get<bool>()

    };
    v.push_back(p);
  }
  return v;
}
