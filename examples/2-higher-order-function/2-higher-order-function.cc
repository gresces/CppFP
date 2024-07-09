/*
* This program tries to count files' line number in FP.
*/
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

using namespace std::filesystem;
using namespace std::ranges;
using std::accumulate;
using std::cout;
using std::endl;
using std::format;
using std::string;
using std::vector;

// Func: # Input
//   file_directory -> vector<string>
auto getFilesFromDir(string dirPath)
-> vector<string> {
  path baseDir(dirPath);
  vector<string> files;
  auto isDir =  [](const auto it) -> bool {
    return it.is_regular_file();
  };
  for (const auto file : directory_iterator(baseDir) 
                         | views::filter(isDir)) {
    files.push_back(file.path().c_str());
  }

  return files;
}

// Func: # Input
//   string -> string
auto getFile(const string& filename) -> string {
  std::ifstream file(filename);
  string str((std::istreambuf_iterator<char>(file)),
              std::istreambuf_iterator<char>());
  file.close();

  return str;
}

// Func: # Folding
//   (const string&, count_fun) -> unsigned int
//   (unsigned int, char) -> unsigned int
auto count_lines(const string str)
-> unsigned int {

  auto count_fun = [](unsigned int count, const char c) {
    return count += c != '\n' ? 0 : 1;
  };
  
  return accumulate(
    str.cbegin(),
    str.cend(),
    (unsigned int)0,
    count_fun
  );
}

// Func: # Transform
//   (C<string>, (string -> unsigned int)) -> unsigned int
auto count_file_lines(const vector<string>& files)
-> vector<unsigned int> {

    vector<unsigned int> lines = files 
    | views::transform(getFile)
    | views::transform(count_lines)
    | to<std::vector<unsigned int>>();

  return lines;
}

// Program entry
// Function: # Folding
//   current_path -> string
auto main(int, char**) -> int {

  auto lines = 
    count_file_lines(getFilesFromDir(current_path()));

  cout << format("{}", accumulate(lines.cbegin(), lines.cend(), 0))<< endl;

  return 0;
}
