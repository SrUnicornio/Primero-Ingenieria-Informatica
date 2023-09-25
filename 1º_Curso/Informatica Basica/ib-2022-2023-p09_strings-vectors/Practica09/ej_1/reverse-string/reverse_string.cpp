#include "reverse_string.h"

namespace reverse_string {
    string reverse_string(string s) {
  string new_string;
  for (int i = s.length() - 1; i >= 0; i--) {
    new_string += s[i];
  }
  return new_string;
}
}  // namespace reverse_string
