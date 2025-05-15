#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  /* TODO: Implement this method */
  Corpus tokens;

  // 1. Identify all iterators to space characters
  auto token_pos_list = find_all(source.begin(), source.end(), isspace);
  
  if (token_pos_list.size() > 1) {
    // 2. Generate tokens between consecutive space characters
    std::transform(token_pos_list.begin(), token_pos_list.end() - 1, 
                  token_pos_list.begin() + 1,
                  std::inserter(tokens, tokens.end()), 
                  [&source](auto it1, auto it2) { 
                    return Token(source, it1, it2); 
                  });
    
    // 3. Get rid of empty tokens
    std::erase_if(tokens, [](const auto& token){ 
      return token.content.empty(); 
    });
  }

  return tokens;
}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  namespace rv = std::ranges::views;
  
  auto view = source 
    // 1. Skip words that are already correctly spelled.
    | rv::filter([&dictionary](auto token){ return !(dictionary.contains(token.content)); })
    // 2. Find one-edit-away words in the dictionary using Damerau-Levenshtein
    | rv::transform([&dictionary](auto token){
        auto sub_view = dictionary | rv::filter([&token](auto word){
            return levenshtein(token.content, word) == 1;
        });
        return Mispelling(token, std::set<std::string>(sub_view.begin(), sub_view.end()));
      })
    // 3. Drop misspellings with no suggestions.
    | rv::filter([](auto mispell){ return !(mispell.suggestions.empty()); });

  return std::set<Mispelling>(view.begin(), view.end());
};

/* Helper methods */

#include "utils.cpp"