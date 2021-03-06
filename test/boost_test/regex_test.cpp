#include <string>
#include <iostream>
#include <boost/regex.hpp>
//编译选项 "-lboost_regex"
#include "zuo/ioutils.hpp"

boost::regex e("(\\d{3,4})[- ]?(\\d{4})[- ]?(\\d{4})[- ]?(\\d{4})");

bool is_possible_card_number(const std::string& input)
{
   //
   // return false for partial match, true for full match, or throw for
   // impossible match based on what we have so far...
   boost::match_results<std::string::const_iterator> what;
   if(0 == boost::regex_match(input, what, e, boost::match_default | boost::match_partial))
   {
      // the input so far could not possibly be valid so reject it:
      throw std::runtime_error(
         "Invalid data entered - this could not possibly be a valid card number");
   }
   // OK so far so good, but have we finished?
   if(what[0].matched)
   {
      // excellent, we have a result:
      return true;
   }
   // what we have so far is only a partial match...
   return false;
}
int main()
{
   println(is_possible_card_number("17312345687"));
   return 0;
}