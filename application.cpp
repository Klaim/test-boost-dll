/*
   1. Search for loadable modules providing plugin factory functions.
   2. Create plugins from the plugin factory functions.
   3. Use the plugins.
*/
#include <vector>
#include <iostream>

#include <boost/filesystem.hpp>

#include "plugin.hpp"

namespace app
{
  namespace bfs = boost::filesystem;

  std::vector<bfs::path> search_plugin_files()
  {
    std::vector<bfs::path> plugin_files;

    return plugin_files;
  }

  std::vector<SharedPlugin> search_plugins()
  {
    std::vector<SharedPlugin> plugins_found;



    return plugins_found;
  }


}


int main( char** argc, int argv )
{
  if (argv != 2)
  {
    std::cout << "WRONG ARGUMENTS" << std::endl;
    return EXIT_FAILURE;
  }


  static const std::string data = argc[1];

  using namespace app;
  auto plugins = search_plugins();

  std::cout << "Plugins found (" << plugins.size() << ") :" << std:: endl;

  for (auto& plugin : plugins)
  {
    std::cout << "\n\n** Plugin '" << plugin->id() << "' output: \n"
      << "    " << plugin->process(data);
  }


  return EXIT_SUCCESS;
}
