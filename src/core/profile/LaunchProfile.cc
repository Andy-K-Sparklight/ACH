#include "ach/core/profile/LaunchProfile.hh"

#include "ach/util/Commons.hh"

namespace Alicorn
{
namespace Profile
{

LaunchProfile::LaunchProfile(const std::map<std::string, std::string> &slice)
{
  std::map<std::string, std::string> dat = slice;
  id = dat["id"];
  displayName = dat["displayName"];
  icon = dat["icon"];

  jvm = dat["jvm"];
  auto m = Commons::splitStr(dat["mods"], " ");
  for(auto &t : m)
    {
      mods.push_back(t);
    }
  runtime = dat["runtime"];
  account = dat["account"];
  baseProfile = dat["baseProfile"];
  vmArgs = dat["vmArgs"];
  isDemo = dat["isDemo"] != "0";
  width = std::stoi(dat["width"]);
  height = std::stoi(dat["height"]);
}

LaunchProfile::LaunchProfile() {}

std::map<std::string, std::string>
LaunchProfile::toMap()
{
  std::map<std::string, std::string> dat;
  dat["id"] = id;
  dat["displayName"] = displayName;
  dat["icon"] = icon;

  dat["jvm"] = jvm;
  std::string m;
  for(auto &t : mods)
    {
      m += (t + " ");
    }
  if(m.size() > 0)
    {
      m.pop_back();
    }
  dat["mods"] = m;
  dat["runtime"] = runtime;
  dat["account"] = account;
  dat["baseProfile"] = baseProfile;
  dat["vmArgs"] = vmArgs;
  dat["isDemo"] = isDemo ? std::string("1") : std::string("0");
  dat["width"] = std::to_string(width);
  dat["height"] = std::to_string(height);
  return dat;
}

std::vector<LaunchProfile> LAUNCH_PROFILES;

}
}