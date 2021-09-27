#include <string>
#include <vector>

#include "./parser.hpp"

class CompositeParser : public Parser {
 private:
  std::vector<Parser*> child_parsers;

 public:
  CompositeParser(){};
  CompositeParser(std::vector<std::string> unparsed_tokens)
      : Parser(unparsed_tokens){};
  ~CompositeParser();
  std::vector<std::string> parse();
  void add(Parser* parser);
  void remove(Parser* parser);
};