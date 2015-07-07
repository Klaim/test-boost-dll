#pragma once

#include <cassert>
#include <string>
#include <memory>

namespace app
{
  using PluginId = std::string;

  class Plugin
  {
  public:

    explicit Plugin(PluginId id)
      : m_id(id)
    {
      assert(!id.empty());
    }

    ~Plugin() = default;

    const PluginId& id() const { return m_id; }

    virtual std::string process(std::string value) = 0;

  private:
    const PluginId m_id;
  };

  using SharedPlugin = std::shared_ptr<Plugin>;
}


