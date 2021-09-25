#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../src/parser/comment_parser.hpp"
#include "../src/parser/connector_parser.hpp"
#include "../src/parser/group_parser.hpp"

TEST(COMMENT_PARSER_TEST, REMOVE_COMMENT) {
  CommentParser parser1("echo a b c # this should be removed");
  CommentParser parser2("# hello");
  CommentParser parser3("echo hi how are you \"# I should still see this\"");
  std::string parsed1_str = parser1.parse();
  std::string parsed2_str = parser2.parse();
  std::string parsed3_str = parser3.parse();

  EXPECT_EQ(parsed1_str, "echo a b c ");
  EXPECT_EQ(parsed2_str, "");
  EXPECT_EQ(parsed3_str, "echo hi how are you \"# I should still see this\"");
}

TEST(GROUP_PARSER_TEST, SEPARATE_BY_GROUPS) {
  GroupParser parser1("echo [test] (hello)");
  GroupParser parser2("echo [hello(test)]");
  GroupParser parser3("echo \"(hello)\"");

  std::vector<std::string> parsed1_vec = parser1.parse();
  std::vector<std::string> parsed2_vec = parser2.parse();
  std::vector<std::string> parsed3_vec = parser3.parse();

  EXPECT_EQ(parsed1_vec[0], "echo ");
  EXPECT_EQ(parsed1_vec[1], "[");
  EXPECT_EQ(parsed1_vec[2], "test");
  EXPECT_EQ(parsed1_vec[3], "]");
  EXPECT_EQ(parsed1_vec[4], " ");
  EXPECT_EQ(parsed1_vec[5], "(");
  EXPECT_EQ(parsed1_vec[6], "hello");
  EXPECT_EQ(parsed1_vec[7], ")");

  EXPECT_EQ(parsed2_vec[0], "echo ");
  EXPECT_EQ(parsed2_vec[1], "[");
  EXPECT_EQ(parsed2_vec[2], "hello");
  EXPECT_EQ(parsed2_vec[3], "(");
  EXPECT_EQ(parsed2_vec[4], "test");
  EXPECT_EQ(parsed2_vec[5], ")");
  EXPECT_EQ(parsed2_vec[6], "]");

  EXPECT_EQ(parsed3_vec[0], "echo \"(hello)\"");
}

TEST(CONNECTOR_PARSER_TEST, SEPARATE_BY_CONNECTORS) {
  std::vector<std::string> vec1 = {"echo hi &&cd ./src || mkdir dir"};
  std::vector<std::string> vec2 = {"echo hi \"&& echo hello\""};
  std::vector<std::string> vec3 = {"echo hello ;echo yes"};
  ConnectorParser parser1(vec1);
  ConnectorParser parser2(vec2);
  ConnectorParser parser3(vec3);

  std::vector<std::string> parsed_vec1 = parser1.parse();
  std::vector<std::string> parsed_vec2 = parser2.parse();
  std::vector<std::string> parsed_vec3 = parser3.parse();

  EXPECT_EQ(parsed_vec1[0], "echo");
  EXPECT_EQ(parsed_vec1[1], "hi");
  EXPECT_EQ(parsed_vec1[2], "&&");
  EXPECT_EQ(parsed_vec1[3], "cd");
  EXPECT_EQ(parsed_vec1[4], "./src");
  EXPECT_EQ(parsed_vec1[5], "||");
  EXPECT_EQ(parsed_vec1[6], "mkdir");
  EXPECT_EQ(parsed_vec1[7], "dir");

  EXPECT_EQ(parsed_vec2[0], "echo");
  EXPECT_EQ(parsed_vec2[1], "hi");
  EXPECT_EQ(parsed_vec2[2], "\"&& echo hello\"");

  EXPECT_EQ(parsed_vec3[0], "echo");
  EXPECT_EQ(parsed_vec3[1], "hello");
  EXPECT_EQ(parsed_vec3[2], ";");
  EXPECT_EQ(parsed_vec3[3], "echo");
  EXPECT_EQ(parsed_vec3[4], "yes");
}